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
			wsprintf(msg,"%s,��ӭ��ע��!",name);
			//sprintf  �Ǵ�ӡ���ַ����У��൱���ַ��������ټ���һ���ַ���
			//wsprintf  c���Կ���windows����ʱ��wsprintf����sprintf�����Խ�����ĵ����⡣
			MessageBox(hwnd,msg,TEXT("��ʾ"),MB_OK);
		}
		break; 
	case IDR_DEFAULT1:
		{
			MessageBox(hwnd,TEXT("����ת�ӵ����ӵ����磡"),TEXT("��ʾ"),MB_OK);
		}  
	default:
		break;
	}
}

void Main_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

