#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#include "Config.h"
#include "Logging.h"
#include "WifiSetup.h"

MFRC522 mfrc522(IYN_NFC_PIN_SS, IYN_NFC_PIN_RST);

void setup() {
	Serial.begin(IYN_SERIAL_BAUDRATE);
	SPI.begin();
	WifiSetup setup;
	setup.setupWifi();

	mfrc522.PCD_Init();
}

void loop() {
	if(mfrc522.PICC_IsNewCardPresent()){
		Log::info("Card found");
		mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid));
	}
}
