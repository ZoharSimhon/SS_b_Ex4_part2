#pragma once

#include <unistd.h>

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    // private:
    //     vector<Character *> group_;
    //     size_t leaderIndex_;

    //     // helper functions
    //     size_t findClosestToLeader(Team2 *team);

    public:
        Team2(Character *);
        void attack(Team *);
        void print() const;
        // void add(Character *);
        // int stillAlive() const;
        // ~Team();
    };
}