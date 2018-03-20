#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

BOOL WINAPI Main_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		HANDLE_MSG(hWnd, WM_INITDIALOG, Main_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, Main_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, Main_OnClose);
	}

	return FALSE;
}

BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch(id)
	{
	case IDC_OK:
		{
			TCHAR name[64],msg[128];
			GetDlgItemText(hwnd,IDC_EDITNAME,name,sizeof(name));
			wsprintf(msg,"%s,欢迎您注册!",name);
			//sprintf  是打印到字符串中，相当于字符串后面再加上一串字符。
			//wsprintf  c语言开发windows程序时用wsprintf代替sprintf，用以解决中文等问题。
			MessageBox(hwnd,msg,TEXT("提示"),MB_OK);
		}
		break; 
	case IDR_DEFAULT1:
		{
			MessageBox(hwnd,TEXT("即将转接到电子的世界！"),TEXT("提示"),MB_OK);
		}  
	default:
		break;
	}
}

void Main_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

