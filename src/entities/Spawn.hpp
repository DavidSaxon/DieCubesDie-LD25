#ifndef _SPAWN_H_
#   define _SPAWN_H

#include "Entity.hpp"

class Spawn : public Entity {
public:

    Spawn(unsigned xPos, unsigned yPos, GLuint t);

    void update();

    void draw() const;

private:

    GLuint tex;
};

#endif