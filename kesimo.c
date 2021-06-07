//Lécio Oliveira Gonçalves de Assis - RA:148716
#include <stdio.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int v[], int low, int high){
    int pivot = v[high];  // pivo
    int i = (low - 1), j;
    for (j = low; j <= high - 1; j++){
        if (v[j] < pivot){
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return (i + 1);
}

void quickSort(int v[], int low, int high, int K){
    if (low < high){
        int pi = partition(v, low, high);
        if(pi==K-1){
            return;
        }else if(K-1<pi){
            quickSort(v, low, pi - 1, K);
        }else{
            quickSort(v, pi + 1, high, K);  
        } 
    }
}
 
void printv(int v[], int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
}
 
int main(){
    int N, K, i;
    scanf("%d %d", &K, &N);
    int v[N];
    for(i = 0; i < N; i++) scanf("%d", &v[i]);
    quickSort(v, 0, N-1, K);
    printf("%do menor elemento eh o %d\n", K, v[K-1]);
    printv(v, N);
    return 0;
}