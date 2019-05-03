#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100
typedef struct item Item;
typedef struct lista Lista;

struct item {
    int codigo;
    float peso;
    // demais campos desejados
};

struct lista {
    Item item[MAXTAM];
    int ultimo;
};

// criar uma lista vazia
Lista * cria_lista_vazia() {
    Lista *l = malloc(sizeof(Lista));
    l->ultimo = -1;
    return l;
}

// retorna 1 se a lista está cheia ou 0 se não está cheia
int verifica_lista_cheia(Lista *l) {
    return l->ultimo == MAXTAM - 1;
}

// adiciona um elemento no fim da lista
void adiciona_item_fim_lista(Lista *l, int codigo, float peso) {
    if(verifica_lista_cheia(l)){
        printf("Erro: a lista está cheia.\n");
        return;
    }
    else {
        Item novo_item;
        novo_item.codigo = codigo;
        novo_item.peso = peso;
        l->ultimo++;
        l->item[l->ultimo] = novo_item;
    }
}

// imprime a lista
void imprime_lista(Lista *l) {
    int tam = l->ultimo + 1;
    int i;
    for(i = 0; i < tam; i++)
        printf("%d  %f\n", l->item[i].codigo,l->item[i].peso);
}

// retorna indice que contém o item com a codigo buscada
int busca_item_por_chave(Lista *l, int codigo) {
    int tam, i, posicao;
    tam = l->ultimo + 1;
    posicao = -1;
    for(i = 0; i < tam; i++)
        if(l->item[i].codigo == codigo)
            posicao = i;
    return posicao;
}

// retorna 1 se a lista está vazia ou 0 se não está vazia
int verifica_lista_vazia(Lista *l) {
    return l->ultimo == -1;
}

// remove um item qualquer da lista
void remove_item(Lista *l, int codigo) {
    int posicao, vazia, i, tam;
    vazia = verifica_lista_vazia(l);
    posicao = busca_item_por_chave(l, codigo);
    if (vazia || posicao == -1) {
        printf("Erro: a lista está vazia ou o item não existe.\n");
        return;
    }
    else {
        tam = l->ultimo + 1;
        for(i = posicao; i < tam - 1; i++)
            l->item[i] = l->item[i + 1];
        l->ultimo--;
    }
}

void libera_lista(Lista *l) {
    free(l);
}

int busca_maior(Lista *l){
    int tam = l->ultimo+1;
    int i,aux=0;
    for(i=1;i<tam;i++){
        if(l->item[aux].peso < l->item[i].peso){
            aux = i;
        }
    }
    return aux;
}

void main(){
    Lista *l = cria_lista_vazia();
    Item valores;

    float P,M,tot=0;
    int N,i=0;

    scanf("%f",&P);
    scanf("%f",&M);
    scanf("%d",&N);

    while(i<N){
        scanf("%d %f",&valores.codigo,&valores.peso);
        adiciona_item_fim_lista(l,valores.codigo,valores.peso);
        i++;
        tot=tot+valores.peso;
    }
    tot= tot+M;
    imprime_lista(l);
    printf("Total de peso = %f\n",tot);
    i=0;
    while(tot>P){
        valores = l->item[busca_maior(l)];
        printf("%d %f ",valores.codigo,valores.peso);
        tot=tot-valores.peso;
        remove_item(l,valores.codigo);
    }
    printf("\n");
    libera_lista(l);

}
