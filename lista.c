#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


Lista* criar_lista(){
    Lista* l = malloc(sizeof(Lista));

    l->head = NULL;

    return l;
}


Cell* criar_celula(int key){
    Cell *c = malloc(sizeof(Cell));
    c->key = key;

    c->next = NULL;

    return c;
}

int lista_vazia(Lista *l){
    return (l == NULL) || (l->head == NULL);
}


int procurar(int key, Lista *l){
    Cell *aux;

    if (l != NULL){
        aux = l->head;

        while ((aux != NULL) && (aux->key != key))
            aux = aux->next;
    }

    if (aux != NULL)
        return 1;
    else
        return 0;
}


void inserir_na_lista(int key, Lista *l){
    Cell *auxA, *auxP;
    Cell* c;

    if (lista_vazia(l)){
        if (l == NULL)
            l = criar_lista();

        l->head = criar_celula(key);
    }else{
        c = criar_celula(key);

        if (l->head->key >= key){
           c->next = l->head;
           l->head = c;
        }else{
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->key < key)){
                auxA = auxP;
                auxP = auxP->next;
            }

            auxA->next = c;
            c->next = auxP;
        }
    }
}

//criar enfila -> insere no fim
void enfila(Lista *l,int key){
    Cell *auxA,*auxP;
    Cell *c;
    if (lista_vazia(l)){
        if (l == NULL)
            l = criar_lista();

        l->head = criar_celula(key);
    }
    else{
        c = criar_celula(key);
        auxA = l->head;
        auxP = auxA;
        while(auxP != NULL){
            auxA = auxP;
            auxP = auxP->next;
        }
        auxA->next = c;
        c->next = auxP;
    }

}

//criar desenfila -> remove do inicio
int desenfila(Lista *l){
    Cell *aux;
    if(!lista_vazia(l)){
        aux = l->head;
        l->head = l->head->next;
        free(aux);
        return 1;
    }
    return 0;
}
int remover_na_lista(int key, Lista *l){
    Cell *auxA, *auxP;

    if (!lista_vazia(l)){
        auxA = l->head;

        if(auxA->key == key)
            l->head = l->head->next;
        else{
            auxP = auxA;

            while((auxA != NULL) && (auxA->key != key)){
                auxP = auxA;
                auxA = auxA->next;
            }

            auxP->next = auxA->next;
        }

        if (auxA != NULL)
            free(auxA);

        return 1;
    }

        return 0;
}


void imprimir(Lista *l){
    Cell *aux,*prox;

    if (!lista_vazia(l)){
        aux = l->head;
        while (aux != NULL){
            printf("%d ", aux->key);
            aux = aux->next;
        }
    }
}


int liberar_lista(Lista *l){
    Cell *aux;

    if ((l != NULL) && !lista_vazia(l)){

        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}



