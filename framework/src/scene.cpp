/*
 * Scene.cpp
 *
 *  Created on: Apr 18, 2013
 *      Author: pablo
 */

#include "scene.hpp"

Scene::Scene() {
	// TODO Auto-generated constructor stub

}

Scene::~Scene() {
	// TODO Auto-generated destructor stub
}

void
Scene::addShape(std::string shapeName, Shape * shape){
	shapes[shapeName] = shape;
}
void
Scene::addCamera(std::string cameraName, Camera * camera){
	cameras[cameraName] = camera;
}

void
Scene::addMaterial(std::string materialName, Material * material){
	materials[materialName] = material;
}

void
Scene::addLight(Light * light){
	lights.push_back(light);
}

Shape*
Scene::getShape(std::string shapeName){
	return shapes[shapeName];
}

Material*
Scene::getMaterial(std::string materialName){
	return materials[materialName];
}


SceneObject *
Scene::getObjectByName(std::string objectName){
	if (shapes.find(objectName)!=shapes.end()){
		std::cout<<"found shape "<<objectName<<std::endl;
		return shapes[objectName];
	} else if(cameras.find(objectName)!=cameras.end()){
		std::cout<<"found camera "<<objectName<<std::endl;
		return cameras[objectName];
	}
	std::cout<<"ERROR: no object "<<objectName<<" found!"<<std::endl;
	return NULL;
}
