#include "WifiSetup.h"
#include "Logging.h"

#if IYN_WIFI_MANAGER == IYN_WIFI_MANAGER_ON

#include <WiFiManager.h>

void WifiSetup::setupWifi() {
	Log::debug("Enable WiFiManager!");

	WiFiManager manager;
	manager.autoConnect();
}

#else

void WifiSetup::setupWifi() {
	Log::debug("Disable WiFiManager!");
	Log::debug("SSID: " IYN_WIFI_SSID);
	Log::debug("PASSWORD: " IYN_WIFI_PASSWORD);
}

#endif
