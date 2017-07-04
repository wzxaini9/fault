#include "StdAfx.h"
#include "BkBitMap.h"

CBkBitMap::CBkBitMap(void)
{
	m_TempTime = 0;
	m_TimeIsDie = false;
}

CBkBitMap::~CBkBitMap(void)
{
}

void CBkBitMap::InitBkBitMap(HDC hdc, HINSTANCE hinst, int bitmapState)
{
	switch (bitmapState)
	{
	case 1:
		SetIsFlash(3);
		SetSize(800,600);
		SetClipSize(800,600);
		InitSprite(hdc,hinst,"bitmap//UI1.bmp");
		break;
	case 2:
		SetIsFlash(3);
		SetSize(800,600);
		SetClipSize(800,600);
		InitSprite(hdc,hinst,"bitmap//UI2.bmp");
		break;
	case 3:
		SetIsFlash(2);
		SetSize(708,428);
		SetClipSize(708,428);
		SetPos(36,147);
		InitSprite(hdc,hinst,"bitmap//UI3.bmp");
		SetMaskColor(RGB(255,255,255));
		break;
	case 4:
		SetIsFlash(5);
		SetSize(285,33);
		SetClipSize(262,22);
		SetPos(423,111);
		InitSprite(hdc,hinst,"bitmap//progressbar_value.bmp");
		SetMaskColor(RGB(255,255,255));
		break;
	case 5:
		SetIsFlash(2);
		SetSize(212,126);
		SetClipSize(212,126);
		SetPos(294,238);
		InitSprite(hdc,hinst,"bitmap//over.bmp");
		SetMaskColor(RGB(255,0,255));
		break;
	case 6:
		SetIsFlash(2);
		SetSize(212,76);
		SetClipSize(212,76);
		SetPos(294,260);
		InitSprite(hdc,hinst,"bitmap//next.bmp");
		SetMaskColor(RGB(255,255,255));
		break;
	case 7:
		SetIsFlash(1);
		SetTime(1);
		SetSize(180,24);
		SetClipSize(180/10,24);
		SetPos(280,115);
		InitSprite(hdc,hinst,"bitmap//digit1.bmp");
		SetMaskColor(RGB(255,0,255));
		break;
	case 8:
		SetIsFlash(1);
		SetTime(1);
		SetSize(200,24);
		SetClipSize(200/10,24);
		SetPos(280,80);
		InitSprite(hdc,hinst,"bitmap//digit2.bmp");
		SetMaskColor(RGB(255,0,255));
		break;
	case 9:
		SetIsFlash(2);
		SetSize(212,126);
		SetClipSize(212,126);
		SetPos(294,238);
		InitSprite(hdc,hinst,"bitmap//close.bmp");
		SetMaskColor(RGB(255,0,255));
		break;
	}
}
void CBkBitMap::DrawBkBitMap(HDC hdc)
{
	DrawSprite(hdc);
}
bool CBkBitMap::SetTimeBitMap()
{
	int tempX = GetX();
	int tempY = GetY();

	int tempLeft = GetStaticPosX();
	int tempTop = GetStaticPosY();
	if (m_TempTime > 15)
	{
		tempX-=1;
		tempLeft-=1;
		m_TempTime = 0;

	}
	if (tempLeft > 685)
		m_TimeIsDie = true;

	SetPos(tempX,tempY);
	SetStaticPos(tempLeft,tempTop);
	if (tempLeft<=-239)
	{
		return true;
	}
	m_TempTime++;
	return false;
}
void CBkBitMap::IsError()
{
	int tempX = GetX();
	int tempY = GetY();
	int tempLeft = GetStaticPosX();
	int tempTop = GetStaticPosY();
	tempX-=2;
	tempLeft-=2;
	SetPos(tempX,tempY);
	SetStaticPos(tempLeft,tempTop);

}
void CBkBitMap::IsAddTime()
{
	int tempX = GetX();
	int tempY = GetY();
	int tempLeft = GetStaticPosX();
	int tempTop = GetStaticPosY();
	
	if (tempX > 5)
	{
		tempX+=5;
		tempLeft+=5;
	} 
	else 
	{
		tempX = 1;
		tempLeft = 0;
	}
	SetPos(tempX,tempY);
	SetStaticPos(tempLeft,tempTop);

}