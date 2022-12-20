/** Dionatan Eduardo Correa Rodrigues **/
#include <stdio.h>
#include <stdlib.h> // used malloc() in function insertEnd()
#include <stdbool.h> // used bool in function validateLetter()
#include <ctype.h> // uded isalpha() in function validateLetter()

int tam = 12;

struct stBaralho{
    int dado;
    struct stBaralho *next;
};

struct stMsg{
    char letra;
    struct stMsg *next;
};

struct stMsg *insertEnd(char caracter, struct stMsg *list){

  if(list == NULL){
    struct stMsg *new;
    new = (struct stMsg *) malloc(sizeof(struct stMsg));

    if(new == NULL) //ERROR memory allocation
     return NULL;

    new->letra = caracter; // insert
    new->next = NULL;
  }else{
    list->next = insertEnd(caracter,list->next);
  }


  return list;

}

void imprimeList(struct stMsg *list){
  struct stMsg *aux;
  aux = list;
  while(aux != NULL){
    printf("%c \t", aux->letra);
    aux = aux->next;
  }
  printf("\n");
}

bool validateLetter(char caracter){
  if(isalpha(caracter) == 0) // retorna 0 para qualquer caracter que nao esta no alfabeto
    return false; // nao esta no alfabeto
  else 
    return true; // letra minuscula ou MAIUSCULA
}

//Converte char para MAIÚSCULA
char convertToUppercase(char caracter){
  if((caracter >= 'a')&&(caracter <= 'z'))
    return toupper(caracter);
  else  
    return caracter;
}

struct stMsg *le_msg(struct stMsg *list){
  FILE *arq;
  char caracter;
  arq = fopen("input", "r");
  if (arq != NULL) {
    for (int i=0; i<tam; i++) {
      fscanf(arq, "%c", &caracter);
      if(validateLetter(caracter)){
        caracter = convertToUppercase(caracter);
        //printf("%c\t",caracter);
        list = insertEnd(caracter,list);
      }   
    } 
    //printf("\n");     
  }

  //imprimeList(list);
  fclose(arq);
  return list;
}



int main(){
    struct stMsg *ptr_msg = NULL; //cria lista vazia 

    ptr_msg = le_msg(ptr_msg);

    //imprimeList(ptr_msg);

    
    return 0;
}
