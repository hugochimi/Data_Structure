typedef struct GrafoMA GrafoMA;

struct GrafoMA{
   int V; // número de vértices
   int A; // número de arestas
   int **mat;
};

GrafoMA* iniciar_grafoMA(int v);

int aresta_existe(GrafoMA* G, int v1, int v2);

void inserir_aresta(GrafoMA* G, int v1, int v2);

void remover_aresta(GrafoMA* G, int v1, int v2);

void imprimir_arestas(GrafoMA* G);

void liberarGMA(GrafoMA* G);
