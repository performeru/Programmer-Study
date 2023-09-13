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

Point2D& operator--()
	{
		mX--;
		mY--;
		return *this;
	}

}
