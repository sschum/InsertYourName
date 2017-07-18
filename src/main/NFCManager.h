#ifndef SRC_MAIN_NFCMANAGER_H_
#define SRC_MAIN_NFCMANAGER_H_

#include <MFRC522.h>

/**
 * Diese Klasse beinhaltet die Informationen eines NFC-Tokens
 */
class NFCCardInfo {
private:
	MFRC522::Uid uid;

	friend class NFCManager;
};

class NFCManager {
public:
	NFCManager();

	/**
	 * Diese Methode muss aufgerufen werden BEVOR der Manager benutzt werden kann.
	 */
	void init();

	/**
	 * Warte solange bis eine neue Karte/Token dedektiert wurde
	 */
	NFCCardInfo waitForCard();

private:
	bool equals(MFRC522::Uid*, MFRC522::Uid*);

	MFRC522 nfc;

	NFCCardInfo lastNFC;
	unsigned long lastRead = 0;
};


#endif /* SRC_MAIN_NFCMANAGER_H_ */
