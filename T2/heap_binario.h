#ifndef HEAPBINARIO_H
#define HEAPBINARIO_H

typedef struct node_t{
    int data;
    int prio;
}node;

typedef struct priority_queue{
    node *heap;
    int capacity;
    int size;
}prioQueue;

//Autoexplicativo
void swap(node *fila, int data1, int data2);

void promove_elemento(node *fila, int size); 

//Inserção 
void insert(node *fila, int data, int prio);

//Impressão do nó e de seus filhos(dir/esq)
void print_no(node *fila, int data);

//Remoção do nó
void remoção(node *fila, int data);


#endif // HEAPBINARIO_H