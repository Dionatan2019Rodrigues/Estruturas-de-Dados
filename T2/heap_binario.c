#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "heap_binario.h"

void cria_fila_vazia(prioQueue *fp, int capacity){
    fp = (prioQueue*)malloc(sizeof(prioQueue));
    if(fp == NULL)
        printf("ERRO DE ALOCAÇÃO");

    fp->heap = (node*)malloc(capacity * sizeof(node));
    if(fp->heap == NULL)
        printf("ERRO DE ALOCAÇÃO DA FILA");
       
}

void promove_elemento(prioQueue *fp, int filho){
    int pai;
    node aux;
    pai = (filho - 1 ) / 2;

    while( (filho>0)&&(fp->heap[pai].prio <= fp->heap[filho].prio)){
        
        aux = fp->heap[filho];
        fp->heap[filho] = fp->heap[pai];
        fp->heap[pai] = aux;

        filho = pai;
        pai = (pai-1)/2;
    }
}

void insert(prioQueue *fp, int prio, char *nome){
    
    if(fp == NULL)
        return;
    
    if(fp->size == fp->capacity){
        printf("Fila cheia!\n");
        return;
    }

    strcpy(fp->heap[fp->size].nome,nome);
    fp->heap[fp->size].prio = prio;
    promove_elemento(fp,fp->size);
    fp->size ++;
    
}