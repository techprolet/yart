/*
 * sdfreader.cpp
 *
 *  Created on: Sep 17, 2012
 *      Author: pablo
 */
#include "include/sdfreader.hpp"
#include <fstream>

SdfReader::SdfReader():
	sdfFile_("")
{

}


SdfReader::SdfReader(char* sdfFile):
	sdfFile_(sdfFile)
{
	loadSdf();
}

void SdfReader::load(char* sdfFile){
	sdfFile_ = sdfFile;
	loadSdf();
}

void SdfReader::loadSdf(){
	std::ifstream ifs (sdfFile_ , std::ifstream::in );
	std::cout<<sdfFile_<<std::endl;
	while (ifs.good()){

		std::string sdfLine;

		std::getline (ifs, sdfLine);
		std::stringstream ss (sdfLine);
//		ss >> r;
//		ss >> g;
//		ss >> b;
//		ss >>colorName;
//		getline (ss, colorName);
//		trimSpaces (colorName);

		std::string command;
		ss >> command;
		if (command!="#"){
			std::cout<<sdfLine<<std::endl;
		}

	}
	ifs.close();
}

SdfReader::~SdfReader(){

}
