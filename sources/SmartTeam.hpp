#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include <unistd.h>

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *);
        void attack(Team *);
        void print() const;
    };
}

#endif