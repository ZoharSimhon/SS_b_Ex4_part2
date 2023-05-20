#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int spead_;

    public:
        Ninja(const Point &, int, string, int);
        void move(const Character *);
        void slash(Character *) const;

        // override functions
        string print() const override;
        void attack(Character *enemy) override;
    };
}

#endif