#include <stdio.h>
#include <stdlib.h>

typedef struct item Item;
typedef struct fila Fila;

#define MAXTAM 4

struct item {
  int chave;
  // demais campos
};

struct fila {
  Item item[MAXTAM];
  int primeiro;
  int ultimo;
  int tamanho;
};

Fila * cria_fila_vazia() {
  Fila *f = malloc(sizeof(Fila));
  f->primeiro = 0;
  f->ultimo = 0;
  f->tamanho = 0;
  return f;
}

int verifica_fila_vazia(Fila *f) {
  return f->tamanho == 0;
}

int verifica_fila_cheia(Fila *f) {
  return f->tamanho == MAXTAM;
}

void enfileira(Fila* f, int chave) {
  if(verifica_fila_cheia(f)) {
		printf("Erro: a fila está cheia.\n");
    return;
  }
	else {
    Item novo_item;
    novo_item.chave = chave;
		f->item[f->ultimo] = novo_item;
		f->ultimo = (f->ultimo + 1) % MAXTAM;
		f->tamanho++;
	}
}

void imprime(Fila* f) {
	int i = f->primeiro;
	int t = f->tamanho;
	while (t > 0) {
		printf("Chave: %d\n", f->item[i].chave);
		t--;
		i = (i+1) % MAXTAM;
	}
}

int desenfileira(Fila* f) {
    Item novo;
	if(verifica_fila_vazia(f)) {
    printf("Erro: a fila está vazia.\n");
    return -1;
  }
	else{
        novo = f->item[f->primeiro];
		f->primeiro = (f->primeiro + 1) % MAXTAM;
		f->tamanho--;
        return novo.chave;
	}
}

void libera(Fila *f) {
  free(f);
}

int busca_menor(Fila *f){
    int k=0,i=f->primeiro+1;
    while(k<f->tamanho){
        //printf("Indice = %d e Primeiro = %d\n",i,f->primeiro);
        if(f->item[f->primeiro].chave < f->item[i].chave){
            return f->item[i].chave;
        }
        else{
            i++;
        }
        k++;
    }
    return -1;
}

int main(){
    Fila *f = cria_fila_vazia();

    int num,i=0;
    while(i<4){
        scanf("%d",&num);
        enfileira(f,num);
        i++;
    }
    i=0;
    while(i<4){
        num = busca_menor(f);
        printf("%d  %d\n",desenfileira(f),num);
        i++;
    }
    libera(f);
}
