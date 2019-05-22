#include "StatPane.h"


void StatPane::Draw(int _turn)
{
    wattron(m_pWindow, COLOR_PAIR(2));

    std::string turnCheck="TURN : ";
    std::stringstream ss2;
    ss2<<_turn;
    turnCheck.append(ss2.str().c_str());


    mvwprintw(m_pWindow,1,2,turnCheck.c_str());
    mvwprintw(m_pWindow,2,2,"AIRCRAFT : AAAAA");
    mvwprintw(m_pWindow,3,2,"BATTLESHIP : BBBB");
    mvwprintw(m_pWindow,4,2,"CRUISER : CCC");
    mvwprintw(m_pWindow,5,2,"DESTROYER : DD DD");
    wattroff(m_pWindow,COLOR_PAIR(2));

    wrefresh(m_pWindow);
}

void StatPane::Draw(std::string _destroyResult)
{
		wattron(m_pWindow, COLOR_PAIR(5));
	    mvwprintw(m_pWindow,1,2,_destroyResult.c_str());
	    wattroff(m_pWindow,COLOR_PAIR(5));

	    wrefresh(m_pWindow);
}

StatPane::StatPane(int x, int y, int width, int height)
  :Pane(x,y,width,height)
{
  //title
  mvwprintw(m_pWindow,0,3,"< STATUS >");
}

StatPane::StatPane(int x, int y, int width, int height, int destroyResult)
	:Pane(x,y,width,height)
{
	//title
	//mvwprintw(m_pWindow,0,3,"<HIT RESULT>");
}

StatPane::~StatPane()
{  
}
