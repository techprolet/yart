#include "sphere.hpp"
#include <math.h>
/*
 * Die Gleichung für eine Kugel mit der Mitte im Ursprung und Radius r
 *
 *  x2 + y2 + z2 - r2 = x•x - r2 = 0
 *  Einsetzen der Strahlgleichung p(t) = p0 + t d
 *
 *
 * (p0 + t d)(p0 + t d) - r2 = 0
 * t2 d
 * d + 2t p0 • d + p0 • p0 - r2 = 0
 * Quadratische Gleichung in t
 *
 * t2
 * at2 + bt + c = 0 mit
 *
 *
 *
 * d = 1 (d hat Länge 1)
 * b = 2 p0 • d
 * c = p0 • p0 - r2
 */
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
	math3d::matrix translationMatrix = getTranslationMatrix(x,y,z);
	center = translationMatrix * center;
}

void
Sphere::rotate (double ankle, double x, double y, double z){

}




double
Sphere::intersectedBy(const Ray & ray) const{
	math3d::vector p0 = ray.getOrigin();
	math3d::vector d = ray.getDirection();
//	std::cout<<"p0: "<<p0;
//	std::cout<<"        radius: "<<radius;
//	std::cout<<"        d: "<<d<<std::endl;


//	a = dot(d,d); //==1
//	a = 1.0;
//	b = dot(2*p0,d);
//	c = dot(p0,p0)-radius*radius;

	double a, b, c;
	a = d[0]*d[0] +
		d[1]*d[1] +
		d[2]*d[2];

	b = 2*p0[0]*d[0] - 2 * d[0]* center[0] +
		2*p0[1]*d[1] - 2 * d[1]* center[1] +
		2*p0[2]*d[2] - 2 * d[2]* center[2];
	c = p0[0] * p0[0] + center[0] * center[0] - 2 * p0[0] * center[0] +
		p0[1] * p0[1] + center[1] * center[1] - 2 * p0[1] * center[1] +
		p0[2] * p0[2] + center[2] * center[2] - 2 * p0[2] * center[2] -
		radius * radius;

	double t1, t2;
	double det =(b*b-4*a*c);

//	std::cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<" det: "<<det<<std::endl;
	if (det<0){
		return 0;
	}
	det = sqrt(det);

	t1 = 0.5*(-b-det)/a;
	t2 = 0.5*(-b+det)/a;



	std::cout<<"t1:"<<t1<<" t2: "<<t2<<std::endl;

	if ((t1<0)&&(t2<0)){
		return 0;
	} else if (t1<0){
		return t2;
	} else if (t2<0){
		return t1;
	} else {
		return (t1<t2?t1:t2);
	}

	return 0;
}


std::ostream & Sphere::printOn(std::ostream &out) const{
    Shape::printOn(out);
    out<<"Sphere:"<<std::endl;
    out<<"Center: "<<center[0]/center[3]<<", "<<center[1]/center[3]<<", "<<center[2]/center[3]<<std::endl;
    out<<"Radius: "<<radius<<std::endl;
    return out;
}
Sphere::~Sphere(){
    std::cout<<"sphere destructor called"<<std::endl;

}
