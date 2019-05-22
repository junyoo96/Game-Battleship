#include "BattleShipMap.h"

CBattleShipMap::CBattleShipMap()
  :Pane(4,4,MAP_SIZE+4,MAP_SIZE+2)
{
  for(int i=0; i<MAP_SIZE; i++)
  {
    for(int j=0; j<MAP_SIZE; j++)
    {
      // initialize map data
      m_mapData[i][j]='0';
    }
  }

  // distinct area name
  for(int i=0; i<MAP_SIZE; i++)
  {
    mvprintw(i+1+m_y, m_x-1,"%c",'A'+i);
    mvprintw(m_y+m_height, m_x+2+i,"%d",1+i);
  }

  //title
  mvwprintw(m_pWindow,0,2,"DEFENDER");

}

CBattleShipMap::CBattleShipMap(int _paneX, int _paneY,const char* _playerType)
	:Pane(_paneX,_paneY,MAP_SIZE+4,MAP_SIZE+2)
{
	for(int i=0; i<MAP_SIZE; i++)
	  {
	    for(int j=0; j<MAP_SIZE; j++)
	    {
	      // initialize map data
	      m_mapData[i][j]='0';
	    }
	  }

	  // distinct area name
	  for(int i=0; i<MAP_SIZE; i++)
	  {
	    mvprintw(i+1+m_y, m_x-1,"%c",'A'+i);
	    mvprintw(m_y+m_height, m_x+2+i,"%d",1+i);
	  }

	  //title
	  mvwprintw(m_pWindow,0,2,_playerType);

}

CBattleShipMap::~CBattleShipMap()
{
}

void CBattleShipMap::Draw()
{
  wattron(m_pWindow, COLOR_PAIR(1));
  for(int i=0; i<MAP_SIZE; i++)
  {
    for(int j=0; j<MAP_SIZE; j++)
    {
      mvwprintw(m_pWindow,i+1,j+2,"%c",m_mapData[i][j]);
    }
  }
  wattroff(m_pWindow,COLOR_PAIR(1));

  wrefresh(m_pWindow);
}
