apps_fsck_ret_update = <% apps_fsck_ret(); %>;
scan_status = '<% nvram_get("diskmon_status"); %>';
usb_pool_error = ['<% nvram_get("usb_path1_pool_error"); %>', '<% nvram_get("usb_path2_pool_error"); %>'];
