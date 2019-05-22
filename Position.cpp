/*
 * Position.cpp
 *
 *  Created on: 2018. 5. 30.
 *      Author: junyoo96
 */

#include "Position.h"

Position::Position(int _x, int _y)
{
	x=_x;
	y=_y;
}

int Position::GetX()
{
	return x;
}

int Position::GetY()
{
	return y;
}

void Position::SetX(int _x)
{
	x=_x;
}

void Position::SetY(int _y)
{
	y=_y;
}



