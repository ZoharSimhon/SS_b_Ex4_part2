#include "Cowboy.hpp"

using namespace ariel;

Cowboy::Cowboy(string name, const Point &location)
    : Character(location, COWBOY_HIT_POINT, name), bulletsNumber_(COWBOY_BULLETS_NUMBER) {}

void Cowboy::shoot(Character *enemy)
{
    if (this->isAlive() && this->hasboolets())
    {
        enemy->hit(10);
        this->bulletsNumber_ -= 1;
    }
}
bool Cowboy::hasboolets() const
{
    return this->bulletsNumber_ > 0;
}
void Cowboy::reload()
{
    this->bulletsNumber_ += COWBOY_BULLETS_NUMBER;
}

string Cowboy::print() const
{
    string toPrint;
    if (this->isAlive())
        toPrint = "Name: C " + this->getName() +
                  " Number of hit points: " + to_string(this->getHitPoint());
    else
        toPrint = "Name: ( C " + this->getName() + ")";

    return toPrint;
}