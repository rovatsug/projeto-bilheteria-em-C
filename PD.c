#include "PD.h"

pilha *inicializaP() {
	pilha *new = (pilha *)malloc(1*sizeof(pilha));
	new->ini = NULL;
	new->tam = 0;
	return new;
}

void pushP(pilha *p, int x) {
	nodoPD *new = (nodoPD *)malloc(1*sizeof(nodoPD));
	new->id = x;
	new->prox = p->ini;
	p->ini = new;
	p->tam++;
}

int topP(pilha *p) {
	nodoPD *top = p->ini;
	return top->id;
}

void popP(pilha *p) {
	nodoPD *top = p->ini;
	if(top == NULL) return;
	p->ini = top->prox;
	free(top);
	p->tam--;
}

int tamP(pilha *p) { return p->tam; }

void imprimeP(pilha *p) {
	nodoPD *aux = p->ini;
	while(aux != NULL) {
		printf("%d ", aux->id);
		aux = aux->prox;
	}
	printf("\n");
}

nodoPD *destroiListaLigadaP(nodoPD *l) {
	if(l == NULL) return NULL;
	if(l->prox != NULL) l->prox = destroiListaLigadaP(l->prox);
	if(l->prox == NULL) {
		free(l);
		return NULL;
	}	
}

void destroiP(pilha *p) {
	p->ini = destroiListaLigadaP(p->ini);
	free(p);
}

