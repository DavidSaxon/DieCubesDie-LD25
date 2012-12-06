/*********************************************************************\
| File utilities provides a set of static functions relating to files |
\*********************************************************************/
#ifndef _FILEUTILITIES_H_
#	define _FILEUTILITIES_H_

#include <iostream>
#include <fstream>

#include "../exceptions/FileException.hpp"

class FileUtilities {
public:

	//FUNCTIONS
	/*Prints the file to terminal*/
	static void printFile(const std::string& filename);
};

/*Prints the file to terminal*/
inline void FileUtilities::printFile(const std::string& filename) {

	std::ifstream printFile(filename.c_str());

	//check that the file has opened correctly
	if (!printFile.is_open()) {
		throw FileOpenException("file does not exist.");
	}

	//read throught the entire file
	while (printFile.good()) {
		
		std::string line;
		std::getline(printFile, line);

		std::cout << line << std::endl;

	}

	printFile.close();
}

#endif