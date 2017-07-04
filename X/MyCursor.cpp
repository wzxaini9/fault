#include "StdAfx.h"
#include "MyCursor.h"

CMyCursor::CMyCursor(void)
{
	m_CursorState = 0;
}

CMyCursor::~CMyCursor(void)
{
}
void CMyCursor::InitMyCursor(HDC hdc, HINSTANCE hinst, int cursorstate)
{
	m_CursorState = cursorstate;
	switch(m_CursorState)
	{
	case 1:
		SetIsFlash(2);
		SetSize(32,32);
		SetClipSize(32,32);
		InitSprite(hdc,hinst,"bitmap//Cursor.bmp");
		SetMaskColor(RGB(255,0,255));
	case 2:
		break;


	}
}
