#ifndef VECT3
#define VECT3
#include "../vect/vect3.h"
#endif
#ifndef VECT4
#define VECT4
#include "../vect/vect4.h"
#endif

typedef struct Ball {
	vect3 position;
	vect3 velocity;
	vect4 color;
	float radius;
} Ball;

void moveBall(Ball * ball);

void drawBall(Ball ball);
