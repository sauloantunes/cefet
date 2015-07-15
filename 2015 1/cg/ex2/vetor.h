#ifndef __VETOR_H__
#define __VETOR_H__

typedef struct {
	float x;
	float y;
	float z;
	int c;
} vetor;

vetor init(float, float, float, int);
vetor multEscalar(vetor, float);
vetor soma(vetor, vetor);
vetor vetorPorPontos(vetor, vetor);
float norma(vetor);
vetor prodVetorial(vetor, vetor);
float prodEscalar(vetor, vetor);
float menorAngulo(vetor, vetor);

#endif