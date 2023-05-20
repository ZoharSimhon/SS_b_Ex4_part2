#include "Team.hpp"

using namespace ariel;

Team::Team(Character *leader)
{
    if (leader->getIsPlay())
        throw runtime_error("a player can be member of one team only");

    this->group_.push_back(leader);
    this->leaderIndex_ = 0;
    leader->setIsPlay();
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
        if (member->isAlive() && currLeader->distance(member) < minDistance)
        {
            minDistance = currLeader->distance(member);
            minIndex = index;
        }
        index++;
    }
    return minIndex;
}

// getters
vector<Character *> const *Team::getGroup() const
{
    return &this->group_;
}
size_t Team::getLeaderIndex() const
{
    return this->leaderIndex_;
}

// setter
void Team::setLeaderIndex(size_t index)
{
    this->leaderIndex_ = index;
}

void Team::add(Character *member)
{
    if (this->group_.size() == 10)
        throw runtime_error("maximum size of group is 10");
    if (member->getIsPlay())
        throw runtime_error("a player can be member of one team only");
    if (member == nullptr)
        throw invalid_argument("can't add nulptr to team");

    this->group_.push_back(member);
    member->setIsPlay();
}
void Team::attack(Team *enemy)
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
    this->leaderIndex_ = findClosestToLeader(this);

    // first time for cowboys
    for (Character *member : group_)
    {
        // all the enemy members are dead
        if (enemy->stillAlive() == 0)
            return;
        // find victim from the enemy team
        size_t victimindex = findClosestToLeader(enemy);
        if (!member->getIsNinja())
            member->attack(enemy->group_[victimindex]);
    }
    // second time for ninjas
    for (Character *member : group_)
    {
        // all the enemy members are dead
        if (enemy->stillAlive() == 0)
            return;
        // find victim from the enemy team
        size_t victimindex = findClosestToLeader(enemy);
        if (member->getIsNinja())
            member->attack(enemy->group_[victimindex]);
    }
}
int Team::stillAlive() const
{
    int counter = 0;

    for (Character *member : group_)
    {
        if (member->isAlive())
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
        if (!member->getIsNinja())
            cout << member->print() << endl;
    }
    // second time for ninjas
    for (Character *member : group_)
    {
        if (member->getIsNinja())
            cout << member->print() << endl;
    }
}