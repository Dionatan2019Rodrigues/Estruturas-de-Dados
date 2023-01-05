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
  int max_char = 256;

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

char convertIntLetter(int i){
  return 'A'+(i-1);
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

struct stCard *predecessorIndiferent(struct stCard *list, int np, int i){
  struct stCard *aux = list, *ptrAnt = NULL;
  int cont = 0;

  while(aux != NULL){
    ptrAnt = aux;
    if(aux->next->naipe == np)
      cont ++;

    if((aux->next->naipe == np) && (cont == i))
      aux = NULL;
    else
      aux = aux->next;
  }
  return ptrAnt;
}

struct stCard *trocaFim(struct stCard *blocofim){
  struct stCard *aux = blocofim, *ptrAnt = NULL; 

  while(aux != NULL){
    ptrAnt = aux;

    aux = aux->next;

  }
  return ptrAnt;   
    
}

struct stCard *tripleCut(struct stCard *list){
    struct stCard *JokerA, *aux, *blocofim, *aux2, *JokerB, *aux3;

    aux = predecessorIndiferent(list,5,1);    
    JokerA = aux->next;  // ptr primeiro joker

    aux2 = predecessorIndiferent(list,5,2);
    JokerB = aux2->next;  //ptr segundo joker

    blocofim = JokerB->next;    // ptr bloco fim

    JokerB->next = list;
    aux->next = NULL;    // ptr ultima carta

    if(blocofim == NULL)
      list = JokerA;
    else{
      aux3 = trocaFim(blocofim);
      list = blocofim;
      aux3->next = JokerA;
    }
    
  return list;
}

struct stCard *moveCardDown(struct stCard *list, int id, int moves){
  struct stCard *aux, *aux2, *aux3;

  for(int i=0;i < moves;i++){

    aux = predecessor(list,id);

    if(aux->next->next == NULL){ // CARTA EM QUESTÃO NO FINAL DO BARALHO

      aux3 = list->next; // ponteiro para segunda posição da lista
      list->next = aux->next; // insere na segunda posição
      aux->next->next = aux3;
      aux->next = NULL; // penultima posição baralho vira última

    }else{
      //ANTES 1->2->3->4
      aux2 = aux->next;  //guarda ponteiro para DOIS
      aux->next = aux2->next;  // faz UM apontar para TRES
      aux2->next = aux->next->next; // faz DOIS apontar para QUATRO
      aux->next->next = aux2;    // faz TRES apontar para DOIS
      //DEPOIS 1->3->2->4
    }
  }
    
  return list;
}

struct stCard *predecessorValue(struct stCard *list, int v){
  struct stCard *aux = list, *ptrAnt = NULL;
  int cont = 0;
  
  while(aux != NULL){
    ptrAnt = aux;
    cont ++;

    if(cont == v)
      aux = NULL;
    else
      aux = aux->next;
  }
  return ptrAnt;
}

struct stCard *previousFim(struct stCard *baralho){
  struct stCard *aux = baralho, *ptr = NULL;

  while(aux != NULL){
    if(aux->next->next == NULL){
      ptr = aux;
      aux = NULL;
    } 
    else{
      aux = aux->next;
    }
      
  }
  return ptr;
}

struct stCard *countedCut(struct stCard *list){
  struct stCard *cardFim, *aux, *aux2, *baralho;
  
  cardFim = trocaFim(list);
   
  aux = predecessorValue(list,cardFim->value);
  baralho = aux->next;
  aux2 = previousFim(baralho);

  aux2->next = aux;
  aux->next = cardFim;

  list = baralho;


  return list;
}

struct stCard *modifyDeck(struct stCard *list){

  //Joker A
  list = moveCardDown(list,53,1);
  //Joker B
  list = moveCardDown(list,54,2);
  //Corte Triplo
  list = tripleCut(list);
  //Corte Contado
  list = countedCut(list);

  return list;
}
//**************************************************************************************
int showKey(struct stCard *list){
  struct stCard *aux = list;

  for(int i = list->index; i >0 ;i--){
    aux = aux->next;
  }
  return aux->index;
}

void encryptSolitaire(struct stCard *listCard, struct stMsg *listMsg){
  struct stMsg *aux = listMsg;

  showListLetter(listMsg);
  printf("\n\n");
  while(aux != NULL){

    //Realiza todos cortes do baralho
    listCard = modifyDeck(listCard);
    //showDeck(listCard);

    //Gera KeyCard
    int KeyCard = showKey(listCard);

    //Joker keyCard repete até não ser mais joker a keyCard
    while(KeyCard > 52){
      listCard = modifyDeck(listCard);
      KeyCard = showKey(listCard);
    }  
    //printf("%d\n",KeyCard);

    int cripto = letterValue(aux->letter) + letterValue(convertIntLetter(KeyCard));
  
    
    aux->letter = convertIntLetter(cripto);

    showListLetter(listMsg);


    aux = aux->next;
  }

  
  
}



int main(){
    struct stMsg *ptr_msg = NULL; //cria lista vazia 
    struct stCard *ptr_card = NULL; //cria baralho vazio

    ptr_msg = input_msg(ptr_msg);
    ptr_card = createDeck(ptr_card);

    encryptSolitaire(ptr_card,ptr_msg);
  

    
    return 0;
}
