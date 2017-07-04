#pragma once
#include "Sprite.h"
class CBkBitMap:public Sprite
{
public:
	CBkBitMap(void);
	virtual ~CBkBitMap(void);
	void InitBkBitMap(HDC hdc,HINSTANCE hinst,int bitmapState);
	void DrawBkBitMap(HDC hdc);
	bool SetTimeBitMap();
	void IsError();
	void IsAddTime();
	bool GetTimeIsDie(){return m_TimeIsDie;};
private:
	int m_BkState,m_TempTime;
	bool m_TimeIsDie;
};
