#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bulletsNumber_;

    public:
        Cowboy(string, const Point &);
        void shoot(Character *);
        bool hasboolets() const;
        void reload();

        // override functions
        string print() const override;
        void attack(Character * enemy) override;
    };
}

#endif