#include "Team.hpp"

using namespace ariel;

Team::Team(Character *leader)
{
    this->group_.push_back(leader);
    this->leaderIndex_ = 0;
}

// helper functions
size_t Team::findClosestToLeader(Team *team)
{
    Character *currLeader = this->group_[leaderIndex_];

    size_t index = 0;
    double minDistance = __DBL_MAX__;
    size_t minIndex = __INT_MAX__;

    for (Character *member : team->group_)
    {
        if (member->isAlive() && currLeader->distance(*member) < minDistance)
        {
            minDistance = currLeader->distance(*member) < minDistance;
            minIndex = index;
        }
        index++;
    }
    return minIndex;
}

void Team::add(Character *member)
{
    if (this->group_.size() < 10)
        this->group_.push_back(member);
    else
        throw runtime_error("maximum size of group is 10");
}
void Team::attack(Team *enemy)
{
    // first, find the new leader
    this->leaderIndex_ = findClosestToLeader(this);
    // second, find the victiom
    // first time for cowboys
    for (Character *member : group_)
    {
        size_t victimindex = findClosestToLeader(enemy);
        if (!member->getIsNinja())
            member->attack(enemy->group_[victimindex]);
    }
    // second time for ninjas
    for (Character *member : group_)
    {
        size_t victimindex = findClosestToLeader(enemy);
        if (member->getIsNinja())
            member->attack(enemy->group_[victimindex]);
    }
}
int Team::stillAlive() const
{
    int counter = 0;
    // first time for cowboys
    for (Character *member : group_)
    {
        if (member->isAlive() && !member->getIsNinja())
            counter++;
    }
    // second time for ninjas
    for (Character *member : group_)
    {
        if (member->isAlive() && member->getIsNinja())
            counter++;
    }
    return counter;
}
void Team::print() const
{
    cout << "The team's members are:" << endl;
    // first time for cowboys
    for (Character *member : group_)
    {
        if (member->isAlive() && !member->getIsNinja())
            cout << member->print() << endl;
    }
    // second time for ninjas
    for (Character *member : group_)
    {
        if (member->isAlive() && member->getIsNinja())
            cout << member->print() << endl;
    }
}