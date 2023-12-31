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

  friend const Point2D& operator++(Point2D& arg1, int v)
  { 
     Point2D temp(arg1.mX, arg1.mY);
     arg1.mX++;	  
     arg1.mY++;

     return temp;
   }
}
