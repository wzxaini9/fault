#include "StdAfx.h"
#include "Manage.h"

CManage::CManage(void)
{	
	m_game_state = 1;
	m_picture = 1;
	m_cursor = new CMyCursor;
	m_bitmap = new CBkBitMap;
	m_ui = new CBkBitMap;
	m_ui_frame = new CBkBitMap;
	m_time = new CBkBitMap;
	m_game_over = new CBkBitMap;
	m_game_next = new CBkBitMap;
	m_digit1 = new CBkBitMap;
	m_digit2 = new CBkBitMap;
	m_close = new CBkBitMap;
	m_next_dot = false;
	m_pane1 = new CPicture;
	m_pane2 = new CPicture;
	time=0;
	m_exit = 0;

	m_dot_head = m_dot_hear = m_dot_temp = NULL;
	m_read_head = m_read_hear = m_read_temp = NULL;
}

CManage::~CManage(void)
{
}
void CManage::InitGame(HDC hdc, HINSTANCE hinst)
{
	M_InitBitMap(hdc,hinst);
	M_InitUi(hdc,hinst);
	M_InitPicture(hdc,hinst);
	m_cursor->InitMyCursor(hdc,hinst,1);

	for(int i=0;i<3;i++)
	M_DrawPicture(hdc,hinst);
	m_dot_hear = m_dot_head;
	M_InitPane();
}
void CManage::UpDataGame()
{
	switch(m_game_state)
	{
	case 1:
		break;
	case 2:
		if (m_time->SetTimeBitMap())
		{
			m_game_state = 4;
		}
		break;
	}
}
void CManage::DrawGame(HDC hdc)
{
	int l_Frame = m_digit1->GetFrame();
	switch (m_game_state)
	{
	case 1:
		M_DrawBitMap(hdc);
		break;
	case 2:
		{
			M_DrawUiBkMap(hdc);
			//m_dot_hear=m_dot_head;
			//while(m_dot_hear)
			//{
			//	if (m_next_dot)
			//	{
			//		if (m_dot_hear->num==2)
			//		{
			//			break;
			//		}
			//	}
			//	else
			//	{
			//		if (m_dot_hear->num==1)
			//		{
			//			break;
			//		}
			//	}
			//	m_dot_hear=m_dot_hear->next;
			//}
			m_dot_hear->Picture->DrawSprite(hdc);
			M_DarwUiFrame(hdc);
			M_DrawPane(hdc);

			m_digit1->DrawBkBitMap(hdc);
			m_digit2->DrawBkBitMap(hdc);

			if (!m_time->GetTimeIsDie())
			{
				if (m_next_dot)
				{
					if (m_dot_hear->next != NULL)
						m_dot_hear = m_dot_hear->next;
					else
						m_dot_hear = m_dot_head;
					m_next_dot = false;
					M_InitPane();
					m_time->SetPos(423,111);
					m_time->SetStaticPos(0,0);
					m_digit1->SetFrame(l_Frame+1);
				}
			}
				int temp = 0;
				ReadRectData * temp_read = m_read_head;
				while(temp_read != NULL)
				{
					if(temp_read->isDraw)
						temp++;
					temp_read = temp_read->next;
				}
				if(temp == 3)
				{
					m_next_dot = true;

					while (m_read_head != NULL)
					{
						temp_read = m_read_head;
						m_read_head = m_read_head->next;
						delete temp_read;
					}
					time = 0;
					m_game_state = 3;
					m_exit++;
				}
			m_time->DrawBkBitMap(hdc);	
			if (m_exit>=3)
			{
				m_game_state = 5;
			}
		}
		break;
	case 3:
		if (time>88)
		{
			m_game_state = 2;
		}
		else
		{
			m_game_next->DrawBkBitMap(hdc);	
			time++;
		}
		break;
	case 4:
		m_game_over->DrawBkBitMap(hdc);
		break;
	case 5:
		m_close->DrawBkBitMap(hdc);
		break;
	case 9:
		exit(100);
		break;
	}
	m_cursor->DrawSprite(hdc);
}

void CManage::SetMyCursorDot(int x, int y)
{
	m_cursor->SetPos(x,y);

}
void CManage::IsItDot(int x,int y)
{
	int d_Frame=m_digit2->GetFrame();
	if(!m_time->GetTimeIsDie())
	{
		if(m_read_head != NULL)
		{
			m_read_hear = m_read_head;
			while(m_read_hear != NULL)
			{
				if((x >= m_read_hear->leftRectangle.left && x <= m_read_hear->leftRectangle.right && 
					y >= m_read_hear->leftRectangle.top && y <= m_read_hear->leftRectangle.bottom) ||
					(x >= m_read_hear->rightRectangle.left && x <= m_read_hear->rightRectangle.right && 
					y >= m_read_hear->rightRectangle.top && y <= m_read_hear->rightRectangle.bottom))
				{
					m_read_hear->isDraw = true;
					m_time->IsAddTime();
					m_digit2->SetFrame(d_Frame+1);
				}
				else
				{
					m_time->IsError();
				}
				m_read_hear = m_read_hear->next;
			}
		}
	}
}
void CManage::M_InitBitMap(HDC hdc,HINSTANCE hinst)
{
	m_bitmap->InitBkBitMap(hdc,hinst,1);
	m_time->InitBkBitMap(hdc,hinst,4);
	m_game_over->InitBkBitMap(hdc,hinst,5);
	m_game_next->InitBkBitMap(hdc,hinst,6);
	m_digit1->InitBkBitMap(hdc,hinst,7);
	m_digit2->InitBkBitMap(hdc,hinst,8);
	m_close->InitBkBitMap(hdc,hinst,9);
}
void CManage::M_DrawBitMap(HDC hdc)
{
	m_bitmap->DrawBkBitMap(hdc);
}
void CManage::M_InitUi(HDC hdc,HINSTANCE hinst)
{
	m_ui->InitBkBitMap(hdc,hinst,2);
	m_ui_frame->InitBkBitMap(hdc,hinst,3);
}
void CManage::M_DrawUiBkMap(HDC hdc)
{
	m_ui->DrawBkBitMap(hdc);
}
void CManage::M_DarwUiFrame(HDC hdc)
{
	m_ui_frame->DrawBkBitMap(hdc);
}
void CManage::M_InitPicture(HDC hdc,HINSTANCE hinst)
{
	m_pane1->SetIsFlash(2);
	m_pane1->SetSize(76,76);
	m_pane1->SetClipSize(76,76);
	m_pane1->SetMaskColor(RGB(255,255,255));
	m_pane1->InitSprite(hdc,hinst,"bitmap//Pane1.bmp");

	m_pane2->SetIsFlash(2);
	m_pane2->SetSize(76,76);
	m_pane2->SetClipSize(76,76);
	m_pane2->SetMaskColor(RGB(255,0,255));
	m_pane2->InitSprite(hdc,hinst,"bitmap//Pane2.bmp");

}
void CManage::M_DrawPicture(HDC hdc,HINSTANCE hinst)
{
	//m_dot_temp=NULL;
	if(m_dot_head == NULL)
	{
		m_dot_temp =new DotData;
		m_dot_temp->num = m_picture;
		m_dot_temp->Picture = new CPicture;
		m_dot_temp->Picture->InitPicture(hdc,hinst,m_picture);
		//m_dot_temp->leftPicture->SetIsFlash(3);
		//m_dot_temp->leftPicture->SetSize(700,420);
		//m_dot_temp->leftPicture->SetClipSize(700,420);
		//m_dot_temp->leftPicture->SetPos(40,150);
		//m_dot_temp->leftPicture->InitSprite(hdc,hinst,"bitmap//map//c.bmp");
		//m_dot_temp->leftPicture->InitPicture(hdc,hinst,m_picture);
		//m_dot_temp->rightPicture=NULL;
		//m_dot_temp->rightPicture = new CPicture;
		//m_dot_temp->rightPicture->InitPicture(hdc,hinst,m_picture);
		m_dot_temp->next = NULL;
		m_dot_head = m_dot_temp;
	}
	else
	{
		m_dot_hear = m_dot_head;
		while(m_dot_hear->next != NULL)
		{
			m_dot_hear = m_dot_hear->next;
		}
		m_dot_temp = new DotData;
		m_dot_temp->num = m_picture;
		m_dot_temp->Picture = new CPicture;
		m_dot_temp->Picture->InitPicture(hdc,hinst,m_picture);
		//m_dot_temp->leftPicture->SetIsFlash(3);
		//m_dot_temp->leftPicture->SetSize(700,420);
		//m_dot_temp->leftPicture->SetClipSize(700,420);
		//m_dot_temp->leftPicture->SetPos(40,150);
		//m_dot_temp->leftPicture->InitSprite(hdc,hinst,"bitmap//map//b.bmp");
		//m_dot_temp->rightPicture=NULL;
		//m_dot_temp->rightPicture = new CPicture;
		//m_dot_temp->rightPicture->InitPicture(hdc,hinst,m_picture);
		m_dot_temp->next = NULL;
		m_dot_hear->next = m_dot_temp;
	}

	m_picture++;
}
void CManage::M_InitPane()
{
	int tempNum = 0;
	int tempState = 0;

	for(int i = 0; i < 3; i++)
	{
		if(m_read_head == NULL)
		{
			m_read_temp = new ReadRectData;
			m_read_temp->isDraw = false;
			m_read_temp->leftRectangle = *(m_dot_hear->Picture->GetRectangle() + tempNum);
			m_read_temp->rightRectangle = *(m_dot_hear->Picture->GetSrcRectangle() + tempNum);
			m_read_temp->Picture = new CPicture;

			if(m_read_temp->leftRectangle.bottom - m_read_temp->leftRectangle.top <= 60 && m_read_temp->leftRectangle.right - m_read_temp->leftRectangle.left <= 60)
				tempState = 1;
			else
				tempState = 2;

			switch(tempState)
			{
			case 1:
				m_read_temp->Picture = m_pane1;
				break;
			case 2:
				m_read_temp->Picture = m_pane2;
				break;
			}

			m_read_temp->next = NULL;
			m_read_head = m_read_temp;

		}
		else
		{
			m_read_hear = m_read_head;
			while(m_read_hear->next != NULL)
				m_read_hear = m_read_hear->next;
			m_read_temp = new ReadRectData;	
			m_read_temp->isDraw = false;
			m_read_temp->leftRectangle = *(m_dot_hear->Picture->GetRectangle() + tempNum);
			m_read_temp->rightRectangle = *(m_dot_hear->Picture->GetSrcRectangle() + tempNum);
			m_read_temp->Picture = new CPicture;


			if(m_read_temp->leftRectangle.bottom - m_read_temp->leftRectangle.top <= 60 && m_read_temp->leftRectangle.right - m_read_temp->leftRectangle.left <= 60)
				tempState = 1;
			else 
				tempState = 2;
			switch(tempState)
			{
			case 1:
				m_read_temp->Picture = m_pane1;
				break;
			case 2:
				m_read_temp->Picture = m_pane2;
				break;
			}

			m_read_temp->next = NULL;
			m_read_hear->next = m_read_temp;
		}
		tempNum++;
	}
}
void CManage::M_DrawPane(HDC hdc)
{
	if(m_read_head != NULL)
	{
		m_read_hear = m_read_head;
		while(m_read_hear != NULL)
		{
			if(m_read_hear->isDraw)
			{

				if(m_read_hear->leftRectangle.right - m_read_hear->leftRectangle.left <= 60 
					&& m_read_hear->leftRectangle.bottom - m_read_hear->leftRectangle.top <= 60)
					m_read_hear->Picture->SetPos((m_read_hear->leftRectangle.left + m_read_hear->leftRectangle.right) / 2 - 22,
					(m_read_hear->leftRectangle.bottom + m_read_hear->leftRectangle.top) / 2 - 27);
				else
					m_read_hear->Picture->SetPos(m_read_hear->leftRectangle.left + 5,m_read_hear->leftRectangle.top);

				m_read_hear->Picture->DrawSprite(hdc);

				if(m_read_hear->rightRectangle.right - m_read_hear->rightRectangle.left <= 60 
					&& m_read_hear->rightRectangle.bottom - m_read_hear->rightRectangle.top <= 60)
					m_read_hear->Picture->SetPos((m_read_hear->rightRectangle.left + m_read_hear->rightRectangle.right) / 5 - 22,
					(m_read_hear->rightRectangle.bottom + m_read_hear->rightRectangle.top) / 2 - 27);
				else
					m_read_hear->Picture->SetPos(m_read_hear->rightRectangle.left + 5,m_read_hear->rightRectangle.top);

				m_read_hear->Picture->DrawSprite(hdc);
			}

			m_read_hear = m_read_hear->next;
		}
	}
}