/*SH1
*******************************************************************************
**                                                                           **
**         Copyright (c) 2009 - 2013 Quantenna Communications Inc            **
**                                                                           **
**  File        : qcsapi.h                                                   **
**  Description :                                                            **
**                                                                           **
*******************************************************************************
**                                                                           **
**  Redistribution and use in source and binary forms, with or without       **
**  modification, are permitted provided that the following conditions       **
**  are met:                                                                 **
**  1. Redistributions of source code must retain the above copyright        **
**     notice, this list of conditions and the following disclaimer.         **
**  2. Redistributions in binary form must reproduce the above copyright     **
**     notice, this list of conditions and the following disclaimer in the   **
**     documentation and/or other materials provided with the distribution.  **
**  3. The name of the author may not be used to endorse or promote products **
**     derived from this software without specific prior written permission. **
**                                                                           **
**  Alternatively, this software may be distributed under the terms of the   **
**  GNU General Public License ("GPL") version 2, or (at your option) any    **
**  later version as published by the Free Software Foundation.              **
**                                                                           **
**  In the case this software is distributed under the GPL license,          **
**  you should have received a copy of the GNU General Public License        **
**  along with this software; if not, write to the Free Software             **
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA  **
**                                                                           **
**  THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR       **
**  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES**
**  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  **
**  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,         **
**  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT **
**  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,**
**  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY    **
**  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT      **
**  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF **
**  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.        **
**                                                                           **
*******************************************************************************
EH1*/

/**
 * \file qcsapi.h
 *
 * The main QCSAPI header file containing function prototypes, data types etc.
 */

#ifndef _QCSAPI_H
#define _QCSAPI_H

#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#ifndef _NET_ETHERNET_H_
#include <net/ethernet.h>
#endif

#include <qtn/shared_defs.h>
#include <qtn/qvsp_data.h>

#include <common/ruby_pm.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Following #defines come from the TR-098 standard.
 * They are conditional in case another include file has already defined them.
 */

#ifndef IEEE80211_CHAN_MAX
#define IEEE80211_CHAN_MAX	255
#endif

#ifndef IW_ESSID_MAX_SIZE
#define IW_ESSID_MAX_SIZE	32
#endif

/* Begin QCSAPI definitions */

#define QCSAPI_WPS_SHORT_PIN_LEN	4
#define QCSAPI_WPS_MAX_PIN_LEN		8

#define QCSAPI_MAX_PARAMETER_NAME_LEN	24
#define QCSAPI_MAX_PARAMETER_VALUE_LEN	200

#define QCSAPI_MIN_LENGTH_REGULATORY_REGION	10
#define QCSAPI_MAX_BITRATE_STR_MIN_LEN 4

#define QCSAPI_QDRV_NUM_RF_STREAMS	4

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))
#endif

#define REGULATORY_DB_BIN_NOT_SUPPORT		-255

#define GET_PAIRING_ID 0
#define SET_PAIRING_ID 1

#define QCSAPI_SCRIPT_LOG	"/tmp/run_script.log"
#define QCSAPI_CMD_BUFSIZE 128
#define QCSAPI_MSG_BUFSIZE 1024

#define QCSAPI_SYSTEM_STATUS_FILE "/tmp/qtn_sys_status"

#define QCSAPI_PRIMARY_WIFI_IFNAME "wifi0"

#define QCSAPI_CUSTOM_DIR	"/etc/custom/"
#define QCSAPI_FILESYSTEM_SP	".."
#define QCSAPI_CUSTOM_VALUE_MAX_LEN	128

/**
 * @defgroup APIOverview Overview and conventions
 *
 * \brief This chapter gives an overview of how the data structures and APIs
 * are documented. An example function prototype is shown directly below.
 *
 * This chapter details the data structures (structs, enums, types etc.) used
 * by the QCSAPI, as well as the detailed information on the APIs.
 *
 * APIs are documented fully with details of what the functional call does,
 * the parameters accepted (input/outputs) and the return values.
 *
 * Each API also has a brief detail of if and how the function can be called
 * using the <c>call_qcsapi</c> command line utility. Some APIs are not able
 * to be called using <c>call_qcsapi</c> through the nature of the API.
 *
 * This chapter is divided into the data structure detailed documentation,
 * followed by subsections detailing rough functional API areas.
 *
 * The following section gives an example of how an API call is documented.
 */
int local_wifi_get_rf_chipid(int *chipid);

/*!
 * \ingroup APIOverview
 */
/* @{ */
/**
 * \fn int call_qcsapi_example(const char *ifname, int example_input,
 * 				int *example_output);
 *
 * \brief A brief description of the function call is provided inline with
 * the function listing for each section.
 *
 * In the Function Documentation section, for each API call, there is a
 * detailed definition of the function call, with extra information, side
 * effects, pre-requisites etc. This appears in the section which documents
 * the individual API call.
 *
 * After the detailed documentation the list of input/output parameters is
 * given.
 *
 * \param ifname Details of the parameter 'ifname'
 * \param example_input Details of the input parameter 'example_input'
 * \param example_output Details of the output parameter 'example_output'.
 * Output parameters are generally seen as pointers to variables.
 *
 * After the parameter list, the return values are documented.
 *
 * \return Details of the return value (generally >= 0 indicates, success,
 * < 0 indicates failure). See the section @ref mysection4_1_4 "QCSAPI return values"
 * for details of the different return values.
 *
 * In addition to this, there may be extra documentation and references to
 * other function calls.
 *
 * \note Something noteworthy about the API may be documented in one of these
 * blocks.
 *
 * \warning Something that the reader <b>must</b> read and take into account
 * may be documented in one of these blocks.
 *
 * \callqcsapi
 *
 * This is where the command line <c>call_qcsapi</c> interface is detailed.
 * Input parameters, and expected output will be given.
 *
 * \note Not all QCSAPI C API calls have equivalent <c>call_qcsapi</c> command
 * line calls.
 */

/* NOTE: present to show up example documentation for QCSAPI doco. */
extern int call_qcsapi_example(const char *ifname, int example_input,
 				int *example_output);
/* @} */

/**
 * @defgroup DetailedDataTypes Detailed data type and enumeration documentation
 *
 * \brief This section contains detailed documentation on the data types and enumerations
 * used in the QCSAPI.
 */
/**
 * \ingroup DetailedDataTypes
 */
/* @{ */
/**
 * \anchor QCSAPI_ERRNO
 *
 * \brief This enumeration represents the internal QCSAPI error return values that
 * may be returned by various QCSAPIs.
 *
 * This enumeration represents the internal QCSAPI error return values that
 * may be returned by various QCSAPIs. Some errors may be returned from many different
 * APIs, whereas other errors are for only one API call.
 *
 * Each error code indicates the area of the QCSAPI the code is relevant to.
 *
 * To get an error string associated with the error message, use the API call
 * qcsapi_errno_get_message.
 *
 * In addition to the error codes listed in the following sections (which start at
 * error number 1000 - <c>qcsapi_errno_base</c>), the following POSIX defined errors
 * are used in the QCSAPI:
 *
 * <TABLE>
 * <TR><TD>ERRNO value</TD><TD>QCSAPI Error</TD><TD>Description</TD></TR>
 * <TR><TD><c>-EFAULT</c></TD><TD>QCS API error 14: Bad address</TD>
 * <TD>The QCSAPI found a problem with an argument passed by reference;
 * most likely the address was the NULL address.</TD></TR>
 * <TR><TD><c>-EINVAL</c></TD><TD>QCS API error 22: Invalid argument</TD>
 * <TD>The QCSAPI found the value of an argument is not valid. Examples are
 * numeric value out of range (eg, WiFi channel larger than 255), or a parameter
 * value not allowed by the WiFi standard.</TD></TR>
 * <TR><TD><c>-ENODEV</c></TD><TD>QCS API error 19: No such device</TD>
 * <TD>No such device. An operation was attempted using a device that does not
 * exist.</TD></TR>
 * <TR><TD><c>-EOPNOTSUPP</c></TD><TD>QCS API error 95: Operation not supported</TD>
 * <TD>Operation not supported. For example, an operation limited to a WiFi device
 * such as get 802.11 standard or get beacon type was attempted using an interface
 * that is not a WiFi device.</TD></TR>
 * <TR><TD><c>-ERANGE</c></TD><TD>QCS API error 34: Parameter value out of range</TD>
 * <TD>This error occurs when the API accesses an element in an array using an index
 * parameter, and the index is too large or out of range. An example is the per-association
 * APIs.</TD></TR>
 * </TABLE>
 *
 * \sa qcsapi_errno_get_message
 */
enum qcsapi_errno
{
	qcsapi_errno_base = 1000,
	/**
	 * This error code is returned when attempts are made to apply changes when
	 * the wireless system is not started. The most typical situation this error
	 * message is returned is when the Quantenna kernel modules have not been loaded.
	 *
	 * Many different QCSAPI function calls attempt to apply changes, and the
	 * majority of QCSAPI calls dealing with the wireless driver may return this
	 * value.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1000: System not started</c>
	 */
	qcsapi_system_not_started = qcsapi_errno_base,
	/**
	 * This error code is returned when an attempt to read in an unknown parameter
	 * via the qcsapi_config_get_parameter.
	 *
	 * \sa qcsapi_config_get_parameter
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1001: Parameter not found</c>
	 */
	qcsapi_parameter_not_found = qcsapi_errno_base + 1,
	/**
	 * This error code is returned when an SSID API call is made, but the SSID referred
	 * to does not exist.
	 *
	 * The SSID may not exist due to the config file being missing, or due to the config
	 * file not containing the passed in SSID. See \ref SSIDAPIs "SSID APIs".
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1002: SSID not found</c>
	 */
	qcsapi_SSID_not_found = qcsapi_errno_base + 2,
	/**
	 * This error code is returned when a QCSAPI call is attempted on an STA device, but
	 * the call only applies to the AP.
	 *
	 * This return value is used in many different QCSAPIs, across all functional areas.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1003: Operation only available on an AP</c>
	 */
	qcsapi_only_on_AP = qcsapi_errno_base + 3,
	/**
	 * This error code is returned when a QCSAPI call is attempted on an AP device, but
	 * the call only applies to the STA.
	 *
	 * This return value is used in many different QCSAPIs, across all functional areas.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1004: Operation only available on a STA</c>
	 */
	qcsapi_only_on_STA = qcsapi_errno_base + 4,
	/**
	 * This error code is returned when the action implied by the API conflicts with the
	 * current configuration.
	 *
	 * An example is getting a list of authorized MAC addresses when MAC address filtering
	 * is not enabled.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1005: Configuration error</c>
	 */
	qcsapi_configuration_error = qcsapi_errno_base + 5,
	/**
	 * This error code is returned when a variable length input buffer is too small for
	 * the QCSAPI result. For example, when retrieving error messages.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1006: Insufficient space in the string to receive results</c>
	 */
	qcsapi_buffer_overflow = qcsapi_errno_base + 6,
	/**
	 * This error code is returned when an internal error is detected when parsing config
	 * files or other data sets.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1007: Internal formatting error</c>
	 */
	qcsapi_internal_format_error = qcsapi_errno_base + 7,
	/**
	 * This error code is returned when a system call is made in the code and it fails for
	 * some reason.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1008: Internal API programming error</c>
	 */
	qcsapi_programming_error = qcsapi_errno_base + 8,
	/**
	 * This error code is returned when a QCSAPI call is made that is only supported in
	 * bringup mode.
	 *
	 * See @ref mysection4_1_5 "Production Mode vs Bringup Mode"
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1009: Operation only available in bringup mode</c>
	 */
	qcsapi_bringup_mode_only = qcsapi_errno_base + 9,
	/**
	 * This error code is returned when a socket connection to the security daemon (opened
	 * to send a command to the running daemon) fails for whatever reason.
	 *
	 * If this error is returned, one or more of the sequence of events in the QCSAPI call
	 * has failed, and the system may be in an inconsistent state.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1010: Cannot contact security manager</c>
	 */
	qcsapi_daemon_socket_error = qcsapi_errno_base + 10,
	/**
	 * This error code is deprecated and not returned by any current API.
	 */
	qcsapi_conflicting_options = qcsapi_errno_base + 11,
	/**
	 * This error code is returned when the SSID cannot be found (when searching to see if
	 * an SSID is present).
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1012: Required parameter not found in the SSID configuration block</c>
	 */
	qcsapi_SSID_parameter_not_found = qcsapi_errno_base + 12,
	/**
	 * This error code is returned when qcsapi_init has not been called prior to invoking
	 * certain APIs (that require qcsapi_init to be called).
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1013: Initialization API qcsapi_init has not been called</c>
	 */
	qcsapi_not_initialized = qcsapi_errno_base + 13,
	/**
	 * This error code is returned when the flash upgrade image is not a regular file on
	 * the filesystem (eg, is a directory or device special file).
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1014: Invalid file type for a flash image update file</c>
	 */
	qcsapi_invalid_type_image_file = qcsapi_errno_base + 14,
	/**
	 * This error code is returned when the flash upgrade image fails verification checks.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1015: chkimage utility failed for the flash image update file</c>
	 */
	qcsapi_image_file_failed_chkimage = qcsapi_errno_base + 15,
	/**
	 * This error code is returned when the flash upgrade partition is not found or is
	 * invalid.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1016: flash partition not found</c>
	 */
	qcsapi_flash_partition_not_found = qcsapi_errno_base + 16,
	/**
	 * This error code is returned when the command to erase the flash partition failed.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1017: failed to erase the flash memory partition</c>
	 */
	qcsapi_erase_flash_failed = qcsapi_errno_base + 17,
	/**
	 * This error code is returned when the copy of the flash image into the flag part
	 * failed.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1018: failed to copy the new image to the flash memory partition</c>
	 */
	qcsapi_copy_image_flash_failed = qcsapi_errno_base + 18,
	/**
	 * This error code is returned when a call is made into an API where the operational
	 * state of the system is not known. This is an internal error, and should never be
	 * seen in ordinary circumstances.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1019: invalid WiFi mode</c>
	 */
	qcsapi_invalid_wifi_mode = qcsapi_errno_base + 19,
	/**
	 * This error code is returned when the call to qcsapi_console_disconnect fails due
	 * to not enough system resources.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 * <c>QCS API error 1020: Process table is full</c>
	 */
	qcsapi_process_table_full = qcsapi_errno_base + 20,
	/**
	 * This error code is deprecated and not returned by any current API.
	 */
	qcsapi_measurement_not_available = qcsapi_errno_base + 21,
	/**
	 * This error code is returned when trying to create a new BSS, but the maximum number of
	 * BSSes are already created.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1022: Maximum number of BSSIDs / VAPs exceeded</c>
	 */
	qcsapi_too_many_bssids = qcsapi_errno_base + 22,
	/**
	 * This error code is returned when an operation is attempted on a non-primary interface
	 * (wifi0). This can happen for certain security settings and when performing WDS functions.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1023: Operation only available on the primary WiFi interface</c>
	 */
	qcsapi_only_on_primary_interface = qcsapi_errno_base + 23,
	/**
	 * This error code is returned when trying to create a new WDS link, but the maximum
	 * number of WDS links are already created.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1024: Maximum number of WDS links exceeded</c>
	 */
	qcsapi_too_many_wds_links = qcsapi_errno_base + 24,
	/**
	 * This error code is returned when an attempt to update a config file (persistent file)
	 * fails.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1025: Failed to update persistent configuration</c>
	 */
	qcsapi_config_update_failed = qcsapi_errno_base + 25,
	/**
	 * This error code is returned when the /proc/net/dev or /proc/net/packets device files
	 * are not present on the filesystem.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1026: Cannot access network counters</c>
	 */
	qcsapi_no_network_counters = qcsapi_errno_base + 26,
	/**
	 * This error code is returned when the PM interval passed in is invalid.
	 * That is, it is not one of the supported interval device files.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1027: Invalid performance monitoring interval</c>
	 */
	qcsapi_invalid_pm_interval = qcsapi_errno_base + 27,
	/**
	 * This error code is returned when an operation relevant only to WDS mode is attempted on
	 * a non-WDS operational mode device.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1028: Operation only available on a WDS device</c>
	 */
	qcsapi_only_on_wds = qcsapi_errno_base + 28,
	/**
         * This error code is returned when an multicast or broadcast MAC
	 * is used where only unicast MAC is allowed.
         *
         * <c>call_qcsapi</c> printed error message:
         *
         * <c>QCS API error 1029: Only unicast MAC address is allowed</c>
         */
	qcsapi_only_unicast_mac = qcsapi_errno_base + 29,
	/**
	 * This error code is returned when performing an invalid operation.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1030: Operation is not available on the primary interface</c>
	 */
	qcsapi_primary_iface_forbidden = qcsapi_errno_base + 30,
	/**
	 * This error code is returned when a BSS is created, but the interface name is incorrect.The BSS prefix name must be the string 'wifi'.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1031: Invalid BSS name</c>
	 */
	qcsapi_invalid_ifname = qcsapi_errno_base + 31,
	/**
	 * This error code is returned when an error happens on interface.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1032: An error happened on interface</c>
	 */
	qcsapi_iface_error = qcsapi_errno_base + 32,
	/**
	 * This error code is returned when a semaphore takes too long to initialize.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1033: Semaphore initialization error</c>
	 */
	qcsapi_sem_error = qcsapi_errno_base + 33,
	/**
	 * This error code is returned when a command is issued for a feature that is not
	 * supported in this image.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1034: Feature is not supported</c>
	 */
	qcsapi_not_supported = qcsapi_errno_base + 34,
	/**
	 * This error code is returned when a channel as input is not a dfs channel
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1035: API requires a dfs channel</c>
	 */
	qcsapi_invalid_dfs_channel = qcsapi_errno_base + 35,
	/**
	 * This error code is returned when a file can not be found.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1036: Script failed</c>
	 */
	qcsapi_script_error = qcsapi_errno_base + 36,
	/**
	 * This error code is returned when set mac address of wds peer is local address.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1037: Local Mac address can't be used as wds peer address</c>
	 */
	qcsapi_invalid_wds_peer_addr = qcsapi_errno_base + 37,
	/**
	 * This error code is returned when band is not supported.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1038: Band is not supported</c>
	 */
	qcsapi_band_not_supported = qcsapi_errno_base + 38,
	/**
	 * This error code is returned when region is not supported.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1039: Region is not supported</c>
	 */
	qcsapi_region_not_supported = qcsapi_errno_base + 39,
	/**
	 * This error code is returned when region database is not found.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1040: Region database is not found</c>
	 */
	qcsapi_region_database_not_found = qcsapi_errno_base + 40,
	/**
	 * This error code is returned when a parameter name is not supported
	 * by wireless_conf.txt.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1041: Parameter name is not supported</c>
	 */
	qcsapi_param_name_not_supported = qcsapi_errno_base + 41,
	/**
	 * This error code is returned when parameter value is invalid
	 * in wireless_conf.txt.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1042: Parameter value is invalid</c>
	 */
	qcsapi_param_value_invalid = qcsapi_errno_base + 42,
	/**
	 * This error code is returned when an input MAC address is invalid
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <c>QCS API error 1043: Invalid MAC address</c>
	 */
	qcsapi_invalid_mac_addr = qcsapi_errno_base + 43,
	/**
	 * This error code is returned when an option is not supported.
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <QCS API error 1044: Option is not supported>
	 */
	qcsapi_option_not_supported = qcsapi_errno_base + 44,
	/**
	 * This error code is returned when a wps overlap detected
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <QCS API error 1045: WPS Overlap detected>
	 */
	qcsapi_wps_overlap_detected = qcsapi_errno_base + 45,
	/**
	 * This error code is returned when a statistics module is not supported
	 *
	 * <c>call_qcsapi</c> printed error message:
	 *
	 * <QCS API error 1046: MLME statistics is not supported>
	 */
	qcsapi_mlme_stats_not_supported = qcsapi_errno_base + 46,
};

/*
 * GPIO / LED PIN numbers
 *
 * LEDs are a subset of GPIO PINs
 */

/**
 * \brief This enumeration represents an abstract LED value.
 *
 * This enumeration represents an abstract LED value.
 */
enum qcsapi_led
{
	qcsapi_AGPIO1_LED = 1,
	qcsapi_AGPIO2_LED = 2,
	qcsapi_AGPIO3_LED = 3,
	qcsapi_AGPIO4_LED = 4,
	qcsapi_AGPIO5_LED = 5,
	qcsapi_AGPIO7_LED = 7,
	qcsapi_AGPIO11_LED = 11,
	qcsapi_AGPIO12_LED = 12,
	qcsapi_AGPIO27_LED = 27,
	qcsapi_nosuch_GPIO = 255,

	QCSAPI_MAX_LED = 31
};

/**
 * \brief This enumeration represents a set of security and authentication
 * modes.
 *
 * This enumeration represents a set of security and authentication modes.
 *
 * The security mode consists of an authentication method (eg, WPA, WPA2,
 * EAP, etc.) and an encryption method (eg, WEP, TKIP, CCMP). These are
 * represented in this enumeration.
 *
 * See @ref APSTADualFunctions "Authentication protocols and encrypyion" for
 * details of the difference between authentication and encryption.
 */
enum qcsapi_auth_crypto
{
	/**
	 * This value represents WPA v1 authentication mode.
	 */
	qcsapi_protocol_WPA_mask = 1,
	/**
	 * This value represents WPA v2 authentication mode.
	 */
	qcsapi_protocol_11i_mask = 2,

	/**
	 * This value represents preshared key authentication.
	 */
	qcsapi_ap_PSK_authentication = 1,
	/**
	 * This value represents EAP authentication.
	 */
	qcsapi_ap_EAP_authentication = 2,

	/**
	 * Thie value represents use of the TKIP cipher for encryption.
	 */
	qcsapi_ap_TKIP_encryption_mask = 0x01,
	/**
	 * Thie value represents use of the CCMP cipher for encryption.
	 */
	qcsapi_ap_CCMP_encryption_mask = 0x02,

	/**
	 * This value represents security is enabled on the interface.
	 */
	qcsapi_ap_security_enabled = 0x01,
};

/**
 * \brief This enumeration is used to represent GPIO state.
 *
 * This enumeration is used to represent GPIO state.
 */
typedef enum
{
	/**
	 * This value indicates that the GPIO isn't available for some reason.
	 */
	qcsapi_gpio_not_available = 0,
	/**
	 * Thie value indicates that the GPIO is set to input only mode.
	 */
	qcsapi_gpio_input_only,
	/**
	 * Thie value indicates that the GPIO is set to output only.
	 */
	qcsapi_gpio_output,
	/**
	 * This is the invalid value - representing that a GPIO is not present
	 * on the platform.
	 */
	qcsapi_nosuch_gpio_config = -1
} qcsapi_gpio_config;

/**
 * \brief This enumeration is used to abstract configuration file paths.
 *
 * This enumeration is used to abstract configuration file paths.
 */
typedef enum
{
	/**
	 * This value is used to represent the security config file path.
	 */
	qcsapi_security_configuration_path = 0,
	/**
	 * Placeholder - invalid value.
	 */
	qcsapi_nosuch_file_path = -1
} qcsapi_file_path_config;

/**
 * \brief This enumeration represents the operational mode of the device.
 *
 * This enumeration represents the operational mode of the device.
 */
typedef enum {
	/**
	 * This value is a valid, and indicates that programs have not configured the
	 * WiFi mode.
	 */
	qcsapi_mode_not_defined = 1,
	/**
	 * The device is operating as an AP.
	 */
	qcsapi_access_point,
	/**
	 * The device is operating as a STA.
	 */
	qcsapi_station,
	/**
	 * The device is operating in WDS mode - wireless distribution mode, or bridged
	 * mode.
	 */
	qcsapi_wds,
	/**
	 * Invalid mode. Placeholder.
	 */
	qcsapi_nosuch_mode = 0
} qcsapi_wifi_mode;

/**
 * \brief Enumeration to represent rate sets.
 *
 * Enumeration to represent different rate sets as used in the system.
 */
typedef enum {
	/**
	 * The set of basic rates which must be supported by all clients.
	 */
	qcsapi_basic_rates = 1,
	/**
	 * The set of actual rates in use.
	 */
	qcsapi_operational_rates,
	/**
	 * The set of all supported rates on the device.
	 */
	qcsapi_possible_rates,
	/**
	 * Placeholder - invalid.
	 */
	qcsapi_nosuch_rate = 0
} qcsapi_rate_type;

/**
 * \brief Enumeration to represent 802.11 standards
 */
typedef enum {
	/**
	 * 11n
	 */
	qcsapi_mimo_ht = 1,
	/**
	 * 11ac
	 */
	qcsapi_mimo_vht,
	/**
	 * Placeholder - invalid.
	 */
	qcsapi_nosuch_standard = 0
} qcsapi_mimo_type;

/**
 * \brief Enumeration used to represent different interface counters.
 *
 * \sa qcsapi_interface_get_counter
 * \sa qcsapi_pm_get_counter
 * \sa qcsapi_wifi_get_node_counter
 */
typedef enum {
	qcsapi_nosuch_counter = 0,
	QCSAPI_NOSUCH_COUNTER = qcsapi_nosuch_counter,
	qcsapi_total_bytes_sent = 1,
	QCSAPI_TOTAL_BYTES_SENT = qcsapi_total_bytes_sent,
	qcsapi_total_bytes_received,
	QCSAPI_TOTAL_BYTES_RECEIVED = qcsapi_total_bytes_received,
	qcsapi_total_packets_sent,
	QCSAPI_TOTAL_PACKETS_SENT = qcsapi_total_packets_sent,
	qcsapi_total_packets_received,
	QCSAPI_TOTAL_PACKETS_RECEIVED = qcsapi_total_packets_received,
	qcsapi_discard_packets_sent,
	QCSAPI_DISCARD_PACKETS_SENT = qcsapi_discard_packets_sent,
	qcsapi_discard_packets_received,
	QCSAPI_DISCARD_PACKETS_RECEIVED = qcsapi_discard_packets_received,
	qcsapi_error_packets_sent,
	QCSAPI_ERROR_PACKETS_SENT = qcsapi_error_packets_sent,
	qcsapi_error_packets_received,
	QCSAPI_ERROR_PACKETS_RECEIVED = qcsapi_error_packets_received,
	qcsapi_fragment_frames_received,
	QCSAPI_FRAGMENT_FRAMES_RECEIVED = qcsapi_fragment_frames_received,
	qcsapi_vlan_frames_received,
	QCSAPI_VLAN_FRAMES_RECEIVED = qcsapi_vlan_frames_received,
} qcsapi_counter_type;

/**
 * \brief Enumeration for parameters as read in via qcsapi_wifi_get_node_param.
 *
 * \sa qcsapi_wifi_get_node_param
 */
typedef enum {
	QCSAPI_NO_SUCH_PER_ASSOC_PARAM = 0,
	QCSAPI_LINK_QUALITY = 1,
	QCSAPI_RSSI_DBM,
	QCSAPI_BANDWIDTH,
	QCSAPI_SNR,
	QCSAPI_TX_PHY_RATE,
	QCSAPI_RX_PHY_RATE,
	QCSAPI_STAD_CCA,
	QCSAPI_HW_NOISE,
	QCSAPI_STA_IP,
	QCSAPI_RSSI,
	QCSAPI_PHY_NOISE,
	QCSAPI_SOC_MAC_ADDR,
	QCSAPI_SOC_IP_ADDR,
	QCSAPI_NODE_MEAS_BASIC,
	QCSAPI_NODE_MEAS_CCA,
	QCSAPI_NODE_MEAS_RPI,
	QCSAPI_NODE_MEAS_CHAN_LOAD,
	QCSAPI_NODE_MEAS_NOISE_HIS,
	QCSAPI_NODE_MEAS_BEACON,
	QCSAPI_NODE_MEAS_FRAME,
	QCSAPI_NODE_MEAS_TRAN_STREAM_CAT,
	QCSAPI_NODE_MEAS_MULTICAST_DIAG,
	QCSAPI_NODE_TPC_REP,
	QCSAPI_NODE_LINK_MEASURE,
	QCSAPI_NODE_NEIGHBOR_REP,
} qcsapi_per_assoc_param;

#define QCSAPI_LOCAL_NODE	0
#define QCSAPI_REMOTE_NODE	1

/* This enum lists booleans (yes / no ) */

#define QCSAPI_TRUE	1
#define QCSAPI_FALSE	0

/**
 * \brief Enumeration used in the option set/get API.
 *
 * \sa qcsapi_wifi_get_option
 * \sa qcsapi_wifi_set_option
 */
typedef enum {
	qcsapi_channel_refresh = 1,		/* 2.4 GHz only */
	qcsapi_DFS,				/* 5 GHz only */
	qcsapi_wmm,				/* wireless multimedia extensions */
	qcsapi_mac_address_control,
	qcsapi_beacon_advertise,
	qcsapi_wifi_radio,
	qcsapi_autorate_fallback,
	qcsapi_security,
	qcsapi_SSID_broadcast,
	qcsapi_802_11d,
	qcsapi_wireless_isolation,
	qcsapi_short_GI,
	qcsapi_802_11h,
	qcsapi_dfs_fast_channel_switch,
	qcsapi_dfs_avoid_dfs_scan,
	qcsapi_uapsd,
	qcsapi_tpc_query,
	qcsapi_sta_dfs,
	qcsapi_specific_scan,
	qcsapi_GI_probing,
	qcsapi_GI_fixed,
	qcsapi_nosuch_option = 0
} qcsapi_option_type;

/**
 * \brief This enumeration represents the bandwidth in use on the device.
 *
 * This enumeration represents the bandwidth in use on the device.
 */
typedef enum
{
	/**
	 * The device is operating in 20MHz mode.
	 */
	qcsapi_bw_20MHz = 20,
	/**
	 * The device is operating in 40MHz mode.
	 */
	qcsapi_bw_40MHz = 40,
	/**
         * The device is operating in 80MHz mode.
         */
        qcsapi_bw_80MHz = 80,
        /**
         * The device is operating in 160MHz mode.
         */
        qcsapi_bw_160MHz = 160,
        /**
         * Placeholder - unknown bandwidth (indicates error).
         */

	/**
	 * Placeholder - unknown bandwidth (indicates error).
	 */
	qcsapi_nosuch_bw
} qcsapi_bw;

/**
 * \brief This enumeration represents the mode in use on the device.
 *
 * This enumeration represents the bandwidth in use on the device.
 *
 * This enumeration is used to set the correct bandwidth.
 */

typedef enum
{
	qcsapi_11nac_disable = 0,
	qcsapi_11nac_enable = 1
}qcsapi_11nac_stat;

/**
 * \brief This enumeration represents the state of the MAC address filtering.
 *
 * This enumeration represents the state of the MAC address filtering.
 *
 * MAC address filtering can be inclusive, exclusive or disabled.
 */
typedef enum
{
	/**
	 * MAC address filtering is fully disabled.
	 */
	qcsapi_disable_mac_address_filtering = 0,
	/**
	 * MAC address inclusive filtering - allow all packets unless explicitly
	 * denied in the filter list.
	 */
	qcsapi_accept_mac_address_unless_denied,
	/**
	 * MAC address exclusive filtering - deny all packets unless explicitly
	 * allowed in the filter list.
	 */
	qcsapi_deny_mac_address_unless_authorized,
	/**
	 * Placeholder - indicates an error.
	 */
	qcsapi_nosuch_mac_address_filtering = -1
} qcsapi_mac_address_filtering;

/**
 * \brief Enumeration to represent AP isolation status.
 *
 */
typedef enum
{
	/**
	 * AP isolation is disabled.
	 * Frames between associated stations in the BSS are passed.
	 */
	qcsapi_ap_isolate_disabled = 0,
	/**
	 * AP isolation is enabled.
	 * Frames between associated stations in the BSS are blocked.
	 */
	qcsapi_ap_isolate_enabled = 1,
	/**
	 * Placeholder - unused.
	 */
	qcsapi_ap_isolation_end
} qcsapi_ap_isolate_type;

/**
 * \brief This enumeration represents the partitions supported for firmware upgrade.
 *
 * This enumeration represents the partitions supported for firmware upgrade.
 *
 * The two partitions used for firmware are the live and safety images. Ideally, the
 * safety image is never touched, and is always present to allow the system to recover
 * to a known good (factory) setting.
 */
typedef enum
{
	/**
	 * This represents the live image partition - the partition that should be
	 * upgraded.
	 */
	qcsapi_live_image = 0,
	/**
	 * This represents the safety image partition - this should not be touched.
	 */
	qcsapi_safety_image,
	/**
	 * Placeholder - indicates an error.
	 */
	qcsapi_nosuch_partition = -1
} qcsapi_flash_partiton_type;

/**
 * \brief Enumeration to represent WPS parameters as used by the qcsapi_wps_get_param API.
 *
 * \sa qcsapi_wps_get_param
 */
typedef enum
{
	/**
	 * The WPS device UUID.
	 */
	qcsapi_wps_uuid = 0,
	/**
	 * The OS version the WPS device is running.
	 */
	qcsapi_wps_os_version,
	/**
	 * The device name of the WPS device.
	 */
	qcsapi_wps_device_name,
	/**
	 * The supported configuration methods (eg, PBC, PIN) of the WPS device.
	 */
	qcsapi_wps_config_methods,
	/**
	 * Whether the AP setup is locked or able to be reconfigured by an external
	 * registrar.
	 */
	qcsapi_wps_ap_setup_locked,
	/**
	 * The label pin of the ap which is configured in the hostapd.conf
	 */
	qcsapi_wps_ap_pin,
	/**
	 * flag to force broadcast uuid
	 */
	qcsapi_wps_force_broadcast_uuid,
	/**
	 * Last configuration error of WPS registrar
	 */
	qcsapi_wps_last_config_error,
	/**
	 * Number of entries for WPS registrar
	 */
	qcsapi_wps_registrar_number,
	/**
	 * Number of estabalished WPS registrar
	 */
	qcsapi_wps_registrar_established,
	/**
	 * Placeholder - unused.
	 */
	qcsapi_wps_param_end
} qcsapi_wps_param_type;

/**
 * \brief Enumeration to represent VLAN configuration command as used by the qcsapi_wifi_vlan_config API.
 *
 * \sa qcsapi_wifi_vlan_config
 */
typedef enum {
	/**
	 * Command to bind VLAN to a wireless interface.
	 */
	e_qcsapi_vlan_bind,
	/**
	 * Command to unbind VLAN from a wireless interface.
	 */
	e_qcsapi_vlan_unbind,
	/*
	* Command to terminate specified VLAN-ID frames
	*/
	e_qcsapi_vlan_terminate,
	/*
	* Command to unterminate specified VLAN-ID frames
	*/
	e_qcsapi_vlan_unterminate
} qcsapi_vlan_cmd;


/**
 * \anchor QCSAPI_GET_SYSTEM_STATUS
 * \brief Bit number to represent system status value
 *
 * \sa qcsapi_get_system_status
 */
typedef enum {
	/**
	 * 1 means ethernet interface is up.
	 * 0 means ethernet interface is down.
	 */
	qcsapi_sys_status_ethernet = 0,
	/**
	 * 1 means pcie module for EP is loaded correctly.
	 * 0 means pcie module for EP is failed to load.
	 */
	qcsapi_sys_status_pcie_ep = 1,
	/**
	 * 1 means pcie module for RC is loaded correctly.
	 * 0 means pcie module for RC is failed to load.
	 */
	qcsapi_sys_status_pcie_rc = 2,
	/**
	 * 1 means wifi module is loaded correctly.
	 * 0 means wifi module is failed to load.
	 */
	qcsapi_sys_status_wifi = 3,
	/**
	 * 1 means Rpcd is ready.
	 * 0 Rpcd is failed to start.
	 */
	qcsapi_sys_status_rpcd = 4,
	/**
	 * 1 means device works in calstate=3 mode.
	 * 0 means device works in calstate=0 mode.
	 */
	qcsapi_sys_status_cal_mode = 30,
	/**
	 * 1 means system boot up completely.
	 * This bit <b>DOES NOT</b> means system can work correctly.
	 * It only indicates that system gets into a stage.
	 */
	qcsapi_sys_status_completed = 31,
} qcsapi_system_status;

/**
 * Basic unsigned int definition for internal consistency.
 */
typedef uint32_t		qcsapi_unsigned_int;
/**
 * Basic unsigned 64-bit int definition for internal consistency.
 */
typedef uint64_t		qcsapi_unsigned_int64;

#define MACFILTERINGMACFMT	"%02x:%02x:%02x:%02x:%02x:%02x"
#define MAC_ADDR_SIZE		ETHER_ADDR_LEN
#define MAC_ADDR_STRING_LENGTH	18

/**
 * \brief Convenience definition to represent a 6 byte MAC address.
 *
 * Convenience definition to represent a 6 byte MAC address.
 *
 * \note This type should not be considered a string as embedded NULL bytes
 * are allowed as part of a MAC address.
 */
typedef uint8_t			qcsapi_mac_addr[ MAC_ADDR_SIZE ];

#define QCSAPI_SSID_MAXLEN	(IW_ESSID_MAX_SIZE + 1)
#define QCSAPI_SSID_MAXNUM	32
#define QCSAPI_STATUS_MAXLEN	12
#define QCSAPI_SSID_MAX_RECORDS (16)

/**
 * \brief Convenience definition to represent a 64 byte array.
 *
 * Convenience definition to represent a 64 byte array.
 *
 * \note This type should not be considered a string as embedded NULL bytes
 * are allowed as part of a 64 byte array.
 */
typedef uint8_t    u8_array_64[ 64 ];

/**
 * \anchor SSID_RULES
 * \brief Convenience definition for a string large enough for a single SSID.
 *
 * Convenience definition for a string large enough for a single SSID.
 *
 * This typedef has enough room for a single SSID plus the NULL terminating
 * character.
 *
 * The content within the SSID must be a string with between 1 and 32 characters.
 * Control characters (^C, ^M, etc.) are not permitted in API calls using this type.
 */
typedef char			qcsapi_SSID[ QCSAPI_SSID_MAXLEN ];

#define QCSAPI_MCS_RATE_MAXLEN	8


/**
 * \brief Type used to contain an MCS definition.
 *
 * QCSAPI MCS rate maximum length is distinct from MaxBitRate in TR-98.
 * TR-98 provides for 4 characters to represent the bit rate in MBPS.
 * QCSAPI MCS rate stores MCS rate specs - e.g. MCS0, MCS6, MCS76, etc.
 * Provide a bit more space for future expansion.
 * As with all QCSAPI maximum length definitions, space for the NUL ('\\0') is included.
 * So only QCSAPI_MCS_RATE_MAXLEN - 1 (7) non-NUL chars are available.
 */
typedef char	qcsapi_mcs_rate[ QCSAPI_MCS_RATE_MAXLEN ];

/*
 * Leave extra char in these string-with-maximum-length data types for NUL termination.
 * The standard suggests that a string(64) can hold upto 64 non-NUL chars
 *
 * Also, the standard includes string(63); this is represented as string_64,
 * with the corresponding QCSAPI enforcing the limit of 63 chars.
 *
 * Finally, all QCSAPIs that work with strings of defined maximum length are
 * required to enforce string length limits, and cannot rely on the special
 * string-with-maximum-length data type to enforce the corresponding limit.
 */

/**
 * \brief Convenience definition for a string of size 16.
 *
 * Convenience definition for a string of size 16.
 *
 * This type can contain a string of maximum size 16 bytes, plus the
 * NULL terminating character.
 */
typedef char	string_16[ 17 ];
/**
 * \brief Convenience definition for a string of size 32.
 *
 * Convenience definition for a string of size 32.
 *
 * This type can contain a string of maximum size 32 bytes, plus the
 * NULL terminating character.
 */
typedef char	string_32[ 33 ];
/**
 * \brief Convenience definition for a string of size 64.
 *
 * Convenience definition for a string of size 64.
 *
 * This type can contain a string of maximum size 64 bytes, plus the
 * NULL terminating character.
 */
typedef char	string_64[ 65 ];
/**
 * \brief Convenience definition for a string of size 128.
 *
 * Convenience definition for a string of size 128.
 *
 * This type can contain a string of maximum size 128 bytes, plus the
 * NULL terminating character.
 */
typedef char	string_128[ 129 ];
/**
 * \brief Convenience definition for a string of size 256.
 *
 * Convenience definition for a string of size 256.
 *
 * This type can contain a string of maximum size 256 bytes, plus the
 * NULL terminating character.
 */
typedef char	string_256[ 257 ];
/**
 * \brief Convenience definition for a string of size 1024.
 *
 * Convenience definition for a string of size 1024.
 *
 * This type can contain a string of maximum size 1024 bytes, plus the
 * NULL terminating character.
 */
typedef char	string_1024[ 1025 ];

typedef char	string_4096[ 4097 ];

#define IEEE80211_PROTO_11B	0x00000001
#define IEEE80211_PROTO_11G	0x00000002
#define IEEE80211_PROTO_11A	0x00000004
#define IEEE80211_PROTO_11N	0x00000008
#define IEEE80211_PROTO_11AC	0x00000010

#define IEEE80211_WMM_AC_BE	0	/* best effort */
#define IEEE80211_WMM_AC_BK	1	/* background */
#define IEEE80211_WMM_AC_VI	2	/* video */
#define IEEE80211_WMM_AC_VO	3	/* voice */

#define IEEE8021P_PRIORITY_ID0	0
#define IEEE8021P_PRIORITY_ID1	1
#define IEEE8021P_PRIORITY_ID2	2
#define IEEE8021P_PRIORITY_ID3	3
#define IEEE8021P_PRIORITY_ID4	4
#define IEEE8021P_PRIORITY_ID5	5
#define IEEE8021P_PRIORITY_ID6	6
#define IEEE8021P_PRIORITY_ID7	7

#define IEEE8021P_PRIORITY_NUM	8

#define QCSAPI_WIFI_AC_MAP_SIZE	(64)

#define IP_DSCP_NUM		64
/**
 * \brief This structure represents a set of properties for a single AP.
 *
 * This structure represents a set of properties for a single AP.
 *
 * The contents of this structure can be obtained using the function
 * qcsapi_wifi_get_properties_AP.
 *
 * This structure is used to return AP scan results.
 *
 * \sa qcsapi_wifi_get_properties_AP
 */
typedef struct qcsapi_ap_properties
{
	/**
	 * The SSID that this AP is using.
	 */
	qcsapi_SSID		ap_name_SSID;
	/**
	 * The MAC address of the wireless interface of the AP.
	 */
	qcsapi_mac_addr		ap_mac_addr;
	/**
	 * Flags relevant to the AP. 0 = security disabled, 1 = security enabled
	 */
	qcsapi_unsigned_int	ap_flags;
	/**
	 * The operating channel of the AP.
	 */
	int			ap_channel;
	/**
	 * The RSSI of the AP, in the range [0 - 68].
	 */
	int			ap_RSSI;
	/**
	 * The security protocol in use (none / WPA / WPA2)
	 */
	int			ap_protocol;
	/**
	 * The supported encryption modes (eg TKIP, CCMP)
	 */
	int			ap_encryption_modes;
	/**
	 * The supported authentication type(s) (eg PSK)
	 */
	int			ap_authentication_mode;
	/**
	 * The fastest data rate this AP is capable of sending
	 */
	int			ap_best_data_rate;
	/**
	 * The capability of WPS.
	 */
	int			ap_wps;
	/**
	 * The IEEE80211 protocol (e.g. a, b, g, n, ac)
	 */
	int			ap_80211_proto;
} qcsapi_ap_properties;

/**
 * \brief Structure to contain per node statistics.
 *
 * This structure is used as a return parameter in the per-node association APIs
 * associated with statistics gathering.
 *
 * \sa qcsapi_wifi_get_node_stats
 */
typedef struct qcsapi_node_stats
{
        /* TX path */
	/**
	 * The number of transmitted bytes to the node.
	 */
        uint64_t	tx_bytes;
	/**
	 * The number of transmitted packets to the node.
	 */
        uint32_t	tx_pkts;
	/**
	 * The number of transmit discards to the node.
	 */
        uint32_t	tx_discard;
	/**
	 * The number of transmit errors to the node.
	 */
        uint32_t	tx_err;
	/**
	 * The number of transmitted unicast packets to the node.
	 */
        uint32_t	tx_unicast;
	/**
	 * The number of transmitted multicast packets to the node.
	 */
	uint32_t	tx_multicast;
	/**
	 * The number of transmitted broadcast packets to the node.
	 */
        uint32_t	tx_broadcast;

        /* RX path */
	/**
	 * The number of received bytes from the node.
	 */
        uint64_t	rx_bytes;
	/**
	 * The number of received packets from the node.
	 */
        uint32_t	rx_pkts;
	/**
	 * The numbder of received packets discarded from the node.
	 */
        uint32_t	rx_discard;
	/**
	 * The number of received packets in error from the node.
	 */
        uint32_t	rx_err;
	/**
	 * The number of received unicast packets from the node.
	 */
        uint32_t	rx_unicast;
	/**
	 * The number of received multicast packets from the node.
	 */
        uint32_t	rx_multicast;
	/**
	 * The number of received broadcast packets form the node.
	 */
        uint32_t	rx_broadcast;
	/**
	 * The number of received unknown packets from the node.
	 */
        uint32_t	rx_unknown;
} qcsapi_node_stats;

/**
 * \brief Structure to contain per interface statistics.
 *
 * This structure is used as a return parameter in the per-interface APIs
 * associated with statistics gathering.
 *
 * \sa qcsapi_get_interface_stats
 */
typedef struct _qcsapi_interface_stats
{
	/* TX Path */
	/**
	 * The number of transmitted bytes on the interface.
	 */
	uint64_t tx_bytes;
	/**
	 * The number of transmitted packets on the interface.
	 */
	uint32_t tx_pkts;
	/**
	 * The number of discarded transmit packets on the interface.
	 */
	uint32_t tx_discard;
	/**
	 * The number of transmit errors on the interface.
	 */
	uint32_t tx_err;
	/**
	 * The number of transmitted unicast packets on the interface.
	 */
	uint32_t tx_unicast;
	/**
	 * The number of transmitted multicast packets on the interface.
	 */
	uint32_t tx_multicast;
	/**
	 * The number of transmitted broadcast packets on the interface.
	 */
	uint32_t tx_broadcast;

	/* RX Path */
	/**
	 * The number of received bytes on the interface.
	 */
	uint64_t rx_bytes;
	/**
	 * The number of received packets on the interface.
	 */
	uint32_t rx_pkts;
	/**
	 * The number of received packets discarded on the interface.
	 */
	uint32_t rx_discard;
	/**
	 * The number of received packets in error on the interface.
	 */
	uint32_t rx_err;
	/**
	 * The number of received unicast packets on the interface.
	 */
	uint32_t rx_unicast;
	/**
	 * The number of received multicast packets on the interface.
	 */
	uint32_t rx_multicast;
	/**
	 * The number of received broadcast packets on the interface.
	 */
	uint32_t rx_broadcast;
	/**
	 * The number of received unknown packets on the interface.
	 */
	uint32_t rx_unknown;
} qcsapi_interface_stats;


/**
 * \brief Structure containing PHY statistics.
 *
 * This structure is used as a return parameter in the per-interface APIs
 * associated with PHY statistics gathering.
 *
 * \sa qcsapi_get_phy_stats
 */
typedef struct _qcsapi_phy_stats
{
	/**
	 * The timestamp in seconds since system boot up
	 */
	uint32_t	tstamp;
	/**
	 * Associated Station count or if Station is associated
	 */
	uint32_t	assoc;
	/**
	 * Current active channel
	 */
	uint32_t	channel;
	/**
	 * Attenuation
	 */
	uint32_t	atten;
	/**
	 * Total CCA
	 */
	uint32_t	cca_total;
	/**
	 * Transmit CCA
	 */
	uint32_t	cca_tx;
	/**
	 * Receive CCA
	 */
	uint32_t	cca_rx;
	/**
	 * CCA interference
	 */
	uint32_t	cca_int;
	/**
	 * CCA Idle
	 */
	uint32_t	cca_idle;
	/**
	 * Received packets counter
	 */
	uint32_t	rx_pkts;
	/**
	 * Receive gain in dBm
	 */
	uint32_t	rx_gain;
	/**
	 * Received packet counter with frame check error
	 */
	uint32_t	rx_cnt_crc;
	/**
	 * Received noise level in dBm
	 */
	float		rx_noise;
	/**
	 * Transmitted packets counter
	 */
	uint32_t	tx_pkts;
	/**
	 * Deferred packet counter in transmission
	 */
	uint32_t	tx_defers;
	/**
	 * Time-out counter for transimitted packets
	 */
	uint32_t	tx_touts;
	/**
	 * Retried packets counter in transmission
	 */
	uint32_t	tx_retries;
	/**
	 * Counter of short preamble errors
	 */
	uint32_t	cnt_sp_fail;
	/**
	 * Counter of long preamble errors
	 */
	uint32_t	cnt_lp_fail;
	/**
	 * MCS index for last received packet
	 */
	uint32_t	last_rx_mcs;
	/**
	 * MCS index for last transimtted packet
	 */
	uint32_t	last_tx_mcs;
	/**
	 * Received signal strength indicator in dBm
	 */
	float		last_rssi;
	/**
	 * Per Chain RSSI
	 */
	float		last_rssi_array[QCSAPI_QDRV_NUM_RF_STREAMS];
	/**
	 * Received channel power level in dBm
	 */
	float		last_rcpi;
	/**
	 * Error vector magnitude measured in dBm
	 */
	float		last_evm;
	/**
	 * Per Chain EVM
	 */
	float		last_evm_array[QCSAPI_QDRV_NUM_RF_STREAMS];
} qcsapi_phy_stats;

/**
 * \brief Structure containing per client mlme statistics.
 *
 * This structure is used as a return parameter in the mlme statistics
 * request functions.
 *
 * \sa qcsapi_wifi_get_mlme_stats_per_association
 * \sa qcsapi_wifi_get_mlme_stats_per_mac
 */
typedef struct _qcsapi_mlme_stats
{
	unsigned int auth;
	unsigned int auth_fails;
	unsigned int assoc;
	unsigned int assoc_fails;
	unsigned int deauth;
	unsigned int diassoc;
} qcsapi_mlme_stats;

/**
 * \brief Structure containing the list of macs.
 *
 * This structure is used as a return parameter in
 * mlme statistics macs request function
 *
 * \sa qcsapi_wifi_get_mlme_stats_macs_list
 */
#define QCSAPI_MLME_STATS_MAX_MACS	128
typedef struct _qcsapi_mlme_stats_macs {
	/**
	 * MAC addresses existing in mlme stats
	 */
	qcsapi_mac_addr addr[QCSAPI_MLME_STATS_MAX_MACS];
} qcsapi_mlme_stats_macs;

/**
 * Used with API 'qcsapi_wifi_start_cca'
 */
struct qcsapi_cca_info
{
	/**
	 * Channel to switch to for off channel CCA measurements
	 */
	int	cca_channel;

	/**
	 * Duration to stay on the channel being measured, in milliseconds
	 */
	int	cca_duration;
};

/**
 * \brief Structure containing SCS report for current channel.
 *
 * This structure is used as a return parameter in the SCS API to return
 * report for the current channel.
 *
 * \sa qcsapi_wifi_get_scs_currchan_report
 */
typedef struct qcsapi_scs_currchan_rpt {
	/**
	 * Current channel number
	 */
	uint8_t chan;
	/**
	 * Total try count for cca sampling
	 */
	uint16_t cca_try;
	/**
	 * CCA idle count
	 */
	uint16_t cca_idle;
	/**
	 * CCA busy count
	 */
	uint16_t cca_busy;
	/**
	 * CCA interference count
	 */
	uint16_t cca_intf;
	/**
	 * CCA transmitting count
	 */
	uint16_t cca_tx;
	/**
	 * Transmiting time in ms
	 */
	uint16_t tx_ms;
	/**
	 * Receiving time in ms
	 */
	uint16_t rx_ms;
	/**
	 * Preamble error count
	 */
	uint32_t pmbl;
} qcsapi_scs_currchan_rpt;

#define QCSAPI_SCS_REPORT_CHAN_NUM    32
/**
 * \brief Structure containing SCS report for all channels.
 *
 * This structure is used as a return parameter in the SCS API to return
 * report for the all channels.
 *
 * The attributes for a certain channel use the same index into each
 * attribute array.
 *
 * \sa qcsapi_wifi_get_scs_stat_report
 */
typedef struct qcsapi_scs_ranking_rpt {
	/**
	 * Valid record number in the following attribute arrays
	 */
	uint8_t num;
	/**
	 * Channel numbers
	 */
	uint8_t chan[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Whether channel is DFS channel or not
	 */
	uint8_t dfs[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Txpower
	 */
	uint8_t txpwr[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Ranking metric
	 */
	int32_t metric[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * CCA interference
	 */
	uint16_t cca_intf[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Preamble error detected by AP
	 */
	uint32_t pmbl_ap[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Maximum preamble error detected by STAs
	 */
	uint32_t pmbl_sta[QCSAPI_SCS_REPORT_CHAN_NUM];
} qcsapi_scs_ranking_rpt;

/**
 * \brief Structure containing auto channel report for initial channel selection.
 *
 * This structure is used as a return parameter in the Auto Channel API to return
 * report for initial channel selection.
 *
 * The attributes for a certain channel use the same index into each attribute array.
 *
 * \sa qcsapi_wifi_get_autochan_report
 */
typedef struct qcsapi_autochan_rpt {
	/**
	 * Valid record number in the following attribute arrays
	 */
	uint8_t num;
	/**
	 * Channel number
	 */
	uint8_t chan[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Whether channel is DFS channel or not
	 */
	uint8_t dfs[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Txpower
	 */
	uint8_t txpwr[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Ranking metric
	 */
	int32_t metric[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Number of beacons detected
	 */
	uint32_t numbeacons[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Co-channel interference index
	 */
	uint32_t cci[QCSAPI_SCS_REPORT_CHAN_NUM];
	/**
	 * Adjacent Channel interference index
	 */
	uint32_t aci[QCSAPI_SCS_REPORT_CHAN_NUM];
} qcsapi_autochan_rpt;

/**
 * This structure is the same as 'struct ieee80211req_scs_param_rpt', but (re)defined for convenience
 */
typedef struct qcsapi_scs_param_rpt {
	uint32_t scs_cfg_param;
	uint32_t scs_signed_param_flag;
} qcsapi_scs_param_rpt;

/**
 * Used with API 'qcsapi_wifi_get_assoc_records'
 */
#define QCSAPI_ASSOC_MAX_RECORDS	32
typedef struct qcsapi_assoc_records {
	/**
	 * MAC addresses of remote nodes that have associated
	 */
	qcsapi_mac_addr addr[QCSAPI_ASSOC_MAX_RECORDS];
	/**
	 * Time stamp of the most recent association by the corresponding remote node
	 */
	uint32_t timestamp[QCSAPI_ASSOC_MAX_RECORDS];
} qcsapi_assoc_records;

/* @} */


#define TABLE_SIZE( TABLE )	(sizeof( TABLE ) / sizeof( (TABLE)[ 0 ] ))

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))
#endif

/* Channel 0 means channel auto */
#define QCSAPI_ANY_CHANNEL	0
#define QCSAPI_MIN_CHANNEL	1
#define QCSAPI_MAX_CHANNEL	(IEEE80211_CHAN_MAX)

#define RESTORE_DEFAULT_CONFIG	"/scripts/restore_default_config"

#ifndef BRIDGE_DEVICE
#define BRIDGE_DEVICE	"br0"
#endif /* BRIDGE_DEVICE */


/* QCSAPI entry points */

/* error reporting */


/* generic */
#define QCSAPI_CSW_MAX_RECORDS 32
/**
 * Channel switch history record
 */
typedef struct _qcsapi_csw_record {
	/**
	 * Records entry numbers. Max value of cnt is QCSAPI_CSW_MAX_RECORDS.
	 */
	uint32_t cnt;
	/**
	 * Indicates the latest channel change.
	 */
	int32_t index;
	/**
	 * This stores channel number Which the device switch to. If the
	 * value is 0, it means the record is invalid.
	 */
	uint32_t channel[QCSAPI_CSW_MAX_RECORDS];
	/**
	 * Records time when the channel change happens.
	 */
	uint32_t timestamp[QCSAPI_CSW_MAX_RECORDS];
} qcsapi_csw_record;

/**
 * Data should be set to the dscp to ac mapping
 */
typedef struct _qcsapi_dscp2ac_data {
	/**
	 *  dscp value to be mapped
	 */
	u8_array_64 ip_dscp_list;
	/**
	 *  Length of DSCP list
	 */
	uint8_t list_len;
	/**
	 * WME Access Class
	 */
	uint8_t ac;
} qcsapi_dscp2ac_data;


/**
 * Each channel's Radar status and detected history records
 */
typedef struct _qcsapi_radar_status {
	/**
	 *  Which channel to be queried. It must be DFS channel.
	 */
	uint32_t channel;
	/**
	 * If This API returns without error, it indicates the whether the channel is in non-occupy list currently.
	 */
	uint32_t flags;
	/**
	 * This records times radar signal is detected on this channel.
	 */
	uint32_t ic_radardetected;
}qcsapi_radar_status;

/**
 * Connection and Disconnecttion count information
 */
typedef struct _qcsapi_disconn_info {
	/**
	 * This indicates number of stations connect to this device.
	 */
	uint32_t asso_sta_count;
	/**
	 * Count of disconnect event.
	 */
	uint32_t disconn_count;
	/**
	 * Sequence to query disconnect count.
	 */
	uint32_t sequence;
	/**
	 * Time elapses since device boot up.
	 */
	uint32_t up_time;
	/**
	 * If resetflag is set to TRUE, member disconn_count and sequence will be set to 0.
	 */
	uint32_t resetflag;
}qcsapi_disconn_info;

/**
 * Retrieve values of tx_power on all antennas for calcmd
 */
typedef struct _qcsapi_calcmd_tx_power_rsp {
	uint32_t value[QCSAPI_QDRV_NUM_RF_STREAMS];
}qcsapi_calcmd_tx_power_rsp;

/**
 * Retrieve values of rssi on all antennas for calcmd
 */
typedef struct _qcsapi_calcmd_rssi_rsp{
	int32_t value[QCSAPI_QDRV_NUM_RF_STREAMS];
}qcsapi_calcmd_rssi_rsp;

/**
 * request parameter for 11h and 11k measurement
 */
typedef union _qcsapi_measure_request_param {
	/**
	 * basic measurement paramter
	 */
	struct _basic {
		/**
		 * offset to start measurement, based on microsecond
		 */
		uint16_t offset;
		/**
		 * duration to do the measurement, based on microsecond
		 */
		uint16_t duration;
		/**
		 * channel to execute the measurement, based on IEEEE channel number
		 */
		uint8_t channel;
	} basic;
	/**
	 * CCA measurement paramter
	 */
	struct _cca {
		/**
		 * offset to start measurement, based on microsecond
		 */
		uint16_t offset;
		/**
		 * duration to do the measurement, based on microsecond
		 */
		uint16_t duration;
		/**
		 * channel to execute the measurement, based on IEEEE channel number
		 */
		uint8_t channel;
	} cca;
	/**
	 * RPI measurement paramter
	 */
	struct _rpi {
		/**
		 * offset to start measurement, based on microsecond
		 */
		uint16_t offset;
		/**
		 * duration to do the measurement, based on microsecond
		 */
		uint16_t duration;
		/**
		 * channel to execute the measurement, based on IEEEE channel number
		 */
		uint8_t channel;
	} rpi;
	/**
	 * Channel Load measurement paramter
	 */
	struct _chan_load {
		/**
		 * operating class, with channel and region to decide which frequency to execute
		 */
		uint8_t op_class;
		/**
		 * IEEE channel number, with operating class and region to decide which frequency to execute
		 */
		uint8_t channel;
		/**
		 * duration to do the measurement, based on microsecond
		 */
		uint16_t duration;
	} chan_load;
	/**
	 * Noise histogram measurement paramter
	 */
	struct _noise_his {
		/**
		 * operating class, with channel and region to decide which frequency to execute
		 */
		uint8_t op_class;
		/**
		 * IEEE channel number, with operating class and region to decide which frequency to execute
		 */
		uint8_t channel;
		/**
		 * duration to do the measurement, based on microsecond
		 */
		uint16_t duration;
	} noise_his;
	/**
	 * Beacon measurement paramter
	 */
	struct _beacon {
		/**
		 * operating class, with channel and region to decide which frequency to execute
		 */
		uint8_t op_class;
		/**
		 * IEEE channel number, with operating class and region to decide which frequency to execute
		 */
		uint8_t channel;
		/**
		 * duration to do the measurement, based on microsecond
		 */
		uint16_t duration;
		/**
		 * beacon measurement mode, 0 passive, 1 active, 2 table
		 */
		uint8_t mode;
		/**
		 * specified bssid for beacon measurement
		 */
		uint8_t bssid[6];
	} beacon;
	/**
	 * Frame measurement paramter
	 */
	struct _frame {
		/**
		 * operating class, with channel and region to decide which frequency to execute
		 */
		uint8_t op_class;
		/**
		 * IEEE channel number, with operating class and region to decide which frequency to execute
		 */
		uint8_t channel;
		/**
		 * duration to do the measurement, based on microsecond
		 */
		uint16_t duration;
		/**
		 * frame type, currently only frame count report(1) is supported
		 */
		uint8_t type;
		/**
		 * specified mac_address for frame measurement
		 */
		uint8_t mac_address[6];
	} frame;
	/**
	 * transmit stream/category measurement
	 */
	struct _tran_steam_cat {
		/**
		 * duration to do the measurement, based on microsecond
		 */
		uint16_t duration;
		/**
		 * specified mac_address for measurement
		 */
		uint8_t peer_sta[6];
		/**
		 * traffic ID
		 */
		uint8_t tid;
		/**
		 * bin 0
		 */
		uint8_t bin0;
	} tran_stream_cat;
	/**
	 * multicast diagnostics report
	 */
	struct _multicast_diag {
		/**
		 * duration to do the measurement, based on microsecond
		 */
		uint16_t duration;
		/**
		 * specified group mac_address for measurement
		 */
		uint8_t group_mac[6];
	} multicast_diag;
} qcsapi_measure_request_param;


/**
* Neighbor report item
*/
struct _neighbor_item {
	uint8_t bssid[6];
	uint32_t bssid_info;
	uint8_t operating_class;
	uint8_t channel;
	uint8_t phy_type;
};

/**
 * report parameter for 11h and 11k measurement
 */
typedef union {
	/**
	 * common place to store results if no specified
	 */
	int common[16];
	/**
	 * Transmit power control report
	 */
	struct {
		int8_t link_margin;
		int8_t tx_power;
	} tpc;
	/**
	 * Basic measurement report
	 */
	uint8_t basic;
	/**
	 * CCA measurement report
	 */
	uint8_t cca;
	/**
	 * RPI measurement report
	 */
	uint8_t rpi[8];
	/**
	 * Channel Load measurement report
	 */
	uint8_t channel_load;
	/**
	 * Noise histogram measurement report
	 */
	struct {
		uint8_t antenna_id;
		uint8_t anpi;
		uint8_t ipi[11];
	} noise_histogram;
	/**
	 * Beacon measurement report
	 */
	struct {
		uint8_t rep_frame_info;
		uint8_t rcpi;
		uint8_t rsni;
		uint8_t bssid[6];
		uint8_t antenna_id;
		uint32_t parent_tsf;
	} beacon;
	/**
	 * Frame measurement report
	 */
	struct {
		uint32_t sub_ele_report;
		uint8_t ta[6];
		uint8_t bssid[6];
		uint8_t phy_type;
		uint8_t avg_rcpi;
		uint8_t last_rsni;
		uint8_t last_rcpi;
		uint8_t antenna_id;
		uint16_t frame_count;
	} frame;
	/**
	 * Transmit stream/category report
	 */
	struct {
		uint8_t reason;
		uint32_t tran_msdu_cnt;
		uint32_t msdu_discard_cnt;
		uint32_t msdu_fail_cnt;
		uint32_t msdu_mul_retry_cnt;
		uint32_t qos_lost_cnt;
		uint32_t avg_queue_delay;
		uint32_t avg_tran_delay;
		uint8_t bin0_range;
		uint32_t bins[6];
	} tran_stream_cat;
	/**
	 * Multicast diagnostics report
	 */
	struct {
		uint8_t reason;
		uint32_t mul_rec_msdu_cnt;
		uint16_t first_seq_num;
		uint16_t last_seq_num;
		uint16_t mul_rate;
	} multicast_diag;
	/**
	 * Link measurement
	 */
	struct {
		struct {
			int8_t tx_power;
			int8_t link_margin;
		} tpc_report;
		uint8_t recv_antenna_id;
		uint8_t tran_antenna_id;
		uint8_t rcpi;
		uint8_t rsni;
	} link_measure;
	/**
	 * Neighbor report
	 */
	struct {
		uint8_t item_num;
		struct _neighbor_item items[3];
	} neighbor_report;
} qcsapi_measure_report_result;

/* parameter-specific */

/**
 * @addtogroup BootConfigAPIs
 */
/*@{*/

/**
 * \brief Retrieve a parameter from bootcfg environment
 *
 * Read a u-boot environment parameter from the bootcfg driver, which manages persistent u-boot environment variables.
 *
 * \param param_name Name of parameter being requested
 * \param param_value Result storage for the value of the parameter
 * \param max_param_len size of the buffer passed in <i>param_value</i>
 *
 * \return 0 on success, -ENODATA if the parameter is not found, or other negative error codes on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_bootcfg_param \<param_name\></c>
 *
 * Output will be the value of the requested environment variable on success, or an error message on failure.
 */
extern int	qcsapi_bootcfg_get_parameter(const char *param_name,
		char *param_value,
		const size_t max_param_len);
/**
 * \brief Persist a parameter in bootcfg environment flash
 *
 * Write a u-boot environment parameter to the bootcfg driver. Bootcfg driver will handle writing the new parameter to persistent storage.
 *
 * \param param_name Name of parameter being set
 * \param param_value Value of parameter to be set
 *
 * \return 0 on success, negative error codes on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi update_bootcfg_param \<param_name\> \<param_value\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_bootcfg_update_parameter(const char *param_name,
					       const char *param_value);

/**
 * \brief Sync bootcfg updates to flash
 *
 * This function can be called after making changes to bootcfg with
 * <c>qcsapi_bootcfg_update_parameter</c>, to ensure that all pending updates
 * have been committed to flash.
 *
 * \note This call will block until the flash has been written back. Generally
 * this call will complete immediately with interactive use of call_qcsapi,
 * and is used during production for ensuring scripts complete write of the
 * bootcfg parameters prior to calling board reboot.
 *
 * \return 0 when all pending updates have been committed to flash
 * \return negative error codes on failure
 *
 * \callqcsapi
 *
 * <c>call_qcsapi commit_bootcfg</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_bootcfg_commit(void);
/*@}*/

extern int	qcsapi_telnet_enable( const qcsapi_unsigned_int onoff );

/**
 * @addtogroup SCSAPIs
 */
/*@{*/

/**
 * \brief Returns the channels during the last channel change event.
 *
 * Retrieve the previous channel and the current channel during the
 * last channel change event.
 *
 * \param ifname \wifi0
 * \param p_prev_channel the channel before the channel change.
 * \param p_cur_channel the channel after the channel change.
 *
 * \return 0 on success or -EOPNOTSUPP or other negative values on error.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_scs_cce_channels \<WiFi interface\></c>
 *
 * Unless an error occurs, the previous and current channel will be displayed.
 */
extern int	qcsapi_wifi_get_scs_cce_channels(const char *ifname,
						 qcsapi_unsigned_int *p_prev_channel,
						 qcsapi_unsigned_int *p_cur_channel);

/**
 * \brief Turn SCS feature on/off.
 *
 * Turn the SCS feature on or off.
 *
 * \param ifname \wifi0
 * \param enable_val a value turn the feature on/off
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi enable_scs \<WiFi interface\> [ 0 | 1 ]</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_scs_enable(const char *ifname, uint16_t enable_val);

/**
 * \brief Trigger SCS switch channel manually.
 *
 * Trigger SCS switch channel manually, regardless whether there is interference or not,
 * and whether the current channel is the best one or not.
 *
 * \param ifname \wifi0
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi scs_switch_chan \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_scs_switch_channel(const char *ifname);

/**
 * \internal
 * \brief Turn SCS feature's verbose information output on/off.
 *
 * Turn the SCS feature's verbose information output on or off.
 *
 * \param ifname \wifi0
 * \param enable_val a value turn the verbose information output on/off
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_scs_verbose \<WiFi interface\> [ 0 | 1 ]</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_scs_verbose(const char *ifname, uint16_t enable_val);

/**
 * \brief Get the current enabled state of SCS feature.
 *
 * Return the current enabled status of the SCS feature. It could be either
 * enabled or disabled.
 *
 * \param ifname \wifi0
 * \param p_scs_status value that contains if SCS is enabled or disabled.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_scs_status \<WiFi interface\></c>
 *
 * The output will be the word "Disabled" or "Enabled" unless an error occurs.
 */
extern int	qcsapi_wifi_get_scs_status(const char *ifname, qcsapi_unsigned_int *p_scs_status);

/**
 * \internal
 * \brief Turn SCS feature's channel sampling on/off.
 *
 * Turn the SCS feature's channel sampling on or off.
 *
 * \param ifname \wifi0
 * \param enable_val a value turn the channel sampling on/off
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_scs_smpl_enable \<WiFi interface\> [ 0 | 1 ]</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_scs_smpl_enable(const char *ifname, uint16_t enable_val);

/**
 * \internal
 * \brief Set the duration for sampling the busyness of a channel.
 *
 * API sets the dwell time for the scs feature ie. the duration in
 * which the busyness of the channel is sampled.
 * Unit is in milliseconds.
 *
 * \param ifname \wifi0
 * \param scs_sample_time Time during which busyness is sampled.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_scs_smpl_dwell_time \<WiFi interface\> &lt;duration&gt;</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_scs_smpl_dwell_time(const char *ifname, uint16_t scs_sample_time);

/**
 * \internal
 * \brief Set the interval between two samples for SCS feature.
 *
 * API sets the sample interval for the SCS feature. This duration indicates
 * the duration to wait after which the next off-channel sampling session starts.
 * Unit is in seconds.
 *
 * \param ifname \wifi0
 * \param scs_sample_intv Time from the previous sample to the next sample.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_scs_smpl_intv \<WiFi interface\> &lt;duration&gt;</c>
 *
 * <br>Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_scs_sample_intv(const char *ifname, uint16_t scs_sample_intv);

/**
 * \internal
 * \brief Set the interval between two interference detection for SCS feature.
 *
 * API sets the interference detection interval for the SCS feature. This duration indicates
 * the duration to wait after which the next interference detection session starts.
 * Unit is in seconds.
 *
 * \param ifname \wifi0
 * \param scs_intf_detect_intv Time from the previous interference detection to the next interference detection.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_scs_intf_detect_intv \<WiFi interface\> &lt;duration&gt;</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_scs_intf_detect_intv(const char *ifname, uint16_t scs_intf_detect_intv);

/**
 * \internal
 * \brief Set the threshold values for SCS feature.
 *
 * API sets the threshold for various parameters that control the
 * SCS feature. Threshold affects the sensitivity of the feature.
 *
 * \param ifname \wifi0
 * \param scs_param_name The threshold by name which is to be set
 * \param scs_threshold The value of the threshold to be set
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_scs_threshold \<WiFi interface\> &lt;threshold_name&gt; &lt;value&gt;</c>
 * threshold name is one of "smpl_pktnum", "smpl_airtime", "intf_low", "intf_high", "intf_ratio",
 * "atten_inc", "dfs_reentry", "dfs_reentry_minrate". The unit of "dfs_reentry_minrate" is 100kbps.
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */

extern int	qcsapi_wifi_set_scs_thrshld(const char *ifname,
					    const char *scs_param_name,
					    uint16_t scs_threshold);

/**
 * \internal
 * \brief Set if SCS feature should only report.
 *
 * This API controls if SCS should change the channel upon making a decison
 * or just report it.
 *
 * \param ifname \wifi0
 * \param scs_report_only value that indicates if SCS feature should act
 * on thresholds or only report.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_scs_report_only \<WiFi interface\> [ 0 | 1 ]</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_scs_report_only(const char *ifname, uint16_t scs_report_only);

/**
 * \brief Get the channel evaluation result for SCS feature.
 *
 * This API reports the evaluation result for all channels for the SCS feature.
 * Statistics like channel, channel metric are returned.
 *
 * \param ifname \wifi0
 * \param scs_rpt return the channel evaluation result.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_scs_report \<WiFi interface\> all</c>
 *
 * The output will be stats containing channel, channel metric unless an error occurs.
 */
extern int	qcsapi_wifi_get_scs_stat_report(const char *ifname, struct qcsapi_scs_ranking_rpt *scs_rpt);

/**
 * \brief Get current channel's stats for SCS feature.
 *
 * This API reports the statistics for the current channel for the SCS feature.
 * Statistics like channel, cca interference are returned.
 *
 * \param ifname \wifi0
 * \param scs_currchan_rpt return the current channel's stats.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_scs_report \<WiFi interface\> current</c>
 *
 * The output will be stats containing channel, cca interference unless an error occurs.
 */
extern int	qcsapi_wifi_get_scs_currchan_report(const char *ifname, struct qcsapi_scs_currchan_rpt *scs_currchan_rpt);

/**
 * \brief Get the initial auto channel evaluation result.
 *
 * This API reports the initial channel evalution result for Auto Channel feature.
 * Statistics like channel, channel metric are returned.
 *
 * \param ifname \wifi0
 * \param autochan_rpt the initial channel evaluation result.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_scs_report \<WiFi interface\> autochan</c>
 *
 * The output will be stats containing channel, channel metric unless an error occurs.
 */
extern int	qcsapi_wifi_get_autochan_report(const char *ifname, struct qcsapi_autochan_rpt *autochan_rpt);

/**
 * \internal
 * \brief Set smoothing factor for SCS CCA interference measurement.
 *
 * This API controls the degree SCS smoothes sequential cca interference measurement.
 *
 * \param ifname \wifi0
 * \param scs_cca_intf_smth_fctr_noxp value that indicates the smoothing factor
 * for channels once used as working channel.
 * \param scs_cca_intf_smth_fctr_xped value that indicates the smoothing factor
 * for channels never used as working channel.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_scs_cca_intf_smth_fctr \<WiFi interface\> &lt;smth_fctr_noxp&gt; &lt;smth_fctr_xped&gt;</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_scs_cca_intf_smth_fctr(const char *ifname, uint8_t smth_fctr_noxp, uint8_t smth_fctr_xped);

/**
 * \internal
 * \brief Set channel metric margin for SCS channel ranking.
 *
 * This API controls the channel metric margin SCS used for channel ranking.
 *
 * \param ifname \wifi0
 * \param chan_mtrc_mrgn value that indicates the channel metric margin.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_scs_chan_mtrc_mrgn \<WiFi interface\> &lt;chan_mtrc_mrgn&gt;</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_scs_chan_mtrc_mrgn(const char *ifname, uint8_t chan_mtrc_mrgn);

/**
 * \brief Get the specified channel's CCA interference level.
 *
 * This API call gets the CCA interference level for a particular channel.
 * The got CCA interference value should be a integer value from -1 to 1000. -1 means no
 * CCA interference data is available, and other values represent CCA interference levels.
 *
 * \param ifname \wifi0
 * \param the_channel the channel for which the CCA interference is returned.
 * \param p_cca_intf return parameter to contains the CCA interference.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \return -EINVAL or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_scs_cca_intf \<WiFi interface\> &lt;channel&gt; </c>
 *
 * Unless an error occurs, the output will be the CCA interference status.
 */
extern int	qcsapi_wifi_get_scs_cca_intf(const char *ifname,
					 const qcsapi_unsigned_int the_channel,
					 int *p_cca_intf);

/**
 * \brief Get the configured SCS parameters.
 *
 * This API call gets the configured SCS parameters.
 *
 * \param ifname \wifi0
 * \param p_scs_param_rpt return parameter to contain the SCS parameters.
 * \param param_num value that indicates parameter numbers needed to be returned
 *
 * \return -EINVAL or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_scs_param \<WiFi interface\>  </c>
 *
 * Unless an error occurs, the output will include current SCS parameters.
 */
extern int	qcsapi_wifi_get_scs_param_report(const char *ifname, struct qcsapi_scs_param_rpt *p_scs_param_rpt, uint32_t param_num);

/**
 * \internal
 * \brief Get the current state of SCS DFS Re-entry request.
 *
 * Return the current status of the SCS DFS Re-entry request. It could be either
 * 0(not requested) or 1(requested).
 *
 * \param ifname \wifi0
 * \param p_scs_dfs_reentry_request value that contains the request level.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_scs_dfs_reentry_request \<WiFi interface\></c>
 *
 * The output will be an integer representing the request level unless an error occurs.
 */
extern int	qcsapi_wifi_get_scs_dfs_reentry_request(const char *ifname, qcsapi_unsigned_int *p_scs_dfs_reentry_request);
/*@}*/

/**@addtogroup ParameterOCACAPIs
 *@{*/

/**
 * \brief Start off-channel CAC.
 *
 * This API is used to start off-channel CAC on a DFS channel.<br>
 *
 * \param ifname \wifi0
 * \param channel specifies the DFS channel for CAC. 0 is to select DFS channel automatically.
 *
 * \return 0 on success or negative values on error.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi start_ocac wifi0 \<DFS_channel\> </c><br>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int qcsapi_wifi_start_ocac(const char *ifname, uint16_t channel);

/**
 * \brief Stop off-channel CAC.
 *
 * This API is used to stop off-channel CAC.<br>
 *
 * \param ifname \wifi0
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi stop_ocac wifi0</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int qcsapi_wifi_stop_ocac(const char *ifname);

/**
 * \brief Get the current state of off-channel CAC.
 *
 * This API return the current state of off-channel CAC.
 *
 * \param ifname \wifi0
 * \param status value that contains if OCAC is enabled or disabled.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_ocac_status \<WiFi interface\></c>
 *
 * The output will be the word "Disabled" or "Enabled" unless an error occurs.
 */
extern int	qcsapi_wifi_get_ocac_status(const char *ifname, qcsapi_unsigned_int *status);

/**
 * \internal
 * \brief Set the dwell time on off-channel for off-channel CAC.
 *
 * API sets the dwell time for the off-channel CAC feature, ie. the duration on
 * off channel within a beacon interval.
 * Unit is in milliseconds.
 *
 * \param ifname \wifi0
 * \param dwell_time Dwell time on off-channel in a beacon interval.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_ocac_dwell_time \<WiFi interface\> &lt;dwelltime&gt;</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_ocac_dwell_time(const char *ifname, uint16_t dwell_time);

/**
 * \internal
 * \brief Set the duration during which off-channel CAC is running for a DFS channel.
 *
 * API sets the duration during which the off-channel CAC is running for a specified
 * DFS channel
 * Unit is in seconds.
 *
 * \param ifname \wifi0
 * \param duration Duration for a specified DFS channel to run off-channel CAC.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_ocac_duration \<WiFi interface\> &lt;duration&gt;</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_ocac_duration(const char *ifname, uint16_t duration);

/**
 * \internal
 * \brief Set the total time on off channel for a DFS channel.
 *
 * API sets the total time on off channel for a specified DFS channel
 * Unit is in seconds.
 *
 * \param ifname \wifi0
 * \param cac_time total time on the specified DFS channel.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_ocac_cac_time \<WiFi interface\> &lt;cac_time&gt;</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_ocac_cac_time(const char *ifname, uint16_t cac_time);

/**
 * \internal
 * \brief Set the off-channel CAC report only mode.
 *
 * API sets the off-channel CAC as report only mode, that means, don't switch channel
 * after off-channel CAC is completed if report only mode is set.
 *
 * \param ifname \wifi0
 * \param enable 0 - disable report only mode, otherwise enable it.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_ocac_report_only \<WiFi interface\> &lt;1 or 0&gt;</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_ocac_report_only(const char *ifname, uint16_t enable);

/**
 * \internal
 * \brief Set the threshold values for OCAC feature.
 *
 * API sets the threshold for various parameters that control the off-channel CAC
 * feature. Threshold affects the sensitivity of the feature.
 *
 * \param ifname \wifi0
 * \param param_name The threshold by name which is to be set
 * \param threshold The value of the threshold to be set
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_ocac_thrshld \<WiFi interface\> &lt;threshold_name&gt; &lt;value&gt;</c>
 * threshold name is one of "fat", "traffic" and "cca_intf".
 * "fat" means the free air time, and the threshold value is the percentage for the free air time.
 * off-channel CAC can run when the current FAT is larger than this threshold.
 * "traffic" is the traffic of local BSS, and the threshold value is the percentage for the local
 * traffic time against the measurement time. off-channel CAC can run when the local traffic is
 * less than the threshold value.
 * "cca_intf" means the cca interference on off channel. AP can switch to the DFS channel after off
 * channel CAC only when no radar is detected on this DFS channel and the cca interference on DFS
 * channel is less than the threshold, which is the percentage for the interference traffic time
 * against the measurement time.
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_ocac_thrshld(const char *ifname,
					    const char *param_name,
					    uint16_t threshold);

/**@}*/

/**@addtogroup APIInitializationAPIs
 *@{*/

/**
 * \brief Call to initialise the runtime for QCSAPI usage.
 *
 * This function is required to be called prior to any other QCSAPI function.
 *
 * To prevent concurrency issues, a multi-threaded application should call this function
 * prior to creating additional threads.
 *
 * \return 0 if the configuration file path was updated successfully.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note This function does not have a <c>call_qcsapi</c> equivalent call due to its nature.
 */
extern int	qcsapi_init( void );

/**
 * \brief Disconnect the program from the calling terminal.
 *
 * Often a process needs to run in background.  Such a process is described as a daemon process.
 * This API will force the process into background mode and disconnect from the controlling terminal or console.
 * When such a process is run from the command line the effect of calling this API is immediately apparent,
 * as the command line prompt will appear and another command can then be entered.
 *
 * Use this API for any process that starts as the WiFi device boots, and is expected to remain active until
 * the device is halted or rebooted (eg, a long-running daemon process).
 *
 * \return 0 if the configuration file path was updated successfully.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note This function does not have a <c>call_qcsapi</c> equivalent call due to its nature.
 */
extern int	qcsapi_console_disconnect( void );

/**
 * \brief Get the time since the system started up.
 *
 * This function is used to determine system uptime.
 *
 * \param p_elapsed_time return parameter to store the system uptime (number of seconds since boot).
 *
 * \return 0 if the configuration file path was updated successfully.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_time_since_start</c>
 *
 * The output will be the time in seconds since the system started up, or an error string.
 */
extern int	qcsapi_system_get_time_since_start(qcsapi_unsigned_int *p_elapsed_time);


/**
 * \brief Get system status.
 *
 * This function is used to get system status.
 *
 * \param p_status return parameter to store the system status.
 * It is in bit-mask format, each bit represents different status.
 * Possiable values are defined here @ref QCSAPI_GET_SYSTEM_STATUS
 *
 * \return 0 if get status successfully.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_system_status</c>
 */
extern int	qcsapi_get_system_status(qcsapi_unsigned_int *p_status);

/**@}*/

/**@addtogroup ParameterConfAPIs
 *@{*/

/**
 * \brief Get a persistent configuration parameter
 *
 * Get a persistent configuration parameter.
 *
 * \param ifname \wifi0
 * \param param_name the parameter to be retrieved
 * \param param_value a pointer to the buffer for storing the returned value
 * \param max_param_len the size of the buffer
 *
 * \return 0 if the parameter was returned.
 * \return <c>-qcsapi_parameter_not_found</c> if the parameter was not found.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_config_param \<WiFi interface\> \<param_name\></c>
 *
 * or
 *
 * <c>call_qcsapi get_persistent_param \<WiFi interface\> \<parameter name\></c>
 *
 * The output will be the parameter value unless an error occurs or the parameter is not found.
 */
extern int	qcsapi_config_get_parameter(const char *ifname,
					    const char *param_name,
					    char *param_value,
					    const size_t max_param_len);

/**
 * \brief Update a persistent config parameter
 *
 * Set a persistent configuration parameter.  The parameter is added if it does not already exist.
 *
 * All real work for this API is done in the update_wifi_config script, as explained above.
 *
 * Unlike most APIs, this one will spawn a subprocess.  If for any reason the process
 * table is full, this API will fail with unpredictable results.
 *
 * \param ifname \wifi0
 * \param param_name the parameter to be created or updated
 * \param param_value a pointer to a buffer containing the null-terminated parameter value
 * string
 *
 * \return 0 if the parameter was set.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi update_config_param \<WiFi interface\> \<param_name\> \<value\></c>
 *
 * or
 *
 * <c>call_qcsapi update_persistent_param \<WiFi interface\> \<param_name\> \<value\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * <b>Examples</b>
 *
 * To set the WiFi mode to AP, enter:
 *
 * <c>call_qcsapi update_persistent_param wifi0 mode ap</c>
 *
 * To set the WiFi channel to 36 (only effective on an AP), enter:
 *
 * <c>call_qcsapi update_persistent_param wifi0 channel 36</c>
 *
 * In each case the device will need to be rebooted for the change to take effect.
 *
 */
extern int	qcsapi_config_update_parameter(const char *ifname,
					       const char *param_name,
					       const char *param_value);
/**@}*/


/**@addtogroup FilePathAPIs
 *@{*/

/**
 * \brief Get the configuration file path.
 *
 * Reports the location associated with the configuration file path for the security files.
 *
 * \param e_file_path should be the symbolic value <c>qcsapi_security_configuration_path</c>
 * \param file_path return parameter to contain the configuration file path to the security files.
 * \param path_size the size of the file_path parameter above.
 *
 * \return 0 if the configuration file path was set in the file_path parameter.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_file_path security</c>
 *
 * The command should be entered exactly as shown above. The output is the current configured path to the security files.
 */
extern int	qcsapi_file_path_get_config(const qcsapi_file_path_config e_file_path,
					    char *file_path,
					    qcsapi_unsigned_int path_size);

/**
 * @brief Update the location associated with the configuration file path.
 *
 * Updates the location associated with the file path configuration.
 *
 * \param e_file_path Use the symbolic value <c>qcsapi_security_configuration_path</c>.
 * \param new_path A NULL terminated string for the new path to set.
 *
 * \return 0 if the configuration file path was updated successfully.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note The presence or validity of the file path is NOT checked.
 *
 * \note This API is only available in calibration mode (see @ref mysection4_1_5 "Production mode vs calibration mode").
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_file_path security \<new location\> </c>
 *
 * As this is a set API, the output from call_qcsapi is complete, unless an error occurs.
 *
 * \warning <b>Power should not be turned off to the WiFi device when calling the set file path config API or immediately afterwards.
 * Failure to follow this restriction can cause the flash memory on the board to get corrupted.
 * If power needs to be turned off to the WiFi device when working with this API, enter the "halt" command first and wait for the device to shut down.
 * This API should only be called when initially configuring the board.</b>
 */
extern int	qcsapi_file_path_set_config( const qcsapi_file_path_config e_file_path, const char *new_path );

/**
 * \brief Restore the default configuration files.
 *
 * This API call restores the board to its default (factory) configuration.
 *
 * After this call, the current configurations on the board will be replaced with the default
 * values as in the flash image.
 *
 * \param flag if 1 to reset IP address, otherwise keep IP setting
 *
 * \return 0 this call always succeeds.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi restore_default_config [0|1]</c>
 *
 * \warning <b>This call will wipe out any configured parameters and replace them with the default
 * values as per a factory configured board.</b>
 *
 * \note This API requires the script <c>/scripts/restore_default_config</c> to be present on the filesystem.
 */
extern int	qcsapi_restore_default_config( int flag );

/**@}*/



/**@addtogroup NetInterfaceAPIs
 *@{*/
/*following functions in mygroup4: Network Interface APIs*/

/**
 * @brief Enable or disable an interface.
 *
 * Enable (or disable) an interface. Use <c>qcsapi_interface_get_status</c> to establish
 * whether an interface is enabled or disabled.<br>
 *
 * \param ifname \wifi0
 * \param enable_flag if 0, disable the interface, else enable the interface.
 *
 * \return 0 if the interface was successfully enabled or disabled.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi enable_interface \<network interface\> \<0 | 1\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "QCSAPI Return Values" for error codes and messages.
 *
 * Examples:
 *
 * To enable the ethernet interface eth1_0:
 *
 * <c>call_qcsapi enable_interface eth1_0 1</c>
 *
 * To disable the WiFi interface wifi0:
 *
 * <c>call_qcsapi enable_interface wifi0 0</c>
 *
 * \sa qcsapi_interface_get_status
 */
extern int	qcsapi_interface_enable( const char *ifname, const int enable_flag );

/**
 * @brief Get an interface status.
 *
 * Determine whether an interface is enabled (up) or disabled (down).
 *
 * \param ifname \wifi0
 * \param interface_status return parameter to indicate the interface status.
 *
 * \return 0 if the interface was successfully enabled or disabled.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_status \<network interface\></c>
 *
 * Output is one of the words <c>up</c>, <c>disabled</c> or <c>error</c>; or an error message.
 *
 * Examples:
 *
 * To report the ethernet interface eth1_0, enter:
 *
 * <c>call_qcsapi get_status eth1_0</c>
 *
 * To report the WiFi interface status of wifi0, enter:
 *
 * <c>call_qcsapi get_status wifi0</c>
 */
extern int	qcsapi_interface_get_status( const char *ifname, char *interface_status );

/**
 * @brief Get statistics from an interface.
 *
 * This API call returns statistics for a given interface, and given counter.
 *
 * Per the TR-098 standard, all counters are represented as 32-bit unsigned integers.
 *
 * \note Be aware that rollover is quite possible, especially with counters reporting the number of bytes transferred.
 *
 * \param ifname \wifi0
 * \param qcsapi_counter one of the enumerations from the typedef struct qcsapi_counter_type (see the following table).
 * \param p_counter_value return parameter to contain the counter value.
 *
 * \return 0 if the value in p_counter_value is successfully filled in with the correct counter.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_counter \<network device\> \<counter name\></c>
 *
 * Valid counter names are listed in the following table:
 *
 * <TABLE>
 * <TR> <TD>Scripting name\n(call_qcsapi)</TD>  <TD>C-language enum</TD>        <TD>Description</TD></TR>
 * <TR> <TD>tx_bytes</TD>       <TD>qcsapi_total_bytes_sent    </TD>            <TD>The number of bytes transmitted</TD></TR>
 * <TR> <TD>rx_bytes</TD>       <TD>qcsapi_total_bytes_received</TD>            <TD>The number of bytes received</TD></TR>
 * <TR> <TD>tx_packets</TD>     <TD>qcsapi_total_packets_sent  </TD>            <TD>The number of packets transmitted</TD></TR>
 * <TR> <TD>rx_packets</TD>     <TD>qcsapi_total_packets_received</TD>          <TD>The number of packets received</TD></TR>
 * <TR> <TD>tx_discard</TD>     <TD>qcsapi_discard_packets_sent</TD>            <TD>The number of packets discarded on transmit</TD></TR>
 * <TR> <TD>rx_discard</TD>     <TD>qcsapi_discard_packets_received</TD>        <TD>The number of packets discarded on receive</TD></TR>
 * <TR> <TD>tx_errors</TD>      <TD>qcsapi_error_packets_sent</TD>              <TD>The number of packets in error on transmit</TD></TR>
 * <TR> <TD>rx_errors</TD>      <TD>qcsapi_error_packets_received</TD>          <TD>The number of packets in error on receive</TD></TR>
 * </TABLE>
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages
 *
 * \sa typedef enum qcsapi_counter_type
 */
extern int	qcsapi_interface_get_counter(const char *ifname,
					     qcsapi_counter_type qcsapi_counter,
					     qcsapi_unsigned_int *p_counter_value);

/**
 * @brief Get the MAC address of an interface.
 *
 * Returns the MAC address of the interface. For a WiFi device operating in STA mode, this will be different from the BSSID.
 *
 * \param ifname \wifi0
 * \param current_mac_addr return parameter to contain the MAC address.
 *
 * \return 0 if the value in current_mac_addr is successfully filled in with the correct value.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_mac_addr \<network device\></c>
 *
 * Output is the MAC address for the interface, displayed in standard format, i.e. with each byte shown as a 2 digit hexadecimal value,
 * separated by colons, OR an error message.
 *
 * Example MAC address: <c>02:51:55:41:00:4C</c>. See @ref mysection5_1_1 "Format for a MAC address" for details of formatting MAC
 * addresses.
 */
extern int	qcsapi_interface_get_mac_addr( const char *ifname, qcsapi_mac_addr current_mac_addr );

/**
 * @brief Set the MAC address of an interface.
 *
 * Set the MAC address of the interface.
 *
 * \param ifname \wifi0
 * \param interface_mac_addr parameter to contain the desired MAC address.
 *
 * \return 0 if the value in interface_mac_addr is successfully set with the correct value.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_mac_addr \<network device\> <mac address></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * Example MAC address: <c>02:51:55:41:00:4C</c>. See @ref mysection5_1_1 "Format for a MAC address" for details of formatting MAC
 * addresses.
 *
 *\note This API needs a system reboot for the MAC address to take effect.
 */
extern int	qcsapi_interface_set_mac_addr( const char *ifname, const qcsapi_mac_addr interface_mac_addr );

/**
 * \brief Get the Value of a Performance Monitoring Counter.
 *
 * Selected counters are available as Performance Monitor (PM) counters. A PM counter is tied to a PM interval, 15 minutes
 * or 24 hours. The PM counter records the change in the counter since the start of the current
 * PM interval. (The Get PM Interval Elapsed Time API reports how much time has elapsed in the
 * current PM interval.)
 *
 * \param ifname \wifi0
 * \param qcsapi_counter one of the enumerations from the typedef struct qcsapi_counter_type
 * \param pm_interval the PM interval, either "15_min" or "24_hr"
 * \param p_counter_value return parameter to contain the counter value.
 *
 * \return 0 if the value in p_counter_value is successfully filled in with the correct counter.
 * \return A negative value if an error occurred.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_pm_counter \<network device\> \<counter name\> \<PM interval\></c>
 *
 * See @ref mysection4_1_4 "QCSAPI Return Values" for error codes and messages.
 */

extern int	qcsapi_pm_get_counter(const char *ifname,
				      qcsapi_counter_type qcsapi_counter,
				      const char *pm_interval,
				      qcsapi_unsigned_int *p_counter_value);

/**
 * \brief Get the Elapsed Time in the current PM Interval
 *
 * Returns the amount of time in seconds that has elapsed since the start of the referenced
 * PM interval.  PM Intervals last either 15 minutes (900 seconds) or 24 hours (86400 seconds).
 *
 * \param pm_interval the PM interval, either "15_min" or "24_hr"
 * \param p_elapsed_time return parameter to contain the elapsed time in seconds.
 *
 * \return 0 if the value in p_elapsed_time is successfully filled in with the elapsed time.
 * \return A negative value if an error occurred.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_pm_elapsed_time \<PM interval\></c>
 *
 * See @ref mysection4_1_4 "QCSAPI Return Values" for error codes and messages.
 */

extern int	qcsapi_pm_get_elapsed_time(const char *pm_interval,
					   qcsapi_unsigned_int *p_elapsed_time);

/**
 * @brief power on or power off the ethernet PHY.
 *
 * Power off / on eth PHY. Use <c>qcsapi_eth_phy_power_control</c> to establish
 * power on or off the eth PHY.<br>
 *
 * \param on_off if 1, power off the PHY, else power on the PHY.
 * \param interface the interface name of the eth device
 *
 * \return 0 if the eth PHY was successfully power off or power on.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi eth_phy_power_off \<network interface\> \<0 | 1\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "QCSAPI Return Values" for error codes and messages.
 *
 * Examples:
 *
 * To power off the PHY of interface eth1_0:
 *
 * <c>call_qcsapi eth_phy_power_off eth1_0 1</c>
 */
extern int	qcsapi_eth_phy_power_control(int on_off, const char *interface);

/**@}*/



/**\addtogroup WiFiAPIs
 *@{*/
/*following functions in mygroup5: WiFi API*/

/**
 * @brief Get the WiFi mode of the interface.
 *
 * Determine what mode the WiFi interface is operating in, access point or station.
 *
 * \param ifname \wifi0
 * \param p_wifi_mode return parameter to contain the operational mode of the interface.
 *
 * \return 0 if the value in p_wifi_mode is successfully filled in with the correct value.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_mode \<WiFi interface\></c>
 *
 * Output is either <c>Access Point</c> or <c>Station</c>, unless an error occurs.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_mode( const char *ifname, qcsapi_wifi_mode *p_wifi_mode );

/**
 * @brief Set the WiFi mode of the interface.
 *
 * Sets the mode for the WiFi interface.
 *
 * \note As a side effect of this API call, a new network interface may be created.
 *
 * The API will fail if the referenced interface already exists.
 *
 * \param ifname \wifi0
 * \param new_wifi_mode the wifi mode to set the interface to.
 *
 * \return 0 if the WiFi interface mode is set successfully.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_mode \<WiFi interface\> \<ap | sta\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_set_mode( const char *ifname, const qcsapi_wifi_mode new_wifi_mode );

/**
 * @brief Reload the interface to change its mode (AP->STA or STA->AP).
 *
 * This function will delete the interface and other WDS vaps that may exist, then recreate the interface in the requested mode,
 * and perform all necessary initialization.
 *
 * This API is used for switching between AP and STA modes without rebooting. The API will fail if the requested interface doesn't exist,
 * or if the requested interface is not the primary interface.
 *
 * \param ifname \wifi0
 * \param new_wifi_mode the new wifi mode to set the interface to.
 *
 * \return 0 if the WiFi interface mode is changed successfully.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi reload_in_mode \<WiFi interface\> \<ap | sta\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_reload_in_mode( const char *ifname, const qcsapi_wifi_mode new_wifi_mode );

/**
 * \brief Enable or disable the RF on the given interface.
 *
 * This API call enables or disables the passed in interface. Disabling the
 * interface also includes killing off any daemon such as <c>wpa_supplicant</c>
 * or <c>hostapd</c>, in addition to bringing the interface down or up.
 *
 * \param ifname \wifi0
 * \param onoff if zero, turn the RF on the interface off, else turn the RF
 * on.
 *
 * \return 0 on success.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \warning This API relies on the script '/scripts/rfenable' being present on the board to work.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi rfenable \<WiFi interface\> <0 | 1></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_rfenable( const char *ifname, const qcsapi_unsigned_int onoff );

/**
 * \brief Get the current radio status.
 *
 * This API call returns the current status of the device radio.
 *
 * \param ifname \wifi0
 * \param onoff a pointer to the buffer for storing the returned value
 *
 * \return 0 on success.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \warning This API relies on the script '/scripts/rfstatus' being present on the board to work.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi rfstatus \<WiFi interface\> </c>
 *
 * Unless an error occurs, the output will be the current status of radio.
 */
extern int	qcsapi_wifi_rfstatus( const char *ifname, qcsapi_unsigned_int *rfstatus );

/**
 * @brief Get the WiFi interface bandwidth (20MHz or 40MHz).
 *
 * Return the configured bandwidth, as specified in the 802.11n standard, either 20 MHz or 40 MHz.
 *
 * Returned value is in MHz, either 20 40, or 80.  This API is only available on the primary WiFi interface.
 *
 * \param ifname \wifi0
 * \param p_bw return parameter to contain the bandwidth the interface is working in (20, 40 or 80)
 *
 * \return 0 on success.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_bw \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the current bandwidth configuration, either 20, 40 or 80.
 *
 * \sa qcsapi_wifi_set_bw
 * \sa qcsapi_wifi_set_vht
 */
extern int	qcsapi_wifi_get_bw( const char *ifname, qcsapi_unsigned_int *p_bw );

/**
 * @brief Set the WiFi interface bandwidth.
 *
 * Use this API to set the bandwidth during system startup, before calling the Enable Interface API for the WiFi device.
 *
 * Bandwidth can be either 40MHz or 20MHz. This API is only available on the primary WiFi interface.
 *
 * If the bandwidth is set to 20MHz, any associations will have a bandwidth limited to 20 MHz.
 * If the bandwidth is set to 40MHz, an association will default to a bandwidth of 40 MHz (if the peer supports this).
 * If the bandwidth is set to 80MHz, an association will default to a bandwidth of 80 MHz (if the peer supports this).
 *
 * \param ifname \wifi0
 * \param bw the bandwith to set the device to.
 *
 * \note 80MHz bandwidth is only supported in 802.11ac mode. 802.11ac mode is set using qcsapi_wifi_set_vht
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_bw \<WiFi interface\> \<80 | 40 | 20\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_wifi_set_vht
 */
extern int	qcsapi_wifi_set_bw( const char *ifname, const qcsapi_unsigned_int bw );

/**
 * \brief Get the current channel.
 *
 * Get the current channel number.
 *
 * \param ifname \wifi0
 * \param p_current_channel a pointer to the buffer for storing the returned value
 *
 * \return 0 if the channel number was returned.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.  If the channel has not been set properly, this API can
 * return -ERANGE, numeric value out of range.
 *
 * This API is only available on the primary WiFi interface.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_channel \<WiFi interface\></c>
 *
 * The output will be the channel number unless an error occurs.
 */
extern int	qcsapi_wifi_get_channel( const char *ifname, qcsapi_unsigned_int *p_current_channel );

/**
 * \brief Set the current channel.
 *
 * Set the current channel.
 *
 * \param ifname \wifi0
 * \param new_channel the new channel to be used
 *
 * \return 0 if the channel number was returned.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.  If the channel has not been set properly, this API can
 * return -ERANGE, numeric value out of range.
 *
 * This API is only available on the primary WiFi interface.
 *
 * The new channel must be between 1 and 255, and is further restricted by the 802.11
 * standard.
 *
 * This is an engineering API, since it does not account for regulatory requirements.  Use
 * of this API can cause the system to violate regulatory requirements.  Use of the Set
 * Regulatory Channel API is recommended.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_channel \<WiFi interface\> \<new_channel\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_channel( const char *ifname, const qcsapi_unsigned_int new_channel );

/**
 * \brief Set the channel inactive flag of primary channel.
 *
 * Specify whether the channel can be used as primary channel or not.
 *
 * \param ifname \wifi0
 * \param channel the channel to change the inactive flag
 * \param inactive the flag whether it can be used as primary channel or not
 *
 * \return 0 if the channel number was returned.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * This API is only available on the primary WiFi interface.
 *
 * The channel must be between 1 and 255, and is further restricted by the 802.11
 * standard.
 *
 * The inactive flag must be either 0 or 1.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_chan_pri_inactive \<WiFi interface\> \<channel\> \<inactive\></c>
 *
 * If inactive flag is not specified, default is 1.
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_chan_pri_inactive( const char *ifname, const qcsapi_unsigned_int channel, const qcsapi_unsigned_int inactive);

/**
 * \brief Get the beacon interval
 *
 * Get the beacon interval in milliseconds.
 *
 * \param ifname \wifi0
 * \param p_current_intval a pointer to the buffer for storing the returned value
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_beacon_interval \<WiFi interface\></c>
 *
 * The output will be the beacon interval in milliseconds unless an error occurs.
 */
extern int	qcsapi_wifi_get_beacon_interval( const char *ifname, qcsapi_unsigned_int *p_current_intval );

/**
 * \brief Set the beacon interval
 *
 * Set the beacon interval in milliseconds.
 *
 * \param ifname \wifi0
 * \param new_intval a pointer to the buffer for storing the returned value
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_beacon_interval \<WiFi interface\> \<value\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_beacon_interval( const char *ifname, const qcsapi_unsigned_int new_intval );

/**
 * \brief Get the DTIM interval
 *
 * Get the frequency (in number of beacons) at which the DTIM (Delivery Traffic
 * Information Message) Information Element is added to beacons.
 *
 * \param ifname \wifi0
 * \param p_dtim a pointer to the buffer for storing the returned value
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_dtim \<WiFi interface\></c>
 *
 * The output will be the DTIM interval in milliseconds unless an error occurs.
 */
extern int	qcsapi_wifi_get_dtim( const char *ifname, qcsapi_unsigned_int *p_dtim );

/**
 * \brief Set the DTIM interval
 *
 * Set the frequency (in number of beacons) at which the DTIM (Delivery Traffic
 * Information Message) Information Element is added to beacons.
 *
 * \param ifname \wifi0
 * \param new_dtim the new DTIM value
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_dtim \<WiFi interface\> \<DTIM interval\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_dtim( const char *ifname, const qcsapi_unsigned_int new_dtim );

/**
 * \brief Get association limit
 *
 * Available on APs only. This API retrives the current association limit for the primary interface. The association limit is the number of stations that may be simultaneously associated to this AP.
 * It will fail if the interface doesn't exist or not the primary interface.
 *
 * \param ifname \wifi0
 * \param p_assoc_limit Address of variable for result retrieval
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_assoc_limit \<WiFi interface\></c>
 *
 * call_qcsapi will print the association limit of the requested interface to stdout, or print an error message to stdout on failure
 */
extern int	qcsapi_wifi_get_assoc_limit( const char *ifname, qcsapi_unsigned_int *p_assoc_limit );

/**
 * \brief Set association limit
 *
 * Available on APs only. This API sets the current association limit for the primary interface.
 * It will fail if the interface doesn't exist or not the primary interface.
 *
 * This affects only new devices trying to associate to this AP; if the new association limit is smaller than the current number of associated devices, devices are not disassociated.
 *
 * \param ifname \wifi0
 * \param new_assoc_limit New association limit
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_assoc_limit \<WiFi interface\> \<limit\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_assoc_limit( const char *ifname, const qcsapi_unsigned_int new_assoc_limit );

/**
 * \brief Get current BSSID
 *
 * This API retrieves the current BSSID (basic service set identification)
 *
 * \param ifname \wifi0
 * \param current_BSSID memory in which to store the current BSSID. On an unassociated station, or if the interface is disabled, this field will be zeroed.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_BSSID <i>interface</i></c>
 *
 * The output will be a printout of the BSSID MAC address on success, or print an error message on failure.
 */
extern int	qcsapi_wifi_get_BSSID( const char *ifname, qcsapi_mac_addr current_BSSID );

/**
 * @brief Get the WiFi interface SSID.
 *
 * Get the current SSID of the interface.
 *
 * \param ifname \wifi0
 * \param SSID_str return parameter to contain the SSID.
 *
 * \return 0 if the command succeeded and SSID_str contains the SSID.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note On a STA with security enabled and is not in an association, this API will return the 0-length string in the SSID_str parameter.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_SSID \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the current SSID.
 * On a STA, if security is enabled and is not in association, the output will be a blank line.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_SSID( const char *ifname, qcsapi_SSID SSID_str );

/**
 * @brief Set the WiFi interface SSID.
 *
 * Set the current SSID for AP operation on the given interface.
 *
 * \note This API only works on an AP.
 *
 * \warning Any preexisting associations will be dropped, and those stations will be required to reassociate, using the new SSID.
 *
 * Use the WiFi Associate API (qcsapi_wifi_associate) on a STA to set the SSID.
 *
 * The SSID must be a string with between 1 and 32 characters. Control characters (^C, ^M, etc.) are not permitted.
 *
 * \param ifname \wifi0
 * \param SSID_str the new SSID to set on the interface.
 *
 * \return 0 if the command succeeded and the SSID is updated.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_SSID \<WiFi interface\> \<SSID name\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * <b>Examples</b>
 *
 * To set SSID to Quantenna, enter:
 *
 * <c>call_qcsapi set_ssid wifi0 "Quantenna"</c>
 *
 * To set SSID to 'Quantenna', enter:
 *
 * <c>call_qcsapi set_ssid wifi0 "'Quantenna'"</c>
 *
 * To set SSID to "Quantenna", enter:
 *
 * <c>call_qcsapi set_ssid wifi0 "\"Quantenna\""</c>
 *
 * \sa qcsapi_wifi_associate
 */
extern int	qcsapi_wifi_set_SSID( const char *ifname, const qcsapi_SSID SSID_str );

/**
 * @brief Get the IEEE 802.11 PHY mode being used on the interface.
 *
 * Get the current IEEE 802.11 standard(s) that the WiFi device supports. Expected return values (all are character strings) follow:
 *
 * <TABLE>
 * <TR> <TD>Value  </TD>        <TD>Interpretation</TD> </TR>
 * <TR> <TD>a-only </TD>        <TD>Only 802.11a support present (5 GHz with up to 54 Mbps throughput)</TD>     </TR>
 * <TR> <TD>b-only </TD>        <TD>Only 802.11b support present (2.4 GHz with up to 11 Mbps throughput)</TD>   </TR>
 * <TR> <TD>g-only </TD>        <TD>Only 802.11g support present (2.4GHz with up to 54 Mbps throughput)</TD>    </TR>
 * <TR> <TD>n-only </TD>        <TD>Stations / Access Points are required to support 802.11n</TD>       </TR>
 * <TR> <TD>a|n </TD>   <TD>802.11n with 802.11a available for backwards compatibility</TD>     </TR>
 * <TR> <TD>g|n </TD>   <TD>802.11n with 802.11g available for backwards compatibility</TD>     </TR>
 * </TABLE>
 *
 * Currently "n-only" and "a|n" are the only expected return values.
 *
 * \param ifname \wifi0
 * \param IEEE_802_11_standard return parameter to contain the string with the PHY mode.
 *
 * \return 0 if the command succeeded and the IEEE_802_11_standard string is filled in successfully.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note The passed in string MUST be at least 7 bytes to contain the maximum length string per the preceding table.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_standard \<WiFi interface\></c>
 *
 * <c>call_qcsapi get_802.11 \<WiFi interface\></c>
 */
extern int	qcsapi_wifi_get_IEEE_802_11_standard( const char *ifname, char *IEEE_802_11_standard );

/**
 * @brief Get the list of available channels for an interface.
 *
 * Get the list of available channels with each value separated by commas.
 *
 * \warning This API does not respect regulatory requirements.
 * Use the get list regulatory channels API (qcsapi_wifi_get_list_regulatory_channels) to get the list of valid channels by regulatory authority.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \param ifname \wifi0
 * \param list_of_channels return parameter to contain the list of channels, comma separated.
 *
 * \return 0 if the command succeeded and the list_of_channels is filled in correctly.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_channel_list \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the list of WiFi channels per the 802.11 standard.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_list_channels( const char *ifname, string_1024 list_of_channels );

/**
 * \brief Get WiFi mode switch setting
 *
 * This API retrieves the current WiFi mode switch setting.
 *
 * \note It is required that the relevant GPIOs attached to the switch (12 and 13) be configured as inputs for this API to work.
 *
 * \param p_wifi_mode_switch_setting pointer to result memory. On success, the result memory will have 1, 2 or 3 written to it depending on the
 * position of the switch. If the GPIOs are not configured as inputs, 0 will be returned.
 *
 * \return 0 if the command succeeded and the list_of_channels is filled in correctly.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_mode_switch</c>
 *
 * On success, call_qcsapi will print the setting as an integer (1, 2, or 3) depending on the switch setting, or 0 if the relevant GPIOs are not configured as inputs. On failure, an error message will be written to stdout.
 */
extern int	qcsapi_wifi_get_mode_switch( uint8_t *p_wifi_mode_switch_setting );


/**
 * @brief Force a disassociate on the STA.
 *
 * This API call ends the current association and puts the device into an idle state,
 * so that it does not send out probe requests or attempt to associate with any AP.
 *
 * \note This API only applies for a STA.
 *
 * \param ifname \wifi0
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi disassociate \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_disassociate(const char *ifname);

/**
 * @brief Get information of disconnection count and time since device boot up.
 *
 * This API is called to get disconnection count. Each time successfully invoke this API,
 * the sequence of disconn_info will increase 1, by which the caller can determine whether module has reset.
 *
 * In STA mode, the disconn_count of disconn_info indicates how many times STA is disconnected
 * from AP since module boot up, the asso_sta_count is 1 if it connects to AP or 0 if not.
 * In AP mode, the disconn_count records times that AP disconnects STA which has been associated with it,
 * the asso_sta_count means the number of STAs connect to AP.
 *
 * This API also can reset sequence, and asso_sta_count by setting member resetflag of disconn_info
 * with 1.
 *
 * \note This API only applies for the primary interface.
 *
 * \param ifname \wifi0
 * \param disconn_info where to save the data.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_disconn_info \<WiFi interface\></c><br>
 * <c>call_qcsapi reset_disconn_info \<WiFi interface\></c>
 */
extern int qcsapi_wifi_get_disconn_info(const char *ifname, qcsapi_disconn_info *disconn_info);

/**
 * \brief Enable/Disable WPS
 *
 * Available on APs only. This API alters hostapd wps_state.
 *
 * \param ifname \wifi0
 * \param disable_wps 0 = set wps_state to configured. 1 = set wps_state to disabled.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi disable_wps \<WiFi interface\> &lt;0 | 1&gt;</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_disable_wps(const char *ifname, int disable_wps);

/**
 * @brief Associate a STA to a network.
 *
 * This API call causes the STA to attempt to associate with the selected SSID, as identified by the input parameter.
 *
 * The SSID must be present (and configured correctly) on the STA.
 *
 * \note This API only applies for a STA.
 *
 * \param ifname \wifi0
 * \param join_ssid the SSID for the STA to join.
 *
 * \return 0 if the command succeeded (association is started - not that the association succeeds).
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi associate \<WiFi interface\> \<SSID name\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_associate(const char *ifname, const qcsapi_SSID join_ssid);

/**
 * \brief Trigger CCA (Clear Channel Assessment) measurement
 *
 * This API causes a CCA measurement to be scheduled 1 second after invocation, on the requested channel, for a requested number of milliseconds.
 *
 * \param ifname \wifi0
 * \param channel Channel to switch to during CCA measurement
 * \param duration Time in milliseconds to spend on the channel
 *
 * \return 0 if the command succeeded (CCA measurement is triggered)
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi start_cca <i>interface</i> <i>channel</i> <i>duration</i></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_start_cca( const char *ifname, int channel, int duration);

/**
 * @brief Get the noise figure for the current channel.
 *
 * This API reports the noise on the current channel in dBm.
 *
 * Since the noise is expected to be much less than 1 milliwatt (0 dBm), the value should be much less than 0.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \param ifname \wifi0
 * \param p_noise return parameter to contain the noise figure read from the interface.
 *
 * \return 0 if the command succeeded and p_noise contains a valid noise figure.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_noise \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the current noise in dBm, most likely a negative number.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_noise( const char *ifname, int *p_noise );

/**
 * @brief Get the RSSI measurement per RF chain.
 *
 * This API reports the RSSI of the selected RF chain in dBm.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \param ifname \wifi0
 * \param rf_chain the RF chain to get the RSSI of (between 0 and 3).
 * \param p_rssi return parameter to contain the RSSI reading of the interface/RF chain pair.
 *
 * \return 0 if the command succeeded and p_rssi contains a valid value.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_rssi_by_chain \<WiFi interface\> \<RF Chain number\></c>
 *
 * Unless an error occurs, the output will be the RSSI of the selected RF chain in dBm.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_rssi_by_chain( const char *ifname, int rf_chain, int *p_rssi );

/**
 * \brief Get the average SNR of the interface.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \param ifname \wifi0
 * \param p_snr return parameter to contain the average SNR of the interface.
 *
 * \return 0 if the command succeeded and p_snr contains a valid value.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_avg_snr \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the average SNR of the primary WiFi interface.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_avg_snr( const char *ifname, int *p_snr );

/**
 * @brief Get the primary wireless interface.
 *
 * This API will return the name of the primary WiFi interface.
 *
 * The primary interface is usually the first AP-mode interface created on system start up,
 * and is the only WiFi interface that allows configuration of the underlying properties of the radio: channel, TX power, bandwidth, etc.
 *
 * The primary interface is thus distinct from any additional AP-mode virtual interfaces created as part of the MBSSID feature,
 * which do not allow these radio properties to be set.
 *
 * \param ifname \wifi0
 * \param maxlen the size of the buffer pointed to by ifname.
 *
 * \return 0 if the command succeeded and ifname contains the primary WiFi interface.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_primary_interface</c>
 *
 * Output should be the name of the primary interface unless an error occurs.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_get_primary_interface( char *ifname, size_t maxlen );

/**
 * @brief Get a wireless interface by index.
 *
 * This API will return the name of the WiFi interface that corresponds to the input parameter.
 *
 * For if_index = 0, this API will return the name of the primary interface.
 *
 * For if_index > 0, the API will return the corresponding secondary interface.
 *
 * If if_index exceeds the number of interfaces - 1, this API will return a range error indicating the index parameter is too large.
 *
 * No holes in the list of entries will be present; starting at 0, for each consecutive value of index, either a unique interface name is returned
 * or the API returns range error.
 *
 * If for a particular value of index the API returns range error, the API will return the same range error for all larger values of index.
 *
 * \param if_index the interface index to get the name of.
 * \param ifname \wifi0
 * \param maxlen the size of the buffer pointed to by ifname.
 *
 * \return 0 if the command succeeded and ifname contains the string of the interface correspoinding to index 'if_index'.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_interface_by_index \<index\></c>
 *
 * Output should be the name of the interface that corresponds to the index value.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_get_interface_by_index( unsigned int if_index, char *ifname, size_t maxlen );

/**
 * \brief Set the primary WiFi interface MAC address.
 *
 * This API allows the primary WiFi interface MAC address to be set.
 *
 * \param new_mac_addr the new MAC address for the primary WiFi interface.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \warning This API can ONLY be called after the QDRV is started, but before the WiFi mode is selected.
 *
 * \warning This API cannot be used to change the WiFi MAC address dynamically - it can be called only
 * 		once, after the QDRV is started. To change the WiFi MAC address again, a reboot is required.
 *
 * \warning This API does NOT save the set WiFi MAC address across reboots. Additional logic is required
 * 		to save/restore the MAC address across reboots.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_wifi_macaddr \<new MAC addr\></c>
 *
 * Output should be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_set_wifi_macaddr( const qcsapi_mac_addr new_mac_addr );

/**
 * @brief Get the BSSID.
 *
 * Return the Basic Service Set ID (BSSID).
 *
 * For an AP, this is the MAC address of the WiFi interface. For a STA, it is the MAC address of the AP it is associated with.
 * If the STA is not in association, the BSSID will be the address <c>00:00:00:00:00:00</c>
 *
 * \param ifname \wifi0
 * \param current_BSSID return parameter to contain the BSSID.
 *
 * \return 0 if the command succeeded and current_BSSID contains a valid value.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_BSSID \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the current BSSID, expressed in the standard MAC address format.
 *
 * On a station not in association, the value will be <c>00:00:00:00:00:00</c>
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_interface_get_BSSID( const char *ifname, qcsapi_mac_addr current_BSSID );

/**
 * @brief Get the list of supported rates on the given interface.
 *
 * This API will list the supported rates (as a string), with each value in megabits per second, separated by commas.
 *
 * These rates represent what the device is capable of; the return value is NOT affected by the current rate setting.
 *
 * \param ifname \wifi0
 * \param rate_type set this to qcsapi_possible_rates.
 * \param supported_rates return parameter to contain the comma separated rate list.
 *
 * \return 0 if the command succeeded and current_BSSID contains a valid value.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_rates \<WiFi interface\> possible_rates</c>
 *
 * Unless an error occurs, the output will be the set of possible rates supported by the interface.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_rates( const char *ifname, qcsapi_rate_type rate_type, string_1024 supported_rates );

/**
 * \brief Set rates from an MBPS list (unsupported)
 *
 * This API is currently unsupported.
 */
extern int	qcsapi_wifi_set_rates( const char *ifname, qcsapi_rate_type rate_type, const string_256 current_rates );

/**
 * \brief Get the maximum upstream and downstream bit rate available to this connection in Mbps.
 *
 * This API will only output "auto" currently.
 *
 * \param ifname \wifi0
 * \param max_bitrate String value of the max_bitrate, currently only "auto" can be retrieved.
 * \param max_str_len The length of the string point to max_bitrate.
 *
 * \return 0 if the command succeeded and max_bitrate contains a valid value.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_max_bitrate \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the max_bitrate supported by the interface,
 * currently only outputting "auto".
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_get_max_bitrate(const char *ifname, char *max_bitrate, const int max_str_len);

/**
 * \brief Set the maximum upstream and downstream bit rate available to this connection in Mbps.
 *
 * This API can only input "auto" currently.
 *
 * \param ifname \wifi0
 * \param max_bitrate String value of the max_bitrate, currently only "auto" can be set.
 * \param max_str_len The length of the string point to max_bitrate.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_max_bitrate \<WiFi interface\> \<max_bitrate\></c>
 *
 * Unless an error occurs, output should be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_set_max_bitrate(const char *ifname, const char *max_bitrate);

/**
 * \brief Get a Quality of Service (QOS) Parameter
 *
 *
 * Returns the value of a Quality of Service Parameter, based on the selected queue.
 *
 * \param ifname \wifi0
 * \param the_queue which queue to use.  Value ranges from 0 to 3, see section
 *  @ref mygroup5_4 "Quality of Service (QoS) extensions" for queue index to symbolic name mappings.
 * \param the_param which parameter to report.  Value ranges from 1 to 6, refer to sections
 *  @ref mysection5_4_1 "ECWMin" through @ref mysection5_4_6 "AckPolicy" for description and limitations.
 * \param ap_bss_flag set to "0" or "1" to report either egress (self) or ingress (BSS) QoS parameter respectively. Refer to section
 *  @ref mygroup5_4 "Quality of Service (QoS) extensions" for difference.
 * \param p_value address of the location to receive the value of the QOS parameter.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_qos_param <i>interface</i> \<0|1|2|3\> <1|2|3|4|6> [<0|1>] </c>
 */
extern int	qcsapi_wifi_qos_get_param(const char *ifname,
					  int the_queue,
					  int the_param,
					  int ap_bss_flag,
					  int *p_value);

/**
 * \brief Set a Quality of Service (QOS) Parameter
 *
 * \param ifname \wifi0
 * \param the_queue which queue to use. Value ranges from 0 to 3, see section
 *  @ref mygroup5_4 "Quality of Service (QoS) extensions" for queue index to symbolic name mappings.
 * \param the_param which parameter to report. Value ranges from 1 to 6, refer to sections
 *  @ref mysection5_4_1 "ECWMin" through @ref mysection5_4_6 "AckPolicy" for description and limitations.
 * \param ap_bss_flag "0" or "1" to set either egress (self) or ingress (BSS) QoS parameter respectively. Refer to section
 *  @ref mygroup5_4 "Quality of Service (QoS) extensions" for difference.
 * \param value the value of the QOS parameter to set.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_qos_param <i>interface</i> \<0|1|2|3\> <1|2|3|4|6> <value> [<0|1>] </c>
 */
extern int	qcsapi_wifi_qos_set_param(const char *ifname,
					  int the_queue,
					  int the_param,
					  int ap_bss_flag,
					  int value);

/**
 * \brief Get the mapping table from TOS/DSCP or IEEE802.1p priority to WMM AC index
 *
 *
 * Returns the current mapping table from TOS/DSCP or IEEE802.1p priority to WMM AC index
 *
 * \param ifname \wifi0
 * \param mapping_table Return value to contain the mapping table for priorities. Must be
 * a memory area large enough to contain 64 byte values
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * <b><c>call_qcsapi</c> interface:</b>
 *
 * <c>call_qcsapi get_wmm_ac_map <i>interface</i> </c>
 */
extern int qcsapi_wifi_get_wmm_ac_map(const char *ifname, string_64 mapping_table);

/**
 * \brief Set one mapping table item from TOS/DSCP or IEEE802.1p priority to WMM AC index
 *
 * \param ifname \wifi0
 * \param user_prio Which user priority to be set. Value ranges from 0 to 7.
 * \param ac_index The AC index to map to the input user_prio. Valid values are 0 to 3,
 * see @ref mygroup5_4 "Quality of Service (QoS) extensions" for correspondence between AC index and AC symbolic name.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_wmm_ac_map <i>interface</i> \<0|1|2|3|4|5|6|7\> <0|1|2|3> </c>
 */
extern int qcsapi_wifi_set_wmm_ac_map(const char *ifname, int user_prio, int ac_index);

/**
 * \brief Get the mapping table from IP DSCP to IEEE802.1p priority
 *
 * Returns the current mapping table from IP DSCP to IEEE802.1p user priority
 *
 * \param ifname \wifi0
 * \param mapping_table Return value to contain the mapping table for IEEE802.1p user priorities.
 * Must be a memory area large enough to contain 64 byte values
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_dscp_8021p_map <i>interface</i> </c>
 */
extern int qcsapi_wifi_get_dscp_8021p_map(const char *ifname, string_64 mapping_table);

/**
 * \brief Get IP DSCP to WMM AC mapping table entries
 *
 * Returns the current mapping table from IP DSCP to WME AC user priority
 *
 * \param ifname \wifi0
 * \param mapping_table Return value to contain the mapping table for WME AC user priorities.
 * Must be a memory area large enough to contain 64 byte values.
 *
 * Return parameter to contain the mapping table for WME AC user priorities
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_dscp_ac_map <i>interface</i> </c>
 */
extern int qcsapi_wifi_get_dscp_ac_map(const char *ifname, u8_array_64 mapping_table);

/**
 * \brief Set one mapping table item from IP DSCP to IEEE802.1p user priority
 *
 * \param ifname \wifi0
 * \param ip_dscp_list List of IP DSCP values to be set. Value ranges from 0 to 64 and
 * 64 is a special use to revert mapping table to default. If the IP DSCP needed to be set
 * is 40 and 46 the format should be 40,46.
 * \param dot1p_up the 802.1p UP to be mapped to the input IP DSCP. Value ranges from 0~7.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_dscp_8021p_map <i>interface</i> \<0-64\>[,1-64]... <0-7> </c>
 */
extern int qcsapi_wifi_set_dscp_8021p_map(const char *ifname, const char *ip_dscp_list, uint8_t dot1p_up);

/**
 * \brief Set one mapping table item from IP DSCP to WMM AC priority.
 *
 * \param ifname \wifi0
 * \param dscp_list List of IP DSCP value(s) to be set. Value ranges from 0 to 63.
 * If more than one IP DSCP mapping is specified, the values must be separated by commas.
 * \param dcsp_list_len The number of IP DSCP values in the dscp_list argument.
 * \param ac the WME AC value that will be mapped to the input IP DSCP. Value ranges from 0 to 3,
 * see @ref mygroup5_4 "Quality of Service (QoS) extensions" for correspondence between AC index and AC symbolic name.
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note Any DSCP mappings not explicitly set will map to AC_BE.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_dscp_ac_map <i>interface</i> \<0-64\>[,0-64]... <0-3></c>
 *
 * As an example, to map the following:
 *
 * CS0,CS1,CS4,CS7 (map to AC_BE);
 *
 * AF11,CS2, AF21,CS3,CS6 (map to AC_VI); and
 *
 * CS5, EF (map to AC_VO)
 *
 * the following set of call_qcsapi calls are made:
 *
 * @code
 * call_qcsapi set_dscp_ac_map wifi0 0,8,32,56 0
 * call_qcsapi set_dscp_ac_map wifi0 10,16,18,24,48 2
 * call_qcsapi set_dscp_ac_map wifi0 40,46 3
 * @endcode
 */
extern int qcsapi_wifi_set_dscp_ac_map(const char *ifname, const u8_array_64 dscp_list, uint8_t dscp_list_len, uint8_t ac);

/**
 * \brief Get the interface priority
 *
 * Get the priority for the given WiFi interface. The priority is used to differentiate traffic between
 * different SSIDs. Traffic in SSIDs with higher priority takes precedence over traffic in SSIDs with lower
 * priority.
 *
 * \param ifname \wifi0
 * \param p_priority a pointer to the buffer for storing the returned value.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_priority \<WiFi interface\></c>
 *
 * The output will be the priority unless an error occurs.
 */
extern int qcsapi_wifi_get_priority(const char *ifname, uint8_t *p_priority);

/**
 * \brief Set the interface priority
 *
 * Set the priority for the given WiFi interface. The priority is used to differentiate traffic between
 * different SSIDs. Traffic in SSIDs with higher priority takes precedence over traffic in SSIDs with lower
 * priority.
 *
 * \param ifname \wifi0
 * \param priority interface priority. Value ranges from 0 to 3.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_priority \<WiFi interface\> \<priority\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int qcsapi_wifi_set_priority(const char *ifname, uint8_t priority);

/*APIs relating to scanning channels.*/
/**
 * \brief Set dwell times
 *
 * This API sets minimum and maximum active and passive channel dwell times used when scanning.
 *
 * \param ifname \wifi0
 * \param max_dwell_time_active_chan Maximum dwell time for active scans
 * \param min_dwell_time_active_chan Minimum dwell time for active scans
 * \param max_dwell_time_passive_chan Maximum dwell time for passive scans
 * \param min_dwell_time_passive_chan Maximum dwell time for passive scans
 *
 * All units are milliseconds.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_dwell_times <i>interface</i> <i>max_active</i> <i>min_active</i> <i>max_passive</i> <i>min_passive</i></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_dwell_times(
			const char *ifname,
			const unsigned int max_dwell_time_active_chan,
			const unsigned int min_dwell_time_active_chan,
			const unsigned int max_dwell_time_passive_chan,
			const unsigned int min_dwell_time_passive_chan
);

/**
 * \brief Get dwell times
 *
 * This API retrieves dwell times from the WLAN driver.
 *
 * \param ifname \wifi0
 * \param p_max_dwell_time_active_chan Result memory for maximum dwell time for active scans
 * \param p_min_dwell_time_active_chan Result memory for minimum dwell time for active scans
 * \param p_max_dwell_time_passive_chan Result memory for maximum dwell time for passive scans
 * \param p_min_dwell_time_passive_chan Result memory for maximum dwell time for passive scans
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_dwell_times <i>interface</i></c>
 *
 * call_qcsapi will print dwell times in argument order to stdout on success, or print an error message to stdout on failure.
 */
extern int	qcsapi_wifi_get_dwell_times(
			const char *ifname,
			unsigned int *p_max_dwell_time_active_chan,
			unsigned int *p_min_dwell_time_active_chan,
			unsigned int *p_max_dwell_time_passive_chan,
			unsigned int *p_min_dwell_time_passive_chan
);

/**
 * \brief Set bgscan dwell times
 *
 * This API sets active and passive channel dwell times used when background scanning.
 *
 * \param ifname \wifi0
 * \param dwell_time_active_chan dwell time for active scans
 * \param dwell_time_passive_chan dwell time for passive scans
 *
 * All units are milliseconds.
 *
 * \note bgscan dwell times should be less than regular scan dwell times.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_bgscan_dwell_times <i>interface</i> <i>active</i> <i>passive</i></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_bgscan_dwell_times(
			const char *ifname,
			const unsigned int dwell_time_active_chan,
			const unsigned int dwell_time_passive_chan
);

/**
 * \brief Get bgscan dwell times
 *
 * This API retrieves background scan dwell times from the WLAN driver.
 *
 * \param ifname \wifi0
 * \param p_dwell_time_active_chan Result memory for dwell time for active scans
 * \param p_dwell_time_passive_chan Result memory for dwell time for passive scans
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_bgscan_dwell_times <i>interface</i></c>
 *
 * call_qcsapi will print dwell times in argument order to stdout on success, or print an error message to stdout on failure.
 */
extern int	qcsapi_wifi_get_bgscan_dwell_times(
			const char *ifname,
			unsigned int *p_dwell_time_active_chan,
			unsigned int *p_dwell_time_passive_chan
);

/**
 * @brief Start a scan on the given wireless interface.
 *
 * This API causes the STA to scan available WiFi channels for beacons and associate with an Access Point whose SSID is configured correctly.
 *
 * \param ifname \wifi0
 *
 * \return 0 if the command succeeded (the scan is triggered, not that the scan is complete).
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi start_scan \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_start_scan(const char *ifname);

/**
 * @brief Cancel an ongoing scan on the given wireless interface.
 *
 * This API will cancel any ongoing WiFi channels scanning performed by the STA. It will do nothing if no
 * scanning is currently running.
 *
 * \param ifname \wifi0
 * \param force Set to 0 to trigger scanning cancellation as soon as possible and return immediately.
 * Set to 1 to cancel scan immediately and then return.
 *
 * \return 0 if the command succeeded - scan cancellation is triggered (force=0), or scan is cancelled (force=1), or
 * no scan was in progress.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi cancel_scan \<WiFi interface\> \<force\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_cancel_scan(const char *ifname, int force);

/**
 * @brief Get scan status.
 *
 * This API is used to get scan status. Application can use this API to poll scan status
 * and ensure scan is completed.
 *
 * \param ifname \wifi0
 * \param scanstatus return the currently scan status, 1 for scan is running and 0 for no scan is running.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_scanstatus \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the 1 or 0.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_scan_status(const char *ifname, int *scanstatus);

/**
 * @brief Get CAC status.
 *
 * This API is used to get CAC status on AP. Application can use this API to poll CAC status
 * and ensure CAC process is completed.
 *
 * \param ifname \wifi0
 * \param cacstatus return the currently CAC status, 1 for CAC is running and 0 for no CAC is running.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_cacstatus \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the 1 or 0.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_cac_status(const char *ifname, int *cacstatus);

/**
 * @brief Wait until the currently running scan has completed.
 *
 * This API, when called, will block the calling thread until the previously triggered scan completes.
 *
 * \param ifname \wifi0
 * \param timeout how long to wait for the scan to complete.
 *
 * If the scan has not completed in the specified timeout interval, the API will return an error reporting timeout.
 *
 * This API is targeted for the STA but will also work on an AP.
 *
 * If no scan is in progress, the API will block the calling process until the timeout expires.
 *
 * \note To check whether scan is completed in RPC case, use non-block polling API <c>qcsapi_wifi_get_scan_status()</c>
 * instead of this block API.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wait_scan_completes \<WiFi interface\> \<timeout\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * A timeout will be reported as <c>QCSAPI error 62: Timer expired.</c>
 */
extern int	qcsapi_wifi_wait_scan_completes(const char *ifname, time_t timeout);


/**
 * \brief Get the transmit power for the current bandwidth.
 *
 * This API call gets the current transmit power that is being used
 * for a particular channel. The TX power is reported in dBm.
 *
 * \param ifname \wifi0
 * \param the_channel the channel for which the tx power is returned.
 * \param p_tx_power return parameter to contains the transmit power.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \return -EINVAL or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_tx_power \<WiFi interface\> &lt;channel&gt; </c>
 *
 * Unless an error occurs, the output will be the transmit power.
 */
extern int	qcsapi_wifi_get_tx_power(const char *ifname,
					const qcsapi_unsigned_int the_channel,
					int *p_tx_power);

/**
 * \brief Set the transmit power for the current bandwidth.
 *
 * This API call sets the current transmit power for a particular channel.
 * The TX power is in dBm unit.
 *
 * \param ifname \wifi0
 * \param the_channel the channel for which the tx power is set.
 * \param tx_power tx power to be set.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \return negative value on error, 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_tx_power \<WiFi interface\> \<channel\> \<tx_power\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>'.
 */
extern int qcsapi_wifi_set_tx_power(const char *ifname,
					const qcsapi_unsigned_int the_channel,
					const int tx_power);

/**
 * \brief Get the transmit powers for 20/40/80MHz bandwidths.
 *
 * This API call gets the current transmit powers that is being used
 * for a particular channel. The TX powers are reported in dBm.
 *
 * \param ifname \wifi0
 * \param the_channel the channel for which the tx power is returned.
 * \param p_power_20M return parameter to contains the transmit power for 20MHz bandwidth.
 * \param p_power_40M return parameter to contains the transmit power for 40MHz bandwidth.
 * \param p_power_80M return parameter to contains the transmit power for 80MHz bandwidth.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \return -EINVAL or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_bw_power \<WiFi interface\> &lt;channel&gt; </c>
 *
 * Unless an error occurs, the output will be the transmit powers.
 */
extern int	qcsapi_wifi_get_bw_power(const char *ifname,
					const qcsapi_unsigned_int the_channel,
					int *p_power_20M,
					int *p_power_40M,
					int *p_power_80M);

/**
 * \brief Set the transmit power for 20/40/80MHz bandwidths.
 *
 * This API call sets the current transmit powers for a particular channel.
 * The TX powers are in dBm unit.
 *
 * \param ifname \wifi0
 * \param the_channel the channel for which the tx power is set.
 * \param power_20M tx power for 20MHz bandwidth to be set.
 * \param power_40M tx power for 40MHz bandwidth to be set.
 * \param power_80M tx power for 80MHz bandwidth to be set.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \return negative value on error, 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_bw_power \<WiFi interface\> \<channel\> \<power_20M\> \<power_40M\> \<power_80M\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>'.
 */
extern int qcsapi_wifi_set_bw_power(const char *ifname,
			const qcsapi_unsigned_int the_channel,
			const int power_20M,
			const int power_40M,
			const int power_80M);
extern int qcsapi_regulatory_set_bw_power(const char *ifname,
			const qcsapi_unsigned_int the_channel,
			const int power_20M,
			const int power_40M,
			const int power_80M);

/**
 * \brief Get Carrier/Interference.
 *
 * This API is used to get Carrier/Interference (db).
 *
 * \param ifname \wifi0
 * \param ci return the Carrier/Interference in db unit.
 *
 * \return negative value on error, 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_carrier_db \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the value of the
 * Carrier/Interference in db unit.
 */
extern int qcsapi_wifi_get_carrier_interference(const char *ifname,
			int *ci);

/**
 * \brief Get congestion index.
 *
 * This API is used to get current congestion index.
 *
 * \param ifname \wifi0
 * \param ci return value to contain the congestion index.
 * The congestion index is in the range 0 - 10.
 *
 * \return negative value on error, 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_congest_idx \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the value of the congestion index.
 */
extern int qcsapi_wifi_get_congestion_index(const char *ifname,
			int *ci);

/**
 * \brief Get the Supported TX Power Levels (as a list of percentages of the maximum allowed)
 *
 * This API reports the supported transmit power levels on the current channel as a list of
 * percentages of the maximum allowed by the regulatory authority.  A regulatory region must
 * have been configured with the Set Regulatory Region API.
 *
 * \param ifname \wifi0
 * \param available_percentages address of a string to recve the list of available percentages.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \return A negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_supported_tx_power \<WiFi interface\> </c>
 *
 * Unless an error occurs, the output will be the list of percentages of the maximum allowed
 * by the regulatory authority.
 */
extern int	qcsapi_wifi_get_supported_tx_power_levels(const char *ifname,
						 string_128 available_percentages);
/**
 * \brief Get the Current TX Power Level (as a percentage of the maximum allowed)
 *
 * This API reports the transmit power on the current channel as a percentage of
 * the maximum allowed by the regulatory authority.  A regulatory region must have
 * been configured with the Set Regulatory Region API.
 *
 * \param ifname \wifi0
 * \param p_current_percentage return parameter to contains the percentage
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \return A negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_current_tx_power \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the percentage of the maximum allowed
 * by the regulatory authority.
 */
extern int	qcsapi_wifi_get_current_tx_power_level(const char *ifname,
						 uint32_t *p_current_percentage);

/**
 * \brief Set power constraint of current channel
 *
 * This API sets the power constraint on the current channel. Power constraint will be
 * filled in power constraint element of beacon and probe response when spectrum management enabled.
 *
 * \param ifname \wifi0
 * \param pwr_constraint power constraint to set
 *
 * \note This API is only available on AP mode and the primary WiFi interface.
 *
 * \return A negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_power_constraint \<WiFi interface\> \<power constraint\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_power_constraint(const char *ifname,
						 uint32_t pwr_constraint);

/**
 * \brief Get power constraint of current channel
 *
 * This API returns the power constraint on the current channel.
 *
 * \param ifname \wifi0
 * \param p_pwr_constraint return parameter to contains power constraint
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \return A negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_power_constraint \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the power constraint on the current channel.
 */
extern int	qcsapi_wifi_get_power_constraint(const char *ifname,
						 uint32_t *p_pwr_constraint);

/**
 * \brief Set tpc interval if 802_11h is enabled
 *
 * This API sets the tpc request interval if 802_11h is enabled and periodical method
 * is used.
 *
 * \param ifname \wifi0
 * \param tpc_interval interval for tpc request to set
 *
 * \note This API is available on AP/STA/WDS mode and the primary WiFi interface.
 *
 * \return A negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_tpc_interval \<WiFi interface\> \<tpc_interval\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_tpc_interval(const char *ifname,
						 int32_t tpc_interval);

/**
 * \brief Get tpc interval if 802_11h is enabled
 *
 * This API gets the tpc request interval if 802_11h is enabled and periodical method
 * is used.
 *
 * \param ifname \wifi0
 * \param tpc_interval interval for tpc request to set
 *
 * \note This API is available on AP/STA/WDS mode and the primary WiFi interface.
 *
 * \return A negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_tpc_interval \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_get_tpc_interval(const char *ifname,
						 uint32_t *p_tpc_interval);

/**
 * \brief Get the record of nodes that have associated with the device.
 *
 * This API reports all remote STAs that have associated with the local AP.
 * The MAC address of the WiFi interface is reported together with the last time
 * that STA associated.  The STA must pass the 4-way handshake to be included;
 * that is, its security credentials must be correct.  Only one entry will be
 * present for a particular STA, based on its MAC address.
 *
 * \param ifname \wifi0
 * \param reset set this to 1 to clear the association records.
 * The current set of association records will be returned.
 * \param records address of the data structure to receive the association records.
 *
 * \note This API is only available on the primary WiFi interface.
 *
 * \return A negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_assoc_records \<WiFi interface\></c>
 *
 * Unless an error occur, the output will be a list of all remote STAs that have
 * associated with the device, together with the time they last associated.
 *
 */
extern int	qcsapi_wifi_get_assoc_records(const char *ifname,
					      int reset,
					      qcsapi_assoc_records *records);

/**
 * @brief Get AP isolation
 *
 * Get the current AP isolation setting
 *
 * \param ifname \wifi0
 * \param p_ap_isolate return parameter to contain the current AP isolation setting
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_ap_isolate \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be 0, 1, representing the qcsapi_ap_isolate_type values.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_ap_isolate(const char *ifname, int *p_ap_isolate);

/**
 * @brief Set AP isolation for the given interface.
 *
 * Enable or disable AP isolation.
 *
 * When AP isolation is enabled, packets are not bridged between stations in the BSS.
 * When AP isolation is disabled, packets can be bridged between stations in the BSS.
 * AP isolation is disabled by default.
 * \note This API is only valid on AP devices.
 *
 * \param ifname \wifi0
 * \param new_ap_isolate the new AP isolation setting
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_ap_isolate \<WiFi interface\> \<0|1\></c>
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_ap_isolate_type
 */
extern int	qcsapi_wifi_set_ap_isolate(const char *ifname, const int new_ap_isolate);
/**
 *@}*/


/**@addtogroup MBSSIDAPIs
 *@{*/
/*MBSS*/

/**
 * @brief Create a new restricted BSS.
 *
 * Creates a new MBSSID AP-mode virtual interface with a set of default security parameters.
 * This new virtual interface isn't added into back-end bridge, just for test.
 *
 * After calling this API function the host AP security daemon configuration is updated, reloaded and the new BSS is made active.
 * Subsequent security and general interface APIs can then be called on the new virtual interface.
 *
 * \param ifname \wifi0
 * \param mac_addr mac address of the created vap. If set to 0, driver will generate one mac address
 *  based on primary interface mac address.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wifi_create_restricted_bss \<WiFi interface\> [mac_addr]</c><br>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_create_restricted_bss( const char *ifname, const qcsapi_mac_addr mac_addr );

/**
 * @brief Create a new BSS.
 *
 * Creates a new MBSSID AP-mode virtual interface with a set of default security parameters.
 *
 * After calling this API function the host AP security daemon configuration is updated, reloaded and the new BSS is made active.
 * Subsequent security and general interface APIs can then be called on the new virtual interface.
 *
 * \param ifname \wifi0
 * not be present in the hostapd.conf file.</b>
 * \param mac_addr mac address of the created vap. If set to 0, driver will generate one mac address
 *  based on primary interface mac address.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wifi_create_bss \<WiFi interface\> [mac_addr]</c><br>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_create_bss( const char *ifname, const qcsapi_mac_addr mac_addr );

/**
 * @brief Remove a BSS.
 *
 * Removes an existing MBSSID AP-mode virtual interface with interface name ifname.
 *
 * The API will return an error if the named interface does not exist.
 *
 * After calling this function, the host AP security daemon configuration is modified, reloaded and the interface named is no longer active.
 *
 * \param ifname \wifi0
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wifi_remove_bss \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_remove_bss( const char *ifname );
/**@}*/

/**@addtogroup WDSAPIs
 *@{*/
/*WDS*/

/**
 * @brief Add a WDS peer
 *
 * This API adds a new WDS peer with the given peer address.
 *
 * An error is returned if the maximum number of WDS peers has been reached or if the peer address already exists.
 *
 * \note The ifname parameter must refer to a primary interface. All WDS peers belong to the primary interface only.
 *
 * \param ifname \wifi0
 * \param peer_address the peer address to add to the WDS interface.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wds_add_peer \<WiFi interface\> \<BSSID of peer AP\></c>
 *
 * Section \ref  MAC_ADDRESS_DETAILS "Format for a MAC address" shows how to format the BSSID (MAC address).
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wds_add_peer( const char *ifname, const qcsapi_mac_addr peer_address );

/**
 * @brief Remove a WDS peer.
 *
 * This API removes an existing WDS peer. An error is returned if the peer does not exist.
 *
 * \note The ifname parameter must refer to a primary interface. All WDS peers belong to the primary interface only.
 *
 * \param ifname \wifi0
 * \param peer_address the peer address to remove from the WDS interface.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wds_remove_peer \<WiFi interface\> \<BSSID of peer AP\></c>
 *
 * Section \ref  MAC_ADDRESS_DETAILS "Format for a MAC address" shows how to format the BSSID (MAC address).
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wds_remove_peer( const char *ifname, const qcsapi_mac_addr peer_address );

/**
 * @brief Get a WDS peer by index
 *
 * This API is used to find a WDS peer address by index.
 *
 * This API is typically used to construct a list of the configured WDS peers.
 *
 * \note The ifname parameter must refer to a primary interface. All WDS peers belong to the primary interface only.
 *
 * \param ifname \wifi0
 * \param index the index to get the WDS peer address of.
 * \param peer_address return parameter to contain the peer address of the given index.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wds_get_peer_address \<WiFi interface\> \<index\></c>
 *
 * Section \ref  MAC_ADDRESS_DETAILS "Format for a MAC address" shows how to format the BSSID (MAC address).
 *
 * Unless an error occurs, the output will be the BSSID for the peer, as selected by its index.
 */
extern int	qcsapi_wds_get_peer_address( const char *ifname, const int index, qcsapi_mac_addr peer_address );

/**
 * @brief Set the WPA PSK for a WDS peer connection.
 *
 * The WDS link between two APs in a pair can be encrypted. This encryption is per-peer.
 *
 * The scheme used for WDS encryption is similar to WPA-NONE encryption which is often used for ad-hoc connections.
 * There is no key exchange protocol. Frames are encrypted with AES using a 256-bit preshared key,
 * set to the same value on both peers.
 *
 * \param ifname \wifi0
 * \param peer_address the WDS peer to apply the key to.
 * \param pre_shared_key a 256 bit key, encoded as hexadecimal ASCII characters (0-9, a-f). If this parameter is NULL,
 * the WDS peer key will be cleared.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wds_set_psk \<WiFi interface\> \<BSSID of peer AP\> \<WDS PSK\></c>
 *
 * where \<WiFi interface\> is the primary interface, \<BSSID of peer AP\> is the BSSID of the peer AP and \<WDS PSK\> is the PSK.
 * Enter the PSK as a string of exactly 64 hexadecimal digits, or NULL to pass an empty PSK to the API.
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wds_set_psk( const char *ifname, const qcsapi_mac_addr peer_address, const string_64 pre_shared_key );
/**@}*/

/**@addtogroup SecurityAPIs
 *@{*/
/* wifi only, encryption and security */

/**
 * @brief Get the security protocol from the beacon.
 *
 * Get the current beacon type. Only applicable for an AP; for a STA, use the SSID Get Protocol API (qcsapi_SSID_get_protocol).
 * On success, returned string will be one of those as documented in the <b>authentication protocol</b> table in
 * \ref CommonSecurityDefinitions
 *
 * \note This API only works on an AP.
 *
 * \param ifname \wifi0
 * \param p_current_beacon the protocol as returned by the API.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_beacon \<WiFi interface\></c>
 *
 * Unless an error occurs, the response will be one of Basic, 11i, WPA or WPAand11i with the interpretation of each listed in
 * the table in the <b>authentication protocol</b> table in \ref CommonSecurityDefinitions.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_SSID_get_protocol
 */
extern int	qcsapi_wifi_get_beacon_type( const char *ifname, char *p_current_beacon );

/**
 * @brief Set the security protocol in the beacon.
 *
 * Set the current beacon type.
 *
 * This API only applies for an AP; for a Station, use the SSID Set Protocol API (qcsapi_SSID_set_protocol).
 *
 * The value for the new beacon must be one of the expected values listed in the section on the corresponding get API.
 * Value must match exactly including upper vs. lower case letters.
 *
 * \note This API only works on an AP.
 *
 * \param ifname \wifi0
 * \param p_new_beacon the new security protocol to set in the beacon.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_beacon \<WiFi interface\> \<beacon type\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * Beacon type needs to be one of the values as per the <b>authentication protocol</b> table in \ref CommonSecurityDefinitions.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_SSID_set_protocol
 */
extern int	qcsapi_wifi_set_beacon_type( const char *ifname, const char *p_new_beacon );

/* WEP */

/**
 * \brief API is not supported
 *
 * \return -EOPNOTSUPP.
 */
extern int	qcsapi_wifi_get_WEP_key_index( const char *ifname, qcsapi_unsigned_int *p_key_index );

/**
 * \brief API is not supported
 *
 * \return -EOPNOTSUPP.
 */
extern int	qcsapi_wifi_set_WEP_key_index( const char *ifname, const qcsapi_unsigned_int key_index );

/**
 * \brief API is not supported
 *
 * \return -EOPNOTSUPP.
 */
extern int	qcsapi_wifi_get_WEP_key_passphrase( const char *ifname, string_64 current_passphrase );

/**
 * \brief API is not supported
 *
 * \return -EOPNOTSUPP.
 */
extern int	qcsapi_wifi_set_WEP_key_passphrase( const char *ifname, const string_64 new_passphrase );

/**
 * \brief Retrieves current encryption level and supported encryption levels.
 *
 * qcsapi_wifi_get_WEP_encryption_level return current encryption level describing
 * current encryption state and available encrytion options
 * for example '<c>Disabled,40-bit,104-bit,128-bit</c>'
 *
 * \param ifname \wifi0
 * \param current_encryption_level String to store encryption level data. Type string string_64
 *
 * \return >= 0 on success
 * \return -EFAULT if current_encryption_level is NULL
 * \return -EMSGSIZE or negative number if underlying wireless_extensions API indicated an error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_WEP_encryption_level \<WiFi interface\> &lt;current_encryption_level&gt; </c>
 *
 * Unless an error occurs, the output will be the string describing the encryption level
 * for example '<c>Disabled,40-bit,104-bit,128-bit</c>'.
 */
extern int	qcsapi_wifi_get_WEP_encryption_level( const char *ifname, string_64 current_encryption_level );

/**
 * \brief API is not supported
 *
 * \return -EOPNOTSUPP.
 *
 */
extern int	qcsapi_wifi_get_basic_encryption_modes( const char *ifname, string_32 encryption_modes );

/**
 * \brief API is not supported
 *
 * \return -EOPNOTSUPP.
 */
extern int	qcsapi_wifi_set_basic_encryption_modes( const char *ifname, const string_32 encryption_modes );

/**
 * \brief API is not supported
 *
 * \return -EOPNOTSUPP.
 */
extern int	qcsapi_wifi_get_basic_authentication_mode( const char *ifname, string_32 authentication_mode );

/**
 * \brief API is not supported.
 *
 * \return -EOPNOTSUPP.
 */
extern int	qcsapi_wifi_set_basic_authentication_mode( const char *ifname, const string_32 authentication_mode );

/**
 * \brief API is not supported
 *
 * \return -EOPNOTSUPP
 */
extern int	qcsapi_wifi_get_WEP_key( const char *ifname, qcsapi_unsigned_int key_index, string_64 current_passphrase );

/**
 * \brief API is not supported
 *
 * \return -EOPNOTSUPP
 */
extern int	qcsapi_wifi_set_WEP_key( const char *ifname, qcsapi_unsigned_int key_index, const string_64 new_passphrase );

/* WPA */

/**
 * @brief Get the security <b>encryption</b> mode(s) configured.
 *
 * Get the current WPA/11i encryption protocol(s) in use.
 * Applies to AP only. For a STA, use qcsapi_SSID_get_encryption_modes.
 *
 * \note This API only works on an AP.
 *
 * \param ifname \wifi0
 * \param encryption_modes a string containing a value per the <b>encryption</b> definitions table in
 * the \ref CommonSecurityDefinitions section.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_WPA_encryption_modes \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be one of the strings listed in the <b>encryption</b> definitions table
 * in the \ref CommonSecurityDefinitions section.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_SSID_get_encryption_modes
 */
extern int	qcsapi_wifi_get_WPA_encryption_modes( const char *ifname, string_32 encryption_modes );

/**
 * @brief Set the security <b>encryption</b> mode(s).
 *
 * Set the current security encryption mode(s). Applies to AP only. For a STA, use qcsapi_SSID_set_encryption_modes.
 * Value is required to be one of the expected values from the corresponding get operation.
 * Value must match exactly including upper vs. lower case letters.
 *
 * \note This API only works on an AP.
 *
 * \param ifname \wifi0
 * \param encryption_modes a string containing a value per the <b>encryption</b> definitions table in
 * the \ref CommonSecurityDefinitions section.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_WPA_encryption_modes \<WiFi interface\> \<encryption mode(s)\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * Encryptions mode(s) needs to be one of the values per the <b>encryption</b> definitions table in
 * the \ref CommonSecurityDefinitions section.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_SSID_set_encryption_modes
 */
extern int	qcsapi_wifi_set_WPA_encryption_modes( const char *ifname, const string_32 encryption_modes );

/**
 * @brief Get the security <b>authentication</b> mode configured.
 *
 * Get the current security authentication mode in use.
 * Applies to AP only. For a STA, use qcsapi_SSID_get_authentication_mode
 *
 * \note This API only works on an AP.
 *
 * \param ifname \wifi0
 * \param authentication_mode a string containing a value per the <b>authentication types</b> table in
 * the \ref CommonSecurityDefinitions section.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_WPA_authentication_mode \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be one of the strings listed in the <b>authentication type</b> table
 * in the \ref CommonSecurityDefinitions section.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_SSID_get_authentication_mode
 */
extern int	qcsapi_wifi_get_WPA_authentication_mode( const char *ifname, string_32 authentication_mode );


/**
 * @brief Set the security <b>authentication</b> mode.
 *
 * Set the current security authentication mode. Applies to AP only. For a STA, use qcsapi_SSID_set_authentication_modes.
 * Value is required to be one of the expected values from the corresponding get operation.
 * Value must match exactly including upper vs. lower case letters.
 *
 * \note This API only works on an AP.
 *
 * \param ifname \wifi0
 * \param authentication_mode a string containing a value per the <b>authentication type</b> table in
 * the \ref CommonSecurityDefinitions section.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_WPA_authentication_modes \<WiFi interface\> \<authentication mode(s)\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * The authentication mode needs to be one of the values per the <b>authentication type</b> definitions table in
 * the \ref CommonSecurityDefinitions section.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_SSID_set_authentication_modes
 */
extern int	qcsapi_wifi_set_WPA_authentication_mode( const char *ifname, const string_32 authentication_mode );

/**
 * \brief see qcsapi_wifi_get_WPA_encryption_modes
 *
 * \sa qcsapi_wifi_get_WPA_encryption_modes
 */
extern int	qcsapi_wifi_get_IEEE11i_encryption_modes( const char *ifname, string_32 encryption_modes );

/**
 * \brief see qcsapi_wifi_set_WPA_encryption_modes
 *
 * \sa qcsapi_wifi_set_WPA_encryption_modes
 */
extern int	qcsapi_wifi_set_IEEE11i_encryption_modes( const char *ifname, const string_32 encryption_modes );

/**
 * \brief see qcsapi_wifi_get_WPA_authentication_mode
 *
 * \sa qcsapi_wifi_get_WPA_authentication_mode
 */
extern int	qcsapi_wifi_get_IEEE11i_authentication_mode( const char *ifname, string_32 authentication_mode );

/**
 * \brief see qcsapi_wifi_set_WPA_authentication_mode
 *
 * \sa qcsapi_wifi_set_WPA_authentication_mode
 */
extern int	qcsapi_wifi_set_IEEE11i_authentication_mode( const char *ifname, const string_32 authentication_mode );

/**
 * @brief Get TKIP MIC errors count.
 *
 * The total number of times the Michael integrity check has failed. This is an accumulated value of number of times
 * MIC check failed starting from the beginning of device operation. Used for information purposes, it is not used
 * directly for triggering Michael countermeasures event. Relevant only to WPA and 802.11i.
 *
 * \param ifname \wifi0
 * \param errcount a pointer to memory where MIC error count value should be placed
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_michael_errcnt \<WiFi interface\> </c>
 *
 * Unless an error occurs, the output will be the total number of Michael integrity check errors on specified interface.
 */
extern int qcsapi_wifi_get_michael_errcnt( const char *ifname, uint32_t *errcount );

/**
 * \brief Get the preshared key
 *
 * Get the WPA or RSN preshared key for an SSID.
 *
 * \param ifname \wifi0
 * \param key_index reserved - set to zero
 * \param pre_shared_key a pointer to the buffer for storing the returned value
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note ifname must be the primary interface.
 *
 * This command is only supported on Access Points.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_pre_shared_key \<WiFi interface\> \<key index\></c>
 *
 * <c>call_qcsapi get_PSK \<WiFi interface\> \<key index\></c>
 *
 * The output will be the preshared key unless an error occurs.
 */
extern int	qcsapi_wifi_get_pre_shared_key( const char *ifname, const qcsapi_unsigned_int key_index, string_64 pre_shared_key );

/**
 * \brief Set the preshared key
 *
 * Set the WPA or RSN preshared key for an SSID.
 *
 * \param ifname \wifi0
 * \param key_index reserved - set to zero
 * \param pre_shared_key a 64 hex digit PSK
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note ifname must be the primary interface.
 *
 * This command is only supported on Access Points.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_pre_shared_key \<WiFi interface\> \<key index\> \<preshared key\></c>
 *
 * <c>call_qcsapi set_PSK \<WiFi interface\> \<key index\> \<preshared key\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_pre_shared_key( const char *ifname, const qcsapi_unsigned_int key_index, const string_64 pre_shared_key );

/**
 * @brief Get the WiFi passphrase for the given interface.
 *
 * Returns the current WPA/11i passphrase. Applies to AP only. For a STA, use qcsapi_SSID_get_key_passphrase.
 *
 * \note This API only works on an AP.
 *
 * \param ifname \wifi0
 * \param key_index - reserved, set to 0.
 * \param passphrase a string to store the passphrase.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_key_passphrase \<WiFi interface\> 0</c>
 *
 * <c>call_qcsapi get_passphrase \<WiFi interface\> 0</c>
 *
 * Unless an error occurs, the output will be the current passphrase.
 *
 * The final '0' in the command line represents the key index.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_SSID_get_key_passphrase
 */
extern int	qcsapi_wifi_get_key_passphrase( const char *ifname, const qcsapi_unsigned_int key_index, string_64 passphrase );

/**
 * @brief Set the WiFi passphrase for the given interface.
 *
 * Sets the WPA/11i passphrase. Applies to AP only. For a STA, use qcsapi_SSID_set_key_passphrase.
 *
 * \note This API only works on an AP.
 *
 * \param ifname \wifi0
 * \param key_index - reserved, set to 0.
 * \param passphrase a string containing the passphrase.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_key_passphrase \<WiFi interface\> 0</c>
 *
 * <c>call_qcsapi set_passphrase \<WiFi interface\> 0</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * The final '0' in the command line represents the key index.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \note The Linux shell processes the passphase parameter.  Selected characters are interpreted by the shell,
 * including the dollar sign ($), the backslash (\) and the backquote (`).  We recommend putting the new passphrase
 * in quotes and/or using the backslash character to "escape" characters that could be processed by the shell.
 *
 * \sa qcsapi_SSID_get_key_passphrase
 */
extern int	qcsapi_wifi_set_key_passphrase( const char *ifname, const qcsapi_unsigned_int key_index, const string_64 passphrase );

/**
 * @brief Get the the WPA status for the given interface.
 *
 * Returns the current WPA status. Only applies to AP.
 *
 * Possible WPA status are:
 * For AP
 * \li <c>WPA_HANDSHAKING</c> - WPA handshaking started.
 * \li <c>NO_WPA_HANDSHAKING</c> - WPA handshaking not started.
 * \li <c>WPA_SUCCESS</c> - WPA handshaking is successful.
 *
 * \param ifname \wifi0
 * \param wpa_status return parameter for storing the informative wpa_status string.
 * \param mac_addr the mac_addr of the station that is connecting or connected to the AP.
 * \param max_len the length of the wpa_status string passed in.
 *
 * \return 0 if the command succeeded.
 * \return a negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_wpa_status \<WiFi interface\> \< Mac address\></c>
 *
 * Unless an error occurs, the output will be the current WPA handshaking status for the AP
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wifi_get_wpa_status( const char *ifname,
		char *wpa_status,
		char *mac_addr,
		const qcsapi_unsigned_int max_len );

/**
 * @brief Get the total number of PSK authentication failures.
 *
 * This API returns the total number of PSK authentication failures from
 * the AP and associated stations.
 *
 * \param ifname \wifi0
 * \param count return parameter to contain the count of PSK authentication failures.
 *
 * \return 0 if the command succeeded.
 * \return a negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_psk_auth_failures \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the count of PSK authentication failures.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wifi_get_psk_auth_failures(const char *ifname, qcsapi_unsigned_int *count);

/**
 * @brief Get the the authenticated state of the specific station according to the mac_addr
 * for the given interface.
 *
 * Returns the authenticated state(0/1). Only applies to AP.
 *
 * Possible authenticated state are:
 * For AP
 * \li <c>1</c> - the station is authorized.
 * \li <c>0</c> - the station is not authorized.
 *
 * \param ifname \wifi0
 * \param mac_addr the mac_addr of the station.
 * \param auth_state the state value to return .
 *
 * \return 0 if the command succeeded.
 * \return a negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_auth_state \<WiFi interface\> \< Mac address\></c>
 *
 * Unless an error occurs, the output will be the authorized state for the station
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wifi_get_auth_state(const char *ifname,
			char *mac_addr,
			int *auth_state);


/**@}*/


/**@addtogroup MACFilterAPIs
 *@{*/

/**
 * @brief Set MAC address filtering for the given interface.
 *
 * Set the current MAC address filtering, based on the input parameters
 *
 * If the MAC address filtering was configured as Disabled (<c>qcsapi_disable_mac_address_filtering</c>),
 * calling the API to deny access to a MAC address will change the configuration to
 * Accept unless Denied (<c>qcsapi_accept_mac_address_unless_denied</c>),
 * so the referenced MAC address will be blocked from associating.
 *
 * Note that MAC address filtering is disabled by default.
 *
 * \param ifname \wifi0
 * \param new_mac_address_filtering the new MAC address filtering mode to enable.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_macaddr_filter \<WiFi interface\> \<0|1|2\></c>
 *
 * Final argument configures the MAC address filtering:
 *
 * \li 0 to disable MAC address filtering,
 * \li 1 to accept an association unless the MAC address has been blocked,
 * \li 2 to block associations unless the MAC address has been authorized.
 *
 * These values match those in the enumerated data type qcsapi_mac_address_filtering.  Unless an error occurs, the output will be
 * the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \note If the MAC address filtering is set to Accept Unless Blocked, and MAC address filtering is turned off, the list of blocked MAC
 * addresses will be lost.
 *
 * \sa qcsapi_mac_address_filtering
 */
extern int	qcsapi_wifi_set_mac_address_filtering(
			const char *ifname,
			const qcsapi_mac_address_filtering new_mac_address_filtering
);

/**
 * @brief Get MAC Address Filtering
 *
 * Get the current MAC address filtering. Returned value will matches one of those in the enumerated data type.
 *
 * This is the dual function of qcsapi_wifi_set_mac_address_filtering.
 *
 * \param ifname \wifi0
 * \param current_mac_address_filtering return parameter to contain the MAC address filtering mode currently enabled.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_macaddr_filter \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be 0, 1 or 2, representing the enumerators in the enumeration qcsapi_mac_address_filtering.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_mac_address_filtering(
			const char *ifname,
			qcsapi_mac_address_filtering *current_mac_address_filtering
);

/**
 * @brief Authorize a MAC address for MAC address filtering.
 *
 * Authorize the referenced MAC address against the MAC address filtering function.
 *
 * \param ifname \wifi0
 * \param address_to_authorize the MAC address of the device to authorize.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi authorize_macaddr \<WiFi interface\> \<MAC address\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection5_1_1 "section here" for details on the format for entering the MAC address.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_authorize_mac_address( const char *ifname, const qcsapi_mac_addr address_to_authorize );

/**
 * @brief Block MAC addresses using the MAC address filtering feature.
 *
 * Block the referenced MAC address. If the MAC address filtering was configured as disabled,
 * calling this API will change the configuration to accept unless denied.
 *
 * \param ifname \wifi0
 * \param address_to_deny the MAC address to deny.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi deny_macaddr \<WiFi interface\> \<MAC address\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection5_1_1 "section here" for details on the format for entering the MAC address.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_deny_mac_address( const char *ifname, const qcsapi_mac_addr address_to_deny );

/**
 * @brief Remove MAC address from the MAC address filtering list.
 *
 * Remove the referenced MAC address.
 *
 * \param ifname \wifi0
 * \param address_to_remove the MAC address to remove.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi remove_macaddr \<WiFi interface\> \<MAC address\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection5_1_1 "section here" for details on the format for entering the MAC address.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_remove_mac_address( const char *ifname, const qcsapi_mac_addr address_to_remove );

/**
 * @brief Check whether a MAC address is authorized.
 *
 * Reports whether a STA with the referenced MAC address is authorized, that is, MAC address filtering will allow the STA to associate.
 *
 * \param ifname \wifi0
 * \param address_to_verify the MAC address to check for authorization.
 * \param p_mac_address_authorized return parameter to indicate authorized (1) or not authorized (0).
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi is_macaddr_authorized \<WiFi interface\> \<MAC address\></c>
 *
 * See @ref mysection5_1_1 "section here" for details on the format for entering the MAC address.
 *
 * Unless an error occurs, the output is either 1 (MAC address can associate) or 0 (MAC address will be blocked from associating).
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_is_mac_address_authorized(
			const char *ifname,
			const qcsapi_mac_addr address_to_verify,
			int *p_mac_address_authorized
);

/**
 * @brief Get a list of authorized MAC addresses
 *
 * Get a list of authorized MAC addresses.
 * MAC address filtering must have been configured to Deny unless Authorized <c>(qcsapi_deny_mac_address_unless_authorized)</c>.
 *
 * MAC addresses will be returned in <c>list_mac_addresses</c> up to the size of the parameter, as expressed in <c>sizeof_list</c>,
 * in the standard format for MAC addresses, separated by commas.
 *
 * \param ifname \wifi0
 * \param list_mac_addresses return parameter to contain the list of comma delimited MAC addresses
 * \param sizeof_list the size of the input list_mac_addresses buffer.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_authorized_macaddr \<WiFi interface\> \<size of string\></c>
 *
 * Unless an error occurs, output will be the list of authorized MAC addresses, separated by commas.
 * MAC address filtering must be set to deny unless authorized (2);
 * use <c>call_qcsapi get_macaddr_filter</c> to verify this.
 *
 * Final parameter is the size of the string to receive the list of authorized MAC addresses.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_authorized_mac_addresses( const char *ifname, char *list_mac_addresses, const unsigned int sizeof_list );

/**
 * @brief Get a list of denied MAC addresses.
 *
 * Get a list of denied or blocked MAC addresses.
 * MAC address filtering must have been configured to accept unless denied (<c>qcsapi_accept_mac_address_unless_denied</c>).
 * MAC addresses will be returned in <c>list_mac_addresses</c> up to the size of the passed in buffer, as expressed in <c>sizeof_list</c>,
 * in the standard format for MAC addresses, separated by commas.
 *
 * \param ifname \wifi0
 * \param list_mac_addresses return parameter to contain the list of comma delimited MAC addresses
 * \param sizeof_list the size of the input list_mac_addresses buffer.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_denied_macaddr \<WiFi interface\> \<size of string\>   </c><br>
 *
 * Unless an error occurs, output will be the list of denied MAC addresses, separated by commas.
 * MAC address filtering must be set to accept unless denied (1); use <c>call_qcsapi get_macaddr_filter</c> to verify this.
 * Final parameter is the size of the string to receive the list of denied MAC addresses.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_denied_mac_addresses( const char *ifname, char *list_mac_addresses, const unsigned int sizeof_list );

/**
 * @brief API to set OUI to filter list.
 *
 * This function can be called to set OUI into filter list.
 *
 * \param ifname \wifi0
 * \param oui Organizationally unique identifier string in full MAC address format.
 * \param flag 1 to insert OUI and 0 to remove OUI to/from white list
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values".
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_accept_oui_filter \<WiFi interface\> \<OUI\> \<1 | 0\></c>
 *
 * Unless an error occurs, the output will be "complete".
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wifi_set_accept_oui_filter(const char *ifname, const qcsapi_mac_addr oui, int flag);

/**
 * @brief API to get of OUI filter list.
 *
 * This function can be called to get OUI filter list.
 *
 * \param ifname \wifi0
 * \param oui_list Where to receive oui in string format.
 * \param sizeof_list Specifies the size of string that prepare for the list return.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_accept_oui_filter \<WiFi interface\> [size]</c>
 *
 * Unless an error occurs, the output will be string that contains MAC address separated by comma.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wifi_get_accept_oui_filter(const char *ifname, char *oui_list, const unsigned int sizeof_list);

/**
 * @brief Clear the MAC address lists.
 *
 * This function can be called to clear any accept or deny lists created using the MAC address filtering APIs.
 *
 * After this is called, the hostapd.deny and hostapd.accept files will be reset to default - any existing MAC addresses
 * in these files will be cleared.
 *
 * \param ifname \wifi0
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi clear_mac_filters \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_clear_mac_address_filters( const char *ifname );

/**@}*/


/**@addtogroup OptionsAPIs
 *@{*/
/* generic */

/**
 * @brief Get a WiFi option
 *
 * Get the value for an option, as specified by the qcsapi_option_type parameter,
 * with the value returned in the address specified by p_current_option.
 *
 * Value will be either 0 (disabled, false) or 1 (enabled, true). If the option (feature)
 * is not supported, the API will return <c>-qcsapi_option_not_supported</c>.
 *
 * \param ifname \wifi0
 * \param qcsapi_option the option to get the value of.
 * \param p_current_option return parameter to contain the value of the option.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_option \<WiFi interface\> \<option\>   </c>
 *
 * \sa qcsapi_option_type
 */
extern int	qcsapi_wifi_get_option( const char *ifname, qcsapi_option_type qcsapi_option, int *p_current_option );

/**
 * @brief Set a WiFi option
 *
 * Set the value for an option, as specified by the qcsapi_option_type parameter,
 * with a value of 0 disabling the option or setting it to false and a value of 1 enabling the option or setting it to true.
 * A non-zero value will be interpreted as 1.
 *
 * \note Not all options can be set. If the feature is not supported, the API
 * returns <c>-qcsapi_option_not_supported</c>. For some options having fixed value,
 * the API will return <c>-EOPNOTSUPP</c>.
 *
 * \param ifname \wifi0
 * \param qcsapi_option the option to set the value of.
 * \param new_option the new option value..
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_option \<WiFi interface\> \<option\> \<1 | TRUE | 0 | FALSE\></c>
 *
 * \sa qcsapi_option_type
 */
extern int	qcsapi_wifi_set_option( const char *ifname, qcsapi_option_type qcsapi_option, int new_option );
/**@}*/


/*
 * Service Set (SSID) QCSAPIs
 *
 * Multiple instantiations of the Service Set configuration
 * (mostly security parameters) can be configured.
 * Separate instantiations are identified by the SSID.
 * Thus the QCSAPIs that work with these multiple instantiations are
* called Service Set ID APIs.  Each requires an interface (e.g. wifi0)
 * and an SSID.
 */

/**\addtogroup SSIDAPIs
 *@{
 */

/**
 * @brief Create a new SSID.
 *
 * Create a new SSID configuration, as identified by new_SSID.
 *
 * If the Service Set is already present, this API returns an error.
 *
 * The SSID must be a string with between 1 and 32 characters, as outlined in \ref SSID_RULES
 *
 * \param ifname \wifi0
 * \param new_SSID the new SSID to add.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi create_SSID \<WiFi interface\> \<new SSID\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_SSID_create_SSID( const char *ifname, const qcsapi_SSID new_SSID );

/**
 * @brief Remove an existing SSID.
 *
 * Remove an existing SSID configuration, as identified by del_SSID.
 *
 * If the Service Set is absent, this API returns an error.
 *
 * \param ifname the interface to remove the SSID from.
 * \param del_SSID the existing SSID to remove.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * <b><c>call_qcsapi</c> interface:</b>
 *
 * <c>call_qcsapi remove_SSID \<WiFi interface\> \<del SSID\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */

extern int	qcsapi_SSID_remove_SSID( const char *ifname, const qcsapi_SSID del_SSID );
/**
 * @brief Verify an SSID is present
 *
 * Verifies a Service Set configuration is present, as identified by current_SSID.
 * If the Service Set is not present, this API returns an error, -qcsapi_SSID_not_found (see @ref mysection11_1 "section here" for more details).
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID to check.
 *
 * \return 0 if the SSID is present.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi verify_SSID \<WiFi interface\> \<current SSID\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_SSID_verify_SSID( const char *ifname, const qcsapi_SSID current_SSID );

/**
 * @brief Rename an existing SSID
 *
 * Renames an SSID, as identified by current_SSID.
 * If the original Service Set ID is not present, this API returns an error.
 *
 * Both new_SSID and current_SSID must be strings with between 1 and 32 characters, as outlined in \ref SSID_RULES
 *
 * \param ifname \wifi0
 * \param current_SSID a currently defined SSID on this interface.
 * \param new_SSID the new SSID value.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi rename_SSID \<WiFi interface\> \<current SSID\> \<new SSID\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.<br>
 */
extern int	qcsapi_SSID_rename_SSID( const char *ifname, const qcsapi_SSID current_SSID, const qcsapi_SSID new_SSID );


/**
 * \brief Get the list of SSIDs
 *
 * Get the list of configured SSIDs.
 *
 * \param ifname \wifi0
 * \param arrayc the maximum number of SSID names to return
 * \param list_SSID a pointer to the buffer for storing the returned values
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_SSID_list \<WiFi interface\></c>
 *
 * The output will be the SSID list unless an error occurs.  An additional optional parameter selects
 * the number of SSID names to be displayed.  The default count is 2; the maximum count is 10.
 */
extern int	qcsapi_SSID_get_SSID_list( const char *ifname, const unsigned int arrayc, char **list_SSID );

/**
 * @brief Set the authentication protocol for an SSID
 *
 * Set the security authentication protocol (WPA or 11i or both) for an SSID.
 * Valid values for new_protocol are WPA, 11i and WPAand11i.
 *
 * This API is the SSID/STA equivalent of the AP only set beacon API.
 *
 * Basic will not be accepted for the new protocol.  To disable security for an SSID,
 * use the SSID set authentication mode API (qcsapi_SSID_set_authentication_mode) with an authentication mode of NONE.
 *
 * \param ifname \wifi0
 * \param current_SSID an previously defined SSID to apply the protocol to.
 * \param new_protocol the new protocol, as a string. See the <b>authentication protocol</b> table in \ref CommonSecurityDefinitions for valid values.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_set_proto \<WiFi interface\> \<SSID name\> \<protocol type\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * Protocol type needs to be one as listed in the <b>authentication protocol</b> table in \ref CommonSecurityDefinitions.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_SSID_set_authentication_mode
 * \sa qcsapi_wifi_set_beacon_type
 */
extern int	qcsapi_SSID_set_protocol( const char *ifname, const qcsapi_SSID current_SSID, const char *new_protocol );

/**
 * \brief Get the security protocol for an SSID.
 *
 * Get the security protocol (WPA or 11i or both) for an SSID.
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID to check against.
 * \param current_protocol set to one of the values in the <b>authentication protocol</b> table in /ref CommonSecurityDefinitions
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * This API is the SSID/STA equivalent of the get beacon API.<br>
 *
 * \note This API should not be used to determine whether security is enabled for a particular SSID.
 * Use the SSID Get Authentication Mode API to determine if security is enabled for the SSID.
 * If the returned value is None, then security is disabled for the targeted SSID.<br>
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_get_proto \<WiFi interface\> \<SSID name\>    </c><br>
 *
 * Unless an error occurs, the response will be one of the values from the <b>authentication protocol</b> table in
 * \ref CommonSecurityDefinitions
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_SSID_get_authentication_mode
 * \sa qcsapi_wifi_get_beacon_type
 */
extern int	qcsapi_SSID_get_protocol( const char *ifname, const qcsapi_SSID current_SSID, string_16 current_protocol );


/**
 * @brief Get the encryption modes for an SSID
 *
 * Get available encryption modes for an SSID.
 *
 * This API is called to determing the encryption modes supported on the given SSID.
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID to read the encryption modes from.
 * \param encryption_modes a comma delimited set of strings, one for each encryption mode. The values in this string are from the
 * <b>encryption</b> type table in \ref CommonSecurityDefinitions.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_get_encryption_modes \<WiFi interface\> \<SSID name\></c>
 *
 * Unless an error occurs, the output will be one of these three strings, AESEncryption, TKIPEncryption or TKIPandAESEncryption. That is,
 * one of the values from the <b>encryption</b> type table in \ref CommonSecurityDefinitions.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_SSID_set_encryption_modes
 */
extern int	qcsapi_SSID_get_encryption_modes(
			const char *ifname,
			const qcsapi_SSID current_SSID,
			string_32 encryption_modes
);

/**
 * @brief Set the encryption mode for an SSID.
 *
 * Configure available encryption modes for an SSID.
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID to set the encryption mode against.
 * \param encryption_modes a value as per the <b>encryption</b> type table in \ref CommonSecurityDefinitions.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_set_encryption_modes \<WiFi interface\> \<SSID name\> \<encryption mode(s)\></c>
 * where \<encryption mode(s)\> is one of the modes listed in the <b>encryption</b> type table in \ref CommonSecurityDefinitions.
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_SSID_set_encryption_modes(
			const char *ifname,
			const qcsapi_SSID current_SSID,
			const string_32 encryption_modes
);

/**
 * \brief Get the group encryption cipher.
 *
 * Get the group encryption cipher for an SSID.
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID for which to retrieve the group encryption cipher
 * \param encryption_mode a pointer to the buffer for storing the returned value
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * This command is only supported on Stations.
 *
 * <c>call_qcsapi SSID_get_group_encryption \<WiFi interface\> \<SSID\></c>
 *
 * The output will be the encryption cipher unless an error occurs.
 */
extern int	qcsapi_SSID_get_group_encryption(
			const char *ifname,
			const qcsapi_SSID current_SSID,
			string_32 encryption_mode
);

/**
 * \brief Set the group encryption cipher.
 *
 * Set the group encryption cipher for an SSID.
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID for which to set the group encryption cipher
 * \param encryption_mode the cipher to be applied
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * This command is only supported on Stations.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_set_group_encryption \<WiFi interface\> \<SSID\> \<encryption_mode\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_SSID_set_group_encryption(
			const char *ifname,
			const qcsapi_SSID current_SSID,
			const string_32 encryption_mode
);

/**
 * @brief Get the authentication mode for an SSID.
 *
 * Get the current configured authentication mode for an SSID.
 *
 * This API is the SSID/STA version of WPA get authentication mode API (qcsapi_wifi_get_WPA_authentication_mode);
 * see that section for a description of possible authentication modes returned by this API.
 * If security is disabled for the referenced SSID, this API will return <c>NONE</c>.
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID to get the authentication modes from.
 * \param authentication_mode return parameter to store the authentication type.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_get_authentication_mode \<WiFi interface\> \<SSID name\></c>
 *
 * Unless an error occurs, the response will be of <c>PSKAuthentication, EAPAuthentication</c> or <c>NONE</c>. That is, one of
 * the values outlined in the <b>authentication type</b> table in \ref CommonSecurityDefinitions.
 *
 * A response of NONE implies security is disabled for the referenced SSID.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_wifi_get_WPA_authentication_mode
 */
extern int	qcsapi_SSID_get_authentication_mode(
			const char *ifname,
			const qcsapi_SSID current_SSID,
			string_32 authentication_mode
);

/**
 * @brief Set the authentication mode for an SSID.
 *
 * Set the authentication mode for an SSID.
 *
 * This API is the SSID/STA version of WPA set authentication mode API (qcsapi_wifi_set_WPA_authentication_mode);
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID to get the authentication modes from.
 * \param authentication_mode the authentication mode to use. One of the values from the <b>authentication type</b> table in
 * \ref CommonSecurityDefinitions.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_set_authentication_mode \<WiFi interface\> \<SSID name\> \<authentication mode\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * Valid values for the authentication mode paramter are outlined in the <b>authentication type</b> table in \ref CommonSecurityDefinitions.
 *
 * To disable authentication on the SSID, pass the value <c>NONE</c> to the authentication mode parameter.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_wifi_set_WPA_authentication_mode
 */
extern int	qcsapi_SSID_set_authentication_mode(
			const char *ifname,
			const qcsapi_SSID current_SSID,
			const string_32 authentication_mode
);

/**
 * \brief Get the preshared key
 *
 * Get the WPA or RSN preshared key for an SSID.
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID for which to retrieve the preshared key
 * \param key_index reserved - set to zero
 * \param pre_shared_key a pointer to the buffer for storing the returned value
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note ifname must be the primary interface.
 *
 * This command is only supported on Stations.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_get_pre_shared_key \<WiFi interface\> \<SSID\> \<key index\></c>
 *
 * The output will be the preshared key unless an error occurs.
 */

extern int	qcsapi_SSID_get_pre_shared_key(
			const char *ifname,
			const qcsapi_SSID current_SSID,
			const qcsapi_unsigned_int key_index,
			string_64 pre_shared_key
);

/**
 * \brief Set the preshared key
 *
 * Set the WPA or RSN preshared key for an SSID.
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID to set the WPA PSK on
 * \param key_index reserved - set to zero
 * \param pre_shared_key a 64 hex digit PSK
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \note ifname must be the primary interface.
 *
 * This command is only supported on Stations.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_set_pre_shared_key \<WiFi interface\> \<SSID\> \<key index\> \<preshared key\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_SSID_set_pre_shared_key(
			const char *ifname,
			const qcsapi_SSID current_SSID,
			const qcsapi_unsigned_int key_index,
			const string_64 pre_shared_key
);

/**
 * @brief Get the passphrase for an SSID.
 *
 * Get the passphrase for an SSID.
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID to get the passphrase for.
 * \param key_index reserved - set to zero
 * \param passphrase return parameter to contain the NULL terminated passphrase.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_get_key_passphrase \<WiFi interface\> \<SSID name\> 0 </c>
 *
 * <c>call_qcsapi SSID_get_passphrase \<WiFi interface\> \<SSID name\> 0 </c>
 *
 * Unless an error occurs, the output will be the passphrase configured for the SSID.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_SSID_get_key_passphrase(
			const char *ifname,
			const qcsapi_SSID current_SSID,
			const qcsapi_unsigned_int key_index,
			string_64 passphrase
);

/**
 * @brief Set the passphrase for an SSID.
 *
 * Set the passphrase for a Service Set.
 *
 * By the WPA standard, the passphrase is required to have between 8 and 63 ASCII characters.
 *
 * \param ifname \wifi0
 * \param current_SSID the SSID to set the passphrase on.
 * \param key_index reserved - set to zero
 * \param passphrase the NULL terminated passphrase.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_set_key_passphrase \<WiFi interface\> \<SSID name\> 0 \<new passphrase\></c>
 *
 * <c>call_qcsapi SSID_set_passphrase \<WiFi interface\> \<SSID name\> 0 \<new passphrase\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \note The Linux shell processes the passphase parameter.
 * Selected characters are interpreted by the shell, including the dollar sign ($), the backslash (\) and the backquote (`).
 * We recommend putting the new passphrase in quotes and/or using the backslash character
 * to escape characters that could be processed by the shell.
 */
extern int	qcsapi_SSID_set_key_passphrase(
			const char *ifname,
			const qcsapi_SSID current_SSID,
			const qcsapi_unsigned_int key_index,
			const string_64 passphrase
);

/**
 * \brief Get the SSID associated with the WPS session.
 *
 * This API returns the SSID as configured via WPS. This network block
 * is marked using a 'flags' parameter to indicate that the SSID was
 * configured via WPS.
 *
 * \note This API can only be called on an STA device.
 *
 * \param ifname \wifi0
 * \param wps_SSID the return value to contain the SSID.
 *
 * \return >= 0 on success, -qcsapi_configuration_error if the SSID is not
 * one configured via WPS, -qcsapi_only_on_STA if called on an AP, -EFAULT or
 * -qcsapi_programming_error on other errors (NULL parameter etc).
 *
 * \callqcsapi
 *
 * <c>call_qcsapi SSID_get_WPS_SSID \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string containing the SSID
 * as obtained via WPS.
 */
extern int	qcsapi_SSID_get_wps_SSID(
			const char *ifname,
			qcsapi_SSID wps_SSID
);
/**@}*/

/*
 * VLAN ...
 */
/**\addtogroup VLANAPIs
 *@{
 */

/**
 * \brief VLAN configuration for a wireless interface.
 *
 * Bind a VLAN to a (non-primary) wireless interface
 * , or unbind a VLAN from it.
 *
 * \note This API can only be called on an AP device.
 *
 * \param ifname \wifi1
 * \param cmd VLAN command - see below.
  * @code
 *  e_qcsapi_vlan_bind	bind a VLAN to wireless interface
 *  e_qcsapi_vlan_unbind	unbind a VLAN from wireless interface
 * @endcode
 *
 * \param VLANID VLAN identifier.
 * \param flags command-specific flags(Not support yet) - see below:<br>
 * @code
 * Please note:
 *	By now, flags only works for command of "bind":
 * @endcode
 * @code
 *	enable tx tag if command is "bind"	1
 *	disable tx tag if command is "bind"	0
 * @endcode
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vlan_config \<WiFi interface\> {bind | unbind} \<VLANID\> [tx tag] </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_vlan_config(
			const char *ifname,
			qcsapi_vlan_cmd cmd,
			uint32_t vlanid,
			uint32_t flags);

/**
 * \brief get vlan configuration
 *
 * This API call is used to retrieve current VLAN configuration which is taking effect.
 *
 * \param vtable
 *
 * \return >= 0 on success, < 0 on error.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi show_vlan_config </c>
 *
 * Unless an error occurs, the output will be a table of VLAN configuration
 */
extern int qcsapi_wifi_show_vlan_config(string_4096 vtable);

/**
 * \brief Enable and disable bridge VLAN pass through.
 *
 * Enable and disable bridge VLAN pass through.
 *
 * \note This API can only be called on an AP device.
 *
 * \param enabled set 1 to enable VLAN pass through, otherwise set it to 0.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi enable_vlan_pass_through \<flag\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_enable_vlan_pass_through(int *enabled);

/**
 * \brief Enable and disable VLAN promiscuous mode.
 *
 * If VLAN promiscuous mode is enabled, all VLAN tagged packets will be sent to the Linux protocol stack.
 *
 * \note This API can only be called on an AP device.
 *
 * \param enabled set to 1 to enable VLAN promiscuous mode, otherwise set to 0.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi enable_vlan_promisc \<enable\> </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_set_vlan_promisc(int *enable);
/**@}*/

/*
 * WPS ...
 */
/**\addtogroup WPSAPIs
 *@{
 */

/**
 * @brief WPS registrar report button press
 *
 * This API starts a WPS session on the Registrar (AP) by pressing the (virtual) WPS Push Button.
 *
 * Under the WPS standard, a WPS session can be started by pressing a virtual button; i.e. by entering a command.
 *
 * A side effect of this API call is that a WPS session will be started.
 *
 * \param ifname \wifi0
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi registrar_report_button_press \<WiFi interface\> </c>
 *
 * <c>call_qcsapi registrar_report_pbc \<WiFi interface\>          </c>
 *
 * This API has 2 scripting interface synonyms.
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wps_registrar_report_button_press( const char *ifname );

/**
 * @brief Report a PIN event on the registrar.
 *
 * This API starts a WPS session on the registrar (AP) by reporting a PIN event.
 *
 * Under the WPS standard, a WPS session can be started by entering a PIN.
 *
 * The PIN is a sequence of either 4 or 8 digits. If the proposed PIN has a length different from 4 or 8 characters,
 * or if any of the characters are not digits, the API will return an error code of Invalid Value (-EINVAL).
 *
 * \note The 8 digit PIN (which has a checksum) does not check the validity of the checksum digit.
 *
 * \param ifname \wifi0
 * \param wps_pin the NULL terminated PIN - either 4 or 8 decimal numbers.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi registrar_report_pin \<WiFi interface\> \<PIN\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wps_registrar_report_pin( const char *ifname, const char *wps_pin );

/**
 * \brief Get the WPS Access Control list
 *
 * Get the WPS Access Control list.
 *
 * \note This API is only relevant on an AP device
 *
 * \param ifname \wifi0
 * \param pp_devname comma-separated list of device IDs allowed or denied to receive credentials via WPS
 *
 * \return 0 if the command succeeded and pp_devname contains list of Device IDs allowed
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 *
 * \callqcsapi
 *
 * <c>call_qcsapi registrar_get_pp_devname \[blacklist\] \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string of allowed Device IDs.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wps_registrar_get_pp_devname( const char *ifname, int blacklist, string_128 pp_devname );

/**
 * @brief Set WPS Access Control Device ID List
 *
 * Set the list of Device IDs that are allowed or denied to receive WPS credentials from the AP.
 *
 * \note This API only works on an AP.
 *
 * The Device IDs are a comma separated list 1 to 256 characters in length with commas as delimiters
 *
 * \param ifname \wifi0
 * \param update_blacklist flag to indicate whether update white-list or black-list
 * \param pp_devname comma-separated list of device IDs allowed or denied to receive credentials via WPS.
 *
 * \return 0 if the command succeeded and the SSID is updated.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi registrar_set_pp_devname \<WiFi interface\> \[blacklist\] \<Comma-separated list of device ID\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wps_registrar_set_pp_devname( const char *ifname, int update_blacklist, const string_256 pp_devname );

/**
 * @brief Report a WPS PBC event on the enrollee.
 *
 * This API starts a WPS session on the Enrollee (STA) by pressing the (virtual) WPS Push Button.
 *
 * Under the WPS standard, a WPS session can be started by pressing a virtual button; i.e. by entering a command.
 *
 * The bssid parameter is present for future expansion and should be set to all 0s (zeros).
 *
 * \callqcsapi
 *
 * <c>call_qcsapi enrollee_report_button_press \<WiFi interface\></c>
 * <c>call_qcsapi enrollee_report_pbc \<WiFi interface\></c>
 *
 * This API has 2 scripting interface synonyms. The bssid parameter is not required and will default to all zeros.
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wps_enrollee_report_button_press( const char *ifname, const qcsapi_mac_addr bssid );

/**
 * @brief Report a PIN event on the enrollee.
 *
 * This API starts a WPS session on the enrollee (STA) by reporting a PIN event.
 *
 * Under the WPS standard, a WPS session can be started by entering a PIN.
 *
 * The PIN is a sequence of either 4 or 8 digits. If the proposed PIN has a length different from 4 or 8 characters,
 * or if any of the characters are not digits, the API will return an error code of Invalid Value (-EINVAL).
 *
 * \note The 8 digit PIN (which has a checksum) does not check the validity of the checksum digit.
 *
 * \param ifname \wifi0
 * \param bssid the BSSID to report the PIN evens for.
 * \param wps_pin the NULL terminated PIN - either 4 or 8 decimal numbers.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi enrollee_report_pin \<WiFi interface\> \<PIN\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wps_enrollee_report_pin( const char *ifname, const qcsapi_mac_addr bssid, const char *wps_pin );

/**
 * @brief Generate a WPS PIN on the enrollee.
 *
 * This API starts a WPS session on the enrollee (STA) by generating a PIN and then reporting
 * that newly generated PIN to any suitably configured and available registrars. The generated PIN will have 8 digits.
 *
 * \param ifname \wifi0
 * \param bssid reserved - set to all zeros.
 * \param wps_pin return parameter to contain the WPS PIN (8 digits, so the string should be at least 9 bytes long).
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi enrollee_generate_pin \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be a string of 8 digits - the newly generated PIN
 *
 * The bssid parameter is not required and will default to all zeros.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wps_enrollee_generate_pin( const char *ifname, const qcsapi_mac_addr bssid, char *wps_pin );

/**
 * \brief Get the AP PIN used for WPS PIN operation.
 *
 * This API call is used to get the AP PIN associated with the WPS PIN
 * function. The PIN is either 4 digits or 8 digits long.
 *
 * \note this API can only be called on an AP device.
 *
 * \param ifname \wifi0
 * \param wps_pin return parameter for containing the NULL terminated string.
 * \param force_regenerate whether to force the AP daemon (hostapd) to regenerate
 * the WPS PIN - a random PIN - for this call.
 *
 * \note a side effect of this call is if there is no WPS PIN currently set for
 * the device, a random PIN will be generated.
 *
 * \return >= 0 success, < 0 or -qcsapi_only_on_AP on error. If success, the
 * wps_pin parameter will be filled with the NULL terminated string containing
 * the PIN.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_wps_ap_pin \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be a string of 8 digits - the PIN on the AP.
 */
extern int	qcsapi_wps_get_ap_pin( const char *ifname, char *wps_pin, int force_regenerate );

/**
 * \brief set the AP PIN used for WPS PIN operation .
 *
 * This API call is used to set the AP PIN associated with the WPS PIN
 * function. The PIN is either 4 digits or 8 digits long.
 *
 * \note this API can only be called on an AP device.
 *
 * \param ifname \wifi0
 * \param wps_pin return parameter for containing the NULL terminated string.
 *
 * \return >= 0 success, < 0 or -qcsapi_only_on_AP on error.
 * \callqcsapi
 *
 * <c>call_qcsapi set_wps_ap_pin \<WiFi interface\> \<wps_pin\> </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wps_set_ap_pin(const char *ifname, const char *wps_pin);

/**
 * \brief save ap PIN to configure file
 *
 * This API call is used to save PIN to configure file
 *
 * \note this API can only be called on an AP device.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 success, < 0 or -qcsapi_parameter_not_found on error.
 * \callqcsapi
 *
 * <c>call_qcsapi save_wps_ap_pin \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wps_save_ap_pin(const char *ifname);

/**
 * @brief Generate a new PIN randomly
 *
 * This API is used to generate a new PIN randomly on a STA.
 * This API won't start WPS session.
 *
 * \param ifname \wifi0
 * \param wps_pin return parameter for containing the NULL terminated string.
 *
 * \return >= 0 success, < 0 on error. If success, the
 * wps_pin parameter will be filled with the NULL terminated string containing
 * the PIN.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wps_get_sta_pin \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be a string of 8 digits.
 */
extern int qcsapi_wps_get_sta_pin(const char *ifname, char *wps_pin);

/**
 * @brief Get the state of the current WPS session.
 *
 * Get the current WPS state, reported as a string in the format "%d (%s)", that is,
 * an integer followed by a short descriptive string in parentheses.
 * This API works for either an enrollee or a registrar; or stated differently, it works on both an AP and a STA.
 *
 * Possible WPS states are:
 *
 * \li <c>0(WPS_INITIAL)</c> - Initial WPS state.
 * \li <c>1(WPS_START)</c> - WPS transaction has started.
 * \li <c>2(WPS_SUCCESS)</c> - WPS transaction succeeded and the device is in association with its partner.
 * \li <c>3(WPS_ERROR)</c> - WPS transaction ended with an error.
 * \li <c>4(WPS_TIMEOUT)</c> - WPS transaction timed out.
 * \li <c>5(WPS_OVERLAP)</c> - WPS overlap is detected.
 *
 * \param ifname \wifi0
 * \param wps_state return parameter for storing the informative WPS state string.
 * \param max_len the length of the wps_state string passed in.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_wps_state \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be one of the WPS State strings listed in the description of the API itself.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wps_get_state( const char *ifname, char *wps_state, const qcsapi_unsigned_int max_len );

/**
 * \brief Get the WPS configured state for the given interface.
 *
 * This API call is used to find the WPS configured state - either configured or
 * not configured.
 *
 * \note this API can only be called on an AP device. WPS configured/not configured
 * is a concept that only applies to the AP.
 *
 * \param ifname \wifi0
 * \param wps_state return parameter to store the WPS state (configured or
 * not configured).
 * \param max_len the size of the input buffer (wps_state).
 *
 * \return >= 0 on success, < 0 on error. If success, the wps_state parameter
 * will be filled with the NULL terminated string 'configured' or 'not configured'.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_wps_configured_state \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string '<c>configured</c>' or '<c>
 * not configured</c>'.
 */
extern int	qcsapi_wps_get_configured_state( const char *ifname, char *wps_state, const qcsapi_unsigned_int max_len );


/**
 * \brief Get the WPS runtime state for the given interface.
 *
 * This API call is used to find the WPS runtime state, disabled, not configured or
 * configuired
 *
 * \note this API can only be called on an AP device.
 *
 * \param ifname \wifiX
 * \param state return parameter to store the WPS state (disabled, configured or
 * not configured).
 * \param max_len the size of the input buffer (state).
 *
 * \return >= 0 on success, < 0 on error. If success, the wps_state parameter
 * will be filled with the NULL terminated string 'disable', 'configured' or 'not configured'.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_wps_runtime_state \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string '<c>disabled</c>', '<c>configured</c>' or '<c>
 * not configured</c>'.
 */
extern int	qcsapi_wps_get_runtime_state(const char *ifname, char *state, int max_len);

/**
 * \brief Set the WPS configured state for the given interface.
 *
 * This API call is used to set the WPS state to configured or unconfigured.
 *
 * \note this API can only be called on an AP device. WPS configured/not configured
 * is a concept that only applies to the AP.
 *
 * \param ifname \wifiX
 * \param state either 0 (disabled), 1 (not configured) or 2 (configured).
 *
 * \return >= 0 on success, < 0 on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_wps_configured_state \<WiFi interface\> \<0 | 1 | 2\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wps_set_configured_state( const char *ifname, const qcsapi_unsigned_int state );

/**
 * @brief Get a WPS parameter
 *
 * This API returns the value of a WPS Parameter.
 *
 * \param ifname \wifi0 \wifi1 etc.
 * \param wps_type the WPS parameter.  See the definition of the enun <c>qcsapi_wps_param_type</c>.
 * \param wps_str Address of the string to receive the parameter's value.
 * \param max_len Maximum number of characters that can be written to the parameter <c>wps_str</c>
 *
 * \return >= 0 on success, < 0 on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_wps_param \<WiFi interface\> \<WPS parameter name\> </c>
 *
 * where <c>WPS parameter name</c> is one of <c>uuid</c>, <c>os_version</c>,
 * <c>device_name</c>, <c>config_methods</c> or <c>ap_setup_locked</c>
 * <c>last_config_error</c> <c>registrar_number</c> <c>registrar_established</c>
 * <c>force_broadcast_uuid</c>
 *
 * \note this API can be used both on AP and STA, except for parameter name is <c>ap_setup_locked</c> and <c>force_broadcast_uuid</c>.
 *
 * Unless an error occurs, the output will be the value of the selected WPS parameter.
 *
 * \note last_config_error, registrar_number, and registrar_established are not supported currently.
 */
extern int	qcsapi_wps_get_param(const char *ifname, qcsapi_wps_param_type wps_type, char *wps_str, const qcsapi_unsigned_int max_len);

/**
 * @brief set wps walk time value from 120s to 600s
 *
 * This API call is used to set the wps walk time
 *
 * \note this API can be called both on an AP device or a STA device.
 *
 * \param ifname \wifi0
 * \param value. walk time value
 *
 * \return >= 0 on success, < 0 on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wps_set_timeout \<WiFi interface\> \<timeout value\> </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wps_set_timeout(const char *ifname, const int value);

/**
 * @brief set wps_on_hidden_ssid enabled or disabled
 *
 * This API call is used to enable or disable the feature wps_on_hidden_ssid
 *
 * \note this API can be called only on an AP device.
 *
 * \param ifname \wifiX
 * \param value. 1 wps_on_hidden_ssid enabled, 0 wps_on_hidden_ssid disabled
 *
 * \return >= 0 on success, < 0 on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wps_on_hidden_ssid \<WiFi interface\> \<0 | 1\> </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wps_on_hidden_ssid(const char *ifname, const int value);

/**
 * @brief get wps_on_hidden_ssid status
 *
 * This API call is used to check status of wps_on_hidden_ssid
 *
 * \note this API can be called only on an AP device.
 *
 * \param ifname \wifiX
 *
 * \return "on", "off" or "FAIL"
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wps_on_hidden_ssid_status \<WiFi interface\> </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wps_on_hidden_ssid_status(const char *ifname, char *state, int max_len);

/**
 * @brief enable or disable wps upnp module
 *
 * This API call is used to enable or disable wps upnp module
 *
 * \note this API can be called only on an AP device.
 *
 * \param ifname \wifi0
 * \param value. 1 upnp enabled, 0 upnp disabled
 *
 * \return >= 0 on success, < 0 on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wps_upnp_enable \<WiFi interface\> \<0 | 1\> </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wps_upnp_enable(const char *ifname, const int value);

/**
 * @brief get upnp status
 *
 * This API call is used to get upnp status
 *
 * \note this API can be called only on an AP device.
 *
 * \param ifname \wifi0
 * \param reply. reply buffer
 * \param reply_len. reply buffer length
 *
 * \return >= 0 on success, < 0 on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wps_upnp_status \<WiFi interface\> </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wps_upnp_status(const char *ifname, char *reply, int reply_len);

/**
 * @brief Allow or forbid the detection of WPS PBC overlap
 *
 * This API call is used to allow/forbid the detection of PBC overlap.
 *
 * \note this API can be called both on an AP device or a STA device.
 *
 * \param ifname \wifi0
 * \param allow.  1 indicates allow, 0 indicates forbid.
 *
 * \return >= 0 on success, < 0 on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi allow_pbc_overlap \<WiFi interface\> \<0 | 1\> </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wps_allow_pbc_overlap(const char *ifname, const qcsapi_unsigned_int allow);
/**
 * @brief get status if PBC overlap is allowed on AP or STA.
 *
 * This API returns the status if PBC overlap is allowed on AP or STA.
 *
 * \note this API can be called both on an AP device or a STA device.
 *
 * \param ifname \wifi0
 * \param status the return value if allow PBC overlap.
 *
 * \return >= 0 on success, < 0 on failure. If success, the status of allowing
 * PBC overlap (0/1) will be returned.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_allow_pbc_overlap_status \<WiFi interface\> </c>
 *
 * Unless an error occurs, the output will be the string '<c>1</c>' or '<c>0</c>'
 */
extern int	qcsapi_wps_get_allow_pbc_overlap_status(const char *ifname, int *status);

/**
 * \brief Enable/Disable the WPS Pair Protection for the given interface.
 *
 * This API call is used to Enable/Disable the WPS Pair Protection.
 *
 * \note this API can only be called on an AP device.
 *
 * \param ifname \wifi0
 * \param ctrl_state either 0 (disabled) or 1 (enabled).
 *
 * \return >= 0 on success, < 0 on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_wps_access_control \<WiFi interface\> \<0 | 1\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wps_set_access_control(const char *ifname, uint32_t ctrl_state);

/**
 * \brief Get the WPS Pair Protection state for the given interface.
 *
 * This API call is used to get the WPS Pair Protection state - either enabled or
 * disabled.
 *
 * \note this API can only be called on an AP device.
 *
 * \param ifname \wifi0
 * \param ctrl_state return parameter to store the WPS Pair Protection state (enabled or
 * disabled).
 *
 * \return >= 0 on success, < 0 on error. If success, the wps pair protection state parameter
 * (0/1)will be returned.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_wps_access_control \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string '<c>1</c>' or '<c>0</c>'.
 */
extern int	qcsapi_wps_get_access_control(const char *ifname, uint32_t *ctrl_state);

/**
 * @brief Set a WPS parameter
 *
 * This API is called to set a WPS Parameter.
 *
 * \param ifname \wifi0 \wifi1 etc. use \all to set parameter for each existing interface, AP mode only.
 * \param wps_type the WPS parameter.  See the definition of the enun <c>qcsapi_wps_param_type</c>.
 * \param param_value Address of the string to set the parameter's value.
 *
 * \return >= 0 on success, < 0 on failure.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_wps_param \<WiFi interface\> \<WPS parameter name\> \<WPS parameter value\></c>
 *
 * where <c>WPS parameter name</c> is one of <c>config_methods</c>, <c>ap_pin</c>, <c>setup_lock</c>, <c>ap_setup_locked</c>
 * , <c>uuid</c> or <c>force_broadcast_uuid</c>. The API is only available for AP mode, except for the parameter name <c>uuid</c> and
 * <c>config_methods</c>.
 *
 * When parameter name is <c>config_methods</c>, the available parameter value is
 * one of following value or combination of them, <c>usba</c>, <c>ethernet</c>, <c>label</c>,
 * <c>display</c>, <c>ext_nfc_token</c>, <c>int_nfc_token</c>, <c>nfc_interface</c>,
 * <c>push_button</c>, <c>keypad</c>, <c>virtual_display</c>,
 * <c>virtual_push_button</c>, <c>physical_push_button</c>.
 *
 * The parameter value of uuid has format xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx. For example:<br>
 * <c>cdcb13e6-baa5-5f43-807f-4b4c28223a68</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int qcsapi_wps_set_param(const char *ifname, const qcsapi_wps_param_type param_type, const char *param_value);

/**
 * @brief Cancel the ongoing wps procedure if any.
 *
 * This API equivalent to "wpa_cli wps_cancel". It will cancel ongoing wps procedure,
 * and do nothing if there are no wps procedure undergoing.
 *
 * \note this API can only be called on an STA device.
 *
 * \param ifname \wifi0
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi wps_cancel \<WiFi interface\> </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wps_cancel( const char *ifname );

/**
 * @brief Add/remove PBC methods in SRCM.
 *
 * This API is used to add or remove PBC methods in SRCM (selected registrar config methods)
 * attribute in WSC IE.
 *
 * \note this API can only be called on an AP device.
 *
 * \param ifname \wifi0
 * \param enabled 1 to add and 0 to remove PBC methods in SRCM attribute in WSC IE.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_wps_pbc_in_srcm \<WiFi interface\> \<1 | 0\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wps_set_pbc_in_srcm(const char *ifname, const qcsapi_unsigned_int enabled);

/**
 * @brief Get currently setting of PBC methods in SRCM attribute.
 *
 * This API is used to get currently setting of PBC methods in SRCM attribute.
 *
 * \note this API can only be called on an AP device.
 *
 * \param ifname \wifi0
 * \param p_enabled Where to store the result return.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_wps_pbc_in_srcm \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string <c>0</c> or <c>1</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */

extern int qcsapi_wps_get_pbc_in_srcm(const char *ifname, qcsapi_unsigned_int *p_enabled);

/**
 * @brief set default bss for WPS Push button
 *
 * This API is used to set default bss for WPS Push button if there's more than one BSS such like MBSS mode
 * default bss for WPS PBC is primary interface(wifi0) after powered up
 *
 * \note this API can only be called on an AP device. set "null" would remove default setting
 *
 * \param ifname \wifiX
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi registrar_set_default_pbc_bss \<WiFi interface | null\> </c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */

extern	int qcsapi_registrar_set_default_pbc_bss(const char *ifname);

/**
 * @brief get default bss for WPS Push button
 *
 * This API is used to get default bss for WPS Push button
 * default bss for WPS PBC is primary interface(wifi0) after powered up
 *
 * \note this API can only be called on an AP device.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi registrar_get_default_pbc_bss </c>
 *
 * Unless an error occurs, the output will be WiFi interface or null.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */

extern	int qcsapi_registrar_get_default_pbc_bss(char *default_bss, int len);

/**@}*/


/*
 * GPIO ...
 */
/**@addtogroup LEDGPIOAPIs
 *@{*/

/**
 * @brief Set GPIO configuration
 *
 * \warning <b>This API can potentially damage the chip, please treat it with respect and read through the following documentation
 * before using the API.</b>
 *
 * Configures a GPIO pin for input (1), input/output (2), or disables further use of the GPIO pin (0),
 * as specified by the new GPIO config parameter (see \ref qcsapi_gpio_config).
 *
 * GPIO pin values run from 0 to 31.
 *
 * \note This API is only available in calibration mode (see @ref mysection4_1_5 "Production mode vs calibration mode").
 *
 * \param gpio_pin the GPIO to change.
 * \param new_gpio_config the new state of the PIN.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_gpio_config \<GPIO pin number\> \<configuration\></c>
 *
 * where \<GPIO pin number\> is a GPIO pin number, an integer in the range 0 to 31, and &lt;configuration&gt; is either 0, 1 or 2.
 *
 * See above for the meaning of 0, 1 and 2 as a GPIO pin configuration.
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \warning <b>Power should not be turned off to the WiFi device when calling the set GPIO config API or immediately afterwards.
 * Failure to follow this restriction can cause the flash memory on the board to become corrupted.
 * If power needs to be turned off to the WiFi device when working with this API,
 * enter the <c>halt</c> command first and wait for the device to shut down.
 * This API should only be called when initially configuring the board.</b>
 *
 * \warning <b>Be aware that configuring a GPIO pin for output that either not present or wired for input can leave the board or
 * chip open to being damaged should a set API attempt
 * to change the GPIO pin setting to a state not supported by the hardware.</b>
 *
 *
 * \sa qcsapi_gpio_config
 */
extern int	qcsapi_gpio_set_config( const uint8_t gpio_pin, const qcsapi_gpio_config new_gpio_config );

/**
 * @brief Get GPIO configuration
 *
 * Get the current configuration of a GPIO pin, either input (1), output (2), or disabled (0).
 *
 * GPIO pin values are the same as in the set GPIO config API.
 *
 * \param gpio_pin the GPIO to read.
 * \param p_gpio_config return parameter to store the state of the PIN.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c> call_qcsapi get_gpio_config \<GPIO pin number\></c>
 *
 * where \<GPIO pin number\> is a GPIO pin number, an integer in the range 0 to 31.
 */
extern int	qcsapi_gpio_get_config( const uint8_t gpio_pin, qcsapi_gpio_config *p_gpio_config );

/**
 * @brief Get LED state.
 *
 * Get the current level for an LED/GPIO pin, either HIGH (1) or LOW (0).
 *
 * \note The GPIO pin must have been previously configured for input or output thru qcsapi_gpio_set_config.
 *
 * \param led_ident the GPIO pin number.
 * \param p_led_setting
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_LED \<LED / GPIO pin number\></c>
 *
 * where \<LED / GPIO pin number\> is an LED / GPIO pin number, an integer in the range 0 to 31.
 *
 * Unless an error occurs, the output will be either 0 (LOW) or 1 (HIGH).
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_led_get( const uint8_t led_ident, uint8_t *p_led_setting );

/**
 * @brief Set LED state.
 *
 * Set the current level for an LED/GPIO pin, either HIGH (1) or LOW (0).
 *
 * The LED identity is the GPIO pin number.
 *
 * \note The GPIO pin must have been previously configured for output thru the set GPIO config API (qcsapi_gpio_set_config).
 *
 * \warning <b>Be aware that configuring an incorrect GPIO pin for input/output and then setting the level for that invalid GPIO pin can damage the board.
 * Consult the documentation or schematics for the board for details on the GPIO pin configuration.</b>
 *
 * \param led_ident the GPIO corresponding to the LED to change.
 * \param new_led_setting the new state of the LED.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_LED \<LED / GPIO pin number\> \<0 | 1\></c>
 *
 * where <LED / GPIO pin number> is an LED / GPIO pin number, an integer in the range 0 to 31.
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \note Most GPIO pins connect to an LED or other item of hardware that software controls directly using the get and set LED APIs.
 * However, the WPS Push Button and the Reset Device Push Button require additional programming,
 * since the end-user can press these push buttons to start a WPS association process or reset the WiFi device.
 * The software thus needs to be "armed" to respond to these events.
 * Because the way the system is expect to respond to a WPS push button press is quite different from
 * the way it should respond to a Reset Device button press, separate APIs are provided for each.
 */
extern int	qcsapi_led_set( const uint8_t led_ident, const uint8_t new_led_setting );

/**
 * This typedef is used to force a function prototype for reset button function callback.
 *
 * The reset_device_pin passes in the GPIO pin being monitored, and the current_level is either 1 or 0.
 *
 * \sa qcsapi_gpio_monitor_reset_device
 */
typedef void	(*reset_device_callback)(uint8_t reset_device_pin, uint8_t current_level);

/**
 * @brief Monitor the reset device GPIO pin.
 *
 * This API lets an application identify the GPIO pin connected to the reset device push button,
 * and then monitors this push button.
 *
 * \param reset_device_pin the GPIO pin that is connected to the push button. This pin must be configured for input.
 * \param active_logic identifies whether the active state of the pin is high or low, and should be 1 or 0 respectively.
 * \param blocking_flag specifies whether the API should block the process until the button is pressed. Currently this must be set to 1 - ie
 * the API only supports blocking operation.
 * \param respond_reset_device is the address of a callback entry point, with signature as per the \ref reset_device_callback.
 *
 * When called, this API (after completing error checking) periodically checks the state of reset_device_pin.
 * When this pin goes active, as specified by active_logic, it calls the callback entry point identified by reset_device_callback.
 * Notice the entry point is responsible for handling any response to pressing the reset device push button.
 *
 * A sample requirement for how this API is used is:
 *
 * \li If the Reset Device Push Button is pressed for between 1 second and 5 seconds, the WiFi device reboots.
 * \li If the Reset Device Push Button is pressed for more than 5 seconds, the factory default settings are restored and the device then reboots.
 *
 * Again, the reset device callback, programming not part of the QCSAPI,
 * is responsible for handling the response to pressing this push button.
 *
 * \note The script to restore factory default settings is expected to be located in /scripts/restore_default_config.
 *
 * \note This API cannot be called from within <c>call_qcsapi</c>
 */
extern int	qcsapi_gpio_monitor_reset_device(const uint8_t reset_device_pin,
						 const uint8_t active_logic,
						 const int blocking_flag,
						 reset_device_callback respond_reset_device);

/**
 * @brief Enable the WPS GPIO push button.
 *
 * This API enables the WPS push button.
 *
 * Unlike the reset device push button, the expected response when the WPS push button is pressed is predefined.
 * For this reason no callback programming is required.
 *
 * \param wps_push_button the GPIO used for WPS push button operation.
 * \param active_logic identifies whether the active state of the pin is high or low, and should be 1 or 0 respectively.
 * \param use_interrupt_flag if set to 0, selects polling operation, if 1, selects interrupt operation. If interrupt mode is selected,
 * the active logic must be 1.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi enable_wps_push_button \<GPIO pin\> \<0 | 1\></c>
 *
 * where \<GPIO pin\> is the number of the GPIO pin that controls the WPS push button.
 * The parameter that follows selects active logic, either LOW (0) or HIGH (1).
 *
 * To enable the WPS push button in interrupt mode, enter:
 * <c>call_qcsapi enable_wps_push_button \<GPIO pin\> 0 intr </c>
 */
extern int	qcsapi_gpio_enable_wps_push_button(const uint8_t wps_push_button,
						   const uint8_t active_logic,
						   const uint8_t use_interrupt_flag);
/**@}*/


/*Per associations API*/
/**@addtogroup PerAssocAPIs
 *@{*/
/* Associations (AP only) */

/**
 * @brief Get the number of STAs associated.
 *
 * Gets the number of stations currently associated with the access point.
 * As associations are dynamic, this count can change at any time.
 *
 * \note This API is used on both AP and STA. On a STA, it is used to
 * indicate whether it is associated with an AP.
 *
 * \param ifname \wifi0
 * \param p_association_count return parameter to store the count of STAs associated with the AP.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_count_assoc \<WiFi interface\></c>
 *
 * <c>call_qcsapi get_count_associations \<WiFi interface\></c>
 *
 * <c>call_qcsapi get_association_count \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the count of stations currently associated to this AP.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_wifi_get_BSSID
 */
extern int	qcsapi_wifi_get_count_associations( const char *ifname, qcsapi_unsigned_int *p_association_count );

/**
 * @brief Get the associated STA MAC addresses.
 *
 * Gets the MAC address of a STA currently associated with the AP.  Second parameter selects the association index,
 * with a range from 0 to the association count - 1.
 * An index out of range causes the API to fail with the error set to Out of Range (-ERANGE).
 * Use qcsapi_wifi_get_count_associations to determine the current association count.
 *
 * \note This API is only used on the AP.
 *
 * As associations are dynamic, the count of associations can change at any time.
 * An application should never assume that a value previously returned from qcsapi_wifi_get_count_associations remains valid.
 * Applications should always be prepared for a return value of -ERANGE from this API, even if it just verified the number of current associations.
 *
 * As noted previously, this API only works on an AP; for a STA, use the get BSSID API (\ref qcsapi_wifi_get_BSSID) to get the MAC
 * address of the associated AP.
 *
 * \param ifname \wifi0
 * \param device_index the index of the STA MAC address to return.
 * \param device_mac_addr the MAC address of the STA at index 'device_index'.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_associated_device_mac_addr \<WiFi interface\> \<association index\>	</c><br>
 *
 * The output will be the MAC address of the associated station, or an error message.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * \sa qcsapi_wifi_get_BSSID
 */
extern int	qcsapi_wifi_get_associated_device_mac_addr(const char *ifname,
							   const qcsapi_unsigned_int device_index,
							   qcsapi_mac_addr device_mac_addr);

/**
 * @brief Get the associated STA IP addresses.
 *
 * Gets the IP address of a STA currently associated with the AP. Second parameter selects the association index,
 * with a range from 0 to the association count - 1.
 * An index out of range causes the API to fail with the error set to Out of Range (-ERANGE).
 * Use qcsapi_wifi_get_count_associations to determine the current association count.
 *
 * \note This API is only used on the AP.
 *
 * As associations are dynamic, the count of associations can change at any time.
 * An application should never assume that a value previously returned from qcsapi_wifi_get_count_associations remains valid.
 * Applications should always be prepared for a return value of -ERANGE from this API, even if it just verified the number of current associations.
 *
 * \param ifname \wifi0
 * \param device_index the index of the STA IP address to return.
 * \param ip_addr the IP address of the STA at index 'device_index'.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_associated_device_ip_addr \<WiFi interface\> \<association index\></c><br>
 *
 * The output will be the IP address of the associated station, or an error message.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_associated_device_ip_addr(const char *ifname,
							  const qcsapi_unsigned_int device_index,
							  unsigned int *ip_addr);

/**
 * @brief Get the link quality per association index.
 *
 * Returns the link quality as the current TX PHY rate in megabits per second (MBPS).
 *
 * \note The device must have the autorate fallback option enabled.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA link quality to be read. On the STA, this should be 0.
 * \param p_link_quality the link quality for the given index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_link_quality \<WiFi interface\> \<association index\></c>
 *
 * The output will be the current link quality for the association, in terms of the current TX PHY rate in Mbps
 */
extern int	qcsapi_wifi_get_link_quality(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_link_quality
);

/**
 * @brief Get RX bytes per association index.
 *
 * Returns the current number of bytes received on the association.
 *
 * The count is set to 0 at the start of the association.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA RX bytes is to be read. On the STA, this should be 0.
 * \param p_rx_bytes return parameter to contain the number of bytes received on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_rx_bytes \<WiFi interface\> \<association index\></c>
 *
 * The output will be the current number of bytes received on that association.
 */
extern int	qcsapi_wifi_get_rx_bytes_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			u_int64_t *p_rx_bytes
);

/**
 * @brief Get TX bytes per association index.
 *
 * Returns the current number of bytes transmitted on the association.
 *
 * The count is set to 0 at the start of the association.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA TX bytes is to be read. On the STA, this should be 0.
 * \param p_tx_bytes return parameter to contain the number of bytes transmitted on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_tx_bytes \<WiFi interface\> \<association index\></c>
 *
 * The output will be the current number of bytes transmitted on that association.
 */
extern int	qcsapi_wifi_get_tx_bytes_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			u_int64_t *p_tx_bytes
);

/**
 * @brief Get RX Packets by association.
 *
 * Returns the current number of packets received on the association.
 *
 * The count is set to 0 at the start of the association.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA. On the STA, this should be 0.
 * \param p_rx_packets return parameter to contain the number of packets received on this association.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_rx_packets \<WiFi interface\> \<association index\></c>
 *
 * <c>call_qcsapi get_assoc_rx_packets \<WiFi interface\> \<association index\></c>
 *
 * The output will be the current number of packets received on that association.
 */
extern int	qcsapi_wifi_get_rx_packets_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_rx_packets
);

/**
 * @brief Get TX Packets by association.
 *
 * Returns the current number of packets transmitted on the association.
 *
 * The count is set to 0 at the start of the association.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA. On the STA, this should be 0.
 * \param p_tx_packets return parameter to contain the number of packets transmitted on this association.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_tx_packets \<WiFi interface\> \<association index\></c>
 *
 * <c>call_qcsapi get_assoc_tx_packets \<WiFi interface\> \<association index\></c>
 *
 * The output will be the current number of packets transmitted on that association.
 */
extern int	qcsapi_wifi_get_tx_packets_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_tx_packets
);

/**
 * @brief Get TX Packets Errors by association.
 *
 * Returns the current number of packets that failed to be transmitted on the association.
 *
 * The count is set to 0 at the start of the association.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA. On the STA, this should be 0.
 * \param p_tx_err_packets return parameter to contain the number of packets which failed transmission on this association.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_tx_err_packets \<WiFi interface\> \<association index\></c>
 *
 * The output will be the current number of packets that failed to be transmitted on the association.
 */
extern int	qcsapi_wifi_get_tx_err_packets_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_tx_err_packets
);

/**
 * @brief Get RSSI per association index.
 *
 * Returns the current Received Signal Strength Indication (RSSI) in the range [0, 68].
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA RSSID is to be read. On the STA, this should be 0.
 * \param p_rssi return parameter to contain the RSSI on this association index, in the range [0 - 68].
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_rssi \<WiFi interface\> \<association index\></c>
 *
 * The output will be the current RSSI for the association in the range [0 - 68].
 */
extern int	qcsapi_wifi_get_rssi_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_rssi
);

/**
 * @brief Get RSSI in dBm per association index.
 *
 * Returns the current Received Signal Strength Indication (RSSI) in dBm.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA to be read. On the STA, this should be 0.
 * \param p_rssi return parameter to contain the RSSI on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_rssi_dbm \<WiFi interface\> \<association index\></c>
 *
 * The output will be the current RSSI in dBm for the association.
 */
extern int	qcsapi_wifi_get_rssi_in_dbm_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			int *p_rssi
);

/**
 * \brief Get the associated peer bandwidth (20 vs 40MHz).
 *
 * This API call is used to determine the bandwidth used by the peer STA.
 * The bandwidth is 20 or 40, representing 20MHz or 40MHz.
 *
 * \param ifname \wifi0
 * \param association_index the entry into the association table.
 * \param p_bw return parameter for storing the return value (either
 * 20 or 40)
 *
 * \return >= 0, success, < 0 error.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_assoc_bw \<WiFi interface\> &lt;index&gt;</c>
 *
 * Unless an error occurs, the output will be one of the strings
 * '<c>20</c>' or '<c>40</c>'.
 */
extern int	qcsapi_wifi_get_bw_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_bw
);

/**
 * @brief Get TX PHY rate by association index.
 *
 * Returns the current TX PHY rate in megabits per second (MBPS)
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA to be read. On the STA, this should be 0.
 * \param p_tx_phy_rate return parameter to receive the TX PHY rate on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_tx_phy_rate \<WiFi interface\> \<association index\></c>
 *
 * Unless an error occurs, the output will be the current TX PHY rate in MBPS.
 */
extern int	qcsapi_wifi_get_tx_phy_rate_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_tx_phy_rate
);

/**
 * @brief Get RX PHY rate by association index.
 *
 * Returns the current RX PHY rate in megabits per second (MBPS)
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA to be read. On the STA, this should be 0.
 * \param p_rx_phy_rate return parameter to receive the RX PHY rate on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_rx_phy_rate \<WiFi interface\> \<association index\></c>
 *
 * Unless an error occurs, the output will be the current RX PHY rate in MBPS.
 */
extern int	qcsapi_wifi_get_rx_phy_rate_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_rx_phy_rate
);

/**
 * @brief Get TX MCS by association index.
 *
 * Returns the current TX MCS
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA to be read. On the STA, this should be 0.
 * \param p_mcs return parameter to receive the TX MCS on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_tx_mcs \<WiFi interface\> \<association index\></c>
 *
 * Unless an error occurs, the output will be the current TX MCS.
 */
extern int	qcsapi_wifi_get_tx_mcs_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_mcs
);

/**
 * @brief Get RX MCS by association index.
 *
 * Returns the current RX MCS
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA to be read. On the STA, this should be 0.
 * \param p_mcs return parameter to receive the RX MCS on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_rx_mcs \<WiFi interface\> \<association index\></c>
 *
 * Unless an error occurs, the output will be the current RX MCS.
 */
extern int	qcsapi_wifi_get_rx_mcs_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_mcs
);

/**
 * @brief Get Achievable TX PHY rate by association index.
 *
 * Returns the achievable TX PHY rate in kilobits per second (KBPS)
 *
 * \note The units for this API are kilobits per second.  The reported achievable TX PHY rate typically ranges between 250000 and 600000.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA to be read. On the STA, this should be 0.
 * \param p_achievable_tx_phy_rate return parameter to receive the achievable RX PHY rate on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_achievable_tx_phy_rate \<WiFi interface\> \<association index\></c>
 *
 * Unless an error occurs, the output will be the achievable TX PHY rate in KBPS.
 */
extern int	qcsapi_wifi_get_achievable_tx_phy_rate_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_achievable_tx_phy_rate
);

/**
 * @brief Get Achievable RX PHY rate by association index.
 *
 * Returns the achievable RX PHY rate in kilobits per second (KBPS)
 *
 * \note The units for this API are kilobits per second.  The reported achievable RX PHY rate typically ranges between 250000 and 600000.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA RSSID is to be read. On the STA, this should be 0.
 * \param p_achievable_rx_phy_rate return parameter to receive the achievable RX PHY rate on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_achievable_rx_phy_rate \<WiFi interface\> \<association index\></c>
 *
 * Unless an error occurs, the output will be the achievable RX PHY rate in KBPS.
 */
extern int	qcsapi_wifi_get_achievable_rx_phy_rate_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			qcsapi_unsigned_int *p_achievable_rx_phy_rate
);

/**
 * @brief Get Signal to Noise Ratio (SNR) by association index.
 *
 * Returns the current SNR for the given association index.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA RSSID is to be read. On the STA, this should be 0.
 * \param p_snr return parameter to receive the SNR on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_snr \<WiFi interface\> \<association index\></c>
 *
 * Unless an error occurs, the output will be the current SNR.
 */
extern int	qcsapi_wifi_get_snr_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			int *p_snr
);

/**
 * @brief Get the associated device time per association index.
 *
 * Returns the time in seconds a STA has been associated with an AP.
 * This API can be applied to both station and AP mode.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA to be read. On the STA, this should be 0.
 * \param time_associated return parameter to contain the time associated on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_time_associated \<WiFi interface\> 0</c>
 *
 * The output will be the time in seconds that the STA has been associated with an AP.
 *
 * For the AP, the final parameter is
 *
 * <c>call_qcsapi get_time_associated \<WiFi interface\> \<association index\></c>
 *
 * The output will be the time in seconds that the STA at association index has been associated with an AP.
 */
extern int	qcsapi_wifi_get_time_associated_per_association(const char *ifname,
								const qcsapi_unsigned_int association_index,
								qcsapi_unsigned_int *time_associated );
/**
 * @brief Get a Parameter for a Node
 *
 * Returns the value of the selected parameter for the selected node.
 *
 * \param ifname \wifi0
 * \param node_index selects the node to report.
 * \param param_type the parameter type.  See the definition of the enun <c>qcsapi_per_assoc_param</c>.
 * \param local_remote_flag use local flag to get local parameters, use remote flag to get parameters from remote associated STA; set to <c>QCSAPI_LOCAL_NODE</c> or <c>QCSAPI_REMOTE_NODE</c>
 * \param input_param_str address to related request parameters, actual request structure information please refer to qcsapi_measure_request_param
 * \param report_result address to receive all kinds of results
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_node_param \<WiFi interface\> \<node index\> \<parameter name\> \<local remote flag\> \<paramteres indicated by type\></c>
 *
 * where <c>parameter name</c> is one of <c>link_quality</c>, <c>tx_phy_rate</c>,
 * <c>rx_phy_rate</c>, <c>rssi_dbm</c>, <c>snr</c>, <c>rssi</c>, <c>hw_noise</c>,
 * <c>soc_macaddr</c>, <c>bw</c>, <c>basic</c>, <c>cca</c>, <c>rpi</c>, <c>chan_load</c>,
 * <c>noise_histogram</c>, <c>beacon</c>
 *
 * The output will be the value for the selected parameter.  RSSI_DBM will be in dBm; SNR and RSSI will be in dB.
 */
extern int	qcsapi_wifi_get_node_param(
			const char *ifname,
			const uint32_t node_index,
			qcsapi_per_assoc_param param_type,
			int local_remote_flag,
			string_128 input_param_str,
			qcsapi_measure_report_result *report_result);
/**
 * @brief Get a Counter for a Node
 *
 * Returns the value of the selected counter for the selected node.
 *
 * \param ifname \wifi0
 * \param node_index selects the node to report.
 * \param counter_type the counter to select.  See the definition of the enun <c>qcsapi_counter_type</c>.
 * \param local_remote_flag use local flag to get local counters, use remote flag to get counters from remote associated STA; set to <c>QCSAPI_LOCAL_NODE</c> or <c>QCSAPI_REMOTE_NODE</c>
 * \param p_value address to receive the value of the parameter.  It must address a 64-bit quantity.
 *
 * \note Not all per-node counters are 64 bits wide.  Some will roll over when the maximum 32-bit value is reached.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_node_counter \<WiFi interface\> \<node index\> \<counter type\> \<local remote flag\></c>
 *
 * where <c>counter name</c> is as defined in the section on the Get Counter API.
 *
 * The output will be the value for the selected counter.
 */
extern int	qcsapi_wifi_get_node_counter(
			const char *ifname,
			const uint32_t node_index,
			qcsapi_counter_type counter_type,
			int local_remote_flag,
			uint64_t *p_value);
/**
 * @brief Get the Statistics (data structure of counters) for a Node
 *
 * Returns a data structure populated with statistics (counters) for a node.
 *
 * \param ifname \wifi0
 * \param node_index selects the node to report.
 * \param local_remote_flag use local flag to get local statistics, use remote flag to get statistics from remote associated STA; set to <c>QCSAPI_LOCAL_NODE</c> or <c>QCSAPI_REMOTE_NODE</c>
 * \param p_stats address of a <c>struct qcsapi_node_stats</c>
 *
 * \note See the definition of the Node Stats data struct for details on what
 * counters this API will return.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_node_stats \<WiFi interface\> \<node index\> \<local remote flag\> </c>
 *
 * The output will be the contents of the Node Stats data struct, one value per line.
 * The name of the field is also displayed.
 */
extern int	qcsapi_wifi_get_node_stats(
			const char *ifname,
			const uint32_t node_index,
			int local_remote_flag,
			struct qcsapi_node_stats *p_stats);

/**
 * @brief Get the Maximum Number of Packets That Were Queued for the Selected Node
 *
 * Returns the maxiumum number of packets that were queued for the selected node.
 *
 * \param ifname \wifi0
 * \param node_index selects the node to report.
 * \param local_remote_flag use local flag to get local max queued packets, use remote flag to get max queues packets from remote associated STA; set to <c>QCSAPI_LOCAL_NODE</c> or <c>QCSAPI_REMOTE_NODE</c>
 * \param reset_flag whether to reset the statistic on read. "1" to reset and "0" not to reset.
 * \param max_queued address of a 32-bit unsigned integer to receive the value
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_max_queued \<WiFi interface\> \<node index\> \<local remote flag\> \<reset flag\> </c>
 *
 * The output will be the maximum number of packets that were queued for the selected
 * node index.
 */
extern int	qcsapi_wifi_get_max_queued(
			const char *ifname,
			const uint32_t node_index,
			int local_remote_flag,
			int reset_flag,
			uint32_t *max_queued);

/**
 * @brief Get HW Noise per association index.
 *
 * Returns the current HW noise.
 *
 * \param ifname \wifi0
 * \param association_index On the AP this is the association index of the STA RSSID is to be read. On the STA, this should be 0.
 * \param p_hw_noise return parameter to contain the hw_noise on this association index.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_hw_noise \<WiFi interface\> \<association index\></c>
 *
 * The output will be the current HW noise for the association in the range.
 */
extern int	qcsapi_wifi_get_hw_noise_per_association(
			const char *ifname,
			const qcsapi_unsigned_int association_index,
			int *p_hw_noise);
/**@}*/


/**@addtogroup RegulatoryAPIs
 *@{*/

/*Transmit power by regulatory authority*/
/**
 * \brief Get the list of WiFi regulatory regions.
 *
 * Use this API to get a list of the regulatory regions supported by the current firmware.
 * String will contain a list of regions, each separated by a comma.
 *
 * \param list_regulatory_regions the string where the results are returned.
 *
 * \return -EFAULT on error, or 0.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_list_regulatory_regions \<WiFi interface\></c>
 *
 * The output will be the list of regulatory regions that the firmware supports.
 * Some listed regions may be synonyms, e.g. "Europe" and "eu" are synonyms as are "USA" and "us".
 */
extern int	qcsapi_wifi_get_list_regulatory_regions( string_128 list_regulatory_regions );
extern int	qcsapi_regulatory_get_list_regulatory_regions( string_128 list_regulatory_regions );

/**
 * \brief Get the List of Regulatory Channels.
 *
 * Use this API to get the list of channels authorized for use in the indicated regulatory region.
 * Bandwidth parameter should be either 20 or 40.  Valid channels are returned
 * in the <c>list_of_channels</c> parameter as a list of numeric values separated by commas.
 * This API is provided as a reference and a convenience; its use is not required to insure regulatory compliance.
 *
 * \param region_by_name the regulatory region for which the channel list is expected.
 * \param bw the bandwidth that is currently used. 40Mhz or 20Mhz.
 * \param list_of_channels the list of channels returned.
 *
 * \return -EFAULT, -EINVAL, -EOPNOTSUPP or other negative values on
 * error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_regulatory_channels \<region\> \<20 | 40></c>
 *
 * <c>call_qcsapi get_list_regulatory_channels \<region\> \<20 | 40></c>
 *
 * where <c>\<regulatory region\></c> should be one of the regions listed in by the get list
 * regulatory regions API / command.  Final parameter is the bandwidth and is optional.
 * If not present, the system will use the current configured bandwidth, defaulting to 40 if that cannot be established.
 * Output is the list of channels valid for that region separated by commas.
 *
 * Example:<br>
 * <c>call_qcsapi get_list_regulatory_channels EU</c>
 */
extern int	qcsapi_wifi_get_list_regulatory_channels(const char *region_by_name,
							 const qcsapi_unsigned_int bw,
							 string_1024 list_of_channels);
extern int	qcsapi_regulatory_get_list_regulatory_channels(const char *region_by_name,
							 const qcsapi_unsigned_int bw,
							 string_1024 list_of_channels);

extern int qcsapi_regulatory_get_list_regulatory_bands(const char *region_by_name, string_128 list_of_channels);

/**
 * \brief Get the Regulatory Transmit Power.
 *
 * This API call gets the transmit power in a regulatory region for a particular
 * channel.
 *
 * \param ifname \wifi0
 * \param the_channel the channel for which the tx power is returned.
 * \param region_by_name the regulatory region for which the tx power is returned.
 * \param p_tx_power the result which contains the transmit power.
 *
 * \return -EFAULT, -EOPNOTSUPP or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_regulatory_tx_power \<WiFi interface\> \<channel\> \<region\></c>
 *
 * Unless an error occurs, the output will be the channel number.
 * eg. 20<br>
 * Examples:<br>
 *   A valid call:
 * @code
 *	quantenna # call_qcsapi get_regulatory_tx_power wifi0 100 eu
 *	22
 * @endcode
 *   An invalid call:
 * @code
 *	quantenna # call_qcsapi get_regulatory_tx_power wifi0 188 eu
 *	QCS API error 22: Invalid argument
 * @endcode
 */
extern int	qcsapi_wifi_get_regulatory_tx_power(const char *ifname,
						    const qcsapi_unsigned_int the_channel,
						    const char *region_by_name,
						    int *p_tx_power);

extern int qcsapi_regulatory_get_regulatory_tx_power(const char *ifname,
	    const qcsapi_unsigned_int the_channel,
	    const char *region_by_name,
	    int *p_tx_power);

/**
 * \brief Get WiFi Configured TX power.
 *
 * This API call gets the configured transmit power in a regulatory region
 * for a particular channel.
 *
 * \param ifname \wifi0
 * \param the_channel the channel for which the tx power is returned.
 * \param region_by_name the regulatory region for which the tx power is returned.
 * \param bw the bandwidth that is currently used. 40Mhz or 20Mhz.
 * \param p_tx_power the result which contains the transmit power.
 *
 * \return -EFAULT, -EOPNOTSUPP or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_configured_tx_power \<WiFi interface\> &lt;channel&gt; &lt;region&gt;</c>
 *
 * Unless an error occurs, the output will be the channel number.
 * Examples:<br>
 * @code
 *	quantenna # call_qcsapi get_configured_tx_power wifi0 100 eu 40
 *	19
 *	quantenna # call_qcsapi get_configured_tx_power wifi0 100 eu 20
 *	19
 *	quantenna # call_qcsapi get_configured_tx_power wifi0 64 eu 40
 *	15
 *	quantenna # call_qcsapi get_configured_tx_power wifi0 64 eu 20
 *	15
 *	quantenna # call_qcsapi get_configured_tx_power wifi0 188 eu 20
 *	QCSAPI error 22: Invalid argument
 * @endcode
 * Note: Numeric TX power results are just examples.  Actual TX Power values may differ from what is shown above.
 */
extern int	qcsapi_wifi_get_configured_tx_power(const char *ifname,
						    const qcsapi_unsigned_int the_channel,
						    const char *region_by_name,
						    const qcsapi_unsigned_int bw,
						    int *p_tx_power);
extern int qcsapi_regulatory_get_configured_tx_power(const char *ifname,
							const qcsapi_unsigned_int the_channel,
							const char *region_by_name,
							const qcsapi_unsigned_int bw,
							int *p_tx_power);

/**
 * \brief Set the Regulatory Region.
 *
 * This API call sets the regulatory region on a given interface.
 *
 * \param ifname \wifi0
 * \param region_by_name the regulatory region.
 *
 * \return -EFAULT, -EOPNOTSUPP or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_regulatory_region \<WiFi interface\> \<region\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_regulatory_region(const char *ifname,
						  const char *region_by_name);
extern int	qcsapi_regulatory_set_regulatory_region(const char *ifname,
		  const char *region_by_name);
/**
 * \brief Get the Regulatory Region.
 *
 * This API call gets the regulatory region on a given interface.
 *
 * \param ifname \wifi0
 * \param region_by_name the regulatory region that is currently configured.
 *
 * \return -EFAULT or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_regulatory_region \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the '<c>&lt;region&gt;</c>'.
 */
extern int	qcsapi_wifi_get_regulatory_region(const char *ifname,
						  char *region_by_name);

/**
 * \brief Overwrite country code, mainly set speicfic country string
 * in country IE when EU region is used.
 *
 * This API call sets secific country code for EU region on a given interface.
 *
 * \param ifname \wifi0
 * \param curr_country_name the current country name.
 * \param new_country_name the specific country name.
 *
 * \return -EFAULT, -EOPNOTSUPP or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi overwrite_country_code \<WiFi interface\> \<curr_country_name\> \<new_country_name\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int qcsapi_regulatory_overwrite_country_code(const char *ifname,
	const char *curr_country_name, const char *new_country_name);
/**
 * \brief Set WiFi Regulatory Channel.
 *
 * This API call sets the transmit power adjusting the offset on a given channel
 * on a given region(should be current region) for the passed in interface.
 *
 * \param ifname \wifi0
 * \param the_channel the channel for which the tx power is returned.
 * \param region_by_name the regulatory region for which the tx power is modified
 * \param tx_power_offset the offset in integer from the currently configured tx power.
 *
 * \return -EOPNOTSUPP or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_regulatory_channel \<WiFi interface\> \<channel\> \<region\> \<offset\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_wifi_set_regulatory_channel(const char *ifname,
						   const qcsapi_unsigned_int the_channel,
						   const char *region_by_name,
						   const qcsapi_unsigned_int tx_power_offset);

extern int	qcsapi_regulatory_set_regulatory_channel(const char *ifname,
						   const qcsapi_unsigned_int the_channel,
						   const char *region_by_name,
						   const qcsapi_unsigned_int tx_power_offset);

/**
 * \brief Get regulatory database version number
 *
 * This API call gets the regulatory database version number
 *
 * \param p_version pointer to save version number
 * \param index - which version number will be retrieved
 *
 * \return -EOPNOTSUPP or other negative values on error, or 0 on success.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_regulatory_db_version [index]</c>
 *
 * Unless an error occurs, the output will be the version number.
 */
extern int qcsapi_regulatory_get_db_version(int *p_version, const int index);

/**@}*/


/*
 * DFS
 */
/**@addtogroup DFSAPIs
 *@{*/

/**
 * @brief Get the list of DFS channels
 *
 * Use this API to get a list of all channels that require following the DFS protocols,
 * or alternately a list of channels that do not require the DFS protocols.
 *
 * \param region_by_name the region to return. Has the same interpretation as with the regulatory authority APIs.
 * \param DFS_flag set to 1 to get a list of DFS affected channels, set to 0 to get the complement list of channels.
 * \param bw the bandwidth in use - either 20 or 40 to represent 20MHz and 40MHz respectively.
 * \param list_of_channels return parameter to contain the comma delimited list of channels.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_list_DFS_channels \<regulatory region\> \<1 | 0\> \<20 | 40\></c>
 *
 * where \<regulatory region\> should be one of the regions listed in by the get list regulatory
 * regions API/command.
 *
 * Choices for the other two parameters are as shown above.
 *
 * Unless an error occurs, the output will be a list of channels, each value separated by a comma.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 *
 * <b>Examples:</b>
 *
 * To get the list of 40 MHz channels that require following the DFS protocols for Europe, enter:
 *
 * <c>call_qcsapi get_list_DFS_channels eu 1 40</c>
 *
 * To get the list of 20 MHz channels that do not require DFS protocols for the US, enter:
 *
 * <c>call_qcsapi get_list_DFS_channels us 0 20</c>
 */
extern int	qcsapi_wifi_get_list_DFS_channels(const char *region_by_name,
						  const int DFS_flag,
						  const qcsapi_unsigned_int bw,
						  string_1024 list_of_channels);

extern int	qcsapi_regulatory_get_list_DFS_channels(const char *region_by_name,
						  const int DFS_flag,
						  const qcsapi_unsigned_int bw,
						  string_1024 list_of_channels);

/**
 * @brief Is the given channel a DFS channel.
 *
 * Use this API to determine whether a particular channel is subject to the DFS protocols.
 *
 * \param region_by_name the region to return. Has the same interpretation as with the regulatory authority APIs.
 * \param the_channel unsigned integer from 0 to 255. The channel must be valid for the referenced regulatory region.
 * \param p_channel_is_DFS return value which is set to 1 if the channel is affected by DFS, set to 0 otherwise.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi is_channel_DFS \<regulatory region\> \<channel\></c>
 *
 * where &lt;regulatory region&gt; should be one of the regions listed in by the get list regulatory
 * regions API / command and &lt;channel&gt; is an unsigned integer.
 *
 * Unless an error occurs, the output will be either 0 or 1 depending on
 * whether DFS protocols are required for the referenced channel.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_is_channel_DFS(const char *region_by_name,
					   const qcsapi_unsigned_int the_channel,
					   int *p_channel_is_DFS);

extern int	qcsapi_regulatory_is_channel_DFS(const char *region_by_name,
					   const qcsapi_unsigned_int the_channel,
					   int *p_channel_is_DFS);
/**
 * @brief Get previous and current channels from the most recent DFS channel change event
 *
 * This API returns the channel switched from and to as a result of the most recent DFS channel change event.
 *
 * \param ifname \wifi0
 * \param p_prev_channel result memory pointer for the channel switched from
 * \param p_cur_channel result memory pointer for the channel switched to
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_dfs_cce_channels \<WiFi interface\></c>
 *
 * The output will be the previous channel number then the current channel number, unless an error occurs. If no DFS channel change has occurred, both numbers will be zero.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_dfs_cce_channels(const char *ifname,
						 qcsapi_unsigned_int *p_prev_channel,
						 qcsapi_unsigned_int *p_cur_channel);

/**
 * \brief Get the alternative DFS channel to be used in case of radar
 * detection.
 *
 * This API call is used to get the alternative DFS channel that will be
 * switched over to in case radar is detected in the current channel.
 * This is known as a 'fast switch', to allow quickly changing to another
 * high power channel without having to do slow scans through all the
 * channels.
 *
 * \note This API can only be called on an AP device.
 *
 * \param ifname \wifi0
 * \param p_dfs_alt_chan return parameter for the alternative DFS channel.
 *
 * \return >= 0 on success, < 0 on error. On success, p_dfs_alt_chan will
 * contain the configured alternate DFS channel.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_DFS_alt_channel \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string containing the
 * DFS alternative channel (<c>0</c> if no alternative channel is specified).
 *
 * \sa qcsapi_wifi_set_DFS_alt_channel
 */
extern int qcsapi_wifi_get_DFS_alt_channel( const char *ifname, qcsapi_unsigned_int *p_dfs_alt_chan );

/**
 * \brief Set the alternative DFS channel to be used in case of radar
 * detection.
 **
 * This API call is used to set the alternative DFS channel that will be
 * switched over to in case radar is detected in the current channel.
 * This is known as a 'fast switch', to allow quickly changing to another
 * high power channel without having to do slow scans through all the
 * channels.
 *
 * \param ifname \wifi0
 * \param dfs_alt_chan the alternative DFS channel to set.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_DFS_alt_channel \<WiFi interface\> &lt;alternative channel&gt;</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * Error can occur if the alternative channel being set is the same as the
 * current channel on the device.
 *
 * \sa qcsapi_wifi_get_DFS_alt_channel
 */
extern int qcsapi_wifi_set_DFS_alt_channel( const char *ifname, const qcsapi_unsigned_int dfs_alt_chan );

/**
 * \brief Start a channel scan and select a best DFS channel for usage.
 *
 * This API is used to trigger a channel scan and once the scan is done, the AP will switch to a
 * DFS channel based on channel ranking algorithm.
 *
 * \param ifname \wifi0
 *
 * \callqcsapi
 *
 * <c>call_qcsapi start_dfsreentry \<WiFi interface\> </c>
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * Error can occur if all DFS channels have been in non-occupy list.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wifi_start_dfs_reentry(const char *ifname);

/**
 * \brief Start a channel scan and select channel based on given rules.
 *
 * This API provides a way to scan channel and select channel by different rules.<br>
 * The value of <c>scan_flag</c> specifies which channel set to choose and which algorithm to choose.
 * Flags used as channel set are defined as below and they are mutually-exclusive:<br>
 * @code
 *	IEEE80211_PICK_ALL		0x0001
 *	IEEE80211_PICK_DFS		0x0002
 *	IEEE80211_PICK_NONDFS		0x0004
 * @endcode
 *
 * Flags used as algorithm are defined as below and they are mutually-exclusive:<br>
 * @code
 *	IEEE80211_PICK_CLEAREST		0x0100
 *	IEEE80211_PICK_REENTRY		0x0200
 *	IEEE80211_PICK_NOPICK		0x0400
 *	IEEE80211_PICK_NOPICK_BG	0x0800
 * @endcode
 * <c>scan_flag</c> may be any combination of channel set and algorithm.
 * The header file <c>net80211/ieee80211_dfs_reentry.h</c> including this macros comes with the package libqcsapi_client_src.zip.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi start_scan wifi0 \<algorithm\> \<select_channel\> </c><br>
 * Where <c>\<algorithm\></c> should be "reentry", "clearest", "no_pick" or "background". "reentry" means it will start dfs-reentry function. "clearest" means it will pick the clearest channel.
 * "no_pick" means it will only perform channel scan. "background" means scan channel in the background and no_pick.
 *
 * Where <c>\<select_channel\></c> should be "dfs", "non_dfs" or "all". This parameter indicates that what kind of channel to be selected.
 * With using "dfs", It will pick channel from available dfs channels. With using "non-dfs", it will pick channel from available non-dfs channels.
 * And "all" is default which means it will pick channel from all available channels.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi start_scan wifi0 reentry dfs</c>
 */
extern int qcsapi_wifi_start_scan_ext(const char *ifname, const int scanflag);

/**
 * \brief Get channel switch history records
 *
 * This API reports back the channel change history up to a maximum of 32 records. This API can also reset the
 * records. As a get function, it need struct qcsapi_csw_record as a buffer to receive return data.
 *
 * \param ifname \wifi0
 * \param reset indicate whether to reset the records. "1" to reset records, and "0" to get records.
 * \param record where to store the records.
 *
 * \return >=0 on success, <0 on error.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_csw_records \<WiFi interface\> </c><br>
 * <c>call_qcsapi get_csw_records \<WiFi interface\> 1</c>
 *
 * For the first command, unless an error occurs, the output will be the channel change record count,
 * followed by a list of channel change records. For the second command, it output channel change history
 * then output string <c>"clear records complete"</c> at last.
 *
 * @code
 * #call_qcsapi get_csw_records wifi0 1
 * channel switch history record count : 2
 * time=11 channel=36
 * time=7 channel=40
 * clear records complete
 * @endcode
 */
extern int qcsapi_wifi_get_csw_records( const char *ifname, int reset, qcsapi_csw_record *record);

/**
 * \brief Get channel radar status and history of detected records
 *
 * This API is used to query the status of a DFS channel; whether it is in non-occupy list, and how many times
 * the radar signal has be detected on this channel. This data can be used to analyse the local enviroment for radar usage.
 *
 * \param ifname \wifi0
 * \param rdstatus when used as input,it contain channel to query, when used as return value, it stores the radar channel status.
 *
 * \return >=0 on success, <0 on error.
 * \note The channel passed in the rdstatus structure must be DFS affected, based on the regulatory region.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_radar_status \<WiFi interface\> \<DFS-Channel\> </c><br>
 *
 * Unless an error occurs, the output will show the radar status of <c>DFS-Channel</c>.<br>
 * Example:
 *
 * @code
 * #call_qcsapi get_radar_status wifi0 100
 * channel 100:
 * radar_status=0
 * radar_count=1
 * @endcode
 */
extern int qcsapi_wifi_get_radar_status(const char *ifname, qcsapi_radar_status *rdstatus);
/**@}*/

/* Reporting the results of an AP scan */
/**@addtogroup ScanAPIs
 *@{*/

/**
 * @brief Get the results of an AP scan.
 *
 * This API gets the results of the most recent AP scan and caches them in memory for future reference.
 *
 * \param ifname \wifi0
 * \param p_count_APs return parameter to contain the count of the number of AP scan results.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_results_AP_scan \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the number of APs found in the last scan.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_results_AP_scan( const char *ifname, qcsapi_unsigned_int *p_count_APs );

/**
 * \brief Get a count of the number of APs scanned.
 *
 * This API call is used to get the count of APs that have been scanned in the
 * most recent channel scan.
 *
 * \param ifname \wifi0
 * \param p_count_APs return parameter to contain the count of APs that have
 * been scanned in the most recent scan.
 *
 * \return >= 0 on success, < 0 on error. If success, p_count_APs contains a
 * count of the number of APs scanned in the previous scan.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_count_APs_scanned \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the number of APs that were
 * scanned in the previous channel scan.
 */
extern int	qcsapi_wifi_get_count_APs_scanned( const char *ifname, qcsapi_unsigned_int *p_count_APs );

/**
 * @brief Get AP properties per scan result.
 *
 * This API reports on the properties of an AP, with the AP indentified by index.
 * The index is numbered starting at 0.
 *
 * If the cache of AP scan results is not present, this API will call the Get Results AP Scan to update the cache.
 *
 * \param ifname \wifi0
 * \param index_AP the index to get the result from.
 * \param p_ap_properties return parameter for storing the AP scan properties.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_properties_AP \<WiFi interface\> \<index\></c>
 *
 * Unless an error occurs, the output will be the properties of the referenced AP,
 * in the order of SSID, MAC address, WiFi channel, RSSI, flags, protocol,
 * authentication mode and encryption mode. The SSID is enclosed in quotes since it can have embedded blanks.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.<br>
 *
 * Example output from call_qcsapi:
 *
 * @code
	quantenna # call_qcsapi get_properties_AP wifi0 0
	"FAE-Lab-10" c0:3f:0e:7d:5a:dc 40 25 0 0 0 0
	quantenna #@endcode
 *
 * This AP has "FAE-Lab-10" as its SSID (the SSID is enclosed in quotes since an
 * SSID can have embedded blank characters), MAC address of c0:3f:03:7d:51:dc,
 * is broadcasting on WiFi channel 40 (5.2 GHz), with an RSSI of 25.  Security is disabled for the AP.
 *
 * @code
	quantenna # call_qcsapi get_properties_AP wifi0 2
	"rlasater" 00:26:86:00:11:5f 60 56 1 2 1 2
	quantenna #@endcode
 *
 * This AP has "rlasater" as its SSID, MAC address of 00:26:86:00:11:5f,
 * is broadcasting on WiFi channel 60 (5.3 GHz), with an RSSI of 56.
 * Security is enabled for this AP.  The security protocol is WPA2 (11i);
 * the authentication mode is PSK; and the encryption mode is CCMP.
 *
 * @code
	quantenna # call_qcsapi get_properties_AP wifi0 4
	QCS API error 34: Parameter value out of range
	quantenna #@endcode
 * When the index becomes too large, the call_qcsapi command will fail as shown above.
 * In this setup, only 4 APs were found in the scan.  Since the index is numbered starting at 0,
 * valid index values here are 0, 1, 2 and 3.<br>
 *
 * \note The Get Properties API uses the results it finds in the in-memory cache.
 * To ensure the results from the latest AP scan are used,
 * an application should always call the Get Results AP Scan API first.
 * The example application shows how this should be programmed.
 *
 * \sa qcsapi_ap_properties
 */
extern int	qcsapi_wifi_get_properties_AP(
			const char *ifname,
			const qcsapi_unsigned_int index_AP,
			qcsapi_ap_properties *p_ap_properties
);
/**@}*/


/*
 * APIs relating to STA backoff in the event security parameters do not match those on the partner AP.
 */
/**@addtogroup SecurityMisAPIs
 *@{*/

/**
 * @brief Configure the retry backoff failure maximum count.
 *
 * Sets the number of times an association attempt can fail before backing off.
 *
 * \note This API is only valid on an STA.
 *
 * \param ifname \wifi0
 * \param fail_max the maximum number of failures permitted. The parameter can range from 2 to 20. The default failure value is 3.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi backoff_fail_max \<WiFi interface\> \<max failure count\></c>
 *
 * Example:
 *
 * <c>call_qcsapi backoff_fail_max wifi0 3</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_backoff_fail_max(  const char *ifname, const int fail_max );

/**
 * @brief Configure retry backoff timeout.
 *
 * Configures the time to wait in seconds after backing off before attempting to associate again.
 *
 * \note This API is only valid on an STA.
 *
 * \param ifname \wifi0
 * \param timeout the timeout between backoff and attempting a reconnection. Range is between 10 and 300 seconds. Default value
 * is 60 seconds.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi backoff_timeout \<WiFi interface\> \<timeout\></c>
 *
 * Example:
 *
 * <c>call_qcsapi backoff_timeout wifi0 60</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_backoff_timeout(  const char *ifname, const int timeout );
/**@}*/

/**@addtogroup EngineeringAPIs
 *@{*/

/**
 * @brief Get the current MCS rate.
 *
 * Get the current MCS rate.
 *
 * Value will be a string with format "MCSn" or "MCSnn",
 * where n or nn is an integer in ASCII format from 0 to 76, excluding 32.
 * For 11ac rate, the value will be string with format "MCSx0y",
 * where x is from 1 to 4, and y is from 0 to 9. x means Nss (number of spatial stream) and y
 * mean MCS index.
 *
 * If the autorate fallback option has been selected, this API will return Configuration Error.
 *
 * This API only returns an actual MCS rate if the set MCS rate API has been called to select a particular MCS rate.
 *
 * \param ifname \wifi0
 * \param current_mcs_rate return parameter for storing the current MCS rate.
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_mcs_rate \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be an MCS index string, e.g. for 11n,
 * <c>MCS0, MCS8, MCS76</c>, for 11ac, <c>MCS100, MCS307</c> etc, or
 * <c>Configuration Error</c> if the auto rate fallback option has been selected.
 *
 * This command can return incorrect results if the rate has never been configured.
 */
extern int qcsapi_wifi_get_mcs_rate(const char *ifname,
		qcsapi_mcs_rate current_mcs_rate);

/**
 * @brief Set the MCS rate.
 *
 * Set the current MCS rate.
 * For 11n rate, value is required to be a string with format "MCSn" or "MCSnn",
 * where n or nn is an integer in ASCII format from 0 to 76, excluding 32. Leading zeros are NOT permitted;
 * the string "MCS01" will not be accepted.
 * For 11ac rate, value is required to be a string with format
 * "MCSx0y", where x means Nss (number of spatial streams) and y means MCS index, the possible value are
 * 100 ~ 109, 200 ~ 209, 300 ~ 309, 400 ~ 409.
 * This API cannot be used to configure auto rate fallback;
 * use the Set Option API with qcsapi_autorate_fallback as the option to select auto rate fallback.
 * This API is only available on the primary WiFi interface.
 *
 * \note To set an 802.11n MCS on a VHT capable device, you must first set the bandwidth to 20MHz or 40MHz.
 * \sa qcsapi_wifi_set_bw
 *
 * \note This API should only be used to evaluate the performance of a particular MCS (modulation and coding) index.
 * Using it in a production application (i.e. with the end-user) can result in unexpectedly poor performance,
 * either lower than expected transfer rates or a failure to associate.
 * Use of the auto rate fallback option is strongly recommended.
 *
 * If option autorate fallback is enabled, this API will disable it as a side effect.
 *
 * \param ifname \wifi0
 * \param new_mcs_rate the new MCS rate to use (fixed rate).
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_mcs_rate \<WiFi interface\> \<MCS index string\></c>
 *
 * where \<MCS index string\> is an MCS index string.
 *
 * See the description of the API itself for the expected format of the MCS index string.
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * \note This command cannot be used to configure the auto rate fallback option;
 * use call_qcsapi set_option with autorate as the option for that purpose.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_set_mcs_rate( const char *ifname, const qcsapi_mcs_rate new_mcs_rate );

/**
 * @brief Set pairing ID for pairing protection
 *
 * Set pairing ID for use of pairing protection
 *
 * \note This API only works on an AP.
 *
 * The pairing ID is a 32 characters' string
 *
 * \param ifname \wifi0
 * \param pairing_id a 32 characters' string used for pairing protection.
 *
 * \return 0 if the command succeeded and the pairing ID is updated.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_pairing_id \<WiFi interface\> \<pairing ID\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_set_pairing_id(const char *ifname, const char *pairing_id);

/**
 * @brief Get pairing ID for pairing protection
 *
 * Get pairing ID which is for use of pairing protection
 *
 * \note This API only works on an AP.
 *
 * The pairing ID is a 32 characters' string
 *
 * \param ifname \wifi0
 * \param pairing_id a 32 characters' string used for pairing protection.
 *
 * \return 0 if the pairing ID is fetched.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_pairing_id \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string of pairing ID.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_pairing_id(const char *ifname, char *pairing_id);

/**
 * @brief Set pairing enable flag for pairing protection
 *
 * enable/disable the pairing protection
 *
 * \note This API only works on an AP.
 *
 * \param ifname \wifi0
 * \param enable Enabling flag of the pairing protection.
 *
 * \return 0 if the command succeeded and the pairing enable flag is updated.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_pairing_enable \<WiFi interface\> \<pairing enable flag\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_set_pairing_enable(const char *ifname, const char *enable);

/**
 * @brief Get pairing enable flag for pairing protection
 *
 * Get pairing enable flag which is for enabling pairing protection
 *
 * \note This API only works on an AP.
 *
 * The pairing enable flag is "0" or "1"
 *
 * \param ifname \wifi0
 * \param enable a string used for enabling pairing protection.
 *
 * \return 0 if the enable flag is fetched.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_pairing_enable \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string of enable flag
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_get_pairing_enable(const char *ifname, char *enable);

/**
 * @brief Set non_WPS pairing ptrotection enable flag for pairing protection
 *
 * Set non_WPS pairing enable flag which is for enabling pairing protection
 *
 * The pairing enable flag is "0" or "1"
 *
 * \param ifname \wifi0
 * \param ctrl_state a string used for enabling non WPS pairing protection.
 *
 * \return 0 if the enable flag is set.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_non_wps_pp_enable \<WiFi interface\> \<value\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_non_wps_set_pp_enable(const char *ifname, uint32_t ctrl_state);

/**
 * @brief Get non_WPS pairing ptrotection enable flag for pairing protection
 *
 * Get non_WPS pairing enable flag which is for enabling pairing protection
 *
 * The pairing enable flag is "0" or "1"
 *
 * \param ifname \wifi0
 * \param ctrl_state a string used for getting the non WPS pairing protection status.
 *
 * \return 0 if the enable flag is fetched.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_non_wps_pp_enable \<WiFi interface\></c>
 *
 * Unless an error occurs, the output will be the string of enable flag
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_non_wps_get_pp_enable(const char *ifname, uint32_t *ctrl_state);

/**
 * @brief Set various fix items for compatibility issue with other vendor chipset.
 *
 * Set various fix items for compatibility issue with other vendor chipset.
 *
 * \param ifname \wifi0
 * \param fix_param the param to enable or disable the fix.
 * \param value enable(1) or disable(0) the fix.
 *
 * \return 0 if the enabling or disabling the fix is successful.
 * \return A negative value if an error occurred.  See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * <b><c>call_qcsapi</c> interface:</b>
 *
 * <c>call_qcsapi set_vendor_fix \<WiFi interface\> \<fix-param\> \<value\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_wifi_set_vendor_fix(const char *ifname, int fix_param, int value);

/**
 * @brief Convert a numeric error code to a descriptive string
 *
 * Given a numeric error code, convert to a human readable string. This wills for conventional negative errno values, as well as QCSAPI negative error values (<= -1000).
 *
 * \param qcsapi_retval a negative error value to find the associated string of
 * \param error_msg memory for result storage
 * \param msglen length of <i>error_msg</i> buffer in bytes, including the null terminator
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_error_message \<errno\></c>
 *
 * where \<errno\> is a negative error value
 *
 * Output will be the requested error message, or the relevant error message if an error occurs.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_errno_get_message( const int qcsapi_retval, char *error_msg, unsigned int msglen );
/**@}*/

/**@addtogroup StatisticsAPIs
 *@{*/
/**
 * \brief Get statistics data of an interface.
 *
 * This API call is used to get interface statistics data.
 *
 * \param ifname \wifi0
 * \param stats return parameter to contain the statistics data of the interface being queried.
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 * the statistics data retrieved from the device for the interface.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_interface_stats &lt;interface name&gt;</c>
 *
 * Unless an error occurs, the output will be the statistics data of the interface.
 */
extern int	qcsapi_get_interface_stats( const char *ifname, qcsapi_interface_stats *stats );
/**@}*/

/**@addtogroup StatisticsAPIs
 *@{*/
/**
 * \brief Get latest PHY statistics data of an interface
 *
 * This API call is used to get latest PHY statistics data.
 *
 * \param ifname \wifi0
 * \param stats return parameter to contain the statistics data of the interface being queried.
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 * the PHY statistics data retrieved from the device for the interface.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_phy_stats &lt;interface name&gt;</c>
 *
 * Unless an error occurs, the output will be the PHY statistics data of the interface.
 */
extern int	qcsapi_get_phy_stats( const char *ifname, qcsapi_phy_stats *stats );
/**@}*/

/**@addtogroup StatisticsAPIs
 *@{*/
/**
 * \brief Reset statistics data of an interface.
 *
 * This API call is used to reset interface statistics data.
 *
 * \param ifname \wifi0
 * \param node_index selects the node to operate, it's valid in AP mode when local_remote_flag is set to <c>QCSAPI_REMOTE_NODE</c>.
 * \param local_remote_flag use local flag to reset local all counters, use remote flag to reset all counters on the remote associated STA; set to <c>QCSAPI_LOCAL_NODE</c> or <c>QCSAPI_REMOTE_NODE</c>
 *
 * \return >= 0 on success, < 0 on error. If success,the statistics data
 * of the interface will be cleared.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi reset_all_stats \<WiFi interface\> \<node_index\> \<QCSAPI_LOCAL_NODE/QCSAPI_REMOTE_NODE\></c>
 *
 */
extern int	qcsapi_reset_all_counters( const char *ifname, const uint32_t node_index, int local_remote_flag );
/**@}*/

/**@addtogroup FirmwareAPIs
 *@{*/

/**
 * @brief Get the version of the firmware running on the device.
 *
 * This API reports the version of the firmware running on the device.
 *
 * \param firmware_version return parameter string to contain the firmware version.
 * \param version_size the size of the buffer firmware_version.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_firmware_version</c>
 *
 * Unless an error occurs, the output will be the version of the firmware currently running on the device.
 * It is not necessary to specify the version size parameter; it will default to 40 (characters).
 */
extern int	qcsapi_firmware_get_version( char *firmware_version, const qcsapi_unsigned_int version_size );

/**
 * @brief Update an image partition with the requested image.
 *
 * This API updates either the live or safety partition with a new image. The image is checked to be for the appropriate architecture and checksummed before writing to flash.
 *
 * \param image_file path to the new firmware image in the filesystem
 * \param partition_to_upgrade either the live or safety partition
 *
 * \callqcsapi
 *
 * <c>call_qcsapi flash_image_update \<path\> \<live|safety\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int	qcsapi_flash_image_update( const char *image_file, qcsapi_flash_partiton_type partition_to_upgrade );

/**
 * @brief Set the mac addr of the SOC board.
 *
 * This API sets the SOC's mac addr of the STB to the wlan, then the mac addr will be stored for use.
 *
 * \param ifname the interface to perform the action on.
 * \param soc_mac_addr the mac addr to set
 *
 * <b><c>call_qcsapi</c> interface:</b>
 *
 * <c>call_qcsapi set_soc_macaddr \<WIFI interface\> \<soc mac addr\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int qcsapi_set_soc_mac_addr(const char *ifname, qcsapi_mac_addr soc_mac_addr);

/**
 * @brief Get a custom value.
 *
 * This API returns the value of a custom key contained in a file named <c>/etc/custom/<i>key</i></c>.
 *
 * \note The filename must not have the substring '..' as any part or the filename
 * will be rejected as invalid.
 *
 * \param custom_key The custom key name
 * \param custom_value A buffer in which to store the returned value, which must be at least 129 bytes.
 * The value will be truncated if longer than 128 characters.
 *
 * \return 0 if the custom key is valid and contians a valid value
 * \return -qcsapi_configuration_error if the custom key has not been defined
 * \return -qcsapi_configuration_error if the key includes the string ".."
 * \return -qcsapi_configuration_error if the custom key value is an empty string
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_custom_value \<key\></c>
 *
 * Unless an error occurs, the output will be the custom key value.
 */
extern int qcsapi_get_custom_value(const char *custom_key, string_128 custom_value);

/**
 * @brief Get a MLME statistics record.
 *
 * This API returns the mlme statistics record for specified mac address.
 *
 * \param ifname the interface to perform the action on.
 * \param client_mac_addr the mac addr of the client. 00:00:00:00:00:00 should be used
 * to get mlme stats for clients who were not associated with an AP.
 * \param stats address of a <c>struct qcsapi_mlme_stats</c>
 *
 * \note This API is only available on AP mode and the primary WiFi interface.
 *
 * \return 0 if the stats record for required mac address exists.
 * \return -qcsapi_mlme_stats_not_supported if statistics facility is not suported.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_mlme_stats_per_mac \<mac_addr\></c>
 *
 * Unless an error occurs, the output will be the mlme statistics for specified mac.
 */
extern int qcsapi_wifi_get_mlme_stats_per_mac(const char *ifname, const qcsapi_mac_addr client_mac_addr, qcsapi_mlme_stats *stats);

/**
 * @brief Get a MLME statistics record.
 *
 * This API returns the mlme statistics record for specified association index.
 *
 * \param ifname the interface to perform the action on.
 * \param association_index the association index to get mlme statistics about
 * \param stats address of a <c>struct qcsapi_mlme_stats</c>
 *
 * \note This API is only available on AP mode and the primary WiFi interface.
 *
 * \return 0 if the stats record for required association index address exists.
 * \return -qcsapi_mlme_stats_not_supported if statistics facility is not suported.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_mlme_stats_per_association \<association index\></c>
 *
 * Unless an error occurs, the output will be the mlme statistics for specified association index.
 */
extern int qcsapi_wifi_get_mlme_stats_per_association(const char *ifname, const qcsapi_unsigned_int association_index, qcsapi_mlme_stats *stats);

/**
 * @brief Get a list of macs addresses.
 *
 * This API returns the list of macs currently existing in mlme statistic factory.
 *
 * \param ifname the interface to perform the action on.
 * \param macs_list address of a <c>struct qcsapi_mlme_stats_macs</c>
 *
 * \note This API is only available on AP mode and the primary WiFi interface.
 *
 * \return 0 if the list obtained successfully.
 * \return -qcsapi_mlme_stats_not_supported if statistics facility is not suported.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_mlme_stats_macs_list</c>
 *
 * Unless an error occurs, the output will be the list of the mac addresses existing in mlme statistics table.
 */
extern int qcsapi_wifi_get_mlme_stats_macs_list(const char *ifname, qcsapi_mlme_stats_macs *macs_list);

/**@}*/


/**@addtogroup PowerAPIs
 *@{*/

/**
 * @brief Set power save setting
 *
 * Set the current power save setting
 *
 * \param mode new power save setting. Valid values are:
 *	<ul>
 *		<li><i>QCSAPI_PM_MODE_DISABLE</i> - Disable all power saving features</li>
 *		<li><i>QCSAPI_PM_MODE_AUTO</i> - Automatic; power saving will adjust itself based on associated stations, traffic levels etc </li>
 *		<li><i>QCSAPI_PM_MODE_SUSPEND</i> - Suspend all operations
 *	</ul>
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi pm \<off|on|auto|suspend\></c>
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int	qcsapi_pm_set_mode(int mode);

/**
 * @brief Get power save setting
 *
 * Get the current power save setting. This is related to the SoC power saving, not 802.11 power saving.
 *
 * \param mode pointer to where the current power save setting value should be stored.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi pm</c>
 *
 * Unless an error occurs, the output will be the current value of power save setting from a list \<off|auto|suspend\>.
 */
extern int	qcsapi_pm_get_mode(int *mode);

#define QCSAPI_PM_MODE_DISABLE	BOARD_PM_LEVEL_FORCE_NO
#define QCSAPI_PM_MODE_AUTO	-1
#define QCSAPI_PM_MODE_SUSPEND	BOARD_PM_LEVEL_SUSPEND

/**@}*/

/**@addtogroup vsp_group
 *@{*/

/**
 * \brief Get VSP status
 *
 * This API obtains VSP runtime status and flags
 *
 * \param ifname \wifi0
 * \param param item to query status of. Valid values are:
 * 	\li QVSP_STATE_ENABLE - query whether vsp is enabled
 *	\li QVSP_STATE_FAT - query most recently reported free air time
 * \param value result memory
 *
 * \return 0 on success, negative on error.
 */
extern int	qcsapi_vsp_get_state(const char *ifname, unsigned int param, unsigned int *value);

/**
 * \brief Get all VSP status
 *
 * This API obtains all VSP runtime status and flags with 1 invocation
 *
 * \param ifname \wifi0
 * \param value pointer to an array of unsigned ints for value storage
 * \param max maximum number of unsigned ints to return, typically QVSP_STATE_READ_MAX
 *
 * \return 0 on success, negative on error.
 */
extern int	qcsapi_vsp_get_state_all(const char *ifname, unsigned int *value, unsigned int max);

/**
 * \brief Set VSP status
 *
 * This API handles VSP enable/disable, test settings and reset
 *
 * \param ifname \wifi0
 * \param param item to query status of. Valid values are:
 * 	\li QVSP_STATE_ENABLE - enable (value nonzero) / disable (value zero) VSP
 * 	\li QVSP_STATE_RESET - reset VSP stream accounting (value unused)
 * 	\li QVSP_STATE_TEST_FAT - set a FAT value in order to simulate undersubscription or oversubscription (value is FAT to set)
 * \param value context dependant parameter value
 *
 * Parts of this API can be called via <c>call_qcsapi</c>.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> enable</c>
 * <c>call_qcsapi vsp <ifname> disable</c>
 * <c>call_qcsapi vsp <ifname> reset</c>
 * <c>call_qcsapi vsp <ifname> test fat <value></c>
 */
extern int	qcsapi_vsp_set_state(const char *ifname, unsigned int param, unsigned int value);

/**
 * \internal
 * \brief Get VSP config option
 *
 * This API obtains VSP configuration options
 *
 * \param ifname \wifi0
 * \param param configuration option to query
 * \param value result memory
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> get <param></c>
 *
 * This will print the parameter obtained if successful, or an error message on failure.
 */
extern int	qcsapi_vsp_get_config(const char *ifname, unsigned int param, unsigned int *value);

/**
 * \internal
 * \brief Get all VSP config options
 *
 * This API stores all VSP configuration options into an array
 *
 * \param ifname \wifi0
 * \param value pointer to an array of unsigned ints for value storage
 * \param max maximum number of unsigned ints to return, typically QVSP_STATE_READ_MAX
 *
 * \return 0 on success, negative on error.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> show config</c> will call this API, and some others.
 *
 * Unless an error occurs, the output will be all configuration options, all whitelist entries and all rules.
 */
extern int	qcsapi_vsp_get_config_all(const char *ifname, unsigned int *value, unsigned int max);

/**
 * \internal
 * \brief Set VSP config option
 *
 * This API sets VSP configuration options
 *
 * \param ifname \wifi0
 * \param param configuration option to modify
 * \param value value to set
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> set <param> <value></c>
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */
extern int	qcsapi_vsp_set_config(const char *ifname, unsigned int param, unsigned int value);

/**
 * \internal
 * \brief Add a VSP whitelist entry
 *
 * Add a VSP whitelist entry
 *
 * \param ifname \wifi0
 * \param entry memory containing whitelist entry to add
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> wl add <saddr>[/<smask>] <sport> <daddr>[/<dmask>] <dport></c>
 *
 * Where <saddr>[/<smask>] is an ipv4 dotted quad, with an optional CIDR notation netmask.
 * <sport> is the stream TCP/UDP source port, <daddr>[/<dmask>] is the stream destination address/netmask,
 * and <dport> is the stream TCP/UDP destination port.
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */
extern int	qcsapi_vsp_add_wl(const char *ifname, const struct qvsp_wl_flds *entry);

/**
 * \internal
 * \brief Delete a VSP whitelist entry
 *
 * Delete a VSP whitelist entry
 *
 * \param ifname \wifi0
 * \param entry memory containing whitelist entry to delete
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> wl del <saddr>[/<smask>] <sport> <daddr>[/<dmask>] <dport></c>
 *
 * Where <saddr>[/<smask>] is an ipv4 dotted quad, with an optional CIDR notation netmask.
 * <sport> is the stream TCP/UDP source port, <daddr>[/<dmask>] is the stream destination address/netmask,
 * and <dport> is the stream TCP/UDP destination port.
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */
extern int	qcsapi_vsp_del_wl(const char *ifname, const struct qvsp_wl_flds *entry);

/**
 * \internal
 * \brief Delete a VSP whitelist entry by index
 *
 * Delete a VSP whitelist entry by index
 *
 * \param ifname \wifi0
 * \param index index of the entry to delete, starting from 1
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> wl del <index>
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */
extern int	qcsapi_vsp_del_wl_index(const char *ifname, unsigned int index);

/**
 * \internal
 * \brief Read VSP whitelist entries
 *
 * Read VSP whitelist entries
 *
 * \param ifname \wifi0
 * \param entries an array of whitelist structures for result storage
 * \param max_entries the length of the array passed in 'entries'
 *
 * \return Number of whitelist entries currently configured on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> show config</c> will call this API, and some others.
 *
 * Unless an error occurs, the output will be all configuration options, all whitelist entries and all rules.
 */
extern int	qcsapi_vsp_get_wl(const char *ifname, struct qvsp_wl_flds *entries, unsigned int max_entries);

/**
 * \internal
 * \brief Add VSP rule
 *
 * Add a VSP rule. Rules determine which streams to drop in an oversubscription event.
 *
 * \param ifname \wifi0
 * \param entry rule to add
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> rule add <p1> <v1> [<pn> <vn>]...</c>
 *
 * Where <p1> <v1> are rule parameter name/value pairs. Many pairs can be used in one rule.
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */
extern int	qcsapi_vsp_add_rule(const char *ifname, const struct qvsp_rule_flds *entry);

/**
 * \internal
 * \brief Delete VSP rule
 *
 * Delete a VSP rule.
 *
 * \param ifname \wifi0
 * \param entry rule to delete
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> rule add <p1> <v1> [<pn> <vn>]...</c>
 *
 * Where <p1> <v1> are rule parameter name/value pairs. Many pairs can be used in one rule.
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */
extern int	qcsapi_vsp_del_rule(const char *ifname, const struct qvsp_rule_flds *entry);

/**
 * \internal
 * \brief Delete a VSP rule by index
 *
 * Delete a VSP rule by index
 *
 * \param ifname \wifi0
 * \param index index of the entry to delete, starting from 1
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> rule del <index>
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */
extern int	qcsapi_vsp_del_rule_index(const char *ifname, unsigned int index);

/**
 * \internal
 * \brief Read VSP rules
 *
 * Read VSP rules
 *
 * \param ifname \wifi0
 * \param entries an array of rule structures for result storage
 * \param max_entries the length of the array passed in 'entries'
 *
 * \return Number of rules currently configured on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> show config</c> will call this API, and some others.
 *
 * Unless an error occurs, the output will be all configuration options, all whitelist entries and all rules.
 */
extern int	qcsapi_vsp_get_rule(const char *ifname, struct qvsp_rule_flds *entries, unsigned int max_entries);

/**
 * \internal
 * \brief Read VSP streams
 *
 * Read VSP streams
 *
 * \param ifname \wifi0
 * \param entries an array of stream structures for result storage
 * \param max_entries the length of the array passed in 'entries'
 * \param show_all show all streams
 *
 * \return Number of streams currently configured on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> show [all]</c> will call this API, and some others.
 *
 * Unless an error occurs, the output will be status, and current high throughput streams. Usage of the argument 'all' adds low throughput streams.
 */
extern int	qcsapi_vsp_get_strm(const char *ifname, struct qvsp_strm_info *strms,
					unsigned int max_entries, int show_all);

/**
 * \internal
 * \brief Read VSP statistics
 *
 * Read VSP statistics
 *
 * \param ifname \wifi0
 * \param stats result memory
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> show stats</c>
 *
 * The output will show various statistics on success, and an error message on failure.
 */
extern int	qcsapi_vsp_get_stats(const char *ifname, struct qvsp_stats *stats);

/**
 * \internal
 * \brief Read VSP inactive flags
 *
 * Read VSP inactive flags
 *
 * \param ifname \wifi0
 * \param flags result memory
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi vsp <ifname> show</c>
 *
 * The output will show the inactive reason if VSP is inactive.
 */
extern int qcsapi_vsp_get_inactive_flags(const char *ifname, unsigned long *flags);

/**@}*/


/**@addtogroup invoke_script
 *@{*/

/**
 * \brief API of scripts for EMI testing and RF testing
 *
 * This function is used to call a script on the board. This API should be used when device
 * is configured to calstate=1 mode. The following scripts are supported:
 *
 * <b>set_test_mode</b><br>
 * This script is used to configure the packet type.<br>
 * <c>set_test_mode <Channel> <Antenna> \<MCS Level\> <BW> <Size> <11n signal> <BF> </c><br>
 * Channel: channel number of the center frequency<br>
 * Antenna: 127 - 4 chanis on, 113 - chain 1 on, 116 - chain3 on, 120 - chain 4 on.<br>
 * MCS level: MCS# of packet transmitted<br>
 * BW: 20 or 40 in MHz units.<br>
 * Size: packet size in 100bytes units, it should be a number smaller than 40 and bigger than 0<br>
 * 11n signal: 1 - 11n, 0 - 11a.<br>
 * BF: 0 default.
 *
 * <b>send_test_packet</b><br>
 * Start to transmit packet. Please note that before calling this script, test mode should be set by
 * script <c>set_test_mode</c><br>
 * <c>send_test_packet <number></c><br>
 * number: How many(number*1000) packets will be sent.
 *
 * <b>stop_test_packet</b><br>
 * stop sending packet.
 *
 * <b>set_tx_pow x</b><br>
 * set the packet output power to xdBm where x can vary depending on the front end device.
 *
 * <b>send_cw_signal</b><br>
 * Generate CW tone for different channels for frequency offset measurement.<br>
 * <c>send_cw_signal <channel> <chain> \<CW pattern\> <tone> <sideband></c><br>
 * channel: channel number like 36, 40, 44, ...<br>
 * chain: the value are 2 separate numbers.
 *  - 0 0 - chain1
 *  - 0 2 - chain2
 *  - 1 0 - chain3
 *  - 1 2 - chain4
 *
 * CW pattern:
 *  - 0 - 625KHz with 0 dBFS power
 *  - 1 - 625KHz with -3 dBFS power
 *  - 2 - 1MHz with 0 dBFS power
 *  - 3 - 1MHz with -3dBFS power
 *
 * <b>stop_cw_signal</b><br>
 * stop the CW tone.
 *
 * <b>send_cw_signal_4chain</b><br>
 * Generate CW tone for different channels and send signal using all four chains, or stop the CW tone.<br>
 * <c>send_cw_signal_4chain { start \<channel\> | stop } </c><br>
 *
 * <b>show_test_packet</b><br>
 * show information about test packet.
 *
 * \param scriptname the name of the script file
 * \param param parameters used by the script
 *
 * \return 0 on success, negative on error.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi run_script \<scriptname\> \<parameters\></c>
 *
 * The output will be silent on success, or an error message on failure.
 *
 * Example:<br>
 * <c>call_qcsapi run_script set_test_mode 36 127 15 20 40 1 0</c>
 */
extern int qcsapi_wifi_run_script(const char *scriptname, const char *param);

/**@}*/


/**@addtogroup WiFiAPIs
 *@{*/

/**
 * @brief Start/Stop test traffic.
 *
 * Start/Stop test traffic (null or qos null packets) on specified WiFi interface.
 *
 * \param ifname \wifi0
 * \param period Period interval for sending test traffic in milliseconds. 0 means disable.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi test_traffic \<start|stop\> \<period\></c>
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wifi_test_traffic(const char *ifname, uint32_t period);

/**
 * \brief Add a multicast IP address to the flood-forwarding table
 *
 * Packets matching these addresses will be flood-forwarded to every interface and every associated
 * station.
 *
 * \param ipaddr the multicast IPv4 address to be added to the table
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi add_ipff \<ipaddr\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wifi_add_ipff(qcsapi_unsigned_int ipaddr);

/**
 * \brief Remove a multicast IP address from the flood-forwarding table
 *
 * \param ipaddr the multicast IPv4 address to be removed from the table
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi del_ipff \<ipaddr\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wifi_del_ipff(qcsapi_unsigned_int ipaddr);

/**
 * \brief Display the contents of the flood-forwarding table
 *
 * \return 0 if the call succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_ipff</c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 *
 * See @ref mysection4_1_4 "section here" for more details on error codes and error messages.
 */
extern int qcsapi_wifi_get_ipff(void);

/**@}*/

/**@addtogroup StatisticsAPIs
 *@{*/
/**
 * @brief Get RFIC temperature
 *
 * Get RFIC temperature
 *
 * \param temp_exter Buffer to contain the returned external temperature.
 * \param temp_inter Buffer to contain the returned internal temperature.
 *
 * \return 0 if the command succeeded.
 * \return A negative value if an error occurred. See @ref mysection4_1_4 "QCSAPI Return Values"
 * for error codes and messages.
 *
 * Note: Use the following method to convert a value returned from <c>temp_exter</c> or <c>temp_inter</c>
 * into degrees Celsius.<br>
 * @code
 * float rfic_temperature_extr, rfic_temperature_inter;
 * rfic_temperature_extr = temp_exter / 100000.0f;
 * rfic_temperature_inter = temp_inter / 1000000.0f;
 * @endcode
 *
 * \callqcsapi<br>
 *
 * <c>call_qcsapi get_temperature</c>
 */
extern int qcsapi_get_temperature_info(int *temp_exter, int *temp_inter);
/**@}*/


/**@addtogroup CalcmdAPI
 *@{*/

/**
 * \brief QCSAPI for calcmd SET_TEST_MODE
 *
 * \param ifname \wifi0
 * \param value value to set. The param belonging to each value is predefined.
 *
 * \return 0 on success, negative on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_test_mode calcmd \<value:channel\> \<value:antenna\> \<value:MCS\> \<value:BW\> \<value:Packet size\> \<value:11N\> <value:beamforming\></c>
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 *
 * Example:<br>
 * <c>call_qcsapi set_test_mode calcmd 36 127 15 40 40 1 0 (Channel 36, 4 antenna, MCS 15, HT40, 4Kbytes, 11N Signal, bf)</c>
 */

extern int qcsapi_calcmd_set_test_mode( qcsapi_unsigned_int channel,
					qcsapi_unsigned_int antenna,
					qcsapi_unsigned_int mcs,
					qcsapi_unsigned_int bw,
					qcsapi_unsigned_int pkt_size,
					qcsapi_unsigned_int eleven_n,
					qcsapi_unsigned_int bf);


/**
 * \brief Show TX packet number, RX packet number and CRC number
 *
 * This API call is used to show test mode packet statistics.
 *
 * \param ifname \wifi0
 * \param stats return parameter to contain the statistics of TX, RX, CRC packet number.
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 * the packet number statistics data retrieved from the device for the interface.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi show_test_packet calcmd</c>
 *
 * Unless an error occurs, the output will be the PHY statistics data of the interface.
 */

extern int qcsapi_calcmd_show_test_packet(qcsapi_unsigned_int *tx_packet_num, qcsapi_unsigned_int *rx_packet_num, qcsapi_unsigned_int *crc_packet_num);


/**
 * \brief Start sending OFDM Packet
 *
 * This API call is used to send OFDM packet.
 *
 * \param ifname \wifi0
 * \param value the number of packet to transmit, 1 is 1000 packets. If number is set, it will automatically stop, if 0, transmit infinitely
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 * the packet number statistics data retrieved from the device for the interface.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi send_test_packet calcmd \<value\></c>
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */

extern int qcsapi_calcmd_send_test_packet(qcsapi_unsigned_int to_transmit_packet_num);

/**
 * \brief Stop transmitting OFDM Packet
 *
 * This API call is used to stop transmitting OFDM packet in test mode.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi stop_test_packet calcmd </c>
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */

extern int qcsapi_calcmd_stop_test_packet(void);

/**
 * \brief send CW signal at center frequency for Frequency offset measurement
 *
 * This API call is used to send continuous signal in test mode.
 *
 * \param ifname \wifi0
 *
 * \param channel to perform the action on. (calcmd)
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi send_dc_cw_signal calcmd <channel></c>
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */

extern int qcsapi_calcmd_send_dc_cw_signal(qcsapi_unsigned_int channel);

/**
 * \brief stop transmitting CW signal
 *
 * This API call is used to stop Continuous signal in test mode.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi stop_dc_cw_signal calcmd</c>
 *
 * Output is silent with a return code of zero if successful, and an error message on failure.
 */

extern int qcsapi_calcmd_stop_dc_cw_signal(void);

/**
 * \brief get antenna selection
 *
 * This API call is used to retrieve antenna configuration in test mode.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_test_mode_antenna_sel calcmd</c>
 *
 * Output is antenna number with bit mask type. e.g) 1010 means Ant4 & Ant2 is enabled.
 */

extern int qcsapi_calcmd_get_test_mode_antenna_sel(qcsapi_unsigned_int *antenna_bit_mask);

/**
 * \brief get mcs config
 *
 * This API call is used to retrieve MCS configuration in test mode.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_test_mode_mcs calcmd</c>
 *
 * Output is MCS configuration.
 */

extern int qcsapi_calcmd_get_test_mode_mcs(qcsapi_unsigned_int *test_mode_mcs);


/**
 * \brief get bandwidth config
 *
 * This API call is used to retrieve bandwidth configuration in test mode.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_test_mode_bw calcmd</c>
 *
 * Output is Bandwidth configuration.
 */

extern int qcsapi_calcmd_get_test_mode_bw(qcsapi_unsigned_int *test_mode_bw);


/**
 * \brief get tx power value
 *
 * This API call is used to retrieve current TX power.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_test_mode_tx_power calcmd</c>
 *
 * Output is TX power value.
 */

extern int qcsapi_calcmd_get_tx_power(qcsapi_calcmd_tx_power_rsp *tx_power);


/**
 * \brief set target tx power
 *
 * This API call is used to set TX power.
 *
 * \param ifname \wifi0
 *
 * \value target power to transmission
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_test_mode_tx_power calcmd \<value\></c>
 */

extern int qcsapi_calcmd_set_tx_power(qcsapi_unsigned_int tx_power);


/**
 * \brief get RSSI value
 *
 * This API call is used to retrieve RSSI value in test mode.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_test_mode_rssi calcmd</c>
 *
 * Output is RSSI value.
 */

extern int qcsapi_calcmd_get_test_mode_rssi(qcsapi_calcmd_rssi_rsp *test_mode_rssi);


/**
 * \brief set mac filter
 *
 * This API call is used to set mac filter.
 *
 * \param q_num the contention queue number
 *
 * \param sec_enable the security if enable or not
 *
 * \param mac_addr the mac address which the device is used to filter the packet
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi calcmd_set_mac_filter calcmd \<q_num\> \<sec_enable\> \<mac_addr\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete.</c>
 *
 * Example:<br>
 * <c>call_qcsapi calcmd_set_mac_filter calcmd 0 2 00:11:22:33:44:55</c>
 */

extern int qcsapi_calcmd_set_mac_filter(int q_num, int sec_enable, const qcsapi_mac_addr mac_addr);


/**
 * \brief get number of antenna
 *
 * This API call is used to retrieve auntenna counter in test mode.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_antenna_counter calcmd</c>
 *
 * Output is number of antenna.
 */

extern int qcsapi_calcmd_get_antenna_count(qcsapi_unsigned_int *antenna_count);


/**
 * \brief clear tx/rx counter
 *
 * This API call is used to clear counter of tx/rx packets.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \callqcsapi
 *
 * <c>call_qcsapi calcmd_clear_counter calcmd</c>
 */

extern int qcsapi_calcmd_clear_counter(void);

/**
 * \brief get carrier ID
 *
 * This API call is used to retrieve current carrier ID which is taking effect.
 *
 * \param p_carrier_id
 *
 * \return >= 0 on success, < 0 on error.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_carrier_id </c>
 *
 * Unless an error occurs, the output will be the carrier ID.
 */
extern int qcsapi_get_carrier_id(qcsapi_unsigned_int *p_carrier_id);

/**
 * \brief Set carrier ID.
 *
 * This API call is used to interprete the carrier ID to a set of configurations
 * and write the setting carrier ID back to uboot according to the second parameter.
 *
 * \param carrier_id
 * \param update_uboot whether it is needed to write the carrier ID back to uboot env.
 *
 * \return 0 on success or negative values on error
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_carrier_id  \<carrier_id\> \<update_uboot\></c>
 *
 * Unless an error occurs, the output will be the string <c>complete</c>.
 */
extern int qcsapi_set_carrier_id(uint32_t carrier_id, uint32_t update_uboot);

/**
 * \brief set vht
 *
 * This API call is used to set vht mode to enable 802.11ac operation.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error. If success, stats contains
 *
 * \note The bandwidth to use is set independently, using qcsapi_wifi_set_bw
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_vht \<wifi interface\> \<0 | 1\></c>
 *
 * \sa qcsapi_wifi_set_bw
 */
extern int qcsapi_wifi_set_vht( const char *ifname, const qcsapi_unsigned_int the_vht );

/**
 * \brief get vht
 *
 * This API call is used to get vht mode.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error.
 *
 * Unless an error occurs, the output will be <c>1</c> (enabled) or <c>0</c> (disabled)
 *
 * \callqcsapi
 *
 * <c>call_qcsapi get_vht \<wifi interface\> </c>
 */
extern int qcsapi_wifi_get_vht( const char *ifname, qcsapi_unsigned_int *vht );

/**
 * \brief get spinor jedecid.
 *
 * This API get the spinor flash jedec id.
 *
 * \param ifname \wifi0
 *
 * \return >= 0 on success, < 0 on error.
 *
 * Unless an error occurs, the output will be the jedec id.
 *
 * \call_qcsapi
 *
 * <c>call_qcsapi get_spinor_jedecid \<wifi interface\> </c>
 */
extern int qcsapi_wifi_get_spinor_jedecid(const char * ifname, unsigned int * p_jedecid);

/**
 * \brief set nss cap
 *
 * This API call is used to set the maximum number of spatial streams for a given interface
 *
 * \param ifname \wifi0
 * \param modulation either 'ht' (for 802.11n) or 'vht' (for 802.11ac)
 * \note This API works across all wifi interfaces.
 *
 * \return >= 0 on success, < 0 on error.
 *
 * \callqcsapi
 *
 * <c>call_qcsapi set_nss_cap \<wifi interface\> {ht | vht} \<nss\></c>
 */
extern int qcsapi_wifi_set_nss_cap(const char *ifname, const qcsapi_mimo_type modulation,
					const qcsapi_unsigned_int nss);

/**
 * \brief get nss cap
 *
 * This API call is used to get the maximum number of spatial streams for a given interface
 *
 * \param ifname \wifi0
 * \param modulation either 'ht' (for 802.11n) or 'vht' (for 802.11ac)
 * \note This API works across all wifi interfaces.
 *
 * \return >= 0 on success, < 0 on error.
 *
 * \call_qcsapi
 *
 * <c>call_qcsapi get_nss_cap \<wifi interface\> {ht | vht}</c>
 */
extern int qcsapi_wifi_get_nss_cap(const char *ifname, const qcsapi_mimo_type modulation,
					qcsapi_unsigned_int *nss);

/**@}*/
#ifdef __cplusplus
}
#endif

#endif /* _QCSAPI_H */
