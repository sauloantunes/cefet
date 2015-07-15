#include "stdio.h"
#include "vetor.h"

int main(){
	vetor u,v,w;
	vetor a, b;
	float n;

	a = init(1, 1, 1, 1);
	b = init(3, 3, 3, 1);
	
	u = init(1,2,3,0);
	v = init(1,5,9,0);

	printf("Vetores:\n");
	printf("U = (%.2f, %.2f, %.2f, %d)\n", u.x, u.y, u.z, u.c);
	printf("V = (%.2f, %.2f, %.2f, %d)\n", v.x, v.y, v.z, v.c);
	printf("\n");

	printf("Pontos:\n");
	printf("A = (%.2f, %.2f, %.2f, %d)\n", a.x, a.y, a.z, a.c);
	printf("B = (%.2f, %.2f, %.2f, %d)\n", b.x, b.y, b.z, b.c);
	printf("\n");

	w = multEscalar(u, 3);
	printf("Multiplicao por escalar:\n");
	printf("U * 3 = (%.2f, %.2f, %.2f, %d)\n", w.x, w.y, w.z, w.c);
	printf("\n");

	w = soma(u, v);
	printf("Soma:\n");
	printf("U + V = (%.2f, %.2f, %.2f, %d)\n", w.x, w.y, w.z, w.c);
	printf("\n");
	

	w = vetorPorPontos(a, b);
	printf("Criacao vetor por Pontos:\n");
	printf("B - A = (%.2f, %.2f, %.2f, %d)\n", w.x, w.y, w.z, w.c);
	printf("\n");

	n = norma(v);
	printf("Norma de V:\n");
	printf("|V| = %.2f\n", n);
	printf("\n");

	w = prodVetorial(u, v);
	printf("Produto Vetorial:\n");
	printf("U x V = (%.2f, %.2f, %.2f, %d)\n", w.x, w.y, w.z, w.c);
	printf("\n");	

	n = prodEscalar(u, v);
	printf("Produto Escalar:\n");
	printf("U . V = %.2f\n", n);
	printf("\n");	

	n = menorAngulo(u, v);
	printf("Menor Angulo entre U e V\n");
	printf("(U,V) = %.2f rad\n", n);
	printf("\n");	
}
