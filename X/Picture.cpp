#include "StdAfx.h"
#include "Picture.h"

CPicture::CPicture(void)
{
	m_type = 0;
	for (int a=0;a<3;a++)
	{
		m_SrcRect[a].left = -1;
		m_SrcRect[a].right = -1;
		m_SrcRect[a].top = -1;
		m_SrcRect[a].bottom = -1;
		m_DestRect[a].left = -1;
		m_DestRect[a].right = -1;
		m_DestRect[a].top = -1;
		m_DestRect[a].bottom = -1;

	}

}

CPicture::~CPicture(void)
{
}
void CPicture::InitPicture(HDC hdc, HINSTANCE hinst, int type)
{
	char *temp = NULL;
	SetIsFlash(3);
	SetSize(700,420);
	SetClipSize(700,420);
	SetPos(40,150);
	m_type = type;
	switch(type)
	{
	case 1:
		temp = "bitmap//map//c.bmp";
		break;
	case 2:
		temp = "bitmap//map//b.bmp";
		break;
	case 3:
		temp = "bitmap//map//a.bmp";
		break;
	}
	InitSprite(hdc,hinst,temp);
	SetRectangle();
}
void CPicture::SetRectangle()
{

	switch(m_type)
	{
	case 1:
		m_DestRect[0].top = 158;
		m_DestRect[0].left = 40;
		m_DestRect[0].right = 115;
		m_DestRect[0].bottom = 200;

		m_DestRect[1].top = 245;
		m_DestRect[1].left = 275;
		m_DestRect[1].right = 340;
		m_DestRect[1].bottom = 320;

		m_DestRect[2].top = 488;
		m_DestRect[2].left = 300;
		m_DestRect[2].right = 375;
		m_DestRect[2].bottom = 560;

		m_SrcRect[0].top = 158;
		m_SrcRect[0].left = 393;
		m_SrcRect[0].right = 480;
		m_SrcRect[0].bottom = 200;

		m_SrcRect[1].top = 245;
		m_SrcRect[1].left = 625;
		m_SrcRect[1].right = 695;
		m_SrcRect[1].bottom = 320;

		m_SrcRect[2].top = 488;
		m_SrcRect[2].left = 653;
		m_SrcRect[2].right = 725;
		m_SrcRect[2].bottom = 565;
		break;
	case 2:
		m_DestRect[0].top = 170;
		m_DestRect[0].left = 175;
		m_DestRect[0].right = 240;
		m_DestRect[0].bottom = 230;

		m_DestRect[1].top = 280;
		m_DestRect[1].left = 300;
		m_DestRect[1].right = 350;
		m_DestRect[1].bottom = 340;

		m_DestRect[2].top = 485;
		m_DestRect[2].left = 180;
		m_DestRect[2].right = 240;
		m_DestRect[2].bottom = 560;

		m_SrcRect[0].top = 170;
		m_SrcRect[0].left = 525;
		m_SrcRect[0].right = 590;
		m_SrcRect[0].bottom = 230;

		m_SrcRect[1].top = 280;
		m_SrcRect[1].left = 643;
		m_SrcRect[1].right = 713;
		m_SrcRect[1].bottom = 340;

		m_SrcRect[2].top = 485;
		m_SrcRect[2].left = 530;
		m_SrcRect[2].right = 590;
		m_SrcRect[2].bottom = 560;
		break;
	case 3:
		m_DestRect[0].top = 485;
		m_DestRect[0].left = 55;
		m_DestRect[0].right = 80;
		m_DestRect[0].bottom = 545;

		m_DestRect[1].top = 483;
		m_DestRect[1].left = 227;
		m_DestRect[1].right = 290;
		m_DestRect[1].bottom = 535;

		m_DestRect[2].top = 231;
		m_DestRect[2].left = 217;
		m_DestRect[2].right = 270;
		m_DestRect[2].bottom = 280;

		m_SrcRect[0].top = 485;
		m_SrcRect[0].left = 392;
		m_SrcRect[0].right = 460;
		m_SrcRect[0].bottom = 545;
					
		m_SrcRect[1].top = 483;
		m_SrcRect[1].left = 577;
		m_SrcRect[1].right = 640;
		m_SrcRect[1].bottom = 535;
					
		m_SrcRect[2].top = 231;
		m_SrcRect[2].left = 567;
		m_SrcRect[2].right = 660;
		m_SrcRect[2].bottom = 280;
		break;
	}
}