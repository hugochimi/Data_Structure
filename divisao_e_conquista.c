#include <stdio.h>
#include <math.h>

int inf = 2147483647;

/*int maiorI(int v[], int n){
    int i;
    int x = v[0];

    for (i = 1; i < n; i++)
        if (x < v[i])
            x = v[i];

    return x;
}


int max(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}


int maiorDC(int v[], int ini, int fim){
    int a1, a2, m;

    if (fim - ini <= 1)
        return max(v[ini], v[fim]);
    else{
        m = (ini + fim) / 2;

        a1 = maiorDC(v, ini, m);
        a2 = maiorDC(v, m + 1, fim);
    }

    return max(a1, a2);
}


int powI(int a, int n){
    int i, aux;

    if (n <= 0)
        return 1;
    else{
        aux = a;

        for (i = 2; i <= n; i++)
            aux = aux * a;

        return aux;
    }
}


int powDC(int a, int n){
    if (n <= 0)
        return 1;
    else if (n == 1)
        return a;
    else
        if (n % 2 == 0)
            return powDC(a, n / 2) * powDC(a, n / 2);
        else
            return a * powDC(a, (n - 1) / 2) * powDC(a, (n - 1) / 2);
}*/


void merge(int v[], int p, int q, int r){
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];

    for (i = 0; i < n1; i ++)
        L[i] = v[p + i];

    for (j = 0; j < n2; j++)
        R[j] = v[j + q + 1];

    L[n1] = inf;
    R[n2] = inf;

    i = 0;
    j = 0;

    for (k = p; k <= r; k++)
        if (L[i] <= R[j]){
            v[k] = L[i];
            i++;
        }else{
            v[k] = R[j];
            j++;
        }
}


void mergesort(int v[], int p, int r){
    int q;

    if (p < r){
        q = (p + r) / 2;

        mergesort(v, p, q);
        mergesort(v, q + 1, r);
        merge(v, p, q, r);
    }
}


int main(){
    int i;
    int v[] = {22, 33, 55, 77, 99, 44, 66, 88};

    printf("Antes:\n");

    for (i = 0; i < 8; i++)
        printf("%d\n", v[i]);

    mergesort(v, 0, 8);

    printf("\nDepois:\n");

    for (i = 0; i < 8; i++)
        printf("%d\n", v[i]);

    //printf("%d elevado a %d = %d", 2, 8, powI(2, 8));
    //printf("%d elevado a %d = %d", 2, 8, powDC(2, 8));

    /*int v[] = {2, 1, 3, 6, 5, 9, 8, 5};

    printf("Maior: %d\n", maiorDC(v, 0, 7));
    printf("Maior: %d\n", maiorI(v, 8));*/
}
