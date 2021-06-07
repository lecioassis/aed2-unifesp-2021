//Lécio Oliveira Gonçalves de Assis - RA:148716
#include <stdio.h>
 
int main(){
    int caso, N, i, j, primo; //declaração de variáveis
    scanf("%d", &N); //entrada da quantidade de casos
    for(j = 0; j < N; j++){ //repete o processo de analise N vezes
        scanf("%d", &caso); //entrada do número a ser analisado
        primo = (caso == 1) ? 0 : 1; //retorna 1 para a variável primo se caso == 1, do contrário retorna 0
        for(i = 2; i <= caso/2; i++){ //verifica se o caso é divisível por algum número diferente de 1 e dele mesmo
            if (caso % i == 0) { // se o caso for divisível a variável primo recebe 0 e o loop é encerrado
                primo--;
                break;
            }
        }
        printf("%d %d\n", caso, primo); //exibe no terminal o número analisado seguido de 1 se for primo ou 0 se não for
    }
    return 0;
}


