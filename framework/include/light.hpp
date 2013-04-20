#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "color.hpp"
#include "point.hpp"
#include <iostream>
#include <string>


class Light
{
    public:
        Light();
        Light(std::string const&, math3d::point const&, Color const&, Color const&);
        Light(const Light&);
        ~Light();

        std::string name();
        math3d::point pos();
        Color la();
        Color ld();

        void print(std::ostream&) const;

    private:
        std::string name_;
        math3d::point pos_;
        Color la_;
        Color ld_;
};

std::ostream& operator<<(std::ostream&, Light const&);

#endif // LIGHT_HPP
