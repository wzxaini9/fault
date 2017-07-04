#pragma once
#include "Sprite.h"
class CMyCursor:public Sprite
{
public:
	CMyCursor(void);
	~CMyCursor(void);
	void InitMyCursor(HDC hdc,HINSTANCE hinst,int cursorstate);
private:
	int m_CursorState;
};
