/*
 * sceneobject.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: pablo
 */
#include <cmath>
#include <iostream>

#include "sceneobject.hpp"

SceneObject::SceneObject() {
	// TODO Auto-generated constructor stub

}




void
SceneObject::translate (double x, double y, double z){

}
void
SceneObject::rotate (double ankle, double x, double y, double z){

}


SceneObject::~SceneObject() {
	// TODO Auto-generated destructor stub
}



math3d::matrix
SceneObject::getTranslationMatrix (double x, double y, double z){
	math3d::matrix translationMatrix = math3d::matrix();
//	translationMatrix[3] = x;
//	translationMatrix[7] = y;
//	translationMatrix[11] = z;
	translationMatrix[12] = x;
	translationMatrix[13] = y;
	translationMatrix[14] = z;
	std::cout<<"translationMatrix:"<<std::endl;
	std::cout<<translationMatrix<<std::endl;
	std::cout<<"#####################"<<std::endl;
	return translationMatrix;
}

math3d::matrix
SceneObject::getRotationMatrix (double ankle, double x, double y, double z){
	ankle = ankle*M_PI/180.0;
//	(Euler-XYZ): Rotation around x-, y- and z-axes in a global
//	right-handed reference frame using angles in degrees:
	math3d::matrix Rx,Ry,Rz = math3d::matrix();
	if (x==1.0){
//		Rx[5] = cos(ankle);
//		Rx[6] = -sin(ankle);
//		Rx[9] = sin(ankle);
//		Rx[10] = cos(ankle);
		Rx[5] = cos(ankle);
		Rx[9] = -sin(ankle);
		Rx[6] = sin(ankle);
		Rx[10] = cos(ankle);
	}
	if (y==1.0){
//		Ry[0] = cos(ankle);
//		Ry[2] = sin(ankle);
//		Ry[8] = -sin(ankle);
//		Ry[10] = cos(ankle);
		Ry[0] = cos(ankle);
		Ry[8] = sin(ankle);
		Ry[2] = -sin(ankle);
		Ry[10] = cos(ankle);
	}
	if (z==1.0){
//		Rz[0] = cos(ankle);
//		Rz[1] = -sin(ankle);
//		Rz[4] = sin(ankle);
//		Rz[5] = cos(ankle);
		Rz[0] = cos(ankle);
		Rz[4] = -sin(ankle);
		Rz[1] = sin(ankle);
		Rz[5] = cos(ankle);
	}
	std::cout<<"Rx:"<<std::endl;
	std::cout<<Rx<<std::endl;
	std::cout<<"Ry:"<<std::endl;
	std::cout<<Ry<<std::endl;
	std::cout<<"Rz:"<<std::endl;
	std::cout<<Rz<<std::endl;
	std::cout<<"#####################"<<std::endl;
	std::cout<<Rz*Ry*Rx<<std::endl;
	std::cout<<"#####################"<<std::endl;
	return Rz*Ry*Rx;
}

std::ostream & operator<<(std::ostream& lhs, const SceneObject & rhs)
{
  lhs<<"operator<< overridden"<<std::endl;
  return rhs.printOn(lhs);
}
