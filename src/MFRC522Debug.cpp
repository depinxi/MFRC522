
#include "MFRC522Debug.h"

/**
 * Returns a __FlashStringHelper pointer to the PICC type name.
 * 
 * @return const MFRC522_STRING_TYPE
 */
const MFRC522_STRING_TYPE MFRC522Debug::PICC_GetTypeName(MFRC522::PICC_Type piccType	///< One of the PICC_Type enums.
) {
	switch (piccType) {
		case MFRC522::PICC_TYPE_ISO_14443_4:		return MFRC522_STRING("PICC compliant with ISO/IEC 14443-4");
		case MFRC522::PICC_TYPE_ISO_18092:		return MFRC522_STRING("PICC compliant with ISO/IEC 18092 (NFC)");
		case MFRC522::PICC_TYPE_MIFARE_MINI:		return MFRC522_STRING("MIFARE Mini, 320 bytes");
		case MFRC522::PICC_TYPE_MIFARE_1K:		return MFRC522_STRING("MIFARE 1KB");
		case MFRC522::PICC_TYPE_MIFARE_4K:		return MFRC522_STRING("MIFARE 4KB");
		case MFRC522::PICC_TYPE_MIFARE_UL:		return MFRC522_STRING("MIFARE Ultralight or Ultralight C");
		case MFRC522::PICC_TYPE_MIFARE_PLUS:		return MFRC522_STRING("MIFARE Plus");
		case MFRC522::PICC_TYPE_MIFARE_DESFIRE:	return MFRC522_STRING("MIFARE DESFire");
		case MFRC522::PICC_TYPE_TNP3XXX:			return MFRC522_STRING("MIFARE TNP3XXX");
		case MFRC522::PICC_TYPE_NOT_COMPLETE:	return MFRC522_STRING("SAK indicates UID is not complete.");
		case MFRC522::PICC_TYPE_UNKNOWN:
		default:						return MFRC522_STRING("Unknown type");
	}
} // End PICC_GetTypeName()

/**
 * Returns a __FlashStringHelper pointer to a status code name.
 * 
 * @return const MFRC522_STRING_TYPE
 */
const MFRC522_STRING_TYPE MFRC522Debug::GetStatusCodeName(MFRC522::StatusCode code	///< One of the StatusCode enums.
) {
	switch (code) {
		case MFRC522::STATUS_OK:				return MFRC522_STRING("Success.");
		case MFRC522::STATUS_ERROR:			return MFRC522_STRING("Error in communication.");
		case MFRC522::STATUS_COLLISION:		return MFRC522_STRING("Collission detected.");
		case MFRC522::STATUS_TIMEOUT:		return MFRC522_STRING("Timeout in communication.");
		case MFRC522::STATUS_NO_ROOM:		return MFRC522_STRING("A buffer is not big enough.");
		case MFRC522::STATUS_INTERNAL_ERROR:	return MFRC522_STRING("Internal error in the code. Should not happen.");
		case MFRC522::STATUS_INVALID:		return MFRC522_STRING("Invalid argument.");
		case MFRC522::STATUS_CRC_WRONG:		return MFRC522_STRING("The CRC_A does not match.");
		case MFRC522::STATUS_MIFARE_NACK:	return MFRC522_STRING("A MIFARE PICC responded with NAK.");
		default:					return MFRC522_STRING("Unknown error");
	}
} // End GetStatusCodeName()
