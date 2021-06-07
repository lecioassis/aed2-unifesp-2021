//Lécio Oliveira Gonçalves de Assis - RA:148716
#include <stdio.h>

int rec(int nvales, int *pvale); //prototipo da funcao recursiva

int main(){
    int N, i, d, p, v, nlivrosf, nlivrosi; //declaração de variáveis
    scanf("%d", &N); //entrada da quantidade de casos
    for(i = 0; i < N; i++){ //repete o processo de analise N vezes
        scanf("%d %d %d", &d, &p, &v); //entrada do dinheiro, preco e quantidade de livros por vale
        nlivrosi = d/p; //numero de livros adquiridos inicialmente
        nlivrosf = nlivrosi + rec(nlivrosi, &v); //calculo do numero final de livros
        printf("%d\n", nlivrosf); //output
    }
    return 0;
}

int rec(int nvales, int* pvale){ //calcula o numero de livros adquiridos por vales
    if (nvales >= *pvale) return (1 + rec(nvales - *pvale + 1, pvale));
    else return 0;
}
