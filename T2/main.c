#include <stdio.h>
#include "heap_binario.h"

int main(){
    int capacity;

    printf("Digite a capacidade máxima da sua fila: ");
    scanf("%d",&capacity);

    prioQueue *fp = cria_fila_vazia(capacity);    
    
    menu(fp);

    return 0;
}
