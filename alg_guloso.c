#include <stdio.h>
#include <stdlib.h>

int qtd_moedas(int v[], int n, int troco){
    int qtd = 0;
    int i;

    for (i = 0; (i < n) && (troco > 0); i++){
        qtd += troco / v[i];
        troco = troco % v[i];
    }


    if (troco == 0)
        return qtd;
    else
        return -1;
}


float mochila_fracionaria(int p[], int v[], int n, int c){
    float total = 0;
    int i = 0;

    while ((i < n) && (p[i] <= c)){
        total += v[i];
        c -= p[i];
        i++;
    }


    if ((i < n) && (c > 0))
        valor += ((float) c/p[i]) * v[i];


    return total;
}


int atividades(int ini[], int fim[], int n){
    int i, qtd, aux_fim;

    if (n > 0){
        qtd = 1;
        aux_fim = 0;

        for (i = 1; i < n; i++)
            if (ini[i] > fim[aux_fim]){
                qtd++;
                aux_fim = i;
            }

        return qtd;
    }else
        return -1;
}


int main(){
    /*int v[] = {100, 50, 25, 10, 5, 1};
    int troco = 450;*/
    int ini[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int fim[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    //printf("A quantidade de moedas para %d eh: %d", troco, qtd_moedas(v, 5, troco));
    printf("A maior quantidade posssivel de atividades que podem ser alocadas eh: %d", atividades(ini, fim, 11));

    return 0;
}
