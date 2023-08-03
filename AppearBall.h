#pragma once
#include <stdint.h>

enum class Type { Danger, Coin };
#define DANGER_COLOR 0
#define COIN_COLOR INT32_MAX

class AppearBall
{
	int length = 40;
	int position_x = 0;
	int position_y;
	double k;
	int b;
	int color;
	Type type;
	bool move;
public:
	AppearBall();
	AppearBall(int x1, int y1, int x2, int y2, int t, bool m);
	int getLength();
	int getX();
	int getY();
	int getColor();
	Type getType();
	bool getMove();
	void setMove(bool m);
	void updateBall();
};

