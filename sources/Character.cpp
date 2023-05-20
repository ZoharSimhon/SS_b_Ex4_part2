#include "Character.hpp"
using namespace ariel;

// constructor
Character::Character(const Point &location, int hitPoint, string name, bool isNinja)
    : location_(location), hitPoint_(hitPoint), name_(name), isNinja_(isNinja), isPlay_(false) {}

// five methods:
Character::Character(const Character &other)
    : location_(other.location_), hitPoint_(other.hitPoint_),
      name_(other.name_), isNinja_(other.isNinja_), isPlay_(false) {}

Character::Character(Character &&other) noexcept
    : location_(other.location_), hitPoint_(other.hitPoint_),
      name_(other.name_), isNinja_(other.isNinja_), isPlay_(false) {}

Character &Character::operator=(const Character &other)
{
    if (this == &other)
        return *this;

    this->location_ = other.location_;
    this->hitPoint_ = other.hitPoint_;
    this->name_ = other.name_;
    this->isNinja_ = other.isNinja_;
    this->isPlay_ = other.isPlay_;

    return *this;
}
Character &Character::operator=(Character &&other) noexcept
{
    if (this == &other)
        return *this;

    this->location_ = move(other.location_);
    this->hitPoint_ = other.hitPoint_;
    this->name_ = move(other.name_);
    this->isNinja_ = other.isNinja_;
    this->isPlay_ = other.isPlay_;

    return *this;
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

bool Character::isAlive() const
{
    return this->hitPoint_ > 0;
}
double Character::distance(const Character *otherCharecter) const
{
    return this->location_.distance(otherCharecter->location_);
}

void Character::hit(int num)
{
    if (num < 0)
        throw invalid_argument("can't hit negive number");

    this->hitPoint_ -= num;
    if (this->hitPoint_ < 0)
        this->hitPoint_ = 0;
}
