#ifndef PD_H
#define PD_H

typedef struct nodoPD{
	int id;
	struct nodoPD *prox;
}nodoPD;

typedef struct{
	nodoPD *ini;
	int tam;
}pilha;

pilha *inicializaP();

void pushP(pilha *p, int x);

int topP(pilha *p);

void popP(pilha *p);

int tamP(pilha *p);

void imprimeP(pilha *p);

nodoP *destroiListaLigadaP(nodoPD *l);

void destroiP(pilha *p);

#endif
