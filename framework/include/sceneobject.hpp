/*
 * sceneobject.hpp
 *
 *  Created on: Apr 20, 2013
 *      Author: pablo
 */

#ifndef SCENEOBJECT_HPP_
#define SCENEOBJECT_HPP_

#include "isceneobject.hpp"

class SceneObject: public ISceneObject {
public:
	SceneObject();
    virtual void translate (double x, double y, double z);
    virtual void rotate (double ankle, double x, double y, double z);


	virtual ~SceneObject();
};

#endif /* SCENEOBJECT_HPP_ */
