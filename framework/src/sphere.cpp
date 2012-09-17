#include "sphere.hpp"
#include <math.h>

Sphere::Sphere():
    Shape(),
    center_(0,0,0),
    r_(0)
{
//    std::cout<<"sphere constructor called"<<std::endl;
}
Sphere::Sphere(const Sphere & copy):
    Shape(),
    center_(copy.getCenter()),
    r_(copy.getRadius())
{
//    std::cout<<"sphere constructor called"<<std::endl;
}

Sphere::Sphere(const math3d::point &center, double r):
    Shape(),
    center_(center),
    r_(r)
{
//    std::cout<<"sphere constructor called"<<std::endl;
}
Sphere::Sphere(const math3d::point &center, double r,color color, std::string name):
    Shape(color,name),
    center_(center),
    r_(r)
{
//    std::cout<<"sphere constructor called"<<std::endl;
}

const math3d::point & Sphere::getCenter() const {
    return center_;
}
double Sphere::getRadius() const {
    return r_;
}

double Sphere::getSurface() const{
    return 4.0*M_PI*pow(r_,2);
}
double Sphere::getVolume() const{
    return (4.0*M_PI*pow(r_,3))/3.0;
}
bool Sphere::isInside(const math3d::point & p ) const{
    if (center_.distanceFrom(p)<r_){
        return true;
    } else {
        return false;
    }
}

std::ostream & Sphere::printOn(std::ostream &out) const{
    Shape::printOn(out);
    out<<"Center: "<<center_[0]<<", "<<center_[1]<<", "<<center_[2]<<std::endl;
    out<<"Radius: "<<r_<<std::endl;
    return out;
}
Sphere::~Sphere(){
//    std::cout<<"sphere destructor called"<<std::endl;

}
