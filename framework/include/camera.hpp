#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <string>
#include <iostream>
#include "sceneobject.hpp"

class Camera: public SceneObject
{
    public:
        Camera();
        Camera(double const&);
        Camera (const Camera&);
        virtual ~Camera();

        double getAnkle();

        virtual void translate (double x, double y, double z);
        virtual void rotate (double ankle, double x, double y, double z);

        void print(std::ostream&) const;

    private:
        double ankle_;
};

std::ostream& operator<<(std::ostream&, Camera const&);

#endif // CAMERA_HPP
