#include <Arduino.h>

#include "Config.h"
#include "Logging.h"
#include "WifiSetup.h"

void setup() {
	Serial.begin(IYN_SERIAL_BAUDRATE);
	delay(100);
	WifiSetup setup;
	setup.setupWifi();
}

void loop() {
}
