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
        //0800 031 8000
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
        printf("Fila cheia!\n");
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
        printf("Fila VAZIA!\n");
        return;
    }

    fp->size--;
    fp->heap[0] = fp->heap[fp->size];
    rebaixa_elemento(fp,0);
}

void print_array(prioQueue *fp){
    if (fp->size == 0) {
        printf("Fila de prioridade vazia.\n");
        return;
    }

    for(int i=0;i < fp->size;i++){
        printf("%s: %d \n",fp->heap[i].nome, fp->heap[i].prio);
    }
}