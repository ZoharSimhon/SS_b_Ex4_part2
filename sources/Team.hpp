#pragma once

#include <unistd.h>

#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

namespace ariel
{
    class Team
    {
    private:
        vector<Character *> group_;
        size_t leaderIndex_;

        // helper functions
        size_t findClosestToLeader(Team *team);

    public:
        Team(Character *);
        void add(Character *);
        void attack(Team *);
        int stillAlive() const;
        void print() const;
        // ~Team();
    };
}