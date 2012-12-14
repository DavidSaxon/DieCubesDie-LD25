/****************************************************************\
| Input utilities is a set of static functions realting to input |
\****************************************************************/

#include <iostream>
#include <vector>

class InputUtilities {
public:
    
    //FUNCTIONS
    /*Waits for a valid character to inputed via terminal. Input is a string
    containing the valid characters*/
    static std::string waitForInputChar(std::string input);

};

inline std::string InputUtilities::waitForInputChar(std::string input) {
    //a vector that conatins the valid characters
    std::vector<char> validChars;

    //get the valid characters from the string
    for (unsigned i = 0; i < input.length(); ++i) {

        validChars.push_back(input.at(i));
    }

    //wait for a valid char then return it
    char in;
    while (true) {

        std::cin >> in;

        //iterate through the vector
        std::vector<char>::const_iterator
            it = validChars.begin(),
            ite = validChars.end();
        for (; it != ite; ++it) {
            if (*it == in) {
                return std::string(static_cast<const char*>(&in));
            }
        }
    }
}