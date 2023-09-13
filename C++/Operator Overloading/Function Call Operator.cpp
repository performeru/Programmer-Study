#include <iostream>

class Point2D
{
private:
	int mX;
	int mY;

public:
	Point2D();
	Point2D(int x, int y);
	void Print();

void operator ()()
	{
		mX = mY = 0;
	}

	void operator ()(int x, int y)
	{
		mX = x;
		mY = y;
	}
}
