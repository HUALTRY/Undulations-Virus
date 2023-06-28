#include "Undulations.h"

bool InterferenceClass::interferenceFlag = true;
int InterferenceClass::textRnd = 0;
LONG InterferenceClass::addStyle = 0;


BOOL CALLBACK EnumChildProc(HWND hWnd,LPARAM ItParam)
{
	LONG style = 0;
	char cWinText[8] = {0};
	WCHAR winTextTmp[8] = {0};
	LPCWSTR winText = {0};

	style = GetWindowLong(hWnd, GWL_STYLE);
	SetWindowLong(hWnd, GWL_STYLE,style | WS_DISABLED | InterferenceClass::addStyle);
	Sleep(30);
	if (ItParam > 18)
	{
		SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_HIDEWINDOW | SWP_NOSIZE | SWP_NOMOVE);
	}
	if(InterferenceClass::textRnd)
	{
		cWinText[0] = (char)(rand()%94 + 33), cWinText[1] = (char)(rand()%94 + 33);
		cWinText[2] = (char)(rand()%94 + 33), cWinText[3] = (char)(rand()%94 + 33);
		cWinText[4] = (char)(rand()%94 + 33), cWinText[5] = (char)(rand()%94 + 33);
		cWinText[6] = (char)(rand()%94 + 33), cWinText[7] = '\0';
		winText = winTextTmp;
		swprintf_s(winTextTmp, L"%S", cWinText);
		SetWindowText(hWnd,winText);
	}
	return TRUE;
}


BOOL CALLBACK EnumChildWindowsInParent(HWND hWnd,LPARAM ItParam)
{
	char cWinText[8] = {0};
	WCHAR winTextTmp[8] = {0};
	LPCWSTR winText = {0};
	EnumChildWindows(hWnd,EnumChildProc,ItParam); 
	if(InterferenceClass::textRnd)
	{
		cWinText[0] = (char)(rand()%94 + 33), cWinText[1] = (char)(rand()%94 + 33);
		cWinText[2] = (char)(rand()%94 + 33), cWinText[3] = (char)(rand()%94 + 33);
		cWinText[4] = (char)(rand()%94 + 33), cWinText[5] = (char)(rand()%94 + 33);
		cWinText[6] = (char)(rand()%94 + 33), cWinText[7] = '\0';
		winText = winTextTmp;
		swprintf_s(winTextTmp, L"%S", cWinText);
		SetWindowText(hWnd,winText);
	}
	if(ItParam > 18)
	{
		SetWindowPos(hWnd,HWND_BOTTOM,0,0,0,0,SWP_HIDEWINDOW | SWP_NOSIZE | SWP_NOMOVE);
	}
	return TRUE;
}


void InterferenceClass::Interference(int index)
{
	interferenceFlag = true;
	addStyle = 0;
	textRnd = rand()%2;
	for(int i = 0;i< rand()%17 + 1;i++)
	{
		LONG styleList[17] = {
			WS_BORDER, WS_DLGFRAME, WS_EX_DLGMODALFRAME,
			WS_EX_TOOLWINDOW, WS_EX_WINDOWEDGE, WS_EX_CLIENTEDGE, WS_EX_RIGHT,
			WS_EX_RTLREADING, WS_EX_LEFTSCROLLBAR, WS_EX_STATICEDGE, WS_EX_OVERLAPPEDWINDOW,
			WS_EX_PALETTEWINDOW, DS_3DLOOK, DS_ABSALIGN, DS_NOIDLEMSG, DS_CENTER, DS_CENTERMOUSE
		};
		addStyle |= styleList[rand()%17];
	}
	while(interferenceFlag)
	{
		EnumChildWindows(NULL,EnumChildWindowsInParent,index);
	}
}