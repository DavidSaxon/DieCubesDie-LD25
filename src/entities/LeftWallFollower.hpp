#ifndef _LEFTWALLFOLLOWER_H_
#	define _LEFTWALLFOLLOWER_H_

#include "Entity.hpp"


class LeftWallFollower : public Entity {
public:

	//CONSTRUCTOR
	LeftWallFollower(unsigned xPos, unsigned yPos,
        GLuint t1, GLuint t2, GLuint t3, GLuint t4, GLuint t5,
        std::vector<Entity*>* e);

	//METHODS
	void update();

	void draw() const;

    bool canComplete();

private:

    enum Direction {
    
        LEFT = 0,
        UP,
        RIGHT,
        DOWN
    };

	//VARIABLES
	GLuint tex1;
    GLuint tex2;
    GLuint tex3;
    GLuint tex4;
    GLuint tex5;
    unsigned moveCounter;
    int rotate;
    const std::vector<Entity*>* entities;
    bool animate;
    bool onLeft;
    bool inFront;
    bool tonLeft;
    bool tinFront;
    bool tmove;
    Direction dir;
    bool move;
};

#endif