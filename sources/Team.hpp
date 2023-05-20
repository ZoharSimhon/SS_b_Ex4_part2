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

    public:
        // helper functions
        size_t findClosestToLeader(Team *team);
        Team(Character *);
        // getters
        vector<Character *> const *getGroup() const;
        size_t getLeaderIndex() const;

        // setter
        void setLeaderIndex(size_t);

        void add(Character *);
        void attack(Team *);
        int stillAlive() const;
        void print() const;
        // ~Team();
    };
}