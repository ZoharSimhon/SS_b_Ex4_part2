#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name, const Point &location)
            : Ninja(location, OLD_NINJA_HIT_POINT, std::move(name), OLD_NINJA_SPEAD) {}
    };
} // namespace name

#endif