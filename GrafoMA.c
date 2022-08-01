#include <stdio.h>
#include <stdlib.h>
#include "GrafoMA.h"

static int** iniciar_MA(int n){
    int i, j;
    int **mat = malloc(n * sizeof(int*));

    for (i = 0; i < n; i++)
        mat[i] = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mat[i][j] = 0;

    return mat;
}


static int valida_vertice(GrafoMA* G, int v){
    return (v >= 0) && (v < G->V);
}


GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = malloc(sizeof(GrafoMA));

    G->V = v;
    G->A = 0;
    G->mat = iniciar_MA(G->V);

    return G;
}


int aresta_existe(GrafoMA* G, int v1, int v2){
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] == 1);
}


void inserir_aresta(GrafoMA* G, int v1, int v2){
    if ((G != NULL) && (valida_vertice(G, v1)) && (valida_vertice(G, v2)) && (!aresta_existe(G, v1, v2))){
        G->mat[v1][v2] = G->mat[v2][v1] = 1;
        G->A++;
    }
}

void remover_aresta(GrafoMA* G, int v1, int v2){
    if ((G != NULL) && (valida_vertice(G, v1)) && (valida_vertice(G, v2)) && (aresta_existe(G, v1, v2))){
        G->mat[v1][v2] = 0;
        G->mat[v2][v1] = 0;
        G->A--;
    }
}

void imprimir_arestas(GrafoMA* G){
    int i, j;

    for (i = 1; i < G->V; i++)
        for (j = 0; j < i; j++)
            if (G->mat[i][j] == 1)
                printf("(%d, %d)\n", i, j);
}


void liberarGMA(GrafoMA* G){
    if (G != NULL){
        free(G->mat);
        free(G);
    }
}
