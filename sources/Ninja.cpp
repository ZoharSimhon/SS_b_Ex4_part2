#include "Ninja.hpp"
using namespace ariel;

Ninja::Ninja(const Point &location, int hitPoint, string name, int spead)
    : Character(location, hitPoint, name, NINJA), spead_(spead) {}

void Ninja::move(const Character *enemy)
{
    if (this->isAlive())
    {
        this->setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), this->spead_));
    }
}
void Ninja::slash(Character *enemy) const
{
    if (this->isAlive() && this->distance(*enemy) < 1)
    {
        enemy->hit(40);
    }
}

// override functions
string Ninja::print() const
{
    string toPrint;
    if (this->isAlive())
        toPrint = "Name: N " + this->getName() +
                  " Number of hit points: " + to_string(this->getHitPoint());
    else
        toPrint = "Name: ( N " + this->getName() + ")";

    return toPrint;
}
void Ninja::attack(Character *enemy)
{
    if (this->distance(*enemy) < 1)
        this->slash(enemy);
    else
    {
        cout<<to_string(distance(*enemy))<<endl;
        this->move(enemy);
    }
}