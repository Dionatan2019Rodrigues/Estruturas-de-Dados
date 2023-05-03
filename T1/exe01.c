/*Desenvolvido por Dionatan Rodrigues e Mateus Quadros*/
#include <stdio.h>
#include <stdlib.h>

 struct lista {
    int row; 
    int column;
    int value;
    struct lista *next;
    
};

struct identidade {
    int ordem;
    struct lista *prim;
};

struct lista *allocation_memory(struct lista *ptr){
 
  ptr = (struct lista *) malloc(sizeof(struct lista));
  if(ptr == NULL){ //ERROR memory allocation
    printf("ERRO DE ALOCAÇÃO");
    return NULL;
  }
  else{ return ptr; } 
    
}

struct identidade *le_dados(struct identidade *ptr_mat, int ordem){

    printf ("passagem\n");
    ptr_mat->prim = NULL;
    printf ("passagem\n");
    ptr_mat->prim = allocation_memory(ptr_mat->prim);
    printf ("passagem\n");
    struct lista *aux = ptr_mat->prim;
    printf ("passagem\n");
    int flag=1;
    printf("\nDIGITE APENAS OS DADOS DOS TERMOS DIFERENTES DE ZERO DA SUA MATRIZ\n");

    while(flag==1){

        printf("Digite linha: ");
        scanf("%d",&aux->row);
        printf("Digite coluna: ");
        scanf("%d",&aux->column); 
        printf("Digite o valor: ");
        scanf("%d",&aux->value);

        printf("Se existir mais um termo a ser informado DIGITE 1, caso contrario digite outro número!");
        scanf("%d",&flag);

        if(flag==1)
            aux = aux->next;
        else 
            aux->next = NULL;

    }
    return ptr_mat;

}

struct identidade *preenche_matrizz(struct identidade *ptr_mat, int ordem){

    ptr_mat = le_dados(ptr_mat,ordem);

}

int le_ordem(){
    int ordem;
    printf("Digite a ordem de sua matriz identidade: ");
    scanf("%d",&ordem);
    return ordem;
}

/*
struct lista *create_matriz(struct lista *ptr_mat, int ordem){
    
    ptr_mat = allocation_memory(ptr_mat);
    struct lista *aux = ptr_mat;

    for(int i=0;i < (ordem*ordem) ;i++){
        if((i+1) != (ordem*ordem) ){
            aux->next = allocation_memory(aux->next);
        }else{
            aux->next = NULL;
        } 
        aux = aux->next;
    }

    return ptr_mat;

}

struct lista *preenche_matriz(struct lista *ptr_mat){

    struct lista *aux = ptr_mat;

    while(aux != NULL){
        printf("Digite linha: ");
        scanf("%d",&aux->row);
        printf("Digite coluna: ");
        scanf("%d",&aux->column); 
        printf("Digite o valor: ");
        scanf("%d",&aux->value);

        aux = aux->next;
    }

    return ptr_mat;

}

void imprime_matriz(struct lista *ptr_mat,int ordem){

    struct lista *aux = ptr_mat;

    printf("\n");
    for(int i=0;i<ordem;i++){
        for(int j=0;j<ordem;j++){
            printf("%d\t",aux->value);
            aux = aux->next;
        }
        printf("\n");
    }
}

*/

int main()
{
    struct identidade *ptr_mat = NULL; 

    int ordem = le_ordem();

    ptr_mat = preenche_matrizz(ptr_mat,ordem);






    //ptr_mat = create_matriz(ptr_mat,ordem);
    //ptr_mat = preenche_matriz(ptr_mat);
    //imprime_matriz(ptr_mat,ordem);


    return 0;

}

