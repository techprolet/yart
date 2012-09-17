#include "shape.hpp"

Shape::Shape():
    color_(),
    name_("undefined")
{
//    std::cout<<"shape constructor called"<<std::endl;
}


Shape::Shape(const color & color, const std::string &name):
    color_(color),
    name_(name)
{
    std::cout<<"shape constructor called"<<std::endl;
}

color Shape::getcolor()        const{
    return color_;
}
std::string Shape::getName()   const{
    return name_;
}


std::ostream & Shape::printOn(std::ostream &out) const{
    out<<"--->Shape"<<std::endl;
    out<<"Name: "<<name_<<std::endl;
//    out<< "color: rgb("<<(int)color_.r<<","<<(int)color_.g<<","<<(int)color_.b<<")"<<std::endl;
    out<<"Surface: "<<getSurface()<<std::endl;
    out<<"Volume: "<<getVolume()<<std::endl;
    return out;
}




Shape::~Shape(){
//    std::cout<<"shape destructor called"<<std::endl;

}
