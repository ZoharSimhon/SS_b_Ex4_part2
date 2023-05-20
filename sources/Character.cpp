#include "Character.hpp"
using namespace ariel;

// constructor
Character::Character(const Point &location, int hitPoint, string name, bool isNinja)
    : location_(location), hitPoint_(hitPoint), name_(name), isNinja_(isNinja), isPlay_(false) {}

bool Character::isAlive() const
{
    return this->hitPoint_ > 0;
}

// getters
string Character::getName() const
{
    return this->name_;
}
Point Character::getLocation() const
{
    return this->location_;
}
int Character::getHitPoint() const
{
    return this->hitPoint_;
}
bool Character::getIsNinja() const
{
    return this->isNinja_;
}
bool Character::getIsPlay() const
{
    return this->isPlay_;
}

// setters
void Character::setLocation(const Point &dest)
{
    this->location_ = dest;
}
void Character::setIsPlay()
{
    this->isPlay_ = true;
}

double Character::distance(const Character *otherCharecter) const
{
    return this->location_.distance(otherCharecter->location_);
}

void Character::hit(int num)
{
    if (num<0)
        throw invalid_argument("can't hit negive number");

    this->hitPoint_ -= num;
    if (this->hitPoint_ < 0)
        this->hitPoint_ = 0;
}
