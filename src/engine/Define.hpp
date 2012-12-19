/********************************************************\
| This defines values and enumerators used by the engine |
\********************************************************/
#ifndef _DEFINE_H_
#   define _DEFINE_H_

#include "../entities/LeftWallFollower.hpp"
#include "../entities/RightWallFollower.hpp"
#include "../entities/Floor.hpp"
#include "../entities/Wall.hpp"
#include "../entities/Spawn.hpp"
#include "../entities/Exit.hpp"
#include "../entities/Spike.hpp"
#include "../entities/Death.hpp"

//the natural x and y resolutions of the game
#define NATURAL_RESO_X 1920
#define NATURAL_RESO_Y 1080

//Pi
#define PI 3.14159265

//The height and width of the level
#define LEVEL_WIDTH 20
#define LEVEL_HEIGHT 20

//ENUMERATORS
enum State {
	TITLE = 0,
	LEVEL
};

//STRUCTURES
/*A 3d dimensional vector*/
struct Vector3 {

	//CONSTRUCTORS
	/*Default constructor*/
	Vector3() :
		x(0),
		y(0),
		z(0) {}

	/*Constructor to assign values*/
	Vector3(float _x, float _y, float _z) :
		x(_x),
		y(_y),
		z(_z) {}

	//OPERATORS
	/*assignment operator*/
	void operator= (const Vector3& other) {

		x = other.x;
		y = other.y;
		z = other.z;
	}

	//VARIAVBLES
	float x;
	float y;
	float z;
};

/*A RBGA colour*/
struct Colour4 {

	//CONSTRUCTORS
	/*Default Constructor*/
	Colour4() :
		r(0),
		g(0),
		b(0),
		a(0) {}


	/*Constructor to assigned values*/
	Colour4(float _r, float _g, float _b, float _a) :
		r(_r),
		g(_g),
		b(_b),
		a(_a) {}

	//OPERATORS
	/*Assignment operator*/
	void operator= (const Colour4& other) {

		r = other.r;
		g = other.g;
		b = other.b;
		a = other.a;
	}

	//VARIABLES
	float r;
	float g;
	float b;
	float a;
};

#endif