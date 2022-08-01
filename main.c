#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "GrafoLA.h"


int main()
{
    int tot_vert=0,i=0,v1=-1,v2=-1,j=0,var=0;
    Lista *l = criar_lista();
    GrafoLA *gLA;
    FILE *arqE;
    FILE * arqA;
        while(var >= 0){
        printf("Escolha uma das opcoes para utilizar este grafo: \n"); 
        printf("1 - Inicia Grafo: \n");
        printf("2 - Verifica existencia do vertice: \n");
        printf("3 - Verifica existencia de uma aresta \n");
        printf("4 - Inserir nova aresta: \n");
        printf("5 - Remover aresta: \n");
        printf("6 - Imprimir aresta: \n");
        printf("7 - Imprimir vertices: \n");
        printf("8 - Retorna lista de adjacencia: \n");
        printf("9 - Abre arquivo: \n");
        printf("10 - Escreve no arquivo: \n");
        printf("-1 - Sair: \n");
        scanf("%d",&var);
        if(var == 1){
            printf("Quantidade de vertices: \n");
            scanf("%d",&tot_vert);
            gLA = iniciar_grafoLA(tot_vert);
        }
        else if(var == 2){
            printf("Digite o vertice a verificar a existencia: \n");
            scanf("%d",&v1);
            vertice_existe(gLA,v1);
        }
        else if(var == 3){
            printf("Digite os dois vertices da aresta a verificar a existencia: \n");
            scanf(" %d %d",&v1,&v2);
            aresta_existeLA(gLA,v1,v2);
        }
        else if(var == 4){
            printf("Digite os dois vertices da aresta a ser inserida: \n");
            scanf(" %d %d",&v1,&v2);
            inserir_arestaLA(gLA,v1,v2);
        }
        else if(var == 5){
            printf("Digite os dois vertices da aresta a remover: \n");
            scanf(" %d %d",&v1,&v2);
            remover_arestaLA(gLA,v1,v2);
        }
        else if(var == 6){
            imprimir_arestasLA(gLA);
        }
        else if(var == 7){
            imprime_vertice(gLA);
        }
        else if(var == 8){
            printf("Digite o vertice a imprimir sua lista de adjacencia: \n");
            scanf("%d",&v1);
            l = vertices_ad(gLA,v1);
        }
        else if (var == 9){
            FILE * arqA = fopen("novo.txt","r"); //Abre o arquivo como leitura // OBS: o arquivo de leitura tem que ter o nome novo.txt, ou ser alterado este parametro nesta funçao
            while(!feof(arqA)){
                fscanf(arqA,"%d %d",&v1,&v2);
                inserir_arestaLA(gLA,v1,v2);
            }
            fclose(arqA);
        }
        else if (var == 10){
            FILE *arqE = fopen("novo_arq.txt","w+");    //escreve no arquivo_criando um novo_arq.txt com as arestas
            int i=0;
            Cell *ajude;
            if( gLA != NULL){
                for(i=0;i<gLA->V;i++){
                    ajude = gLA->adj[i]->head;
                    while(ajude != NULL){
                        fprintf(arqE,"%d %d\n",i,ajude->key);
                        ajude = ajude->next;
                    }
                }

            }
            fclose(arqE);
        }
    }
    liberarGLA(gLA);

    return 0;
}
