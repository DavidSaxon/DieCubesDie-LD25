#ifndef _FLOOR_H_
#	define _FLOOR_H_

#include "Entity.hpp"

class Floor : public Entity {
public:

	//CONSTRUCTOR
	Floor(unsigned xPos, unsigned yPos, GLuint t1, GLuint t2, GLuint t3,
        GLuint t4, GLuint t5);

	void update();

	void draw() const;

private:

	//VARIABLES
	GLuint tex1;
    GLuint tex2;
    GLuint tex3;
    GLuint tex4;
    GLuint tex5;

};

#endif