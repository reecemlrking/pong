#ifndef MATH
#define MATH
#include <math.h>
#endif

typedef struct vect4 {
	float x;
	float y;
	float z;
	float w;
} vect4;

vect4 v4add(vect4, vect4);
vect4 v4sub(vect4, vect4);
vect4 v4scalarMul(float, vect4);
float v4dot(vect4, vect4);
vect4 v4norm(vect4);
float v4magnitude(vect4);
