#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int M = 51307;

typedef struct{

    int chave;
    char valor;

}Key;

Key KeyNula() {
Key nulo;
nulo.chave = 0;
return nulo;
}

typedef struct Node *ligacao;
struct Node{

    Key ch;
    ligacao next;

};

ligacao *tab;

void Inicializar(){

    int i;
    tab = (struct Node*) malloc(M * sizeof(struct Node));
    for(i = 0; i < M; i++){
        tab[i] = NULL;
    }
}

void Inserir(Key ch){

    int i, v;
    v = ch.chave;
    i = v%M;
    ligacao novo = (struct Node*) malloc(sizeof(struct Node));
    novo->ch = ch;
    novo->next = tab[i];
    tab[i] = novo;

}

int hashHorner(char* palavra, int M){

    int i, h = palavra[0];
    for(i = 0; palavra[i] != '\0'; i++){
        h = (h * 251 + palavra[i]) % M;
    }
    return h;
}

Key Pesquisa(int v){

    ligacao p;
    int i;
    i = v%M;
    for(p = tab[i]; p != NULL; p = p->next){
        if(p->ch.chave == v){
            break;
        }
    }
    if(p != NULL){
        return p->ch;
    }
    return KeyNula();
}

int main() {

	int comecouPalavra = 0, numPalavras = 0;

	FILE* descritor;
	char caracter;
	descritor = fopen("dicionario.txt", "r");
	while (!feof(descritor)) {

		fread(&caracter, 1, 1, descritor);

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

	return 0;
}
