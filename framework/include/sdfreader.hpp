/*
 * sdfreader.hpp
 *
 *  Created on: Sep 17, 2012
 *      Author: pablo
 */

#ifndef SDFREADER_HPP_
#define SDFREADER_HPP_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "scene.hpp"

class SdfReader{
public:
	SdfReader();
	SdfReader(std::string sdfFile);
	virtual ~SdfReader();

	void load (std::string sdfFile);

private:
	Scene * loadSdf();
	std::vector<std::string> parseArguments(std::stringstream& ss);
	std::string sdfFile_;
};

#endif /* SDFREADER_HPP_ */
