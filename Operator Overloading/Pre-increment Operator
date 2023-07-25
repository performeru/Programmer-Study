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

friend Point2D& operator ++(Point2D& arg1)
	{
		arg1.mX++;
		arg1.mY++;

		return arg1;
	}
}
