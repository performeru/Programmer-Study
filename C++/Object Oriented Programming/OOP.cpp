#include <iostream>


class Point 
{
private:
    double x;
    double y;

public:
    Point(double xCoord, double yCoord);

    double DistanceFromOrigin() const;

    void PrintCoordinates() const;
};

Point::Point(double xCoord, double yCoord) 
{
    x = xCoord;
    y = yCoord;
}

double Point::DistanceFromOrigin() const
{
    return sqrt(x * x + y * y);
}

void Point::PrintCoordinates() const 
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

int main() 
{
    double x{}, y{};
    std::cout << "Enter x coordinate: ";
    std::cin >> x;
    std::cout << "Enter y coordinate: ";
    std::cin >> y;
    
    Point p(x, y);
    std::cout << "Distance from origin: " << p.DistanceFromOrigin() << std::endl;
    p.PrintCoordinates();

    return 0;
}
