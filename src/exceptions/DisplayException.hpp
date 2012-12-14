#ifndef _DISPLAYEXCEPTION_H_
#   define _DISPLAYEXCEPTION_H_

#include <sstream>

#include "Exception.hpp"

/*************************************************************************\
| Display exception extends exceptions. All exceptions related to SDL and |
| openGL display extend display exceptions                                |
\*************************************************************************/
class DisplayException : public Exception {
};

/******************************************************************\
| SDL exception warns of an error that has occured relating to SDL |
\******************************************************************/
class SDLException : public DisplayException {
public:

    //CONSTRUCTOR
    SDLException(const std::string& s) {

        std::stringstream ss;
        ss << "SDL EXCEPTION: " << s;
        info = ss.str();
    }
};

/************************************************************************\
| OpenGL exception warns of an error that has occured relating to OpenGL |
\************************************************************************/
class OpenGLException : public DisplayException {
public:

    //CONSTRUCTOR:
    OpenGLException(const std::string& s) {

        std::stringstream ss;
        ss << "OPENGL EXCEPTION: " << s;
        info = ss.str();
    }
};

/****************************************************************************\
| Window exception warns of an error that has occured relating to the window |
\****************************************************************************/
class WindowException : public DisplayException {
public:

    //CONSTRUCTOR
    WindowException(const std::string& s) {

        std::stringstream ss;
        ss << "WINDOW EXCEPTION: " << s;
        info =  ss.str();
    }
};

#endif