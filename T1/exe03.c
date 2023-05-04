/*Desenvolvido por Dionatan Rodrigues e Mateus Quadros*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 struct lista {
    int row; 
    int column;
    int value;
    struct lista *next;
    
};

struct lista *aloca_no(struct lista *ptr){
 
  ptr = (struct lista *) malloc(sizeof(struct lista));
  if(ptr == NULL){ //ERROR memory allocation
    printf("ERRO DE ALOCAÇÃO");
    return NULL;
  }
  else{ return ptr; } 
    
}

struct lista *inserir_no_final(struct lista *ptr, int row, int column, int value){
    
    if(ptr == NULL){
        struct lista *aux;
        aux = aloca_no(aux);

        ptr = aux;
        aux->row = row; // insert
        aux->column = column; // insert
        aux->value = value; // insert
        aux->next = NULL;
    }else{
        ptr->next = inserir_no_final(ptr->next,row,column,value);
    }

  return ptr;
}

struct lista *preencher_matriz(struct lista *ptr, int ordem){
    int i, j, valor;
    for (i=0;i<ordem;i++) {
        for (j=0;j<ordem;j++) {
            printf("Digite o valor para a posição [%d][%d]: ", i, j);
            scanf("%d", &valor);
            if (valor != 0 && valor != 1) {
                printf("Valor inválido. Digite 0 ou 1.\n");
                j--;
            } else{
                ptr = inserir_no_final(ptr,i,j,valor);
            }
            
        }
    }
    return ptr;
}

void imprime_matriz(struct lista *ptr, int ordem){
    struct lista *aux = ptr;
    printf("Matriz:\n");
    for(int i=0;i<ordem;i++){
        for(int j=0;j<ordem;j++){
            if((i == aux->row) && (j== aux->column)){
                printf("%d\t",aux->value);
                aux = aux->next;
            }else{
                printf("%d\t",0);
            }
        }
        printf("\n");
    }
}

bool eh_identidade(struct lista *ptr, int ordem){
   struct lista *aux = ptr;
   bool identidade = true ;

    for(int i=0;i<ordem;i++){
        for(int j=0;j<ordem;j++){
            if(i == j){
                if(aux->value!=1){
                    return  false;  
                }
            }else{
                if(aux->value==1){
                    return false;
                }
            }
            aux = aux->next;
        }
        
    }

    return identidade; 

}

void valida_identidade(struct lista *ptr, int ordem){
    
    if(eh_identidade(ptr,ordem)){
        printf("É uma  matriz identidade\n");
    }else{
        printf("Não é uma matriz identidade\n");
    }
}

void mostra_violacoes(struct lista *ptr, int ordem){
    struct lista *aux = ptr;

    for(int i=0;i<ordem;i++){
        for(int j=0;j<ordem;j++){
            if(i == j){
                if(aux->value!=1){
                    printf("Valor diferente de 1 na diagonal principal na posição [%d][%d]: %d\n", aux->row, aux->column, aux->value);  
                }
            }else{
                if(aux->value==1){
                    printf("Valor diferente de 0 fora da diagonal principal na posição [%d][%d]: %d\n", aux->row, aux->column, aux->value);
                }
            }
            aux = aux->next;
        }
        
    }
}

int main()
{
    struct lista *list = NULL; 

    int ordem;
    printf("Digite a ordem de sua matriz identidade: ");
    scanf("%d",&ordem);

    list = preencher_matriz(list, ordem);
    
    imprime_matriz(list,ordem);

    valida_identidade(list,ordem);

    mostra_violacoes(list,ordem);
    
    

    return 0;

}
