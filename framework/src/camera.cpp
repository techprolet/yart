#include "camera.hpp"

Camera::Camera():
    ankle_()
{}


Camera::Camera(double const& ankle):
    ankle_(ankle)
{}


Camera::Camera(const Camera& cam):
    ankle_(cam.ankle_)
{}


Camera::~Camera()    // Destr.
{}



double
Camera::getAnkle() {
	return ankle_;
}

void
Camera::translate (double x, double y, double z){

}

void
Camera::rotate (double ankle, double x, double y, double z){

}


void Camera::print(std::ostream& os) const
{
	os << "Ankle:" << ankle_ << std::endl;
}

std::ostream& operator<<(std::ostream& os, Camera const& camera)
{
	camera.print(os);
	return os;
}
