/* Autor: Victor Hugo Chimilovski Ribeiro
Código base: grafoLA.c /Autor: Prof. Jefferson Tales Oliva

Função: Granfo representado por lista de adjacencia, utilizando a Listas encadeadas
    a partir de um ponteiro de ponteiro

*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "GrafoLA.h"

//Define a ajacencias do vertice por uma lista de lista e retorna
static Lista** iniciar_LA(int n){
    int i;
    Lista **adj = malloc(n * sizeof(Lista*));

    for (i = 0; i < n; i++){
        adj[i] = malloc(sizeof(Lista));

        adj[i]->head = NULL;
    }

    return adj;
}

//Inicia o grafo recebendo como parametro o número de vertices
//    retorna o grafo do tipo GrafoLA
GrafoLA* iniciar_grafoLA(int v){
    GrafoLA* G = malloc(sizeof(GrafoLA));

    G->V = v;
    G->A = 0;
    G->adj = iniciar_LA(G->V);

    return G;
}

//Verifica se a aresta existe e retorna 1 se existir e 0 se não existir
//  recebe como parametro o grafo e os vertices da aresta
int aresta_existeLA(GrafoLA* G, int v1, int v2){
    if ((G!= NULL) && (G->adj[v1]->head != NULL))
        return procurar(v2, G->adj[v1]);

    return 0;
}

//Insere a aresta unindo os vértices recebidos como parametro
//  no grafo tambem informado como parametro
void inserir_arestaLA(GrafoLA* G, int v1, int v2){
    if (!aresta_existeLA(G, v1, v2)){
        inserir_na_lista(v2, G->adj[v1]);
        inserir_na_lista(v1, G->adj[v2]);
        G->A++;
    }
}

//Remove a aresta do grafo (G) recebido
//  tambem é necessario informar os vertices da aresta a ser removida(vertice 1 e vertice 2)
void remover_arestaLA(GrafoLA* G, int v1, int v2){
    if (aresta_existeLA(G, v1, v2)){
        remover_na_lista(v2, G->adj[v1]);
        remover_na_lista(v1, G->adj[v2]);
        G->A--;

    }
}

//Imprime todas as arestas do grafo (G), recebido como parametro
void imprimir_arestasLA(GrafoLA* G){
    int i;
    Cell *aux;

    if (G != NULL)
        for (i = 0; i < G->V; i++){
            aux = G->adj[i]->head;

            while (aux != NULL){
                printf("(%d, %d)\n", i, aux->key);

                aux = aux->next;
            }

        }
}

//Libera a memoria anteriormente alocada pelo grafo (G)
void liberarGLA(GrafoLA* G){
    int i;

    if (G != NULL){
        for (i = 0; i < G->V; i++)
            liberar_lista(G->adj[i]);

        free(G);
    }
}  
//USER CODE BEGIN

//Verifica se o vertice passado como parametro (v), existe no grafo (G), tambem informado
//  Retorna 1 se o vertice existir, e 0 caso o vertice não exista
int vertice_existe(GrafoLA * G,int v){
    if((G != NULL) && (G->V > v))
        return 1;
    else
        return 0;
    
}
//Imprime quais são os vertices do grafo informado
//  recebe como parametro apenas o grafo(G)
void imprime_vertice(GrafoLA * G){
    int i=0;
    Cell * aux;
        if(G != NULL){
            for(i=0; i < G->V; i++){
                aux = G->adj[i]->head;
                printf("vertice %d\n",i);
            }
        }
}
//Retorna a lista de ajacencia do vertice(v) contido no grafo informado(G)
Lista * vertices_ad(GrafoLA * G,int v){
    if(G != NULL && vertice_existe(G,v)==1)
        return G->adj[v];
}
 // Busca em largura de um vertice raiz(S) no grafo passado como parametro(G)
 //     retorna a arvore mínima do grafo
Lista * busca_larg(GrafoLA *G,int S){

}

//Retorna a árvore minima do grafo recebendo o grafo G e o vertice S como inicio
// OBS: o grafo deve ser ponderado para fazer a busca de arvore minima
Lista * prim(GrafoLA *G, int S){

}
//USER CODE END