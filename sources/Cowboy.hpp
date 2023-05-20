#pragma once
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
        void attack(Character *) override;
    };
}
