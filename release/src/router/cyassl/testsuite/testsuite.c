/* testsuite.c */

#include "openssl/ssl.h"
#include "../examples/test.h"
#include "md5.h"

#ifdef SINGLE_THREADED
    #error testsuite needs threads to run, please run ctaocrypt/test, \
           and the examples/ individually
#endif

void wait_tcp_ready(func_args*);
void ctaocrypt_test(void*);

void client_test(void*);
void echoclient_test(void*);

THREAD_RETURN CYASSL_API server_test(void*);
THREAD_RETURN CYASSL_API echoserver_test(void*);

void file_test(char* file, byte* hash);

enum {
    NUMARGS = 3
};


int main(int argc, char** argv)
{
    func_args args;
    func_args server_args;

    tcp_ready ready;
    THREAD_TYPE serverThread;

    StartTCP();

    args.argc = server_args.argc = argc;
    args.argv = server_args.argv = argv;
   
    /* CTaoCrypt test */
    ctaocrypt_test(&args);
    if (args.return_code != 0) return args.return_code;
 
    /* Simple CyaSSL client server test */
    InitCyaSSL();
    InitTcpReady(&ready);
    server_args.signal = &ready;
    start_thread(server_test, &server_args, &serverThread);
    wait_tcp_ready(&server_args);

    client_test(&args);
    if (args.return_code != 0) return args.return_code;
    join_thread(serverThread);
    if (server_args.return_code != 0) return server_args.return_code;

    /* Echo input yaSSL client server test */
    start_thread(echoserver_test, &server_args, &serverThread);
    wait_tcp_ready(&server_args);
    {
        func_args echo_args;
        char* myArgv[NUMARGS];

        char argc0[32];
        char argc1[32];
        char argc2[32];

        myArgv[0] = argc0;
        myArgv[1] = argc1;
        myArgv[2] = argc2;

        echo_args.argc = NUMARGS;
        echo_args.argv = myArgv;
   
        strcpy(echo_args.argv[0], "echoclient");
        strcpy(echo_args.argv[1], "input");
        strcpy(echo_args.argv[2], "output");
        remove("output");

        /* make sure OK */
        echoclient_test(&echo_args);
        if (echo_args.return_code != 0) return echo_args.return_code;  

#ifdef CYASSL_DTLS
        wait_tcp_ready(&server_args);
#endif
        /* send quit to echoserver */
        echo_args.argc = 2;
        strcpy(echo_args.argv[1], "quit");

        echoclient_test(&echo_args);
        if (echo_args.return_code != 0) return echo_args.return_code;
        join_thread(serverThread);
        if (server_args.return_code != 0) return server_args.return_code;
    }

    /* validate output equals input */
    {
        byte input[MD5_DIGEST_SIZE];
        byte output[MD5_DIGEST_SIZE];

        file_test("input",  input);
        file_test("output", output);
        if (memcmp(input, output, sizeof(input)) != 0)
            return -1;
    }

    FreeCyaSSL();
    FreeTcpReady(&ready);

    printf("\nAll tests passed!\n");
    return 0;
}



void wait_tcp_ready(func_args* args)
{
#ifdef _POSIX_THREADS
    pthread_mutex_lock(&args->signal->mutex);
    
    if (!args->signal->ready)
        pthread_cond_wait(&args->signal->cond, &args->signal->mutex);
    args->signal->ready = 0; /* reset */

    pthread_mutex_unlock(&args->signal->mutex);
#endif
}


void start_thread(THREAD_FUNC fun, func_args* args, THREAD_TYPE* thread)
{
#ifndef _POSIX_THREADS
    *thread = (HANDLE)_beginthreadex(0, 0, fun, args, 0, 0);
#else
    pthread_create(thread, 0, fun, args);
#endif
}


void join_thread(THREAD_TYPE thread)
{
#ifndef _POSIX_THREADS
    int res = WaitForSingleObject(thread, INFINITE);
    assert(res == WAIT_OBJECT_0);
    res = CloseHandle(thread);
    assert(res);
#else
    pthread_join(thread, 0);
#endif
}


void InitTcpReady(tcp_ready* ready)
{
    ready->ready = 0;
#ifdef _POSIX_THREADS
    pthread_mutex_init(&ready->mutex, 0);
    pthread_cond_init(&ready->cond, 0);
#endif
}


void FreeTcpReady(tcp_ready* ready)
{
#ifdef _POSIX_THREADS
    pthread_mutex_destroy(&ready->mutex);
    pthread_cond_destroy(&ready->cond);
#endif
}


void file_test(char* file, byte* check)
{
    FILE* f;
    int   i = 0, j;
    Md5   md5;
    byte  buf[1024];
    byte  md5sum[MD5_DIGEST_SIZE];
   
    InitMd5(&md5); 
    if( !( f = fopen( file, "rb" ) )) {
        printf("Can't open %s\n", file);
        return;
    }
    while( ( i = (int)fread(buf, 1, sizeof(buf), f )) > 0 )
        Md5Update(&md5, buf, i);
    
    Md5Final(&md5, md5sum);
    memcpy(check, md5sum, sizeof(md5sum));

    for(j = 0; j < MD5_DIGEST_SIZE; ++j ) 
        printf( "%02x", md5sum[j] );
   
    printf("  %s\n", file);

    fclose(f);
}


