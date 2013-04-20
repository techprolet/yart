/*
 * SceneObject.h
 *
 *  Created on: Apr 20, 2013
 *      Author: pablo
 */

#ifndef ISCENEOBJECT_HPP_
#define ISCENEOBJECT_HPP_


class ISceneObject {
public:

    virtual void translate (double x, double y, double z) = 0;
    virtual void rotate (double ankle, double x, double y, double z) = 0;


	virtual ~ISceneObject(){};
};

#endif /* ISCENEOBJECT_HPP_ */
