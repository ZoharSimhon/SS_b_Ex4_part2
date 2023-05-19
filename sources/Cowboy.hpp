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
        string print() const override;
    };
}
