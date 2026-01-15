#include <stdio.h>
#include <malloc.h>

#define MAX_STACK 100
#define MAX_QUEUE 20

typedef struct nodoPD{
	int id;
	struct nodoPD *prox;
}nodoPD;

typedef struct{
	nodoPD *ini;
	int tam;
}pilhaDinamica;

typedef struct{
	int vet[MAX_STACK];
	int tam;
}pilhaEstatica;

typedef struct{
	char nome[20];
	int qtdeIngressos;
}pessoa;

typedef struct{
	pessoa p;
	struct nodoFD *prox; 
}nodoFD;

typedef struct{
	nodoFD *ini;
	int tam;
}filaDinamica;




//pilha dinamica

pilhaDinamica *inicializaPD() {
	pilhaDinamica *new = (pilhaDinamica *)malloc(1*sizeof(pilhaDinamica));
	new->ini = NULL;
	new->tam = 0;
	return new;
}

void pushPD(pilhaDinamica *p, int x) {
	nodoPD *new = (nodoPD *)malloc(1*sizeof(nodoPD));
	new->id = x;
	new->prox = p->ini;
	p->ini = new;
	p->tam++;
}

int topPD(pilhaDinamica *p) {
	nodoPD *top = p->ini;
	return top->id;
}

void popPD(pilhaDinamica *p) {
	nodoPD *top = p->ini;
	if(top == NULL) return;
	p->ini = top->prox;
	free(top);
	p->tam--;
}

int tamPD(pilhaDinamica *p) { return p->tam; }

void imprimePD(pilhaDinamica *p) {
	nodoPD *aux = p->ini;
	while(aux != NULL) {
		printf("%d ", aux->id);
		aux = aux->prox;
	}
	printf("\n");
}

nodoPD *destroiListaLigadaPD(nodoPD *l) {
	if(l == NULL) return NULL;
	if(l->prox != NULL) l->prox = destroiListaLigadaPD(l->prox);
	if(l->prox == NULL) {
		free(l);
		return NULL;
	}	
}

void destroiPD(pilhaDinamica *p) {
	p->ini = destroiListaLigadaPD(p->ini);
	free(p);
}

//pilha estatica

pilhaEstatica *inicializaPE() {
	pilhaEstatica *new = (pilhaEstatica *)malloc(1*sizeof(pilhaEstatica));
	new->tam = 0;
	return new;
}

void destroiPE(pilhaEstatica *p) { free(p); }

void pushPE(pilhaEstatica *p, int x) {
	p->vet[p->tam] = x;
	p->tam++;
} 

void popPE(pilhaEstatica *p) { p->tam--; }

int topPE(pilhaEstatica *p) { return p->vet[p->tam-1]; }

int tamPE(pilhaEstatica *p) { return p->tam; }

void imprimePE(pilhaEstatica *p) {
	printf("\n");
	for(int i = 0; i < p->tam; i++) printf("%d ", p->vet[i]);
	printf("\n");
}

//fila dinamica

filaDinamica *inicializaFD() {
	filaDinamica *new = (filaDinamica *)malloc(1*sizeof(filaDinamica));
	new->tam = 0;
	new->ini = NULL;
	return new;
}

void pushFD(filaDinamica *f, pessoa pe) {
	nodoFD *new = (nodoFD *)malloc(1*sizeof(1*nodoFD));
	nodoFD *aux = f->ini;
	new->p = pe;








int main() {
	pilhaEstatica *p = inicializaPE();
	pushPE(p, 12);
	pushPE(p, 13);
	pushPE(p, 14);
	pushPE(p, 15);
	imprimePE(p);
	printf("\ntam: %d\n", tamPE(p));
	popPE(p);
	popPE(p);
	imprimePE(p);
	printf("\ntop: %d\n", topPE(p));
	printf("\ntam: %d\n", tamPE(p));
	destroiPE(p);
	return 0;
}
