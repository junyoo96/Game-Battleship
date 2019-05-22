//C++ BattleShip 프로젝트
//작성 일자 : 2018-06-01
//학번 : 20152843 이름 : 유영준

#ifndef StatPane_H
#define StatPane_H

#include "Pane.h"
#include <string>
#include <sstream>

// Window shows status
class StatPane : public Pane
{
public:
  StatPane(int x, int y, int width, int height);
  StatPane(int x, int y, int width, int height, int destroyResult);
  ~StatPane();

  virtual void Draw(int _turn);
  virtual void Draw(std::string _destroyResult);
};

#endif
