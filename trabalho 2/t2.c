/** Dionatan Eduardo Correa Rodrigues **/
#include <stdio.h>

struct stBaralho{
    int dado;
    struct stBaralho *next;
};

FILE* leitura_mensagem(FILE * arq){

    char msg[5];

    arq = fopen("input", "r");
    if (arq != NULL) {
      for (int i=0; i<5; i++) {
        fscanf(arq, "%c", &msg[i]);
        printf("%c\t",msg[i]);
      }
      printf("\n");
      
    }

    return arq;
}

int main(){
    FILE *arq;

    arq = leitura_mensagem(arq);   

    
    return 0;
}
