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

friend std::ostream& operator<<(std::ostream os,Point2D pt)
	{
		os << "(" << pt.mX << "," << pt.mY << ")";

		return os;
	}
}
