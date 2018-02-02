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
	int version = mfrc.PCD_ReadRegister(MFRC522::VersionReg);
	printf("Version : %02X\n", version); 
	return (version ? 0 : 1);
}

