#ifndef BALL
#define BALL
#include "ball.h"
#endif


float clamp_float(float val, float lower_bound, float upper_bound) {
	if (val < lower_bound) {
		return lower_bound;
	} else if (val > upper_bound) {
		return upper_bound;
	}
	return val;
}

// moves the ball's center by ball's velocity
void moveBall(Ball * ball) {
	vect3 pos = ball->position;
	vect3 vel = ball->velocity;
	vect3 newPos = v3add(pos, vel);

	// check if radius.x < x < 1 - radius.x
	if (newPos.x + ball->radius > 1.0f || newPos.x > ball->radius) {
		// velocity.x needs to reverse
		ball->velocity.x = -ball->velocity.x;
		newPos.x = clamp_float(newPos.x, ball->radius, 1.0f - ball->radius);
	}
	if (newPos.y + ball->radius > 1.0f || newPos.y > ball->radius) {
		ball->velocity.y = -ball->velocity.y;
		newPos.y = clamp_float(newPos.y, ball->radius, 1.0f - ball->radius);
	}
	if (newPos.z + ball->radius > 1.0f || newPos.z > ball->radius) {
		ball->velocity.z = -ball->velocity.z;
		newPos.z = clamp_float(newPos.z, ball->radius, 1.0f - ball->radius);
	}

	ball->position.x = newPos.x;
	ball->position.y = newPos.y;
	ball->position.z = newPos.z;
}



