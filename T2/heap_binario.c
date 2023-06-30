#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "heap_binario.h"

prioQueue *cria_fila_vazia(int capacity){
    prioQueue *fp = (prioQueue*)malloc(sizeof(prioQueue));
    if(fp == NULL)
        printf("ERRO DE ALOCAÇÃO");

    fp->heap = (node*)malloc(capacity * sizeof(node));
    if(fp->heap == NULL)
        printf("ERRO DE ALOCAÇÃO DA FILA");

    fp->capacity = capacity;
    fp->size = 0;

    return fp;
       
}

void swap (prioQueue *fp, int pos1, int pos2){
    node aux;

    aux = fp->heap[pos1];
    fp->heap[pos1] = fp->heap[pos2];
    fp->heap[pos2] = aux;

}

void promove_elemento(prioQueue *fp, int filho){
    int pai = (filho - 1 ) / 2;

    while( (filho>0)&&(fp->heap[pai].prio < fp->heap[filho].prio)){
        swap(fp,filho,pai);
        filho = pai;
        pai = (pai-1)/2;
    }
}

void insert(prioQueue *fp, int prio, char *nome){
    
    if(fp == NULL){
        printf("ERRO NA INSERÇÃO PONTEIRO NULO\n");
        return;
    }      
    if(fp->size == fp->capacity){
        printf("\033[1;34mFila cheia!\033[0m\n");
        return;
    }

    strcpy(fp->heap[fp->size].nome,nome);
    fp->heap[fp->size].prio = prio;
    promove_elemento(fp,fp->size);
    fp->size ++;
    
}

void rebaixa_elemento(prioQueue *fp, int pai){
    int filho = 2*pai+1;

    while(filho < fp->size){ //percorre a arvore no maximo até as folhas 
        
        if(filho < fp->size-1){ //TRUE significa que tem um irmão
            if(fp->heap[filho].prio < fp->heap[filho+1].prio){ //testa qual irmão tem maior prioridade
                filho++;
            }
        }

        if(fp->heap[pai].prio >= fp->heap[filho].prio) //pai ja tem prioridade >= , não precisa swap
            break;

        swap(fp,pai,filho);
        pai = filho;
        filho = 2*pai+1;
    }
}

void remocao(prioQueue *fp){
    if(fp == NULL){
        printf("ERRO NA REMOÇÃO PONTEIRO NULO\n");
        return;
    }      
    if(fp->size == 0){
        printf("\033[1;34mFila VAZIA!\033[0m\n");
        return;
    }

    fp->size--;
    fp->heap[0] = fp->heap[fp->size];
    rebaixa_elemento(fp,0);
}

void print_array(prioQueue *fp){

    if (fp->size == 0) {
        printf("\033[1;34mFila de prioridade vazia.\033[0m\n");
        return;
    }

    printf("--------------------------------------------\n");

    for(int i=0;i < fp->size;i++){
        printf(" \033[1;31m\t%s: %d\033[0m\n",
           fp->heap[i].nome, fp->heap[i].prio     //nó pai pintado em vermelho
        ); 
        
        if((2*i)+1 >=  fp->size)                // filho da esquerda 
            printf("esq.[vazio]\t");
        else
            printf("esq.[%s,%d] \t", fp->heap[(2*i)+1].nome, fp->heap[(2*i)+1].prio);

        if((2*i)+2 >=  fp->size)                // filho da direita 
            printf("dir.[vazio]\t");
        else
            printf("dir.[%s,%d] \t", fp->heap[(2*i)+2].nome, fp->heap[(2*i)+2].prio);

        printf("\n\n");
    }
}  

void menu(prioQueue *fp){
    int opcao,prio;
    char nome[50];
    do{
        printf("\n------------Menu------------\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir Heap\n");
        printf("0. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Digite o nome e a prioridade do elemento a ser inserido: \n");
                scanf("%50s", nome);scanf("%d", &prio);
                insert(fp,prio,nome);
                break;
            case 2:
                remocao(fp);
                break;
            case 3:
                print_array(fp);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }

    }while (opcao !=0);
}