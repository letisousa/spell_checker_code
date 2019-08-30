#include <stdlib.h>

int Saida(){
  FILE *saida;
  char palavra[20];

   saida = fopen("saida.txt", "w");

   if(saida == NULL){
     printf("Erro na abertura do arquivo!");
     return 1;
   }

   printf("Escreva uma palavra para testar gravacao de arquivo: ");
   scanf("%s", palavra);

   fprintf(saida, "%s", palavra);

   fclose(saida);

  // printf("Dados gravados com sucesso!");
  // getch();

}
