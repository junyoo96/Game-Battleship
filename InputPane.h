//C++ BattleShip 프로젝트
//작성 일자 : 2018-06-01
//학번 : 20152843 이름 : 유영준

#ifndef InputPane_H
#define InputPane_H

#include "Pane.h"

class InputPane : public Pane
{
public:
  InputPane(int x, int y, int width, int height);
  ~InputPane();

  virtual void Draw();
};

#endif
