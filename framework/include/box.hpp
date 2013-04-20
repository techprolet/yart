#ifndef BOX_H
#define BOX_H

#include <shape.hpp>

class Box : public Shape
{
public:
    Box();
    Box(const math3d::point & p1,const math3d::point & p2);
    Box(const math3d::point & p1,const math3d::point & p2, Material * material_);
    Box(const Box & copy);

//    double getVolume()                              const;
//    double getSurface()                             const;
//    bool    isInside(const math3d::point & p)             const;


    void translate (double x, double y, double z);
    void rotate (double ankle, double x, double y, double z);





    std::ostream& printOn (std::ostream & out)       const;

    math3d::vector& operator [](const unsigned thisVertex);
    const   math3d::vector& operator [](const unsigned thisVertex)   const;

    ~Box();
private:
    math3d::vector vertices[8];

};

#endif // BOX_H
