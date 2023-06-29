#include <stdio.h>
#include "heap_binario.h"

int main(){

    prioQueue *fp = cria_fila_vazia(15);


    insert(fp,4,"Dione");
    insert(fp,5,"eduardo");
    insert(fp,2,"correa");
    insert(fp,3,"rodrigues");

    print_array(fp);
    printf("\n\n");

    remocao(fp);
    print_array(fp);
    printf("\n\n");

    remocao(fp);
    print_array(fp);
    
    return 0;
}
