#ifndef BOX_H
#define BOX_H

#include <shape.hpp>

class Box : public Shape
{
public:
    Box();
    Box(const math3d::point & p1,const math3d::point & p2);
    Box(const math3d::point & p1,const math3d::point & p2,const color & color, const std::string & name);
    Box(const Box & copy);

    double getVolume()                              const;
    double getSurface()                             const;
    bool    isInside(const math3d::point & p)             const;
    math3d::point& operator [](const unsigned thisVertex);




    std::ostream& printOn (std::ostream & out)       const;

    const   math3d::point& operator [](const unsigned thisVertex)   const;

    ~Box();
private:
    math3d::point vertices_[2];
};

#endif // BOX_H
