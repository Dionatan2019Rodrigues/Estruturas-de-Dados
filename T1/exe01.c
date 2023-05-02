/*Desenvolvido por Dionatan Rodrigues e Mateus Quadros*/
#include <stdio.h>
#include <stdlib.h>

 struct identidade {
    int value;
    int row; 
    int column;
    struct identidade *next;
    
};

int le_ordem(){
    int ordem;
    printf("Digite a ordem de sua matriz identidade: ");
    scanf("%d",&ordem);
    return ordem;
}

struct identidade *allocation_memory(struct identidade *ptr){
 
  ptr = (struct identidade *) malloc(sizeof(struct identidade));
  if(ptr == NULL){ //ERROR memory allocation
    printf("ERRO DE ALOCAÇÃO");
    return NULL;
  }
  else{ return ptr; } 
    
}

struct identidade *create_matriz(struct identidade *ptr_mat, int ordem){
    
    ptr_mat = allocation_memory(ptr_mat);
    struct identidade *aux = ptr_mat;

    for(int i=1;i < (ordem*ordem) ;i++){
        if((i+1) != (ordem*ordem) ){
            aux->next = allocation_memory(aux->next);
        }else{
            aux->next = NULL;
        } 
        aux = aux->next;
    }

    return ptr_mat;

}

struct identidade *preenche_matriz(struct identidade *ptr_mat){

    struct identidade *aux = ptr_mat;

    while(aux != NULL){
        printf("Digite linha: ");
        scanf("%d",&ptr_mat->row);
        printf("Digite coluna: ");
        scanf("%d",&ptr_mat->column);
        printf("Digite o valor: ");
        scanf("%d",&ptr_mat->value);

        aux = aux->next;
    }

    return ptr_mat;

}

int main()
{
    struct identidade *ptr_mat = NULL; 
           
    int ordem = le_ordem();
    ptr_mat = create_matriz(ptr_mat,ordem);
    ptr_mat = preenche_matriz(ptr_mat);


    return 0;

}

