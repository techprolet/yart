/*
 * sceneobject.hpp
 *
 *  Created on: Apr 20, 2013
 *      Author: pablo
 */

#ifndef SCENEOBJECT_HPP_
#define SCENEOBJECT_HPP_

#include "matrix.hpp"
#include "isceneobject.hpp"

class SceneObject: public ISceneObject {
public:
	SceneObject();
    virtual void translate (double x, double y, double z);
    virtual void rotate (double ankle, double x, double y, double z);


    virtual std::ostream& printOn (std::ostream & out)       const =0;


	virtual ~SceneObject();




//    friend std::ostream & operator<<(std::ostream& lhs, const SceneObject & rhs)
//    {
//      return rhs.printOn(lhs);
//    }

protected:
	math3d::matrix getTranslationMatrix (double x, double y, double z);
	math3d::matrix getRotationMatrix (double ankle, double x, double y, double z);
};

#endif /* SCENEOBJECT_HPP_ */
