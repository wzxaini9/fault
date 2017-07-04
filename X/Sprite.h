#pragma once
#include "stdafx.h"

class Sprite
{
public:
	Sprite();
	~Sprite();
	void SetIsFlash(int isflash);
	void SetTime(int time);
	void SetDir(int dir);
	void SetFrame(int frame);
	void SetSize(int tw,int th);
	void SetClipSize(int tw,int th);
	void SetPos(int nx,int ny);
	void SetHrh(int hrh);
	void SetStartDir(int t_start);
	void SetEndDir(int t_end);
	void SetStartFrame(int t_frame);
	void SetEndFrame(int t_frame);
	void SetStaticPos(int nx,int ny);
public:
	void InitSprite(HDC hdc,HINSTANCE hinst,char * filename);
	void SetMaskColor(COLORREF color);
	void DrawSprite(HDC hdc);
public:
	int GetDir() {return m_Dir;};
	int GetFrame() {return m_Frame;};
	int GetX() {return  m_SX;};
	int GetY() {return m_SY;};
	int GetWidth() {return m_Width;};
	int GetHeight() {return m_Height;};
	int GetStaticPosX() {return m_LeftPos;};
	int GetStaticPosY() {return m_TopPos;};
	int GetHrh(){return m_hRh;};
	int GetStartDir(){return m_startdir;};
	int GetEndDir(){return m_enddir;};
	HDC GetSpriteDC() {return m_Dc;};
	
private:
	int t_time1;

	int m_hRh;				//���Ż��������Ż�
	int m_startdir;
	int m_enddir;
	int m_startframe;
	int m_endframe;

	int m_IsFlash;			//�Ƿ��Ƕ���
	int m_Time;				//��ʱ
	int m_SX,m_SY;			//X,Y����
	int m_LeftPos,m_TopPos;	//���ϵ�X,Y����
	int m_Dir;				//����
	int m_Frame;			//֡
	int m_Width,m_Height;	//��,��
	int m_ClipWidth,m_ClipHeight;	//�ü���,��
	HBITMAP m_Bitmap;		//λͼ���
	HBITMAP m_MaskBitmap;	//����λͼ���
	HDC m_Dc;				//�豸�������
	HDC m_MaskDc;			//�����豸�������
	COLORREF m_MaskColor;	//������ɫ

	int m_ItsTime;
};