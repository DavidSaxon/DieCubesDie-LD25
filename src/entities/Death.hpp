#ifndef _DEATH_H_
#   define _DEATH_H_

#include "Entity.hpp"

class Death : public Entity {
public:

    GLuint* tex;
    unsigned ani;
    unsigned counter;

    Death(unsigned xPos, unsigned yPos, GLuint* t);

    void update();

    void draw() const;

};

#endif