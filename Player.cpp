#include "Player.h"
//GameManager와 Player사이의 상호참조를 막기위한 것
#include "GameManager.h"

Player::Player(int _paneX, int _paneY,const char* _playerType)
:m_pMap(_paneX, _paneY, _playerType)
{
	m_pMap.Draw();
}

Player::Player()
{

}

Player::~Player()
{

}



CBattleShipMap& Player::get_Map()
{
	return m_pMap;
}

std::vector<std::pair<int,int> > Player::RandomShipLocation(std::vector<std::pair<int,int> >&  allocLocations)
{
	int ranNumX=0;
	int ranNumY = 0;

	std::vector<std::pair<int, int> > decidePosition;

	srand((unsigned int)time(NULL));

	std::vector<std::pair<int, int> >::iterator iter;

	//RandomPosition�� ������ ��ġ�� ���� ��ǥ�� ��ġ�� ���� ���

	while (true)
	{
		bool isPositionUnique = true;

		ranNumX = rand() % 8;
		ranNumY = rand() % 8;

		for (iter = allocLocations.begin(); iter != allocLocations.end(); iter++)
		{
			if (iter->first == ranNumX && iter->second == ranNumY)
			{
				isPositionUnique = false;
				break;
			}
		}

		if (isPositionUnique == true)
		{
			break;
		}

	}

	//std::cout << "[" << ranNumX << "," << ranNumY << "]" << std::endl;

	decidePosition.push_back(std::pair<int, int>(ranNumX, ranNumY));

	return decidePosition;
}

bool Player::CheckFourDirection(int shipSize, char shipName, std::vector<std::pair<int, int> >& decidePosition, std::vector<std::pair<int, int> >& allocLoactions,std::vector<Ship>& m_ships, int targetShipIndex)
{

	int tempX = decidePosition.at(0).first;
	int tempY = decidePosition.at(0).second;//���� ���ľߵ�

	//std::cout << "tempX : " << tempX << std::endl;
	//std::cout << "tempY : " << tempY << std::endl;

	bool isPossible = true;

	//��ġ�� ������ �ĺ� ����
	std::vector<int> possibleDirection;

	//��
	for (int i = tempX; i > tempX-shipSize; i--)
	{
		//Y��ǥ �� ������� �˻�
		if (i < 0)
		{
			isPossible = false;
			break;
		}

		//�ʿ� �̹� ��ġ�� �Ǿ��ִٸ�
		if (m_pMap.m_mapData[i][tempY] == 'A' || m_pMap.m_mapData[i][tempY] == 'B' || m_pMap.m_mapData[i][tempY] == 'C' || m_pMap.m_mapData[i][tempY] == 'D')
		{
			isPossible = false;
			break;
		}
	}

	//�� ������ ��� �����Ѵٸ� �ĺ��������� ����
	if (isPossible==true)
	{
		//���� 0
		possibleDirection.push_back(0);
	}

	isPossible = true;

	//�Ʒ�
	for (int i = tempX; i < tempX+shipSize; i++)
	{
		if (i > 7)
		{
			isPossible = false;
			break;

		}

		//�ʿ� �̹� ��ġ�� �Ǿ��ִٸ�
		if (m_pMap.m_mapData[i][tempY] == 'A' || m_pMap.m_mapData[i][tempY] == 'B' || m_pMap.m_mapData[i][tempY] == 'C' || m_pMap.m_mapData[i][tempY] == 'D')
		{
			isPossible = false;
			break;
		}
	}

	//�ʿ� ��ġ�� �ȵǾ��ִٸ�
	if (isPossible == true)
	{
		//�Ʒ��� 1
		possibleDirection.push_back(1);
	}

	isPossible = true;

	//����
	for (int i = tempY; i > tempY-shipSize; i--)
	{
		if (i < 0)
		{
			isPossible = false;
			break;
		}
		//�ʿ� �̹� ��ġ�� �Ǿ��ִٸ�
		if (m_pMap.m_mapData[tempX][i] == 'A' || m_pMap.m_mapData[tempX][i] == 'B' || m_pMap.m_mapData[tempX][i] == 'C' || m_pMap.m_mapData[tempX][i] == 'D')
		{
			isPossible = false;
			break;
		}

	}

	//�ʿ� ��ġ�� �ȵǾ��ִٸ�
	if (isPossible == true)
	{
		//������ 2
		possibleDirection.push_back(2);
	}

	isPossible = true;

	//������
	for (int i = tempY; i < tempY+shipSize; i++)
	{
		if (i > 7)
		{
			isPossible = false;
		}

		//�ʿ� �̹� ��ġ�� �Ǿ��ִٸ�
		if (m_pMap.m_mapData[tempX][i] == 'A' || m_pMap.m_mapData[tempX][i] == 'B' || m_pMap.m_mapData[tempX][i] == 'C' || m_pMap.m_mapData[tempX][i] == 'D')
		{
			isPossible = false;
			break;
		}
	}

	//�ʿ� ��ġ�� �ȵǾ��ִٸ�
	if (isPossible == true)
	{
		//�������� 3
		possibleDirection.push_back(3);
	}


	/*���� �������� ������ �� �� ��ġ*/

	std::vector<int>::iterator iter;

//	for (iter = possibleDirection.begin(); iter != possibleDirection.end(); iter++)
//	{
//		std::cout << "�����ѹ��� : " << *iter<< std::endl;
//	}


	//��� ������ �� �ȵǴ� ���
	if (possibleDirection.size() == 0)
	{
		//std::cout << "��� ���� �� �ȵ�!" << std::endl;
		return false;
	}
	//�ĺ������� �ִ� ��� �������� ������
	else
	{

		srand((unsigned int)time(NULL));

		int randomTest = possibleDirection.at(rand() % (possibleDirection.size()));

//		std::cout << "RandomTest : " << randomTest << std::endl;
//		std::cout << "ShipName :" << shipName << std::endl;

		//�ĺ����� �� �������� �������ϱ�
		switch (randomTest)
		{
		//��
		case 0:

			for (int i = tempX; i > tempX - shipSize; i--)
			{
				//allocLocation ���Ϳ� ��ǥ ����(�̹� ��ǥ�� �谡 ��ġ�ƴٴ� ���� �˷��ֱ� ����)
				allocLoactions.push_back(std::pair<int, int>(i, tempY));

				//�� �迭�� �� ��ġ
				m_pMap.m_mapData[i][tempY] = shipName;

				Position pos1(i,tempY);
				m_ships[targetShipIndex].GetPosition().push_back(pos1);
			}
			break;
		//�Ʒ�
		case 1:
			for (int i = tempX; i < tempX + shipSize; i++)
			{
				//allocLocation ���Ϳ� ��ǥ ����(�̹� ��ǥ�� �谡 ��ġ�ƴٴ� ���� �˷��ֱ� ����)
				allocLoactions.push_back(std::pair<int, int>(i, tempY));
				//�ʿ� �� ��ġ
				m_pMap.m_mapData[i][tempY] = shipName;


				Position pos1(i,tempY);
				m_ships[targetShipIndex].GetPosition().push_back(pos1);
			}
			break;
		//����
		case 2:

			for (int i = tempY; i > tempY - shipSize; i--)
			{
				//allocLocation ���Ϳ� ��ǥ ����(�̹� ��ǥ�� �谡 ��ġ�ƴٴ� ���� �˷��ֱ� ����)
				allocLoactions.push_back(std::pair<int, int>(tempX, i));
				//�ʿ� �� ��ġ
				m_pMap.m_mapData[tempX][i] = shipName;


				Position pos1(tempX,i);
				m_ships[targetShipIndex].GetPosition().push_back(pos1);
			}
			break;
		//������
		case 3:
			for (int i = tempY; i < tempY + shipSize; i++)
			{
				//allocLocation ���Ϳ� ��ǥ ����(�̹� ��ǥ�� �谡 ��ġ�ƴٴ� ���� �˷��ֱ� ����)
				allocLoactions.push_back(std::pair<int, int>(tempX, i));
				//�ʿ� �̹� ��ġ�� �Ǿ��ִٸ�
				m_pMap.m_mapData[tempX][i] = shipName;

				Position pos1(tempX,i);
				m_ships[targetShipIndex].GetPosition().push_back(pos1);
			}
			break;
		}

		//std::cout <<"allocations :"<< allocLoactions.size() << std::endl;


		return true;
	}

}

void Player::SetupShips(std::vector<Ship>& m_ships)
{
	//�̹� ��ġ�� �ڸ� �����ϴ� vector
		std::vector<std::pair<int, int> > allocLocations;

		//�� Size
		int shipSize = 5;
		//�� �̸�
		char shipName='/';
		//마지막 2개 사이즈 배가 한번더 돌게 해주는 변수
		bool isTwoChecked = false;
		//원하는 배에 랜덤으로 생성된 좌표를 넣어주기 위해서 사용
		int targetShipIndex=0;

		//while�� �ʿ�
		while (shipSize!=1)
		{

			switch (shipSize)
			{
			case 5:
				shipName = 'A';
				break;
			case 4:
				shipName = 'B';
				break;
			case 3:
				shipName = 'C';
				break;
			case 2:
				shipName = 'D';
				break;
			}

			//배 랜덤으로 배치하는 코드
			//���� ��ǥ�� ������ ����
			std::vector<std::pair<int, int> > decidePosition = RandomShipLocation(allocLocations);
			//������ ������ �� ��ġ
			if (CheckFourDirection(shipSize, shipName, decidePosition, allocLocations,m_ships,targetShipIndex) == false)
			{
				continue;
			}



			if (shipSize == 2 && isTwoChecked == false)
			{
				//바꿈
				targetShipIndex++;
				isTwoChecked = true;
			}
			else {
				targetShipIndex++;
				--shipSize;
			}
		}


}

std::vector<std::string>& Player::NoticeHitResult(Position& inputPos,GameManager& gManager, std::vector<std::string>& result, StatPane& _showDestroyResult)
{


	//A
	if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='A')
	{
		if(gManager.Getm_Ships()[0].Getm_Hp()!=0)
		{
			//공격 당한 배의 HP를 10 깍음
			gManager.Getm_Ships()[0].Setm_Hp(gManager.Getm_Ships()[0].Getm_Hp()-10);

			//공격당한 곳을 'AH'로 맵 값 변경 , AH=
			m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]='N';

			if(gManager.Getm_Ships()[0].Getm_Hp()==0)
			{
				for(int i=0; i<gManager.Getm_Ships()[0].GetPosition().size(); ++i)
				{
					//배의 HP가 0이되면 그 배의 좌표값에 해당하는 맵의 값을 모두 AD로 만들어줌
					m_pMap.m_mapData[gManager.Getm_Ships()[0].GetPosition()[i].x][gManager.Getm_Ships()[0].GetPosition()[i].y]='S';


				}

				result.push_back("DESTROY");
				result.push_back("A");
				gManager.SetReaminShips(gManager.GetRemainShips()-1);
				_showDestroyResult.Draw("AIRCRAFT DESTROY");

				return result;
			}
			else
			{
				result.push_back("HIT");
				result.push_back("None");
				_showDestroyResult.Draw("HIT");
				return result;
			}
		}
	}
	else if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='N')//해당좌표가 이미 공격된 곳이라면
	{
		result.push_back("HIT");
		result.push_back("None");
		_showDestroyResult.Draw("HIT");

		return result;
	}
	else if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='S')
	{
		result.push_back("DESTROY");
		result.push_back("A");
		_showDestroyResult.Draw("AIRCRAFT DESTROY");

		return result;
	}

	//B
	if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='B')
		{
			if(gManager.Getm_Ships()[1].Getm_Hp()!=0)
			{
				//공격 당한 배의 HP를 10 깍음
				gManager.Getm_Ships()[1].Setm_Hp(gManager.Getm_Ships()[1].Getm_Hp()-10);

				//공격당한 곳을 'AH'로 맵 값 변경
				m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]='Z';

				if(gManager.Getm_Ships()[1].Getm_Hp()==0)
				{
					for(int i=0; i<gManager.Getm_Ships()[1].GetPosition().size(); ++i)
					{
						//배의 HP가 0이되면 그 배의 좌표값을 모두 AD로 만들어줌
						m_pMap.m_mapData[gManager.Getm_Ships()[1].GetPosition()[i].x][gManager.Getm_Ships()[1].GetPosition()[i].y]='T';
					}

					result.push_back("DESTROY");
					result.push_back("B");
					_showDestroyResult.Draw("BATTLESHIP DESTROY");
					gManager.SetReaminShips(gManager.GetRemainShips()-1);

					return result;
				}
				else
				{

					result.push_back("HIT");
					result.push_back("None");
					_showDestroyResult.Draw("HIT");
					return result;
				}
			}
		}
	else if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='Z')//해당좌표가 이미 공격된 곳이라면
		{
			result.push_back("HIT");
			result.push_back("None");
			_showDestroyResult.Draw("HIT");

			return result;
		}
		else if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='T')
		{
			result.push_back("DESTROY");
			result.push_back("B");
			_showDestroyResult.Draw("BATTLESHIP DESTROY");

			return result;
		}

	//C
	if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='C')
		{
			if(gManager.Getm_Ships()[2].Getm_Hp()!=0)
			{
				//공격 당한 배의 HP를 10 깍음
				gManager.Getm_Ships()[2].Setm_Hp(gManager.Getm_Ships()[2].Getm_Hp()-10);

				//공격당한 곳을 'CH'로 맵 값 변경
				m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]='P';

				if(gManager.Getm_Ships()[2].Getm_Hp()==0)
				{
					for(int i=0; i<gManager.Getm_Ships()[2].GetPosition().size(); ++i)
					{
						m_pMap.m_mapData[gManager.Getm_Ships()[2].GetPosition()[i].x][gManager.Getm_Ships()[2].GetPosition()[i].y]='V';
					}

					result.push_back("DESTROY");
					result.push_back("C");
					_showDestroyResult.Draw("CRUISER DESTROY");

					gManager.SetReaminShips(gManager.GetRemainShips()-1);

					return result;
				}
				else
				{
					result.push_back("HIT");
					result.push_back("None");
					_showDestroyResult.Draw("HIT");
					return result;
				}
			}
		}
	else if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='P')//해당좌표가 이미 공격된 곳이라면
		{
			result.push_back("HIT");
			result.push_back("None");
			_showDestroyResult.Draw("HIT");

			return result;
		}
		else if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='V')
		{
			result.push_back("DESTROY");
			result.push_back("C");
			_showDestroyResult.Draw("CRUISER DESTROY");

			return result;
		}

	//D1	//D구분하는 알고리즘 있어야함 , defender맵에서 실제 값은 다르고 보일때만 D로 출력되게 해야될듯


	if(((gManager.GetShips()[3].GetPosition()[0].x==inputPos.GetX() && gManager.GetShips()[3].GetPosition()[0].y==inputPos.GetY())
			|| (gManager.GetShips()[3].GetPosition()[1].x==inputPos.GetX() && gManager.GetShips()[3].GetPosition()[1].y==inputPos.GetY())) && m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='D'
	)
		{
			if(gManager.Getm_Ships()[3].Getm_Hp()!=0)
			{
				//공격 당한 배의 HP를 10 깍음
				gManager.Getm_Ships()[3].Setm_Hp(gManager.Getm_Ships()[3].Getm_Hp()-10);

				//공격당한 곳을 'AH'로 맵 값 변경
				m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]='Q';

				if(gManager.Getm_Ships()[3].Getm_Hp()==0)
				{
					for(int i=0; i<gManager.Getm_Ships()[3].GetPosition().size(); ++i)
					{
						//배의 HP가 0이되면 그 배의 좌표값을 모두 DD로 만들어줌
						m_pMap.m_mapData[gManager.Getm_Ships()[3].GetPosition()[i].x][gManager.Getm_Ships()[3].GetPosition()[i].y]='U';
					}

					result.push_back("DESTROY");
					result.push_back("D1");
					_showDestroyResult.Draw("DESTROYER DESTROY");

					gManager.SetReaminShips(gManager.GetRemainShips()-1);

					return result;

				}
				else
				{
					result.push_back("HIT");
					result.push_back("None");
					_showDestroyResult.Draw("HIT");
					return result;
				}
			}
		}
	else if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='Q')//해당좌표가 이미 공격된 곳이라면
		{
			result.push_back("HIT");
			result.push_back("None");
			_showDestroyResult.Draw("HIT");

			return result;
		}
		else if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='U')
		{
			result.push_back("DESTROY");
			result.push_back("D1");
			_showDestroyResult.Draw("DESTROYER DESTROY");

			return result;
		}

	//D2	//D구분하는 알고리즘 있어야함 , defender맵에서 실제 값은 다르고 보일때만 D로 출력되게 해야될듯
		if(((gManager.GetShips()[4].GetPosition()[0].x==inputPos.GetX() && gManager.GetShips()[4].GetPosition()[0].y==inputPos.GetY())
				|| (gManager.GetShips()[4].GetPosition()[1].x==inputPos.GetX() && gManager.GetShips()[4].GetPosition()[1].y==inputPos.GetY())) && m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='D'
		)
			{
				if(gManager.Getm_Ships()[4].Getm_Hp()!=0)
				{
					//공격 당한 배의 HP를 10 깍음
					gManager.Getm_Ships()[4].Setm_Hp(gManager.Getm_Ships()[4].Getm_Hp()-10);

					//공격당한 곳을 'AH'로 맵 값 변경
					m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]='R';

					if(gManager.Getm_Ships()[4].Getm_Hp()==0)
					{
						for(int i=0; i<gManager.Getm_Ships()[4].GetPosition().size(); ++i)
						{
							//배의 HP가 0이되면 그 배의 좌표값을 모두 DD로 만들어줌
							m_pMap.m_mapData[gManager.Getm_Ships()[4].GetPosition()[i].x][gManager.Getm_Ships()[4].GetPosition()[i].y]='W';
						}

						result.push_back("DESTROY");
						result.push_back("D2");
						_showDestroyResult.Draw("DESTROYER DESTROY");

						gManager.SetReaminShips(gManager.GetRemainShips()-1);

						return result;

					}
					else
					{
						result.push_back("HIT");
						result.push_back("None");
						_showDestroyResult.Draw("HIT");
						return result;
					}
				}
			}
		else if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='R')//해당좌표가 이미 공격된 곳이라면
			{
				result.push_back("HIT");
				result.push_back("None");
				_showDestroyResult.Draw("HIT");

				return result;
			}
			else if(m_pMap.m_mapData[inputPos.GetX()][inputPos.GetY()]=='W')
			{
				result.push_back("DESTROY");
				result.push_back("D2");
				_showDestroyResult.Draw("DESTROYER DESTROY");

				return result;
			}



	result.push_back("MISS");
	result.push_back("None");
	_showDestroyResult.Draw("MISS");

	return result;


}

//std::vector<std::string,std::string>로 되어있는거 바꿔야됨
void Player::SetHitResult(Position& position, GameManager& gManager,std::vector<std::string>& hitResult)
{
	if(hitResult[0]=="MISS")
	{
		m_pMap.m_mapData[position.GetX()][position.GetY()]='M';
	}
	else if(hitResult[0]=="HIT")
	{
		m_pMap.m_mapData[position.GetX()][position.GetY()]='H';
	}
	else if(hitResult[0]=="DESTROY")
	{
		if(hitResult[1]=="A")
		{
			for(int i=0; i<gManager.Getm_Ships()[0].GetPosition().size(); ++i)
			{
				m_pMap.m_mapData[gManager.Getm_Ships()[0].GetPosition()[i].x][gManager.Getm_Ships()[0].GetPosition()[i].y]='D';
			}
		}
		else if(hitResult[1]=="B")
		{
			for(int i=0; i<gManager.Getm_Ships()[1].GetPosition().size(); ++i)
			{
				m_pMap.m_mapData[gManager.Getm_Ships()[1].GetPosition()[i].x][gManager.Getm_Ships()[1].GetPosition()[i].y]='D';
			}
		}
		else if(hitResult[1]=="C")
		{
			for(int i=0; i<gManager.Getm_Ships()[2].GetPosition().size(); ++i)
			{
				m_pMap.m_mapData[gManager.Getm_Ships()[2].GetPosition()[i].x][gManager.Getm_Ships()[2].GetPosition()[i].y]='D';
			}
		}
		else if(hitResult[1]=="D1")
		{
			for(int i=0; i<gManager.Getm_Ships()[3].GetPosition().size(); ++i)
			{
				m_pMap.m_mapData[gManager.Getm_Ships()[3].GetPosition()[i].x][gManager.Getm_Ships()[3].GetPosition()[i].y]='D';
			}
		}
		else if(hitResult[1]=="D2")
				{
					for(int i=0; i<gManager.Getm_Ships()[4].GetPosition().size(); ++i)
					{
						m_pMap.m_mapData[gManager.Getm_Ships()[4].GetPosition()[i].x][gManager.Getm_Ships()[4].GetPosition()[i].y]='D';
					}
				}
	}

}

std::string Player::GetAttPosFromUser()
{

	char input;
	std::string checkEnter;

	std::string tempString;

	 move(17,39);
	  while(true)
	  {



		  input=getch();
		  if(input!=' ')
		  {
			  tempString=input;
			  checkEnter.append(tempString);
		  }
		  if(input=='\n')
		  {
			  break;
		  }

	  }

	  return checkEnter;

}

void Player::GetRanAttPosFromAI(std::vector<int>& ranPos, std::vector<std::pair<int, int> >& alreadyPos)
{
	srand((unsigned int)time(NULL));

	int ranNumX=0;
	int ranNumY=0;

	bool isSameChecked=false;

	std::vector<std::pair<int, int> >::iterator iter;

	while(true)
	{
		ranNumX = rand() % 8;
		ranNumY = rand() % 8;

		for (iter = alreadyPos.begin(); iter != alreadyPos.end(); iter++)
		{
					if (iter->first == ranNumX && iter->second == ranNumY)
					{
						isSameChecked=true;
						break;
					}
					else
					{
						isSameChecked=false;
					}
		}

		if(isSameChecked==true)
		{
			continue;
		}
		else
		{
			alreadyPos.push_back(std::pair<int, int>(ranNumX, ranNumY));
			ranPos.push_back(ranNumX);
			ranPos.push_back(ranNumY);
			break;
		}

	}


}
