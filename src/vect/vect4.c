#ifndef VECT4
#define VECT4
#include "vect4.h"
#endif


vect4 v4add(vect4 u, vect4 v) {
	vect4 sum = {u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w};
	return sum;
}

vect4 v4sub(vect4 u, vect4 v) {
	vect4 sum = {u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w};
	return sum;
}
vect4 v4scalarMul(float c, vect4 u) {
	vect4 prod = {c *u.x, c*u.y, c*u.z, c*u.w};
	return prod;
}
float v4dot(vect4 u, vect4 v) {
	return u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w;
}
vect4 v4norm(vect4 u) {
	return v4scalarMul(1/v4magnitude(u), u);
}
float v4magnitude(vect4 u) {
	return sqrt(u.x * u.x + u.y * u.y + u.z * u.z + u.w * u.w);
}

#ifdef TEST
#include <stdio.h>

void printV4(vect4 u) {
	printf("<%.2f, %.2f, %.2f, %.2f>\n", u.x, u.y, u.z, u.w);
}

int main() {
	vect4 u = {1.0f, 2.0f, 3.0f, 4.0f};
	vect4 v = {1.0f, 1.0f, 0.0f, 0.0f};
	
	printf("u = ");
	printV4(u);
	printf("v = ");
	printV4(v);

	// testing add
	printf("Adding u + v\n");
	printV4(v4add(u,v));

	// testing sub
	printf("Subtracting u + v\n");
	printV4(v4sub(u,v));

	// testing scalarMul
	printf("Calculating 2 * u\n");
	printV4(v4scalarMul(2,u));

	// testing dot
	printf("Calculating u dot u = %.2f\n", v4dot(u, u));

	// testing norm
	printf("Calculating |u|\n");
	printV4(v4norm(u));
	printf("Calculating || |u| || = %.2f\n", v4magnitude(norm(u)));


	// testing mag
	printf("Calculating ||u|| = %.2f\n", v4magnitude(u));

	return 0;
}
#endif
