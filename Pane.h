//C++ BattleShip 프로젝트
//작성 일자 : 2018-06-01
//학번 : 20152843 이름 : 유영준

#ifndef Pane_H
#define Pane_H

#include <ncurses.h>


class Pane
{
public:
  Pane(int x, int y, int width, int height);
  virtual ~Pane();

  virtual void Draw();

  //윈도우를 얻는 함수
  WINDOW* Getm_pWindow();

protected:
  int m_width, m_height;
  int m_x, m_y;
  WINDOW* m_pWindow;
};

#endif
