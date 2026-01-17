#ifndef FE_H
#define FE_H

typedef struct{
	pessoa vet[MAX_QUEUE];
	int tam;
	int ini;
	int fim;
}fila;

fila *inicializaF();

void pushF(fila *f, pessoa pe);

void destroiF(fila *f);

pessoa topF(fila *f);

void popF(fila *f);

int tamF(fila *f);

void imprimeF(fila *f);

#endif

