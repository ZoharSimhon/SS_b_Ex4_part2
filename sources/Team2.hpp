#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <unistd.h>

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *);
        void attack(Team *);
        void print() const;
    };
}

#endif