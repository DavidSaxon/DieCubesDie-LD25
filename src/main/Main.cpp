#include <iostream>
#include <fstream>

//#include "../engine/Engine.hpp"
#include "../utilities/FileUtilities.hpp"

int main(int argc, char* argv[]) {

	//valid is set false if the program flags are not valid
	bool valid = true;

	//booleans for the flags
	bool help = false;
	bool editor = false;

	//check through the arguments
	for  (unsigned i = 0; i < static_cast<unsigned>(argc); ++i) {

		//check for the flag start
		if (argv[i][0] == '-') {

			for (unsigned j = 1; argv[i][j] != '\0'; ++j) {

				//check for the help flag
				if (argv[i][j] == 'h') {
					help = true;
				}
				//check for the editor flag
				else if (argv[i][j] == 'e') {
					editor = true;
				}
			}
		}
		else {
			valid = false;
		}
	}

	//if the flags arn't valid warn the user and exit
	if (!valid) {

		std::cout << "\nInvalid arguments provided. Use -h for help\n" << std::endl;

		//TODO: wait for an input key here

		return -1;
	}

	//execute the flags
	if (help) {

		FileUtilities::printFile("main/h.txt");

		//TODO: use the utilities for this input
		//now wait for the c or q key
		std::string in = "\0";
		while (in != "c" && in != "C" && in != "q" && in != "Q") {
			std::cin >> in;
		}

		//exit the game
		if (in == "q" || in == "Q") {
			return 0;
		}
	}
	else if (editor) {

		//TODO: run the editor here
	}

	std::cout << "TODO: run the engine here" << std::endl;
}