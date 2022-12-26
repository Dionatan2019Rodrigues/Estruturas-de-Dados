/** Dionatan Eduardo Correa Rodrigues **/
#include <stdio.h>
#include <stdlib.h> // used malloc() in functions insertEnd(),allocationMemoryCard() and createDeck()
#include <stdbool.h> // used bool in function validateLetter()
#include <ctype.h> // uded isalpha() in function validateLetter()

/*
NAIPE VALUE
PAUS    1
OUROS   2
COPAS   3
ESPADAS 4
JOKER   5
*/

struct stCard{
    int index;
    int value;
    int naipe;
    struct stCard *next;
};

struct stMsg{
    char letter;
    struct stMsg *next;
};

struct stMsg *insertLetterEnd(char caracter, struct stMsg *list){

  if(list == NULL){
    struct stMsg *new;
    new = (struct stMsg *) malloc(sizeof(struct stMsg));

    if(new == NULL) //ERROR memory allocation
     return NULL;

    list = new;
    new->letter = caracter; // insert
    new->next = NULL;
  }else{
    list->next = insertLetterEnd(caracter,list->next);
  }

  return list;

}

void showListLetter(struct stMsg *list){
  struct stMsg *aux;
  aux = list;
  while(aux != NULL){
    printf("%c \t", aux->letter);
    aux = aux->next;
  }
  printf("\n");
}
// retorna true caso seja uma letra
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

struct stMsg *input_msg(struct stMsg *list){
  FILE *arq;
  char caracter;
  int max_char = 150;

  arq = fopen("input", "r");
  if (arq != NULL) {
    for (int i=0; i < max_char; i++) { 
      fscanf(arq, "%c", &caracter);
      if(validateLetter(caracter)){
        caracter = convertToUppercase(caracter);
        list = insertLetterEnd(caracter,list);
      }   
    }      
  }

  fclose(arq);
  return list;
}
// recebe um char e retorna o valor numérico de  1 a 26
int letterValue(char c){
  for(int i=0;i < 26;i++){
    if(c == ('A'+i))
      return i+1;
  }
  return 0;
}
//**********************************************************************************
struct stCard *allocationMemoryCard(struct stCard *ptr){
  ptr = (struct stCard *) malloc(sizeof(struct stCard));
  if(ptr == NULL) //ERROR memory allocation
    return NULL;
  else 
    return ptr;
}

struct stCard *createJoker(struct stCard *ptr, int id, int v){
  ptr->index = id;
  ptr->value = v;
  ptr->naipe = 5;
  return ptr;
}
//cria baralho na posição inicial das cartas
struct stCard *createDeck(struct stCard *list){
  int k=0;
  struct stCard *aux;

  aux = (struct stCard *) malloc(sizeof(struct stCard));
  if(aux == NULL) //ERROR memory allocation
    return NULL;
  list = aux;

  for(int i=1;i < 5;i++){ // idenficador NAIPE
    for(int j=1;j < 14;j++){  // idenficador Card (às,dois,três...)
      aux->index = k+1;
      aux->value = j;
      aux->naipe = i;
      aux->next = allocationMemoryCard(aux->next);
      aux = aux->next;
      k++;
    }
  }
  //Joker A 
  aux = createJoker(aux,53,14);
  aux->next = allocationMemoryCard(aux->next);
  aux = aux->next;
  //Joker B
  aux = createJoker(aux,54,15);
  aux->next = NULL;


  return list;
}

void showDeck(struct stCard *list){
  struct stCard *aux;
  aux = list;
  printf("index\tvalue\tnaipe\n");
  while(aux != NULL){
    printf("%d \t", aux->index);
    printf("%d \t", aux->value);
    printf("%d \t", aux->naipe);
    printf("\n");
    aux = aux->next;
  }
  printf("\n");
}

struct stCard *searchDeck(int id, struct stCard *list){
  struct stCard *aux = list;
  while(aux != NULL){
    if(aux->index == id)
      return aux;
      
    aux = aux->next;
  }
  return NULL;
}
//**********************************************************************************
struct stCard *predecessor(struct stCard *list, int v){
  struct stCard *aux = list, *ptrAnt = NULL;

  if(aux != NULL){
      while(aux->index != v){
        ptrAnt = aux;
        aux = aux->next;
        if(aux == NULL){
          return NULL;
        }
      }

  }
  return ptrAnt;
}

struct stCard *moveCardDown(struct stCard *list, int id, int moves){
    
    
  return list;
}

struct stCard *encryptSolitaire(struct stCard *list){
  
  //Joker A
  //ERRO ESTA AQUI
  list = moveCardDown(listCard,53,1);


  return list;
}



int main(){
    struct stMsg *ptr_msg = NULL; //cria lista vazia 
    struct stCard *ptr_card = NULL; //cria baralho vazio

    ptr_msg = input_msg(ptr_msg);
    ptr_card = createDeck(ptr_card);

    ptr_card = encryptSolitaire(ptr_card);
    
    showDeck(ptr_card);
    //showListLetter(ptr_msg);

    
    return 0;
}
