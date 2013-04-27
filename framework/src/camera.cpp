
#include <vector>
#include <cmath>
#include <iostream>

#include "camera.hpp"
/*
focal distance d is computed as:
d=\frac{\sqrt{x^2+y^2}}{2\tan\frac{\alpha}{2}}
*/


Camera::Camera():
    fov(0.0),
	position(math3d::vector({0,0,0,1})),
	orientation(math3d::vector({0,0,-1,1})),
	up(math3d::vector({0,1,0,1}))
{}


Camera::Camera(double const& ankle):
    fov(ankle*M_PI/180),
    position(math3d::vector({0,0,0,1})),
    orientation(math3d::vector({0,0,-1,1})),
	up(math3d::vector({0,1,0,1}))
{

}




Camera::Camera(const Camera& cam):
    fov(cam.fov),
    position(cam.position),
    orientation(cam.orientation),
	up(cam.up)
{
}


Camera::~Camera()    // Destr.
{}



double
Camera::getAnkle() {
	return fov;
}

void
Camera::translate (double x, double y, double z){
	math3d::matrix translationMatrix = getTranslationMatrix(x,y,z);
	std::cout<<"Translationmatrix:"<<translationMatrix<<std::endl;
	std::cout<<"before -- Position: "<<position<<std::endl;
	std::cout<<"before -- orientation: "<<orientation<<std::endl;
	std::cout<<"before -- up: "<<up<<std::endl;
	position = translationMatrix * position;
	orientation = translationMatrix * orientation;
	up = translationMatrix * orientation;
	std::cout<<"after -- Position: "<<position<<std::endl;
	std::cout<<"after -- orientation: "<<orientation<<std::endl;
	std::cout<<"after -- up: "<<up<<std::endl;
}

void
Camera::rotate (double ankle, double x, double y, double z){
	math3d::matrix rotationMatrix = getRotationMatrix(ankle, x, y, z);
	std::cout<<"rotationsMatrix:"<<rotationMatrix<<std::endl;
	std::cout<<"before -- Position: "<<position<<std::endl;
	std::cout<<"before -- orientation: "<<orientation<<std::endl;
	std::cout<<"before -- up: "<<up<<std::endl;
	position = rotationMatrix * position;
	orientation = rotationMatrix * orientation;
	up = rotationMatrix * orientation;
	std::cout<<"after -- Position: "<<position<<std::endl;
	std::cout<<"after -- orientation: "<<orientation<<std::endl;
	std::cout<<"after -- up: "<<up<<std::endl;
}

std::vector<Ray>
Camera::getRays (int width, int height){
//	std::cout<<"Before normalization -- orientation: "<<orientation<<"up: "<<orientation<<std::endl;
	up/=up[3];
	orientation/=orientation[3];
	position/=position[3];
	math3d::vector u = cross(orientation,up);
	std::cout<<"After normalization -- orientation: "<<orientation<<"up: "<<up<<std::endl;
	u[3] = 1.0;
	std::cout<<"Cross: "<<u<<std::endl;
//	u /=u[3];
	math3d::vector v = cross (u,orientation);
//	v/=v[3];
	v[3] = 1.0;
	const double c[] = {
			u[0], u[1], u[2], 0.0,
			v[0], v[1], v[2], 0.0,
			-orientation[0], -orientation[1], -orientation[2], 0.0,
			position[0],position[1],position[2], 1.0
//			0.0,0.0,0.0,1.0
		};
	math3d::matrix cameraTransformationMatrix =math3d::matrix(c);
	std::cout<<"cameraTransformationMatrix: "<<std::endl<<cameraTransformationMatrix<<std::endl;

	std::vector<Ray> rays = std::vector<Ray>(width*height);
	/*
	 * alpha is diagonal fov
	 * 	focal distance d is computed as:
	 * 	d=\frac{\sqrt{x^2+y^2}}{2\tan\frac{\alpha}{2}}
	*/
	double d =(sqrt(width*width+height*height))/(2*tan(fov/2));

	std::cout<<"d:"<<d<<std::endl;
	position /=position[3];
	for (int x=0;x<width;++x){
		for (int y=0;y<height;++y){
			int i = x*y;
			double dx = x-width/2;
			double dy = y-height/2;
			math3d::vector thisDirection = math3d::vector({dx,dy,-d,1.0});
//			std::cout<<"before transformation -- Position: "<<position<<" direction: "<<thisDirection<<std::endl;
			thisDirection = cameraTransformationMatrix * thisDirection;
			thisDirection /=thisDirection[3];
//			std::cout<<" after transformation -- Position: "<<position<<" direction: "<<thisDirection<<std::endl;
			rays[i] = Ray(position,thisDirection);
		}
	}


    return rays;
}

std::ostream&
Camera::printOn (std::ostream & out)       const
{
	out << "Ankle:" << fov << std::endl;
	return out;
}

