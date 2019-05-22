/*
 * GameManager.cpp
 *
 *  Created on: 2018. 5. 30.
 *      Author: junyoo96
 */

#include "GameManager.h"



std::vector<Ship>& GameManager::GetShips()
{
	//pos는 나중에 defender가 배치 할 때 배정

	Aircraft air;
	BattleShip bShip;
	Cruiser cruis;
	Destroyer des1;
	Destroyer des2;

	m_Ships.push_back(air);
	m_Ships.push_back(bShip);
	m_Ships.push_back(cruis);
	m_Ships.push_back(des1);
	m_Ships.push_back(des2);

	return m_Ships;

}

int GameManager::GetRemainShips()
{
	return remainShips;
}

void GameManager::SetReaminShips(int _remainShips)
{
	remainShips=_remainShips;
}

std::vector<Ship>& GameManager::Getm_Ships()
{
	return m_Ships;
}

Player& GameManager::Getm_Attacker()
{
	return m_Attacker;
}

Player& GameManager::Getm_Defender()
{
	return m_Defender;
}

GameManager::GameManager()
{
	remainShips=5;
	m_Turn=0;
}

GameManager::GameManager(int _paneX, int _paneY)
:m_Attacker(_paneX, _paneY, "ATTACKER"), m_Defender(_paneX, _paneY-15, "DEFENDER")
{
	remainShips=5;
		m_Turn=0;
}
GameManager::~GameManager()
{

}

int GameManager::Getm_Turn()
{
	return m_Turn;
}

void GameManager::Setm_Turn(int _turn)
{
	m_Turn=_turn;
}


