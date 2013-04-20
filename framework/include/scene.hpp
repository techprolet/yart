#ifndef SCENE_H_
#define SCENE_H_


#include <map>
#include <vector>

#include "isceneobject.hpp"
#include "material.hpp"
#include "shape.hpp"
#include "camera.hpp"
#include "light.hpp"

class Scene {
public:
	Scene();


	void addShape(std::string shapeName, Shape * shape);
	void addCamera(std::string cameraName, Camera * camera);
	void addMaterial(std::string materialName, Material * material);
	void addLight(Light * light);

	Shape* getShape(std::string shapeName);
	Material* getMaterial(std::string materialName);

	SceneObject * getObjectByName(std::string objectName);

	virtual ~Scene();


private:
	std::map<std::string, Material*> materials;
	std::map<std::string, Shape*> shapes;
	std::map<std::string, Camera*> cameras;
	std::vector<Light*> lights;
};

#endif /* SCENE_H_ */
