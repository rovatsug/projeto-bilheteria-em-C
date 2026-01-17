#include "FD.h"

//fila dinamica

fila *inicializaF() {
	fila *new = (fila *)malloc(1*sizeof(fila));
	new->tam = 0;
	new->ini = NULL;
	return new;
}

void pushF(fila *f, pessoa pe) {
	nodoFD *new = (nodoFD *)malloc(1*sizeof(nodoFD));
	nodoFD *aux = f->ini;
	f->tam++;
	new->p = pe;
	new->prox = NULL;
	if(f->ini == NULL) f->ini = new;
	else {
		while(aux->prox != NULL) aux = aux->prox;
		aux->prox = new;
	}
}

pessoa topF(fila *f) {
	nodoFD *n = f->ini;
	return n->p;
}

int tamF(fila *f) { return f->tam; }

void popF(fila *f) {
	if(f->ini == NULL) return;
	nodoFD *aux = f->ini;
	f->ini = aux->prox;
	f->tam--;
}

void imprimeListaLigadaF(nodoFD *n) {
	if(n == NULL) return;
	else {
		imprimeListaLigadaFD(n->prox);
		printf("%d %s\n", n->p.qtdeIngressos, n->p.nome);
	}
}

void imprimeF(fila *f) { printf("\n"); imprimeListaLigadaF(f->ini); printf("\n");}

void destroiListaLigadaF(nodoFD *n) {
	if(n == NULL) return;
	destroiListaLigadaF(n->prox);
	free(n);
}

void destroiF(fila *f) {
	destroiListaLigadaF(f->ini);
	free(f);
}

