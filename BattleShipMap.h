//C++ BattleShip 프로젝트
//작성 일자 : 2018-06-01
//학번 : 20152843 이름 : 유영준

#ifndef BattleShipMap_H
#define BattleShipMap_H

#include "Pane.h"
//#include <string>

#define MAP_SIZE 8

// Class shows the map of game screen
class CBattleShipMap : Pane
{
public:
  CBattleShipMap();
  CBattleShipMap(int _paneX, int _paneY,const char* _playerType);

  ~CBattleShipMap();

  void Draw();


public:
  char m_mapData[MAP_SIZE][MAP_SIZE];
};

#endif
