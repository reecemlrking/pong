#ifndef BALL
#define BALL
#include "ball.h"
#endif

/*
Translates ball to desired position.
Inputs:
	- ball (Ball*) : pointer to ball desired to move.
	- position (float*) : pointer to a 3d vector containing the desired coordinates for the balls new position.
*/
void translate(Ball* ball, float* position)
{
	ball->center[0] = position[0];
	ball->center[1] = position[1];
	ball->center[2] = position[2];
}

/*
Moves the ball by its velocity.
Inputs:
	- ball (Ball*) : pointer to ball desired to move.	
*/
void move(Ball* ball, int frame_width, int frame_height)
{
	// move ball - velocity normalized to frame size.
	ball->center[0] += ball->velocity[0] / (float)frame_width * 2.0f;
	ball->center[1] += ball->velocity[1] / (float)frame_height * 2.0f;
	ball->center[2] += ball->velocity[2];

	// bound ball to frame boundaries
	if (ball->center[0] - ball->radius / (float) frame_width * 2.0f < -1) {
		ball->velocity[0] = -ball->velocity[0];
		ball->center[0] = -1 + ball->radius / (float)frame_width * 2.0f;
	}
	if (ball->center[0] + ball->radius / (float) frame_width * 2.0f > 1) {
		ball->velocity[0] = -ball->velocity[0];
		ball->center[0] = 1 - ball->radius / (float)frame_width * 2.0f;
	}
	if (ball->center[1] - ball->radius / (float) frame_height * 2.0f < -1) {
		ball->velocity[1] = -ball->velocity[1];
		ball->center[1] = -1 + ball->radius / (float)frame_height * 2.0f;
	}
	if (ball->center[1] + ball->radius / (float)frame_height * 2.0f > 1) {
		ball->velocity[1] = -ball->velocity[1];
		ball->center[1] = 1 - ball->radius / (float)frame_height * 2.0f;
	}
	//if (ball->center[2] - ball->radius < -1) {
	//	ball->velocity[2] = -ball->velocity[2];
	//	ball->center[2] = -1 + ball->radius;
	//}
	//if (ball->center[2] + ball->radius > 1) {
	//	ball->velocity[2] = -ball->velocity[2];
	//	ball->center[2] = 1 - ball->radius;
	//}
}

