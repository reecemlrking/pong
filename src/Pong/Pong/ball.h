#pragma once

typedef struct ball{
	float* center;
	float* velocity;
	float radius;
} Ball;

void translate(Ball*, float*);
void move(Ball*, int, int);

