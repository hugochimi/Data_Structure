typedef struct GrafoLA GrafoLA;

struct GrafoLA{
   int V; // número de vértices
   int A; // número de arestas
   Lista **adj;
};

GrafoLA* iniciar_grafoLA(int v);

int aresta_existeLA(GrafoLA* G, int v1, int v2);

void inserir_arestaLA(GrafoLA* G, int v1, int v2);

void remover_arestaLA(GrafoLA* G, int v1, int v2);

void imprimir_arestasLA(GrafoLA* G);

void liberarGLA(GrafoLA* G);

//USER CODE BEGIN

int vertice_existe(GrafoLA * G,int v);

void imprime_vertice(GrafoLA * G);

Lista * vertices_ad(GrafoLA * G,int v);

Lista * busca_larg(GrafoLA *G,int S);

//USER CODE END
