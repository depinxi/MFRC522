#include <stdio.h>
#include <unistd.h>
#include "MFRC522.h"
#include <stdlib.h>

void delay(int ms)
{
#ifdef WIN32
	Sleep(ms);
#else
	usleep(ms * 1000);
#endif
}

int main(int argc, const char **argv)
{
	MFRC522 mfrc;
	
	mfrc.PCD_Init();
	
	printf("Version : %02X\n", mfrc.PCD_ReadRegister(MFRC522::VersionReg));
	
	if (argc > 1 && atoi(argv[1])) {
		int result =  mfrc.PCD_PerformSelfTest();
		printf("test: %d\n", result);
		return ((result == 1) ? 0 : 1);
	}
	
	while (1)
	{
		if (mfrc.PICC_IsNewCardPresent())
		{
			if (mfrc.PICC_ReadCardSerial())
			{
				MFRC522::PICC_Type piccType = (MFRC522::PICC_Type)mfrc.PICC_GetType(mfrc.uid.sak);
				
				if (piccType == MFRC522::PICC_TYPE_MIFARE_1K)
				{
					printf("MIFARE 1K\n");
				}
			}
			
			mfrc.PICC_HaltA();
			mfrc.PCD_StopCrypto1();
		}
	}
	
	return 0;
}

