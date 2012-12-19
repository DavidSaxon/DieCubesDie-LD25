#ifndef _WALL_H_
#	define _WALL_H_

#include "Entity.hpp"

class Wall : public Entity {
public:

	const bool outside;

	Wall(unsigned xPos, unsigned yPos, GLuint t1, GLuint t2,
    GLuint t3, GLuint t4, GLuint t5, bool o);

	void update();

	void draw() const;

protected:

	GLuint tex1;
    GLuint tex2;
    GLuint tex3;
    GLuint tex4;
    GLuint tex5;
};

#endif