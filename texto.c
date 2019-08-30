#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int comecouPalavra = 0, numPalavras = 0; //numLinhas = 0, numCaracteres = 0;

	FILE* descritor;
	char caracter;
	descritor = fopen("teste.txt", "r");
	while (!feof(descritor)) {
		fread(&caracter, 1, 1, descritor);
		//          numCaracteres++;
		if ((caracter != ' ') && (caracter != '\n') && (!comecouPalavra)) {
			comecouPalavra = 1;
		}
		if (((caracter == ' ') || (caracter == '\n')) && (comecouPalavra)) {
			comecouPalavra = 0;
			numPalavras++;
		}
	}
	printf("\n O numero de palavras do arquivo eh: %d", numPalavras);

	getchar();
}