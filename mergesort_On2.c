//Lécio Oliveira Gonçalves de Assis - RA:148716
#include <stdio.h>
#include <stdlib.h>

int getInvCount(int arr[], int n, int k){
    int inv_count = 0, i, j;

    for (i = 0; i < n; i++){
        for (j = i; j < n; j++){
            if (arr[i] > k*arr[j]) inv_count++; 
        }
    }
    return inv_count;
}

int main(){
    int N, K, i;
    scanf("%d", &N);
    scanf("%d", &K);
    int v[N];
    for(i = 0; i < N; i++) scanf("%d", &v[i]);
    printf("%d", getInvCount(v, N, K));
    return 0;
}