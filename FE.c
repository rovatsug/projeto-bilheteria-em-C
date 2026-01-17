#include "FE.h"

filaEstatica *inicializaF() {
	fila *f = (fila *)malloc(1*sizeof(fila));
	f->tam = f->ini = f->fim = 0;
	return f;
}

void pushF(fila *f, pessoa pe) {
	f->vet[f->fim] = pe;
	f->fim = (f->fim + 1) % MAX_QUEUE;
	f->tam++;
}

void destroiF(fila *f) { free(f); }

pessoa topF(fila *f) { return f->vet[f->ini]; }

void popF(fila *f) { f->ini = (f->ini + 1) % MAX_QUEUE; f->tam--; }

int tamF(fila *f) { return f->tam; }

void imprimeF(fila *f) {
	if(f->tam == 0) return;
	int i = f->ini;
	if(f->ini < f->fim) {
		while(i < f->fim) {
			printf("%s %d\n", f->vet[i].nome, f->vet[i].qtdeIngressos);
			i++;
		}	
	}else if(f->fim <= f->ini) {
		while(i < MAX_QUEUE) {
			printf("%s %d\n", f->vet[i].nome, f->vet[i].qtdeIngressos);
			i++;
		}
		i = 0;
		while(i < f->fim) {
			printf("%s %d\n", f->vet[i].nome, f->vet[i].qtdeIngressos);
			i++;
		}
	}
}

