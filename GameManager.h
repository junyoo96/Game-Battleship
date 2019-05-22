//C++ BattleShip 프로젝트
//작성 일자 : 2018-06-01
//학번 : 20152843 이름 : 유영준

#ifndef GameManager_H
#define GameManager_H

#include "Player.h"
#include "Ship.h"
#include "Aircraft.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include <list>
#include <vector>

class GameManager
{
public:
  GameManager();
  GameManager(int _paneX, int _paneY);
  ~GameManager();
  //AddTurn(); //count turn of the gamek
  //AttackByInput(); //Get Input from Attacker
  //GetGameMode(); //Set GameMode
  //GetInstance(); //instance 받을때
  //GetTurn();
  //Init();
  //isDeadShip();
  //Render();
  //SetGameMode();


  std::vector<Ship>& GetShips(); //배 인스턴스를 생성하고 배를 담은 벡터를 반
  int GetRemainShips();
  void SetReaminShips(int remainShips);

  std::vector<Ship>& Getm_Ships();

  Player& Getm_Attacker();
  Player& Getm_Defender();

  int Getm_Turn();
  void Setm_Turn(int _turn);


private:
  Player m_Attacker;
  Player m_Defender;
  //enum m_GameMode;
  std::vector<Ship> m_Ships;
  int m_Turn; //show how many turns are played
  int remainShips;


};

#endif
