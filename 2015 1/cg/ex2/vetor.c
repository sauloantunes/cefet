#include "vetor.h"
#include "math.h"


vetor init(float x, float y, float z, int c){
	vetor v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.c = c;
	
	return v;
}

vetor multEscalar(vetor v, float a){
	v.x *= a;
	v.y *= a;
	v.z *= a;

	return v;
}

vetor soma(vetor u, vetor v){
	v.x += u.x;
	v.y += u.y;
	v.z += u.z;

	return v;
}

vetor vetorPorPontos(vetor u, vetor v){
	v.x -= u.x;
	v.y -= u.y;
	v.z -= u.z;
	v.c -= u.c;

	return v;
}

float norma(vetor v){
	return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

vetor prodVetorial(vetor u, vetor v){
	vetor w;
	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;

	return w;
}
float prodEscalar(vetor u, vetor v){
	return u.x * v.x + u.y * v.y + u.z * v.z;
}
float menorAngulo(vetor u, vetor v){
	return acos(prodEscalar(u, v) / (norma(u) * norma(v)) );
}
