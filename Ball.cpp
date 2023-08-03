#include "Ball.h"

Ball::Ball()
{

}
Ball::Ball(int x, int y, double a)
{
	position_x = x;
	position_y = y;
	alpha = a;
}
int Ball::getX()
{
	return position_x;
}
int Ball::getY()
{
	return position_y;
}
void Ball::setX(int x)
{
	position_x = x;
}
void Ball::setY(int y)
{
	position_y = y;
}
int Ball::getLength()
{
	return length;
}
int Ball::getColor()
{
	return color;
}
bool Ball::getWise()
{
	return clockwise;
}
void Ball::changeWise()
{
	clockwise = !clockwise;
}
double Ball::getAlpha()
{
	return alpha;
}
void Ball::addAlpha(double a)
{
	alpha += a;
}

