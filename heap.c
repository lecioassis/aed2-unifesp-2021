//Lécio Oliveira Gonçalves de Assis - RA:148716
#include <stdio.h>
#include <string.h>

void printArray(char [][21], int ); 

void swap(char*, char*);

void heapify(char [][21], int, int);

void heapSort(char [][21], int);

int main(){
    int N, M, i, j;
    scanf("%d", &N);
    char arr[N][21];

    for (i = 0; i < N; i++) scanf("%s", &arr[i]);

    scanf("%d", &M);
    char vet[M][21];

    for (i = 0; i < M; i++)    {
        scanf("%d", &j);
        strcpy(vet[i], arr[j]);
    }

    for (i = 0; i < N; i++){
        for (j = 0; j < strlen(arr[i]); j++){
            if (arr[i][j] < 'a' || arr[i][j] > 'z'){
                printf("a palavra %s eh invalida", arr[i]);
                return 0;
            }
        }
    }

    printf("build_heap:");

    heapSort(vet, M);
    printf("\npalavras:");

    printArray(vet, M);
    return 0;
}

void printArray(char arr[][21], int n){
    int i;
    for (i = 0; i < n; i++) printf(" %s", arr[i]);
}

void swap(char *a, char *b){
    char aux[21];
    strcpy(aux, a);
    strcpy(a, b);
    strcpy(b, aux);
}

void heapify(char arr[][21], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && strcmp(arr[l], arr[largest]) > 0) largest = l;

    if (r < n && strcmp(arr[r], arr[largest]) > 0) largest = r;

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(char arr[][21], int n){
    int i;
    for (i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    printArray(arr, n);

    for (i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
