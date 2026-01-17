#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

#define BUFF_SIZE 100
#define MAX_STACK 4
#define MAX_QUEUE 4

typedef struct{
	char nome[20];
	int qtdeIngressos;
}pessoa;

#include "PD.h"
//#include "PE.h"
#include "FD.h"
//#include "FE.h"

pessoa criarPessoa(const char *name, int qtde) {
    pessoa p;
    strncpy(p.nome, name, 19);
    p.nome[19] = '\0';
    p.qtdeIngressos = qtde;
    return p;
}

char *alocaBuffer(int tam) { return (char *)malloc(tam*sizeof(char)); }

void inputBuffer(char *buff) { for(int i = 0; i < BUFF_SIZE && buff[i-1] != '\n'; i++) scanf("%c", buff+i); }

void outputBuffer(char *buff) { for(int i = 0; i < BUFF_SIZE; i++) printf("%c", *(buff+i)); }

void destroiBuffer(char *c) { free(c); }

int characterToNum(char *c) {
	int res = 0;
	if(*c == ' ') c++;
	while(*c >= '0' && *c <= '9') {
		res = res*10 + (*c - '0');
		c++;
	}
	return res;
}

int main() {
	int ingressosVendidos = 0;
	char *buffer = alocaBuffer(BUFF_SIZE);
	fila *f0 = inicializaF(), *f1 = inicializaF();
	pilha *p0 = inicializaP(), *p1 = inicializaP();
	bool condicao = true;
	while(condicao) {
		inputBuffer(buffer);
		outputBuffer(buffer);
		switch(buffer[1]) {
			case 'i': //fim

				printf("Ingressos vendidos: %d.\n", ingressosVendidos); 
				condicao = false;
				break;
			case 'a': //carrega
				  
				break;
			case 'e': //vende
				  
				break;
			case 'h': //chega
				  
				break;
			default:
				condicao = false;
				break;
		}
	}
	destroiBuffer(buffer);
	destroiF(f0);
	destroiF(f1);
	destroiP(p0);
	destroiP(p1);
	return 0;
}
