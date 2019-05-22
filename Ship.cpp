/*
 * Ship.cpp
 *
 *  Created on: 2018. 5. 30.
 *      Author: junyoo96
 */

#include "Ship.h"


Ship::Ship(int m_Hp,std::string m_name,int m_Size, char m_Type)
:m_Hp(m_Hp), m_name(m_name), m_Size(m_Size), m_Type(m_Type)
{

}

Ship::~Ship()
{

}

std::string Ship::GetName()
{
	return m_name;
}

std::vector<Position>& Ship::GetPosition()
{
	return m_position;
}

int Ship::GetSize()
{
	return m_Size;
}

char Ship::GetType()
{
	return m_Type;
}

bool Ship::HitCheck(Position pos)
{
	//구현 필요
	return true;
}

void Ship::SetPosition(int x,int y)
{
	Position p(x,y);


	m_position.push_back(p);
	//구현 필요
}

int Ship::Getm_Hp()
{
	return m_Hp;
}
 void Ship::Setm_Hp(int _m_Hp)
 {
	 m_Hp=_m_Hp;
 }









