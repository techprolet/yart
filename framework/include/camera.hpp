#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <string>
#include <iostream>
#include "sceneobject.hpp"
#include "ray.hpp"

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

        std::vector<Ray> getRays (int width, int height);


        virtual std::ostream& printOn (std::ostream & out)       const;

    private:
        double fov;
        math3d::vector position, orientation,up;

};

std::ostream& operator<<(std::ostream&, Camera const&);

#endif // CAMERA_HPP
