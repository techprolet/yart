#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <iostream>
#include "point.hpp"
#include "sceneobject.hpp"
#include "material.hpp"
#include "ray.hpp"

class Shape :public SceneObject
{
public:
//    virtual double getVolume()  const = 0;
//    virtual double getSurface() const = 0;
//    virtual bool isInside(const math3d::point & p) const = 0;



    virtual void translate (double x, double y, double z) = 0;
    virtual void rotate (double ankle, double x, double y, double z) = 0;


    virtual std::ostream& printOn (std::ostream & out)       const;

    Material * getMaterial()        const;


    virtual double intersectedBy(const Ray & ray) const = 0;





    virtual ~Shape();


protected:
    Shape();
    Shape(Material * material_);

private:
    Material * material;
};




#endif // SHAPE_H
