#ifndef VECT3
#define VECT3
#include "vect3.h"
#endif

// Adds two 3d vectors
vect3 v3add(vect3 u, vect3 v) {
	vect3 sum = {u.x + v.x, u.y + v.y, u.z + v.z};
	return sum;
}

// Subtracts two 3d vectors
vect3 v3sub(vect3 u, vect3 v) {
	vect3 sum = {u.x - v.x, u.y - v.y, u.z - v.z};
	return sum;
}

vect3 v3scalarMul(float c, vect3 u) {
	vect3 prod = {c * u.x, c * u.y, c * u.z};
	return prod;
}

float v3dot(vect3 u, vect3 v) {
	return u.x * v.x + u.y * v.y + u.z * v.z;
	
}

vect3 v3cross(vect3 u, vect3 v) {
	vect3 res = {u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x};
	return res;
}

vect3 v3norm(vect3 u) {
	float mag = v3magnitude(u);
	vect3 norm = v3scalarMul(1/mag, u);
	return norm;
}

float v3magnitude(vect3 u) {
	return sqrt(v3dot(u, u));
}

#ifdef TEST
#include <stdio.h>

void printV3(vect3 u) {
	printf("<%.2f, %.2f, %.2f>\n", u.x, u.y, u.z);
}

int main() {
	vect3 u = {1.0f, 2.0f, 3.0f};
	vect3 v = {1.0f, 1.0f, 0.0f};
	
	printf("u = ");
	printV3(u);
	printf("v = ");
	printV3(v);

	// testing add
	printf("Adding u + v\n");
	printV3(v3add(u,v));

	// testing sub
	printf("Subtracting u + v\n");
	printV3(v3sub(u,v));

	// testing scalarMul
	printf("Calculating 2 * u\n");
	printV3(v3scalarMul(2,u));

	// testing dot
	printf("Calculating u dot u = %.2f\n", v3dot(u, u));

	// testing cross
	printf("Calculating u x v\n");
	printV3(v3cross(u, v));

	// testing norm
	printf("Calculating |u|\n");
	printV3(v3norm(u));
	printf("Calculating || |u| || = %.2f\n", v3magnitude(norm(u)));


	// testing mag
	printf("Calculating ||u|| = %.2f\n", v3magnitude(u));

	return 0;
}
#endif
