//C++ BattleShip 프로젝트
//작성 일자 : 2018-06-01
//학번 : 20152843 이름 : 유영준

#ifndef Position_H
#define Position_H

class Position
{
public:

	Position(int _x, int _y);

	int GetX();
	int GetY();

	void SetX(int x);
	void SetY(int y);



public:
  int x;
  int y;
};

#endif
