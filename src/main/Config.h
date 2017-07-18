#ifndef SRC_MAIN_CONFIG_H_
#define SRC_MAIN_CONFIG_H_

/**
 * Allgemeine Einstellungen
 */

#define IYN_SERIAL_BAUDRATE        115200                   //Die Bautrate für den Serial-Port

/**
 * WIFI-Einstellungen
 */

#define IYN_WIFI_MANAGER_ON         1
#define IYN_WIFI_MANAGER_OFF        0
#define IYN_WIFI_MANAGER            IYN_WIFI_MANAGER_OFF    //De-/Aktivierung des WifiManagers

//Wenn der WifiManager deaktiviert ist:
#define IYN_WIFI_SSID               "MY_SSID"               //Die SSID des AccesPoints zu den verbunden werden soll
#define IYN_WIFI_PASSWORD           "PASSWORD"              //Das Passwort des AccesPoints zu den verbunden werden soll

/**
 * NFC-Einstellungen
 */

#define IYN_NFC_PIN_SS              D8
#define IYN_NFC_PIN_RST             D3
#define IYN_NFC_FORGET_SAME_ID      5000                    //Zeit (in ms) die verstreichen muss, damit das selbe Token als neu interpretiert wird

/**
 * LOGGING
 */

#define IYN_LOG_LEVEL_DEBUG         0
#define IYN_LOG_LEVEL_INFO          1
#define IYN_LOG_LEVEL_WARN          2
#define IYN_LOG_LEVEL_ERROR         3
#define IYN_LOG_LEVEL_NONE          10
#define IYN_LOG_LEVEL               IYN_LOG_LEVEL_DEBUG     //Das verwendete LogLevel

#endif /* SRC_MAIN_CONFIG_H_ */
