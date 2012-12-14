#include <iostream>
#include <fstream>

#include "../engine/Engine.hpp"
#include "../exceptions/Exception.hpp"
#include "../utilities/FileUtilities.hpp"
#include "../utilities/InputUtilities.hpp"

int main(int argc, char* argv[]) {

    //valid is set false if the program flags are not valid
    bool valid = true;

    //booleans for the flags
    bool help = false;
    bool editor = false;

    //check through the arguments
    for  (unsigned i = 1; i < static_cast<unsigned>(argc); ++i) {

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
                else {
                    valid = false;
                }
            }
        }
        else {
            valid = false;
        }
    }

    //if the flags arn't valid warn the user and exit
    if (!valid) {

        std::cout << "\nInvalid arguments provided. Use -h for help\n"
            << std::endl;

        std::cout << "Enter q to exit" << std::endl;
        
        InputUtilities::waitForInputChar("qQ");

        return -1;
    }

    //execute the flags
    if (help) {

        //TODO: catch exception here
        FileUtilities::printFile("src/main/h.txt");

        std::string in = InputUtilities::waitForInputChar("cCqQ");

        //exit the game
        if (in == "q" || in == "Q") {
            return 0;
        }
    }
    else if (editor) {

        //TODO: run the editor here
    }

    //Run the engine
    Engine engine;

    try {
        engine.init();
    } catch (Exception& e) {
        //TODO: display dialog
        std::cout << e.what() << std::endl;

        return -1;
    }

    engine.execute();
    engine.close();
}