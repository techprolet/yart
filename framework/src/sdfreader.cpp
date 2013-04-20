/*
 * sdfreader.cpp
 *
 *  Created on: Sep 17, 2012
 *      Author: pablo
 */

#include <stdlib.h>     /* atoi */

#include "sdfreader.hpp"
#include "material.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "camera.hpp"

SdfReader::SdfReader():
	sdfFile_("")
{

}


SdfReader::SdfReader(std::string sdfFile):
	sdfFile_(sdfFile)
{
	loadSdf();
}

void SdfReader::load(std::string sdfFile){
	sdfFile_ = sdfFile;
	loadSdf();
}


std::vector<std::string> SdfReader::parseArguments(std::stringstream& ss){
	std::vector<std::string> args;
	std::string thisArg;
	while (ss >> thisArg){
		args.push_back(thisArg);
//		std::cout<<" /"<<thisArg<<"/ ";
	}
//	std::cout<<std::endl;
	return args;
}




Scene * SdfReader::loadSdf(){
	Scene * scene = new Scene();
	std::ifstream ifs (sdfFile_.c_str() , std::ifstream::in );
	std::cout<<sdfFile_<<std::endl;
	while (ifs.good()){

		std::string sdfLine;

		std::getline (ifs, sdfLine);
		std::stringstream ss (sdfLine);

		std::vector<std::string> cmd = SdfReader::parseArguments(ss);
		std::cout<<"------>";
		if (cmd.size()>0){
			if (cmd[0]=="#"){
					std::cout<<"Comment:"<<sdfLine<<std::endl;
			} else if (cmd[0]== "define"){
					std::cout<<"Define: "<<sdfLine<<std::endl;
					if (cmd[1]=="material"){
						Material * thisMaterial = new Material(Color(atoi(cmd[3].c_str()),atoi(cmd[4].c_str()),atoi(cmd[5].c_str())),Color(atoi(cmd[6].c_str()),atoi(cmd[7].c_str()),atoi(cmd[8].c_str())),Color(atoi(cmd[9].c_str()),atoi(cmd[10].c_str()),atoi(cmd[11].c_str())),atof(cmd[12].c_str()));
						scene->addMaterial(cmd[2],thisMaterial);
					} else if (cmd[1]=="shape"){
						Shape * thisShape = NULL;
						if (cmd[2]=="box"){
							thisShape = new Box(math3d::point(atof(cmd[4].c_str()),atof(cmd[5].c_str()),atof(cmd[6].c_str())),math3d::point(atof(cmd[7].c_str()),atof(cmd[8].c_str()),atof(cmd[9].c_str())),scene->getMaterial(cmd[10]));
						} else if (cmd[2]=="sphere"){
							thisShape = new Sphere(math3d::point(atof(cmd[4].c_str()),atof(cmd[5].c_str()),atof(cmd[6].c_str())),atof(cmd[7].c_str()),scene->getMaterial(cmd[8]));
						}
						scene->addShape(cmd[3],thisShape);
					}else if (cmd[1]=="camera"){
						Camera * thisCamera = new Camera(atof(cmd[3].c_str()));
						scene->addCamera(cmd[2],thisCamera);
					}

			} else if (cmd[0]== "transform"){
				std::cout<<"Transform: "<<sdfLine<<std::endl;
				SceneObject * sceneObject = scene->getObjectByName(cmd[1]);
				if (cmd[2]=="rotate"){
					sceneObject->rotate(atof(cmd[3].c_str()),atof(cmd[4].c_str()),atof(cmd[5].c_str()),atof(cmd[6].c_str()));
				} else if (cmd[2]=="translate"){
						sceneObject->translate(atof(cmd[3].c_str()),atof(cmd[4].c_str()),atof(cmd[5].c_str()));
					}
			} else if (cmd[0]== "render"){
				std::cout<<"Render: "<<sdfLine<<std::endl;
			} else {
				std::cout<<"Unknown command: "<<sdfLine<<std::endl;
			}
		} else {
			std::cout<<std::endl;
		}
	}
	ifs.close();
	return scene;
}

SdfReader::~SdfReader(){

}
