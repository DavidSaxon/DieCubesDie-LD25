/******************************************************************\
| A standard exception class that all other exceptions extend from |
\******************************************************************/
#ifndef _EXCEPTION_H_
# define _EXCEPTION_H_

#include <iostream>
#include <sstream>

class Exception {
public:

    //METHODS
    const std::string& what() const;

protected:

    //VARIABLES
    std::string info;

};

inline const std::string& Exception::what() const {

    return info;
};

#endif