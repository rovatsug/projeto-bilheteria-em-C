#ifndef FD_H
#define FD_H

typedef struct nodoFD{
	pessoa p;
	struct nodoFD *prox; 
}nodoFD;

typedef struct{
	nodoFD *ini;
	int tam;
}fila;

fila *inicializaF();

void pushF(fila *f, pessoa pe);

pessoa topF(fila *f);

int tamF(fila *f);

void popF(fila *f);

void imprimeListaLigadaF(nodoFD *n);

void imprimeF(fila *f);

void destroiListaLigadaF(nodoFD *n);

void destroiF(fila *f);

#endif

