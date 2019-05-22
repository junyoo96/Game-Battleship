//C++ BattleShip 프로젝트
//작성 일자 : 2018-06-01
//학번 : 20152843 이름 : 유영준

#ifndef Ship_H
#define Ship_H

#include <string>
#include "Position.h"
#include <vector>

class Ship
{
private:
  int m_Hp;
  std::string m_name;
  std::vector<Position> m_position;
  int m_Size;
  char m_Type;	//'A'이런 것 말하는듯

public:
  Ship(int m_Hp,std::string m_name,int m_Size, char m_Type);
  ~Ship();

  std::string GetName();
  std::vector<Position>& GetPosition();
  int GetSize();
  char GetType();
  bool HitCheck(Position pos);
  void SetPosition(int x, int y);

  int Getm_Hp();
  void Setm_Hp(int m_Hp);

};

#endif
