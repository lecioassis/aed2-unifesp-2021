//Lécio Oliveira Gonçalves de Assis - RA:148716
#include <stdio.h>

//funcao de ordenacao em bolha 
int ordenar(int seq[], int N){
    int i, j, contador = 0;
    for(i = 1; i < N; i ++){
        for(j = 0; j < N - i; j++){
            if(seq[j] > seq[j+1]){      //inverter os inteiros da posicao j e j+1 sem utilizar uma terceira variavel
                seq[j] = seq[j] + seq[j+1];
                seq[j+1] = seq[j] - seq[j+1];
                seq[j] = seq[j] - seq[j+1];
                contador++;             //incremento do contador das ordenacoes
            }
        }
    }
    return contador;
}

int main(){
    int N, i, contador; //declaracao de variaveis
    scanf("%d", &N);    //entrada de N
    int seq[N];         //declaracao do vetor de tamanho N
    //entrada da sequencia e chamada da funcao de ordenacao
    for(i = 0; i < N; i++) scanf("%d", &seq[i]);
    contador = ordenar(seq, N);
    //exibir sequencia final
    for(i = 0; i < N; i++) printf("%d ", seq[i]);
    //descobrir vencedor
    if(contador%2) printf("\nMarcelo");
    else printf("\nCarlos");
    return 0;
}
