#ifndef _EXIT_H_
#   define _EXIT_H_

#include "Entity.hpp"

class Exit : public Entity {
public:

    Exit(unsigned xPos, unsigned yPos, GLuint t);

    void update();

    void draw() const;

private:

    GLuint tex;
};

#endif