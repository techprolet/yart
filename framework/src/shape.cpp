#include "shape.hpp"

Shape::Shape():
	SceneObject(),
	material()
{
//    std::cout<<"shape constructor called"<<std::endl;
}


Shape::Shape(Material * material_):
		SceneObject(),
		material(material_)
{
    std::cout<<"shape constructor called"<<std::endl;
}

Material * Shape::getMaterial()        const{
    return material;
}


std::ostream & Shape::printOn(std::ostream &out) const{
    out<<"--->Shape"<<std::endl;
//    out<<"Surface: "<<getSurface()<<std::endl;
//    out<<"Volume: "<<getVolume()<<std::endl;
    return out;
}



Shape::~Shape(){
//    std::cout<<"shape destructor called"<<std::endl;

}

