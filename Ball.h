#pragma once
#include <stdint.h>

class Ball
{
	int length = 40;
	int position_x;
	int position_y;
	double alpha;
	bool clockwise = true;
	int color = INT32_MAX;
public:
	Ball();
	Ball(int x, int y, double a);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int getLength();
	int getColor();
	bool getWise();
	void changeWise();
	double getAlpha();
	void addAlpha(double a);
};

