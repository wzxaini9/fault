#pragma once
#include "BkBitMap.h"
#include "Picture.h"
#include "MyCursor.h"
struct DotData
{
	int num;
	CPicture * Picture;
	//CPicture * leftPicture;
	//CPicture * rightPicture;
	DotData * next;
};

struct ReadRectData
{
	bool isDraw;

	CPicture * Picture;
	RECT leftRectangle;
	RECT rightRectangle;
	ReadRectData * next;
};
class CManage
{
public:
	CManage(void);
	~CManage(void);
	void InitGame(HDC hdc,HINSTANCE hinst);
	void UpDataGame();
	void DrawGame(HDC hdc);
private:
	int m_game_state;
	int  m_picture;
	bool m_next_dot;
	int time;
	int m_exit;
private:
	CBkBitMap *m_bitmap;
	CBkBitMap *m_time;
	CBkBitMap *m_ui,*m_ui_frame;
	CBkBitMap *m_game_over,*m_game_next;
	CBkBitMap *m_digit1,*m_digit2, *m_close;
	CPicture *m_pane1,*m_pane2;
	CMyCursor *m_cursor	;
private:
	DotData *m_dot_head,*m_dot_hear,*m_dot_temp;
	ReadRectData *m_read_head,*m_read_hear,*m_read_temp;
public:
	void SetGameState(int state){m_game_state = state;};
	int GetGameState(){return m_game_state;};
	void SetNextDot(bool nextdot){m_next_dot = nextdot;};
	void SetMyCursorDot(int x,int y);
	void IsItDot(int x,int y);
private:
	void M_InitBitMap(HDC hdc,HINSTANCE hinst);
	void M_DrawBitMap(HDC hdc);
	void M_InitUi(HDC hdc,HINSTANCE hinst);
	void M_DrawUiBkMap(HDC hdc);
	void M_DarwUiFrame(HDC hdc);
	void M_InitPicture(HDC hdc,HINSTANCE hinst);
	void M_DrawPicture(HDC hdc,HINSTANCE hinst);
	void M_InitPane();
	void M_DrawPane(HDC hdc);
};