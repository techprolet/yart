#include "box.hpp"

Box::Box():
    Shape(),
    vertices_({math3d::point(0,0,0),math3d::point(0,0,0)})
{
    std::cout<<"box constructor called"<<std::endl;
}

Box::Box(const math3d::point & p1,const math3d::point & p2):
    Shape(),
    vertices_({p1,p2})
{
    std::cout<<"box constructor called"<<std::endl;
}
Box::Box(const math3d::point & p1,const math3d::point & p2, const color &color, const std::string &name):
    Shape(color,name),
    vertices_({p1,p2})
{
    std::cout<<"box constructor called"<<std::endl;
}
Box::Box(const Box & copy):
    Shape(),
    vertices_({copy[0],copy[1]})
{
    std::cout<<"box constructor called"<<std::endl;
}

double Box::getSurface() const{
    double a = vertices_[1][0]-vertices_[0][0];
    double b = vertices_[1][1]-vertices_[0][1];
    double c = vertices_[1][2]-vertices_[0][2];
    return 2*a*b + 2*a*c + 2*b*c;

}
double Box::getVolume() const{
    double a = vertices_[1][0]-vertices_[0][0];
    double b = vertices_[1][1]-vertices_[0][1];
    double c = vertices_[1][2]-vertices_[0][2];
    return a*b*c;
}

bool Box::isInside(const math3d::point & p) const{
    if (
            (p[0]>vertices_[0][0])&&(p[0]<vertices_[1][0])&&
            (p[1]>vertices_[0][1])&&(p[0]<vertices_[1][1])&&
            (p[2]>vertices_[0][2])&&(p[0]<vertices_[1][2])
    ) {
        return true;
       } else {
        return false;
       }
}

math3d::point& Box::operator [](const unsigned thisVertex){
    return vertices_[thisVertex];
}
const math3d::point & Box::operator [](const unsigned thisVertex)    const{
    return vertices_[thisVertex];
}


std::ostream & Box::printOn(std::ostream &out) const{
    Shape::printOn(out);
    out<<"First Vertex: "<<vertices_[0][0]<<", "<<vertices_[0][1]<<", "<<vertices_[0][2]<<std::endl;
    out<<"Second Vertex: "<<vertices_[1][0]<<", "<<vertices_[1][1]<<", "<<vertices_[1][2]<<std::endl;
    return out;
}

Box::~Box(){
    std::cout<<"box destructor called"<<std::endl;
}
