/*Desenvolvido por Dionatan Rodrigues e Mateus Quadros*/
#include <stdio.h>
#include <stdlib.h>

int*** aloca_matriz(int x, int y, int z) {
    int*** mat = (int***) malloc(x * sizeof(int**));
    for (int i=0;i<x;i++){
        mat[i] = (int**) malloc(y * sizeof(int*));
        for (int j=0;j<y;j++){
            mat[i][j] = (int*) malloc(z * sizeof(int));
        }
    }
    return mat;
}

void preenche_matriz(int*** mat, int x, int y, int z) {
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            for (int k=0;k<z;k++){
                printf("Digite o valor da posicao [%d][%d][%d]: ", i, j, k);
                scanf("%d", &mat[i][j][k]);
            }
        }
    }
}

void imprime_matriz(int*** mat, int x, int y, int z) {
    printf("Matriz de dimensoes %d x %d x %d:\n", x, y, z);
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            for (int k=0;k<z;k++){
                printf("%d\t", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void libera_memoria(int*** mat, int x, int y, int z){
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);
}

int main() {
    int x, y, z;
    int*** mat;

    printf("Informe as dimensoes da matriz (x y z): ");
    scanf("%d %d %d", &x, &y, &z);

    mat = aloca_matriz(x, y, z);
    preenche_matriz(mat,x, y, z);
    imprime_matriz(mat,x, y, z);
    libera_memoria(mat,x,y,z);


    return 0;
}

