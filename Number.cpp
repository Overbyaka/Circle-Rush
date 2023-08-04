#include "Number.h"

Number::Number()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map[i][j] = 0;
		}
	}
}

int Number::getMap(int i, int j)
{
	return map[i][j];
}
int Number::getN()
{
	return n;
}
int Number::getM()
{
	return m;
}
int Number::getSize()
{
	return size;
}
void Number::setZero()
{
	for (int i = 0; i < n; i++)
	{
		map[i][0] = 1;
		map[i][2] = 1;
		if (i == 0 || i == 4)
			map[i][1] = 1;
	}
}
void Number::setOne()
{
	for (int i = 0; i < n; i++)
	{
		map[i][1] = 1;
		if (i == 1)
			map[i][0] = 1;
		else if (i == 4)
		{
			map[i][0] = 1;
			map[i][2] = 1;
		}
	}
}
void Number::setTwo()
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || i == 2 || i == 4)
		{
			map[i][0] = 1;
			map[i][1] = 1;
			map[i][2] = 1;
		}
		else if (i == 1)
		{
			map[i][2] = 1;
		}
		else
		{
			map[i][0] = 1;
		}
	}
}
void Number::setThree()
{
	for (int i = 0; i < n; i++)
	{
		map[i][2] = 1;
		if (i == 0 || i == 2 || i == 4)
		{
			map[i][0] = 1;
			map[i][1] = 1;
		}
	}
}
void Number::setFour()
{
	for (int i = 0; i < n; i++)
	{
		map[i][2] = 1;
		if (i == 0 || i == 1)
		{
			map[i][0] = 1;
		}
		else if (i == 2)
		{
			map[i][0] = 1;
			map[i][1] = 1;
		}
	}
}
void Number::setFive()
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || i == 2 || i == 4)
		{
			map[i][0] = 1;
			map[i][1] = 1;
			map[i][2] = 1;
		}
		else if (i == 1)
		{
			map[i][0] = 1;
		}
		else
		{
			map[i][2] = 1;
		}
	}
}
void Number::setSix()
{
	for (int i = 0; i < n; i++)
	{
		map[i][0] = 1;
		if (i == 0 || i == 2 || i == 4)
		{
			map[i][1] = 1;
			map[i][2] = 1;
		}
		else if (i == 3)
		{
			map[i][2] = 1;
		}
	}
}
void Number::setSeven()
{
	for (int i = 0; i < n; i++)
	{
		map[i][2] = 1;
		if (i == 0)
		{
			map[i][1] = 1;
			map[i][0] = 1;
		}
	}
}
void Number::setEight()
{
	for (int i = 0; i < n; i++)
	{
		map[i][0] = 1;
		map[i][2] = 1;
		if (i == 0 || i == 2 || i == 4)
			map[i][1] = 1;
	}
}
void Number::setNine()
{
	for (int i = 0; i < 5; i++)
	{
		map[i][2] = 1;
		if (i == 0 || i == 2 || i == 4)
		{
			map[i][1] = 1;
			map[i][0] = 1;
		}
		else if (i == 1)
		{
			map[i][0] = 1;
		}
	}
}
void Number::setNull()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map[i][j] = 0;
		}
	}
}