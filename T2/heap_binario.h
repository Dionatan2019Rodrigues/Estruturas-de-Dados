#ifndef HEAPBINARIO_H
#define HEAPBINARIO_H

typedef struct node_t{
    char nome[50];
    int prio;
}node;

typedef struct priority_queue{
    node *heap;
    int capacity;
    int size;
}prioQueue;

//Auxiliares ------------------------------------------------------
prioQueue *cria_fila_vazia(int capacity);

void swap(prioQueue *fp, int pos1, int pos2);

//Inserção --------------------------------------------------------
void promove_elemento(prioQueue *fp, int size); 
 
void insert(prioQueue *fp, int prio, char *nome);

//Remoção ---------------------------------------------------------
void rebaixa_elemento(prioQueue *fp, int pai);

void remocao(prioQueue *fila);

//Impressão -------------------------------------------------------
//do nó e de seus filhos(dir/esq)
//void print_no(node *fila, int data);

void print_array(prioQueue *fp);

#endif // HEAPBINARIO_H