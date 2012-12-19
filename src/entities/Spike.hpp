#ifndef _SPIKE_H_
#	define _SPIKE_H_

#include "Entity.hpp"

class Spike : public Entity {
public:

	Spike(unsigned xPos, unsigned yPos, GLuint t1, GLuint t2,
		GLuint t3, GLuint t4);

	void update();

	void draw() const;

private:

	GLuint tex1;
	GLuint tex2;
	GLuint tex3;
	GLuint tex4;

};

#endif