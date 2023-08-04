#pragma once
class Number
{
	static const int n = 5;
    static const int m = 3;
	int size = 10;
	int map[n][m];
public:
	Number();
	int getMap(int i, int j);
	int getN();
	int getM();
	int getSize();
	void setZero();
	void setOne();
	void setTwo();
	void setThree();
	void setFour();
	void setFive();
	void setSix();
	void setSeven();
	void setEight();
	void setNine();
	void setNull();
};

