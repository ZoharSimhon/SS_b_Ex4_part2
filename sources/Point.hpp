#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x_;
        double y_;

    public:
        // constructors
        Point(double, double);
        //getters
        double getX();
        double getY();
        double distance(const Point &) const;
        string print() const;
        static const Point moveTowards(const Point &,const Point &, double);
    };
}

#endif