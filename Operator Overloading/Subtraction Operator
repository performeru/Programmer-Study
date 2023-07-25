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

friend Point2D operator - (const Point2D& x, const Point2D& y)
	{
		Point2D result;

		result.mX = x.mX - y.mX;
		result.mY = x.mY - y.mY;

		return result;
	}
}
