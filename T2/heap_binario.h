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

//Autoexplicativo
//void swap(node *fila, int data1, int data2);

void cria_fila_vazia(prioQueue *fp, int capacity);

//Inserção --------------------------------------------------------
void promove_elemento(prioQueue *fila, int size); 
 
void insert(prioQueue *fila, int prio, char *nome);

//Impressão do nó e de seus filhos(dir/esq)
//void print_no(node *fila, int data);

//Remoção ---------------------------------------------------------
//void remocao(prioQueue *fila, int data);


#endif // HEAPBINARIO_H