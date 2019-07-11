#include "BattleShipApp.h"

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



	  Position attackPos(attackPosX,attackPosY);
	  //Defender가 입력 좌표가 맞았는지 확인하는 함수 호출
	  std::vector<std::string> hitResult;
	  gManager.Getm_Defender().NoticeHitResult(attackPos,gManager,hitResult,destroyPane);

	  //Test(나중에 지워야함)
	  gManager.Getm_Defender().get_Map().Draw();


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


