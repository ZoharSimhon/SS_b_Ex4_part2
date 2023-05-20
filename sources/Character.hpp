#pragma once
#include "Point.hpp"

const int YOUNG_NINJA_HIT_POINT = 100;
const int TRAINED_NINJA_HIT_POINT = 120;
const int OLD_NINJA_HIT_POINT = 150;
const int COWBOY_HIT_POINT = 110;

const int YOUNG_NINJA_SPEAD = 14;
const int TRAINED_NINJA_SPEAD = 12;
const int OLD_NINJA_SPEAD = 8;
const int COWBOY_BULLETS_NUMBER = 6;

const bool NINJA = true;
const bool COWBOY = false;

namespace ariel
{
    class Character
    {
    private:
        Point location_;
        int hitPoint_;
        string name_;
        bool isNinja_;

    public:
        // constructor
        Character(const Point &, int, string, bool);

        // getters
        string getName() const;
        Point getLocation() const;
        int getHitPoint() const;
        bool getIsNinja() const;

        // setters
        void setLocation(const Point &);

        bool isAlive() const;
        double distance(const Character &) const;
        void hit(int);

        //virtual functions
        virtual string print() const = 0;
        virtual void attack(Character *) = 0;
    }; // class Character

} // namespace ariel
