#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <string>
#include "color.hpp"

class Material
{
public:
    Material();
    Material (const Material  & copy);
    Material (Color ka,Color kd,Color ks,float m);

    void setKa (const Color & ka);
    void setKd (const Color & kd);
    void setKs (const Color & ks);
    void setM (float m);



    const Color & getKa() const;
    const Color & getKd() const;
    const Color & getKs() const;
    float getM() const;

    std::ostream& printOn (std::ostream & out)       const;


    friend std::ostream & operator<<(std::ostream& lhs, const Material & rhs)
        {
          return rhs.printOn(lhs);
        }

    virtual ~Material();
private:
    Color ka_;
    Color kd_;
    Color ks_;
    float m_;
};

#endif // MATERIAL_H
