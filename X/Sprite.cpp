#pragma once
#include "stdafx.h"
#include "sprite.h"

Sprite::Sprite()
{


	m_startdir=0;
	m_enddir=0;
	m_endframe=0;


	m_IsFlash = false;
	m_Time = 0;
	m_SX = m_SY = 0;
	m_LeftPos = m_TopPos = 0;
	m_Dir = m_Frame = 0;
	m_Width = m_Height = 0;
	m_MaskColor = 0x000000;
	t_time1=timeGetTime()/10;
}

Sprite::~Sprite()
{

}

void Sprite::SetIsFlash(int isflash)
{
	m_IsFlash = isflash;
}

void Sprite::SetTime(int time)
{
	m_Time = time;
}

void Sprite::SetDir(int dir)
{
	m_Dir = dir;
}

void Sprite::SetFrame(int frame)
{
	m_Frame = frame;
}

void Sprite::SetSize(int tw,int th)
{
	m_Width = tw;
	m_Height = th;
}

void Sprite::SetClipSize(int tw,int th)
{
	m_ClipWidth = tw;
	m_ClipHeight = th;
}

void Sprite::SetPos(int nx,int ny)
{
	m_SX = nx;
	m_SY = ny;
}
void Sprite::SetHrh(int hrh)
{
	m_hRh=hrh;
}
void Sprite::SetStartDir(int t_start)
{

	m_startdir=t_start;
	m_Dir=m_startdir;
}
void Sprite::SetEndDir(int t_end)
{
	m_enddir=t_end;
	
}
void Sprite::SetStartFrame(int t_frame)
{
	m_startframe=t_frame;
	m_Frame=m_startframe;
}
void Sprite::SetEndFrame(int t_frame)
{
	m_endframe=t_frame;
}
void Sprite::SetStaticPos(int nx,int ny)
{
	m_LeftPos = nx;
	m_TopPos = ny;
}

void Sprite::InitSprite(HDC hdc,HINSTANCE hinst,char * filename)
{
	m_Dc = CreateCompatibleDC(hdc);
	m_MaskDc = CreateCompatibleDC(hdc);

	m_Bitmap = (HBITMAP)LoadImage(hinst,filename,IMAGE_BITMAP,m_Width,m_Height,LR_LOADFROMFILE);
	m_MaskBitmap = CreateBitmap(m_ClipWidth,m_ClipHeight,1,1,0);
	SelectObject(m_Dc,m_Bitmap);
	SelectObject(m_MaskDc,m_MaskBitmap);
	
	
}

void Sprite::SetMaskColor(COLORREF color)
{
	m_MaskColor = color;
}
void Sprite::DrawSprite(HDC hdc)
{
	SetBkColor(m_Dc,m_MaskColor);

	switch(m_IsFlash)
	{
	case 1:
		{
			int temp = m_Width / m_ClipWidth;

			BitBlt(m_MaskDc,0,0,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCCOPY);
			BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
			BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_MaskDc,0,0,SRCAND);
			BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
		}
		break;
	case 2:
		{
			BitBlt(m_MaskDc,0,0,m_Width,m_Height,m_Dc,m_LeftPos,m_TopPos,SRCCOPY);
			BitBlt(hdc,m_SX,m_SY,m_Width,m_Height,m_Dc,m_LeftPos,m_TopPos,SRCINVERT);
			BitBlt(hdc,m_SX,m_SY,m_Width,m_Height,m_MaskDc,0,0,SRCAND);
			BitBlt(hdc,m_SX,m_SY,m_Width,m_Height,m_Dc,m_LeftPos,m_TopPos,SRCINVERT);
		}
		break;
	case 3:
		BitBlt(hdc,m_SX,m_SY,m_Width,m_Height,m_Dc,m_LeftPos,m_TopPos,SRCCOPY);
		break;
	case 4:
		{
			BitBlt(hdc,m_SX,m_SY,m_Width,m_Height,m_Dc,m_LeftPos,m_TopPos,SRCINVERT);
			BitBlt(hdc,m_SX,m_SY,m_Width,m_Height,m_MaskDc,0,0,SRCAND);
			BitBlt(hdc,m_SX,m_SY,m_Width,m_Height,m_Dc,m_LeftPos,m_TopPos,SRCINVERT);
		}
		break;
	case 5:
		{
			BitBlt(m_MaskDc,0,0,m_Width,m_Height,m_Dc,m_LeftPos,m_TopPos,SRCCOPY);
			BitBlt(hdc,m_SX,m_SY,m_Width,m_Height,m_Dc,m_LeftPos,m_TopPos,SRCINVERT);
			BitBlt(hdc,m_SX,m_SY,m_Width,m_Height,m_MaskDc,0,0,SRCAND);
			BitBlt(hdc,m_SX,m_SY,m_Width,m_Height,m_Dc,m_LeftPos,m_TopPos,SRCINVERT);	
		}
		break;
	case 6:
		int temp = m_Width / m_ClipWidth;

		BitBlt(m_MaskDc,0,0,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCCOPY);
		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_MaskDc,0,0,SRCAND);
		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);

		m_Frame++;
		if(m_Frame >= (m_Time * temp))
			m_Frame = 0;
	}


	//switch(m_hRh)
	//{
	//case 1:
	//	if(m_IsFlash)
	//	{
	//		int temp = m_Width / m_ClipWidth;
	//		BitBlt(m_MaskDc,0,0,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCCOPY);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_MaskDc,0,0,SRCAND);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);

	//		m_Frame++;
	//		if(m_Frame >= (m_Time * temp))
	//			m_Frame = 0;
	//	}
	//	else
	//	{
	//		BitBlt(m_MaskDc,0,0,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCCOPY);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_MaskDc,0,0,SRCAND);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);

	//	}
	//	break;
	//case 2:
	//	if(m_IsFlash)
	//	{
	//		int temp = m_enddir;
	//		BitBlt(m_MaskDc,0,0,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame  * m_ClipWidth,m_Dir/ m_Time * m_ClipHeight,SRCCOPY);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame  * m_ClipWidth,m_Dir/ m_Time * m_ClipHeight,SRCINVERT);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_MaskDc,0,0,SRCAND);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame  * m_ClipWidth,m_Dir/ m_Time * m_ClipHeight,SRCINVERT);
	//		m_Dir++;
	//		if(m_Dir >= (m_Time * temp))
	//			m_Dir = 0;
	//	}
	//	else
	//	{
	//		BitBlt(m_MaskDc,0,0,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame  * m_ClipWidth,m_Dir/ m_Time * m_ClipHeight,SRCCOPY);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame  * m_ClipWidth,m_Dir/ m_Time * m_ClipHeight,SRCINVERT);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_MaskDc,0,0,SRCAND);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame  * m_ClipWidth,m_Dir/ m_Time * m_ClipHeight,SRCINVERT);
	//	}
	//	break;
	//case 3:
	//	BitBlt(m_MaskDc,0,0,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame * m_ClipWidth,m_Dir * m_ClipHeight,SRCCOPY);
	//	BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame  * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
	//	BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_MaskDc,0,0,SRCAND);
	//	BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
	//	break;
	//case 4:
	//	{
	//		int temp = m_endframe;
	//		int t_time2 = timeGetTime() / 10;
	//		if (t_time2-t_time1>=15)
	//		{
	//			m_Frame++;
	//			if(m_Frame >= (m_Time * temp))
	//				m_Frame = 0;
	//			t_time1 = t_time2;
	//		}
	//		BitBlt(m_MaskDc,0,0,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCCOPY);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_MaskDc,0,0,SRCAND);
	//		BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
	//		
	//	}
	//	break;
	//case 5:
	//	{
	//		if(m_IsFlash)
	//		{
	//			int temp = m_Width / m_ClipWidth;
	//			BitBlt(m_MaskDc,0,0,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCCOPY);
	//			BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
	//			BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_MaskDc,0,0,SRCAND);
	//			BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);

	//			m_Frame++;
	//			if(m_Frame >= (m_Time * temp))
	//			{
	//				m_Frame = 0;
	//				m_Dir++;
	//			}
	//		}
	//		else
	//		{
	//			BitBlt(m_MaskDc,0,0,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCCOPY);
	//			BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);
	//			BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_MaskDc,0,0,SRCAND);
	//			BitBlt(hdc,m_SX,m_SY,m_ClipWidth,m_ClipHeight,m_Dc,m_Frame / m_Time * m_ClipWidth,m_Dir * m_ClipHeight,SRCINVERT);

	//		}
	//	}
	//	break;
	//}
}