#ifndef PE_H
#define PE_H

typedef struct{
	int vet[MAX_STACK];
	int tam;
}pilha;

pilha *inicializaP();

void destroiP(pilha *p);

void pushP(pilha *p, int x);

void popP(pilha *p);

int topP(pilha *p);

int tamP(pilha *p);

void imprimeP(pilha *p);

#endif

