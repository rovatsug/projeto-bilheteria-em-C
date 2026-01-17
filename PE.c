#include "PE.h"

pilha *inicializaP() {
	pilha *new = (pilha *)malloc(1*sizeof(pilha));
	new->tam = 0;
	return new;
}

void destroiP(pilha *p) { free(p); }

void pushP(pilha *p, int x) {
	p->vet[p->tam] = x;
	p->tam++;
} 

void popP(pilha *p) { p->tam--; }

int topP(pilha *p) { return p->vet[p->tam-1]; }

int tamP(pilha *p) { return p->tam; }

void imprimeP(pilha *p) {
	printf("\n");
	for(int i = 0; i < p->tam; i++) printf("%d ", p->vet[i]);
	printf("\n");
}

