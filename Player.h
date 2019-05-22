//C++ BattleShip 프로젝트
//작성 일자 : 2018-06-01
//학번 : 20152843 이름 : 유영준

#ifndef Player_H
#define Player_H

#include "BattleShipMap.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>
#include "Ship.h"
#include "StatPane.h"


#include <string>
#include "Position.h"

//GameManager와 Player사이의 상호참조를 막기위한 것
class GameManager;


class Player
{
public:
  Player();
  Player(int _paneX, int _paneY,const char* _playerType);
  ~Player();

  //Attack();//input target ship form user and tell defender

  //Init();
  //Render();

  void SetupShips(std::vector<Ship>& m_ships); //for the defender

  //내가 구현 한 함수

  //Defender 함수
  std::vector<std::pair<int,int> > RandomShipLocation(std::vector<std::pair<int,int> >&  allocLocations);
  bool CheckFourDirection(int shipSize, char shipName, std::vector<std::pair<int, int> >& decidePosition, std::vector<std::pair<int, int> >& allocLoactions,std::vector<Ship>& m_ships, int targetShipIndex);
  CBattleShipMap& get_Map();
  std::vector<std::string>& NoticeHitResult(Position& inputPos, GameManager& gManager, std::vector<std::string>& result, StatPane& _showDestroyResult);//defender가 attacker에게 공격 결과를 알려주는

  //Attacker 함수
  std::string GetAttPosFromUser(); //구현 필요
  void SetHitResult(Position& position,GameManager& gManager,std::vector<std::string>& hitResult);	//attacker가 자기 맵에 공격 결과 표시

  //Random으로 aI한테 공격좌표 받기
  void GetRanAttPosFromAI(std::vector<int>& ranPos, std::vector<std::pair<int, int> >& alreadyPos);







private:
  CBattleShipMap m_pMap;


};

#endif
