#ifndef SRC_MAIN_CONFIG_H_
#define SRC_MAIN_CONFIG_H_

/**
 * General Settings
 */

#define IYN_SERIAL_BAUDRATE			115200					//the serial baudrate

/**
 * WIFI-Settings
 */

#define IYN_WIFI_MANAGER_ON			1
#define IYN_WIFI_MANAGER_OFF		0
#define IYN_WIFI_MANAGER 			IYN_WIFI_MANAGER_OFF		//enable or disable wifi-manager

//if wifi-manager is disabled:
#define IYN_WIFI_SSID 				"MY_SSID"				//the target access-point ssid
#define IYN_WIFI_PASSWORD 			"PASSWORD"				//the target access-point password

/**
 * LOGGING
 */

#define IYN_LOG_LEVEL_DEBUG			0
#define IYN_LOG_LEVEL_INFO			1
#define IYN_LOG_LEVEL_WARN			2
#define IYN_LOG_LEVEL_ERROR			3
#define IYN_LOG_LEVEL_NONE			10
#define IYN_LOG_LEVEL				IYN_LOG_LEVEL_DEBUG		//the target log level

#endif /* SRC_MAIN_CONFIG_H_ */
