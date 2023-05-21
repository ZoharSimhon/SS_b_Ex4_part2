#include "SmartTeam.hpp"

using namespace ariel;

SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

void SmartTeam::attack(Team *enemy)
{
    if (enemy == nullptr)
        throw invalid_argument("can't attack nulptr");

    if (enemy == this)
        throw runtime_error("No self harm");

    if (this->stillAlive() == 0)
        throw runtime_error("a dead Team can't attack");

    if (enemy->stillAlive() == 0)
        throw runtime_error("a dead Team can't be attacked");

    // find the new leader
    this->setLeaderIndex(findClosestToLeader(this));

    // first time for ninjas
    for (Character *member : *(this->getGroup()))
    {
        // all the enemy members are dead
        if (enemy->stillAlive() == 0)
            return;
        // find victim from the enemy team
        size_t victimIndex = findClosestToLeader(enemy);
        if (member->getIsNinja())
            member->attack((*enemy->getGroup())[victimIndex]); // attack the victim
    }
    // second time for cowboys
    for (Character *member : *(this->getGroup()))
    {
        // all the enemy members are dead
        if (enemy->stillAlive() == 0)
            return;
        // find victim from the enemy team
        size_t victimIndex = findClosestToLeader(enemy);
        if (!member->getIsNinja())
            member->attack((*enemy->getGroup())[victimIndex]); // attack the victim
    }
}

void SmartTeam::print() const
{
    cout << "The team's members are:" << endl;
    // first time for ninjas
    for (Character *member : *(this->getGroup()))
    {
        if (member->getIsNinja())
            cout << member->print() << endl;
    }
    // second time for cowboys
    for (Character *member : *(this->getGroup()))
    {
        if (!member->getIsNinja())
            cout << member->print() << endl;
    }
}