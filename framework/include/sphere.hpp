#ifndef SPHERE_H
#define SPHERE_H

#include "shape.hpp"

class Sphere : public Shape
{
public:
    Sphere();
    Sphere(const Sphere & copy);
    Sphere(const math3d::point & center, double r);
    Sphere(const math3d::point & center, double r, Material * material_);

    const math3d::point & getCenter() const;
    double getRadius() const;

//    double getVolume()  const;
//    double getSurface() const;
//    bool isInside(const math3d::point & p) const;


    void translate (double x, double y, double z);
    void rotate (double ankle, double x, double y, double z);

    std::ostream& printOn (std::ostream & out)       const;

    virtual ~Sphere();

private:
    math3d::point center;
    double radius;
};

#endif // SPHERE_H
