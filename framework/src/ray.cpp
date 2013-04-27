#include "ray.hpp"
#include <ostream>   // std::ostream
#include <cmath>

Ray::Ray():
	origin(),
	direction()
{}

Ray::Ray(math3d::vector const& o, math3d::vector const& d):
		origin(o),
		direction(d)
{}

Ray::Ray(const Ray& r):
		origin(r.origin),
		direction(r.direction)
{}

Ray::~Ray()
{}


math3d::vector Ray::getOrigin() const
{
    return origin;
}

math3d::vector Ray::getDirection() const
{
    return direction;
}


std::ostream&
operator<<(std::ostream& os, Ray const& r)
{
	os<<"Origin: "<<r.getOrigin()<<" Direction: "<<r.getDirection();

    return os;
}
