#ifndef RAY_HPP
#define RAY_HPP

#include "point.hpp"
#include "vector.hpp"

class Ray
{
    public:
        Ray();
        Ray(math3d::vector const& o, math3d::vector const& d);
        Ray(const Ray&);
        ~Ray();

        math3d::vector getOrigin() const;
        math3d::vector getDirection() const;

    private:
        math3d::vector origin;
        math3d::vector direction;

};

std::ostream& operator<<(std::ostream&, Ray const&);
#endif // RAY_HPP
