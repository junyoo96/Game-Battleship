//C++ BattleShip 프로젝트
//작성 일자 : 2018-06-01
//학번 : 20152843 이름 : 유영준

#ifndef BattleShipApp_H
#define BattleShipApp_H

#include "BattleShipMap.h"
#include "StatPane.h"
#include "InputPane.h"
#include "GameManager.h"
#include <string>
#include <cstdlib>
#include <sstream>

class CBattleShipApp
{
public:
  CBattleShipApp();
  ~CBattleShipApp();

  void Play();

protected:
  void Init();
  void Render();
  void Destroy();

protected:
  //CBattleShipMap* m_pMap;
  StatPane* m_pStatPane;
  InputPane* m_pInputPane;

};

#endif
