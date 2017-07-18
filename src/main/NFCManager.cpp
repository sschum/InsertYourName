#include "NFCManager.h"

#include <Arduino.h>
#include <stddef.h>

#include "Config.h"
#include "Logging.h"

NFCManager::NFCManager(){
	this->nfc = MFRC522(IYN_NFC_PIN_SS, IYN_NFC_PIN_RST);
}

void NFCManager::init(){
	this->nfc.PCD_Init();
}

NFCCardInfo NFCManager::waitForCard() {
	/**
	 * Wenn ein Token an dedektiert wurde, bekommen wir ständig diese ID angeboten.
	 * Um zu vermeiden, dass diese Methode immer die gleiche ID zurückliefert, wird
	 * hier ein Mechanismus eingebaut, um das zu vermeiden. Dazu wird die letzte ID
	 * gespeichert. Sollte eine die gleiche ID kurz darauf (wenige ms) wieder gescant
	 * werden, wird dies entdeckt und die ID wird ignoriert. Somit wird das "Spammen"
	 * vermieden.
	 *
	 * Sollte der Nutzer ein Token gescant haben und nach einer längeren Zeit (>1Sek)
	 * wieder, sollte diese Methode allerdings ebenfals beenden. Um das zu realisieren,
	 * wird die letzte ID nach einer gewissen Zeit vergessen.
	 */
	while (true) {
		if (this->nfc.PICC_IsNewCardPresent() && this->nfc.PICC_ReadCardSerial()) {
			if((millis() - this->lastRead) > IYN_NFC_FORGET_SAME_ID) {
				//vergesse die letzte gescannte Karte wenn der Zeitpunkt,
				//an dem der Scan stattgefunden hat, zu lange her ist
				this->lastNFC = NFCCardInfo();
			}

			this->lastRead = millis();

			//Wenn eine andere Karte/Token gescannt wurde
			if (!this->equals(&this->lastNFC.uid, &this->nfc.uid)) {
				break;
			}
		}

		delay(250);
	}

	//An dieser Stelle wurde ein neues NFC-Token gescannt
	Log::debug("New NFC-Card was detected!");

	this->lastNFC = NFCCardInfo();
	this->lastNFC.uid = this->nfc.uid;

	return this->lastNFC;
}

bool NFCManager::equals(MFRC522::Uid* uuid1, MFRC522::Uid* uuid2) {
	if(uuid1 == NULL && uuid2 == NULL) return true;
	if(uuid1 != NULL && uuid2 == NULL) return false;
	if(uuid1 == NULL && uuid2 != NULL) return false;

	if(uuid1->size != uuid2->size) return false;

	for(byte i=0; i < uuid1->size; i++) {
		if(uuid1->uidByte[i] != uuid2->uidByte[i]) return false;
	}
	return true;
}
