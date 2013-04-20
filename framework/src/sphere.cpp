#include "sphere.hpp"
#include <math.h>

Sphere::Sphere():
    Shape(),
    center(0,0,0),
    radius(0)
{
    std::cout<<"sphere constructor called"<<std::endl;
}
Sphere::Sphere(const Sphere & copy):
    Shape(),
    center(copy.getCenter()),
    radius(copy.getRadius())
{
    std::cout<<"sphere constructor called"<<std::endl;
}

Sphere::Sphere(const math3d::point &center, double r):
    Shape(),
    center(center),
    radius(r)
{
    std::cout<<"sphere constructor called"<<std::endl;
}
Sphere::Sphere(const math3d::point &center, double r, Material * material_):
    Shape(material_),
    center(center),
    radius(r)
{
    std::cout<<"sphere constructor called"<<std::endl;
}

const math3d::point & Sphere::getCenter() const {
    return math3d::point(center[0]/center[3],center[1]/center[3],center[0]/center[3]);
}
double Sphere::getRadius() const {
    return radius;
}

//double Sphere::getSurface() const{
//    return 4.0*M_PI*pow(r_,2);
//}
//double Sphere::getVolume() const{
//    return (4.0*M_PI*pow(r_,3))/3.0;
//}
//bool Sphere::isInside(const math3d::point & p ) const{
//    if (center_.distanceFrom(p)<r_){
//        return true;
//    } else {
//        return false;
//    }
//}

void
Sphere::translate (double x, double y, double z){

}

void
Sphere::rotate (double ankle, double x, double y, double z){

}

std::ostream & Sphere::printOn(std::ostream &out) const{
    Shape::printOn(out);
    out<<"Center: "<<center[0]<<", "<<center[1]<<", "<<center[2]<<center[3]<<std::endl;
    out<<"Radius: "<<radius<<std::endl;
    return out;
}
Sphere::~Sphere(){
    std::cout<<"sphere destructor called"<<std::endl;

}
