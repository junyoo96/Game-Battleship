#include "BattleShipApp.h"
#include "StatPane.h"
#include "InputPane.h"

void CBattleShipApp::Init()
{
  initscr();
  start_color();
  cbreak();
  refresh();

  //color setting

  init_pair(1,COLOR_GREEN,COLOR_BLACK);
  init_pair(2,COLOR_CYAN, COLOR_BLACK);
  init_pair(3,COLOR_YELLOW, COLOR_BLACK);
  init_pair(4,COLOR_YELLOW, COLOR_BLACK);
  init_pair(5,COLOR_RED, COLOR_BLACK);

  //m_pMap=new CBattleShipMap();
  m_pStatPane=new StatPane(30,3,30,7);
  m_pInputPane=new InputPane(30,15,30,4);
}

void CBattleShipApp::Play()
{
	int gameCount=0;
	int turnCount=0;

	while(gameCount<10)
	{



	//처음에 GameMode받아서 분기처리하기 Player모드 or AI모드
  Init();
  Render();
  //mvwprintw(m_pInputPane->Getm_pWindow(),2,3,"ABCD");예시

  //Destroy된 배 출력하는 Pane생성
  StatPane destroyPane(30,23,20,3,1);
  refresh();




  //GameManager이 여기서 게임 로직 적용(여기다 모든 과정 구현 하면됨)
  GameManager gManager(10,20);//Attacker의 좌표

     //배 인스턴스 생성하고 맵에 배 배치시키기
    gManager.Getm_Defender().SetupShips(gManager.GetShips());
    gManager.SetReaminShips(5);
    gManager.Getm_Defender().get_Map().Draw();

    //AI가 중복된 공격좌표를 선택하지 않게 하는 변수
    std::vector<std::pair<int, int> > alreadyPos;



  while(gManager.GetRemainShips()!=0)//끝나는 조건을 남은 배의 수가 0이면으로 판단함
  {
	  //TEst
//	  	  	  std::stringstream ss3;
//	  		ss3<< gManager.Getm_Ships()[3].GetPosition()[1].x;
//
//	  		char const* shipHp3=ss3.str().c_str();
//
//
//	  		mvprintw(20,35,shipHp3);
//
//	  		std::stringstream ss4;
//	  		ss4<< gManager.Getm_Ships()[3].GetPosition()[1].y;
//
//	  		char const* shipHp4=ss4.str().c_str();
//
//
//	  		mvprintw(22,35,shipHp4);
//
//	  	  std::stringstream ss5;
//	  		  		ss5<< gManager.Getm_Ships()[4].GetPosition()[1].x;
//
//	  		  		char const* shipHp5=ss5.str().c_str();
//
//
//	  		  		mvprintw(24,35,shipHp5);
//
//	  		  		std::stringstream ss6;
//	  		  		ss6<< gManager.Getm_Ships()[4].GetPosition()[1].y;
//
//	  		  		char const* shipHp6=ss6.str().c_str();
//
//
//	  		  		mvprintw(26,35,shipHp6);
//
//	  		refresh();
	  		//TEST*

	  	  	  gManager.Setm_Turn(gManager.Getm_Turn()+1);
	  	  	  m_pStatPane->Draw(gManager.Getm_Turn());
		  //Attacker가 공격좌표 입력하는 함수 호출(Position반환)
			//std::string getAxis=gManager.Getm_Attacker().GetAttPosFromUser();


			 werase(destroyPane.Getm_pWindow());

			 //여기에 기존 공격좌표 대신 AI랜덤 공격좌표 함수 받으면 됨
			int attackPosX=0;
			int attackPosY=0;

			 std::vector<int> ranPos;

			gManager.Getm_Attacker().GetRanAttPosFromAI(ranPos,alreadyPos);

			attackPosX=ranPos[0];
			attackPosY=ranPos[1];


//  	  switch(getAxis.at(0))
//  	  {
//  	  case 'A':
//  		  attackPosX=0;
//  		  break;
//  	  case 'B':
//  	  		  attackPosX=1;
//  	  		  break;
//  	  case 'C':
//  	  		  attackPosX=2;
//  	  		  break;
//  	  case 'D':
//  	  		  attackPosX=3;
//  	  		  break;
//  	  case 'E':
//  	  		  attackPosX=4;
//  	  		  break;
//  	  case 'F':
//  	  		  attackPosX=5;
//  	  		  break;
//  	  case 'G':
//  	  		  attackPosX=6;
//  	  		  break;
//  	  case 'H':
//  	  		  attackPosX=7;
//  	  		  break;
//  	  }
//  	  //좌표잘못입력하면 보정해주는 알고리즘필요
//
//  	  attackPosY=getAxis.at(1)-48;
//
//  	  switch(attackPosY)
//  	  {
//  	  case 1:
//  		  attackPosY=0;
//  		  break;
//  	  case 2:
//  	  		  attackPosY=1;
//  	  		  break;
//
//  	  case 3:
//  	  		  attackPosY=2;
//  	  		  break;
//
//  	  case 4:
//  	  		  attackPosY=3;
//  	  		  break;
//  	  case 5:
//  	  		  attackPosY=4;
//  	  		  break;
//  	  case 6:
//  	  		  attackPosY=5;
//  	  		  break;
//  	  case 7:
//  	  		  attackPosY=6;
//  	  		  break;
//  	  case 8:
//  	  		  attackPosY=7;
//  	  		  break;
//  	  }


//					 std::stringstream ss;
//					ss<<attackPosX;
//
//
//					  std::stringstream ss2;
//					ss2<<attackPosY;
//
//					char const* aX=ss.str().c_str();
//					char const* aY=ss2.str().c_str();
//
//					 mvprintw(20,40,aX);
//					mvprintw(22,40,aY);
//					refresh();


	  Position attackPos(attackPosX,attackPosY);
	  //Defender가 입력 좌표가 맞았는지 확인하는 함수 호출
	  std::vector<std::string> hitResult;
	  gManager.Getm_Defender().NoticeHitResult(attackPos,gManager,hitResult,destroyPane);

	  //Test(나중에 지워야함)
	  gManager.Getm_Defender().get_Map().Draw();







	  //aX=hitResult.at(0).c_str();
	  //aY=hitResult.at(1).c_str();
		  //mvprintw(24,40,aX);
		  //mvprintw(26,40,aY);
	  //refresh();
	  //Test


	  //Attacker가 Attacker맵에 공격결과를 표시
	  gManager.Getm_Attacker().SetHitResult(attackPos,gManager,hitResult);
	  gManager.Getm_Attacker().get_Map().Draw();




  }

  turnCount+=gManager.Getm_Turn();

  gameCount++;

	}

	turnCount/=10;

  //게임종료 출력하는 창

	std::string resultString="Ten Times Finished, AVG is ";
	std::stringstream ss2;
	ss2<<turnCount;
	resultString.append(ss2.str().c_str());

    StatPane gameoverPane(30,28,35,3,1);
    gameoverPane.Draw(resultString.c_str());

    getch();

  //게임끝날때 호출
  //Destroy();
    endwin();

}

void CBattleShipApp::Render()
{

  mvprintw(1,1,"<< Battle Ship Game >>");

 // m_pMap->Draw();
  m_pStatPane->Draw(0);
  m_pInputPane->Draw();


  refresh();
}

void CBattleShipApp::Destroy()
{
	getch();

  endwin();
  //delete m_pMap;
}

CBattleShipApp::CBattleShipApp()
{
	m_pInputPane=NULL;
	//m_pMap=NULL;
	m_pStatPane=NULL;
}

CBattleShipApp::~CBattleShipApp()
{
}


