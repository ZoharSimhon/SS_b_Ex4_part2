#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::attack(Team *enemy)
{
    if (enemy == nullptr)
        throw invalid_argument("can't attack nulptr");

    if (enemy == this)
        throw runtime_error("No self harm");

    // find the new leader
    this->setLeaderIndex(findClosestToLeader(this));
    for (Character *member : *(this->getGroup()))
    {
        // all the enemy members are dead
        if (enemy->stillAlive() == 0)
            return;

        // find victim from the enemy team
        size_t victimindex = findClosestToLeader(enemy);
        member->attack((*enemy->getGroup())[victimindex]);
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