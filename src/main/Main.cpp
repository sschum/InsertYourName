#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#include "Config.h"
#include "Logging.h"
#include "WifiSetup.h"
#include "NFCManager.h"

NFCManager nfcManager;

void setup() {
	Serial.begin(IYN_SERIAL_BAUDRATE);
	SPI.begin();
	WifiSetup setup;
	setup.setupWifi();

	nfcManager.init();
}

void loop() {
	nfcManager.waitForCard();
}
