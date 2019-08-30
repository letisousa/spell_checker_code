#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    clock_t Ticks[2];
    Ticks[0] = clock();
    //Código do main
    Ticks[1] = clock();
    double tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo total da verificação: %gms.", tempo); //ao invés de printar, essa parte será jogada no arquivo
    getchar();
    return 0;
}
