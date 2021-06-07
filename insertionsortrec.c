//Lécio Oliveira Gonçalves de Assis - RA:148716
#include <stdio.h>

void insertionSort(int seq[], int contador, int k); //prototipo da funcao
                //(array a ser ordenado, tamanho do array, constante do nivel de recursao)

int main(){
    int N, i;           //declaracao de variaveis
    scanf("%d", &N);    //entrada de N
    int seq[N];         //declaracao do vetor de tamanho N
    //entrada da sequencia e chamada da funcao de ordenacao
    for(i = 0; i < N; i++) scanf("%d", &seq[i]);
    insertionSort(seq, N, N+1);
    //exibir sequencia final
    for(i = 0; i < N; i++) printf("%d ", seq[i]);
    return 0;
}

void insertionSort(int seq[], int contador, int k){
    if(contador <= 1) return;               //caso base
    insertionSort(seq, contador-1, k);      //chamada recursiva da funcao
    printf("%d ", k - contador);            //nivel de recursao
    int chave = seq[contador - 1];          //valor da chave
    int i = contador - 2;                   
    printf("%d ", chave);
    while(i >= 0 && seq[i] > chave){        //mover elementos maiores que o valor chave
        seq[i + 1] = seq[i];
        i--;
    }
    seq[i + 1] = chave;                     //insercao do elemento chave 
    printf("%d\n", i + 1);                  //localicazao do elemento chave no vetor final
}
