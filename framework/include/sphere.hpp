#ifndef SPHERE_H
#define SPHERE_H

#include <shape.hpp>

class Sphere : public Shape
{
public:
    Sphere();
    Sphere(const Sphere & copy);
    Sphere(const math3d::point & center, double r);
    Sphere(const math3d::point & center, double r,color color, std::string name);

    const math3d::point & getCenter() const;
    double getRadius() const;

    double getVolume()  const;
    double getSurface() const;
    bool isInside(const math3d::point & p) const;


    std::ostream& printOn (std::ostream & out)       const;

    ~Sphere();

private:
    math3d::point center_;
    double r_;
};

#endif // SPHERE_H
