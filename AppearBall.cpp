#include "AppearBall.h"

#define SPEED 4
#include <time.h>
#include <stdlib.h>

AppearBall::AppearBall()
{

}
AppearBall::AppearBall(int x1, int y1, int x2, int y2, int t, bool m)
{
	srand(time(NULL));
	move = m;
	k = (double)(y2 - y1) / (double)(x2 - x1);
  	b = y1 - x1 * (y2 - y1) / (x2 - x1);
	position_x = -length;
	position_y = k * position_x + b;

	if (t % 2 == 0)
	{
		type = Type::Danger;
		color = DANGER_COLOR;
	}
	else
	{
		type = Type::Coin;
		color = COIN_COLOR;
	}
}
int AppearBall::getLength()
{
	return length;
}
int AppearBall::getX()
{
	return position_x;
}
int AppearBall::getY()
{
	return position_y;
}
int AppearBall::getColor()
{
	return color;
}
Type AppearBall::getType()
{
	return type;
}
bool AppearBall::getMove()
{
	return move;
}
void AppearBall::setMove(bool m)
{
	move = m;
}
void AppearBall::updateBall()
{
	position_x += SPEED;
	position_y = k * position_x + b;
}

