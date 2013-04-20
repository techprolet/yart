#include "box.hpp"

Box::Box():
    Shape(),
    vertices({
		math3d::vector(0,0,0,1),
		math3d::vector(0,0,0,1),
		math3d::vector(0,0,0,1),
		math3d::vector(0,0,0,1),
		math3d::vector(0,0,0,1),
		math3d::vector(0,0,0,1),
		math3d::vector(0,0,0,1),
		math3d::vector(0,0,0,1)
	})
{
    std::cout<<"box constructor called"<<std::endl;
}

Box::Box(const math3d::point & p1,const math3d::point & p2):
    Shape(),
    vertices({
		math3d::vector(p1[0],p1[1],p1[2],1),
		math3d::vector(p1[0],p1[1],p2[2],1),
		math3d::vector(p1[0],p2[1],p2[2],1),
		math3d::vector(p2[0],p2[1],p2[2],1),
		math3d::vector(p2[0],p2[1],p1[2],1),
		math3d::vector(p2[0],p1[1],p1[2],1),
		math3d::vector(p1[0],p1[1],p1[2],1),
		math3d::vector(p2[0],p1[1],p2[2],1)
	})
{
    std::cout<<"box constructor called"<<std::endl;
}
Box::Box(const math3d::point & p1,const math3d::point & p2, Material * material_):
    Shape(material_),
    vertices({
		math3d::vector(p1[0],p1[1],p1[2],1),
		math3d::vector(p1[0],p1[1],p2[2],1),
		math3d::vector(p1[0],p2[1],p2[2],1),
		math3d::vector(p2[0],p2[1],p2[2],1),
		math3d::vector(p2[0],p2[1],p1[2],1),
		math3d::vector(p2[0],p1[1],p1[2],1),
		math3d::vector(p1[0],p1[1],p1[2],1),
		math3d::vector(p2[0],p1[1],p2[2],1)
	})
{
    std::cout<<"box constructor called"<<std::endl;
}
Box::Box(const Box & copy):
    Shape(),
    vertices({copy[0],copy[1],copy[2],copy[3],copy[4],copy[5],copy[6],copy[7]})
{
    std::cout<<"box constructor called"<<std::endl;
}

//double Box::getSurface() const{
//    double a = vertices[1][0]-vertices[0][0];
//    double b = vertices[1][1]-vertices[0][1];
//    double c = vertices[1][2]-vertices[0][2];
//    return 2*a*b + 2*a*c + 2*b*c;
//
//}
//double Box::getVolume() const{
//    double a = vertices[1][0]-vertices[0][0];
//    double b = vertices[1][1]-vertices[0][1];
//    double c = vertices[1][2]-vertices[0][2];
//    return a*b*c;
//}

//bool Box::isInside(const math3d::point & p) const{
//    if (
//            (p[0]>vertices[0][0])&&(p[0]<vertices[1][0])&&
//            (p[1]>vertices[0][1])&&(p[0]<vertices[1][1])&&
//            (p[2]>vertices[0][2])&&(p[0]<vertices[1][2])
//    ) {
//        return true;
//       } else {
//        return false;
//       }
//}


void
Box::translate (double x, double y, double z){

}

void
Box::rotate (double ankle, double x, double y, double z){

}
math3d::vector& Box::operator [](const unsigned thisVertex){
    return vertices[thisVertex];
}
const math3d::vector & Box::operator [](const unsigned thisVertex)    const{
    return vertices[thisVertex];
}


std::ostream & Box::printOn(std::ostream &out) const{
    Shape::printOn(out);
    out<<"First Vertex: "<<vertices[0][0]<<", "<<vertices[0][1]<<", "<<vertices[0][2]<<std::endl;
    out<<"Second Vertex: "<<vertices[1][0]<<", "<<vertices[1][1]<<", "<<vertices[1][2]<<std::endl;
    return out;
}

Box::~Box(){
    std::cout<<"box destructor called"<<std::endl;
}
