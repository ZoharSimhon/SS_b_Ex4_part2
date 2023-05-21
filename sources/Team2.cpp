#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::attack(Team *enemy)
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
    for (Character *member : *(this->getGroup()))
    {
        // all the enemy members are dead
        if (enemy->stillAlive() == 0)
            return;

        // find victim from the enemy team
        size_t victimIndex = findClosestToLeader(enemy);
        //attack the victim
        member->attack((*enemy->getGroup())[victimIndex]);
    }
}

void Team2::print() const
{
    cout << "The team's members are:" << endl;

    for (Character *member : *(this->getGroup()))
    {
        cout << member->print() << endl;
    }
}