//Lécio Oliveira Gonçalves de Assis - RA:148716
#include <stdio.h>
#include <stdlib.h>

int _mergeSort(int v[], int aux[], int left, int final, int K);

int merge(int v[], int aux[], int left, int mid, int final, int K);

int mergeSort(int v[], int n, int K){
    int* aux = (int*)malloc(sizeof(int) * n);
    return _mergeSort(v, aux, 0, n - 1, K);
}
 
int _mergeSort(int v[], int aux[], int left, int final, int K){
    int mid, contador = 0;
    if (final > left){
        mid = (final + left) / 2;
        contador += _mergeSort(v, aux, left, mid, K);
        contador += _mergeSort(v, aux, mid + 1, final, K);
        contador += merge(v, aux, left, mid + 1, final, K);
    }
    return contador;
}

int merge(int v[], int aux[], int left, int mid, int final, int K){
    int i = left, j = mid, k = left, contador = 0;
    
    while ((i <= mid - 1) && (j <= final)) {
        if (v[i] <= K*v[j]) {
            k++; i++;
        }else{
            k++; j++;
            contador += (mid - i);
        }
    }

    i = left; j = mid; k = left;

    while ((i <= mid - 1) && (j <= final)) {
        if (v[i] <= v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];
    }
 
    while (i <= mid - 1) aux[k++] = v[i++];
    while (j <= final) aux[k++] = v[j++];

    for (i = left; i <= final; i++) v[i] = aux[i];
 
    return contador;
}

int main(){
    int N, K, i;
    scanf("%d", &N);
    scanf("%d", &K);
    int v[N];
    for(i = 0; i < N; i++) scanf("%d", &v[i]);
    printf("%d", mergeSort(v, N, K)); //K!=k
    return 0;
}