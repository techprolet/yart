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

class SdfReader{
public:
	SdfReader();
	SdfReader(char* sdfFile);
	virtual ~SdfReader();

	void load (char* sdfFile);

private:
	void loadSdf();
	char* sdfFile_;
};

#endif /* SDFREADER_HPP_ */
