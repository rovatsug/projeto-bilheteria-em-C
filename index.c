#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_STACK 4
#define MAX_QUEUE 4

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

typedef struct nodoFD{
	pessoa p;
	struct nodoFD *prox; 
}nodoFD;

typedef struct{
	nodoFD *ini;
	int tam;
}filaDinamica;

typedef struct{
	pessoa vet[MAX_QUEUE];
	int tam;
	int ini;
	int fim;
}filaEstatica;


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

pessoa topFD(filaDinamica *f) {
	nodoFD *n = f->ini;
	return n->p;
}

int tamFD(filaDinamica *f) { return f->tam; }

void popFD(filaDinamica *f) {
	if(f->ini == NULL) return;
	nodoFD *aux = f->ini;
	f->ini = aux->prox;
	f->tam--;
}

void imprimeListaLigadaFD(nodoFD *n) {
	if(n == NULL) return;
	else {
		imprimeListaLigadaFD(n->prox);
		printf("%d %s\n", n->p.qtdeIngressos, n->p.nome);
	}
}

void imprimeFD(filaDinamica *f) { printf("\n"); imprimeListaLigadaFD(f->ini); printf("\n");}

void destroiListaLigadaFD(nodoFD *n) {
	if(n == NULL) return;
	destroiListaLigadaFD(n->prox);
	free(n);
}

void destroiFD(filaDinamica *f) {
	destroiListaLigadaFD(f->ini);
	free(f);
}


//fila estatica

filaEstatica *inicializaFE() {
	filaEstatica *f = (filaEstatica *)malloc(1*sizeof(filaEstatica));
	f->tam = f->ini = f->fim = 0;
	return f;
}

void pushFE(filaEstatica *f, pessoa pe) {
	f->vet[f->fim] = pe;
	f->fim = (f->fim + 1) % MAX_QUEUE;
	f->tam++;
}

void destroiFE(filaEstatica *f) { free(f); }

pessoa topFE(filaEstatica *f) { return f->vet[f->ini]; }

void popFE(filaEstatica *f) { f->ini = (f->ini + 1) % MAX_QUEUE; f->tam--; }

int tamFE(filaEstatica *f) { return f->tam; }

void imprimeFE(filaEstatica *f) {
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






pessoa criarPessoa(const char *name, int qtde) {
    pessoa p;
    strncpy(p.nome, name, 19);
    p.nome[19] = '\0'; // Garantia de segurança para fechar a string
    p.qtdeIngressos = qtde;
    return p;
}

int main() {

	return 0;
}
