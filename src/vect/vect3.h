#ifndef MATH
#define MATH
#include <math.h>
#endif 

typedef struct vect3 {
	float x;
	float y;
	float z;
} vect3;

vect3 v3add(vect3, vect3);
vect3 v3sub(vect3, vect3);
vect3 v3scalarMul(float, vect3);
float v3dot(vect3, vect3);
vect3 v3cross(vect3, vect3);
vect3 v3norm(vect3);
float v3magnitude(vect3);
