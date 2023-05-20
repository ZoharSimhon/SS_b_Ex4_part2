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
    string toPrint = "(" + to_string(this->x_) + "," + to_string(this->y_) + ")";
    return toPrint;
}

const Point Point::moveTowards(const Point &src, const Point &dest, double distance)
{

    if (distance < 0)
        throw invalid_argument("Dinstance must to be non-negative number");
    if (distance == 0)
        return src;
    if (src.distance(dest) <= distance)
        return dest;

    // Calculate the vector components (dx, dy) from source to destination
    double dx = dest.x_ - src.x_;
    double dy = dest.y_ - src.y_;

    // Calculate the magnitude of the vector (dx, dy)
    double magnitude = sqrt(dx * dx + dy * dy);

    // Calculate the scaling factor to move along the vector
    double scale = distance / magnitude;

    // Calculate the new point by moving distance along the vector
    double x = src.x_ + scale * dx;
    double y = src.y_ + scale * dy;

    return Point(x, y);
}
