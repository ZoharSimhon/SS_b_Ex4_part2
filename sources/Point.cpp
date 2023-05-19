#include "Point.hpp"
using namespace ariel;

// constructor
Point::Point(double x, double y) : x_(x), y_(y) {}

// getters
double Point::getX() { return this->x_; }
double Point::getY() { return this->y_; }

double Point::distance(const Point &otherPoint) const
{
    double xPow = pow((this->x_-otherPoint.x_), 2);
    double yPow = pow((this->y_-otherPoint.y_), 2);
    return sqrt(xPow+yPow);
}

string Point::print() const
{
    string toPrint;
    toPrint << "(" << this->x_ << "," << this->y_ << ")";
    return toPrint;   
}

const Point Point::moveTowards(const Point &src, const Point &dest, double distance)
{
    
    return Point(0.0, 0.0);
}
