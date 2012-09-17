#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <iostream>
#include <point.hpp>
#include <color.hpp>

class Shape
{
public:
    virtual double getVolume()  const = 0;
    virtual double getSurface() const = 0;
    virtual bool isInside(const math3d::point & p) const = 0;
    virtual std::ostream& printOn (std::ostream & out)       const;



    color getcolor()        const;
    std::string getName()   const;









    friend std::ostream & operator<<(std::ostream& lhs, const Shape & rhs)
    {
      return rhs.printOn(lhs);
    }

    virtual ~Shape();


protected:
    Shape();
    Shape(const color & color, const std::string & name);

private:
    color color_;
    std::string name_;
};




#endif // SHAPE_H
