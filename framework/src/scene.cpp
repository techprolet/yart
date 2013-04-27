/*
 * Scene.cpp
 *
 *  Created on: Apr 18, 2013
 *      Author: pablo
 */

#include <glutwindow.hpp>
#include <ppmwriter.hpp>
#include "pixel.hpp"
#include "scene.hpp"
#include "ray.hpp"

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
Scene::getObject(std::string objectName){
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
Shape *
Scene::getShape (int index){
	std::map<std::string, Shape*>::iterator it;
	std::advance(it, index);
	return it->second;
}
int
Scene::getShapesSize() const{
	return shapes.size();
}
Camera *
Scene::getCamera(std::string objectName){
	if(cameras.find(objectName)!=cameras.end()){
		std::cout<<"found camera "<<objectName<<std::endl;
		return cameras[objectName];
	}
	std::cout<<"ERROR: no camera "<<objectName<<" found!"<<std::endl;
	return NULL;
}



void
Scene::render(std::string cameraName,std::string fileName, int width, int height){

	// create output window
	glutwindow::init(width, height, 100, 100, fileName, 0,NULL);


    // get glutwindow instance
    glutwindow& window = glutwindow::instance();

    // create a ppmwriter
    ppmwriter image(window.width(), window.height(), "./checkerboard.ppm");


    std::vector<Ray> rays = getCamera(cameraName)->getRays(width,height);

	for (int x=0;x<width;++x){
		for (int y=0;y<height;++y){
			// create pixel at x,y
	        Pixel p(x, y);
	        p.rgb = Color(0.0, 1.0, float(x)/height);
			int i = x*y;
//			std::cout<<"render, you fuck!"<<std::endl;
			for (std::map<std::string, Shape*>::iterator it = shapes.begin();it!=shapes.end();it++){
//				std::cout<<"thisRay: "<<rays[i]<<std::endl;
//				std::cout<<it->second->intersectedBy(rays[i])<<std::endl;
				if (it->second->intersectedBy(rays[i])>0){
					p.rgb = Color(1.0,0,0);
				}
			}

	        // write pixel to output window
	        window.write(p);

	        // write pixel to image writer
	        image.write(p);
		}
	}




    // save final image
    image.save();

    // start output on glutwindow
    glutwindow::instance().run();

}
