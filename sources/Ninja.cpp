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
    if (!this->isAlive())
        throw runtime_error("a dead Ninja can't shoot");

    if (!enemy->isAlive())
        throw runtime_error("a dead Character can't be shooted");

    if (enemy == this)
        throw runtime_error("No self harm");

    if (this->distance(enemy) < 1)
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
        toPrint = "(Name: N " + this->getName() + ")" + to_string(this->getHitPoint());

    return toPrint;
}
void Ninja::attack(Character *enemy)
{
    if (this->isAlive())
    {
        if (this->distance(enemy) < 1)
            this->slash(enemy);
        else
        {
            this->move(enemy);
        }
    }
}