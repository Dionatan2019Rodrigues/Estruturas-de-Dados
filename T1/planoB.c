/*Desenvolvido por Dionatan Rodrigues e Mateus Quadros*/
#include <stdio.h>
#include <stdlib.h>

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

void criando_matriz(struct lista *ptr, int ordem){
    struct lista *aux = ptr;

    for(int i=0;i<ordem;i++){
        aux = aloca_no(aux);
        aux = aux->next;
    }
}

void inserir_no(struct lista *ptr, int row, int column, int value){

}

void preencher_matriz(struct lista *ptr, int ordem){
    int i, j, valor;
    for (i=0;i<ordem;i++) {
        for (j=0;j<ordem;j++) {
            printf("Digite o valor para a posição [%d][%d]: ", i, j);
            scanf("%d", &valor);
            
            
        }
    }
}

int main()
{
    struct lista *list = NULL; 

    int ordem;
    printf("Digite a ordem de sua matriz identidade: ");
    scanf("%d",&ordem);

    criando_matriz(list,ordem);

    preencher_matriz(list, ordem);

    return 0;

}


/*
struct identidade *le_dados(struct identidade *ptr_mat){

    ptr_mat->prim = aloca_lista(ptr_mat->prim);
    struct lista *aux = ptr_mat->prim;
    int flag=1;
    printf("\nDIGITE APENAS OS DADOS DOS TERMOS DIFERENTES DE ZERO DA SUA MATRIZ\n");

    while(flag==1){

        printf("linha: ");
        scanf("%d",&aux->row);
        printf("coluna: ");
        scanf("%d",&aux->column); 
        printf("valor: ");
        scanf("%d",&aux->value);

        aux->row -= 1;
        aux->column -= 1;

        printf("Mais um termo a ser informado? DIGITE 1, Não? digite outro número!\t");
        scanf("%d",&flag);

        if(flag==1){
            aux = aux->next;
            aux = aloca_lista(aux);
        }    
        else { aux->next = NULL; }

    }
    return ptr_mat;

}

struct identidade *preenche_matriz(struct identidade *ptr_mat){

    ptr_mat = le_dados(ptr_mat);

}

void imprime_matriz(struct identidade *ptr_mat,int ordem){
    
    struct lista *aux = ptr_mat->prim;
    
    
    for(int i=0;i<ordem;i++){
        for(int j=0;j<ordem;j++){
            
            if((aux->row==i)&&(aux->column==j)){
                
                printf("%d\t",1);
                aux = aux->next;
            }else{
                printf("%d\t",0);
            }
        }
        printf("\n");
    }
}
*/

/*
struct identidade *aloca_identidade(struct identidade *ptr){
 
  ptr = (struct identidade *) malloc(sizeof(struct identidade));
  if(ptr == NULL){ //ERROR memory allocation
    printf("ERRO DE ALOCAÇÃO");
    return NULL;
  }
  else{ return ptr; } 
    
}
*/
