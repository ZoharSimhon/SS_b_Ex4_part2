#include "Point.hpp"
using namespace ariel;

// constructor
Point::Point(double x, double y) : x_(x), y_(y) {}

// getters
double Point::getX() { return this->x_; }
double Point::getY() { return this->y_; }

double Point::distance(const Point &otherPoint) const
{
    double xPow = pow((this->x_ - otherPoint.x_), 2);
    double yPow = pow((this->y_ - otherPoint.y_), 2);
    return sqrt(xPow + yPow);
}

string Point::print() const
{
    string toPrint =  "(" + to_string(this->x_ ) + "," + to_string(this->y_) + ")";
    return toPrint;
}

const Point Point::moveTowards(const Point &src, const Point &dest, double distance)
{
    if (distance == 0)
        return src;
    if (src.distance(dest) <= distance)
        return dest;

    // calculate the equation of a line
    double m = (dest.y_ - src.y_) / (dest.x_ - src.x_); // Calculate the slope
    double b = src.y_ - m * src.x_;                   // Calculate the y-intercept

    // Calculate the coordinates of the point on the line
    double x = (distance / sqrt(1 + m * m)) + src.x_;
    double y = m * (x - src.x_) + src.y_;

    return Point(x, y);
}
