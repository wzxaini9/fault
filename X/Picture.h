#pragma once
#include "Sprite.h"
class CPicture:public Sprite
{
public:
	CPicture(void);
	~CPicture(void);
	void InitPicture(HDC hdc,HINSTANCE hinst,int type);
	void SetRectangle();
private:
	int m_type;
	RECT m_SrcRect[3],m_DestRect[3];
public:
	RECT *GetRectangle(){return m_DestRect;};
	RECT *GetSrcRectangle(){return m_SrcRect;};

};
