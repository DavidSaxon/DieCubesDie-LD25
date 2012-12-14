#ifndef _FILEEXCEPTION_H_
#   define _FILEEXCEPTION_H_

#include <sstream>

#include "Exception.hpp"

/**************************************************************************\
| File exception extends exception. All exceptions related to files extend |
| file exception.                                                          |
\**************************************************************************/
class FileException : public Exception {
};

/************************************************************\
| File open exception warns of an error while opening a file |
\************************************************************/
class FileOpenException : public FileException {
public:

    //CONSTRUCTOR
    FileOpenException(const std::string& s) {
        
        std::stringstream ss;
        ss << "FILE OPEN EXCEPTION: " << s;
        info = ss.str();
    }

};

#endif