#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura dos nós da matriz identidade
typedef struct no {
    int linha;
    int coluna;
    int valor;
    struct no *prox;
} No;

// Função para criar um nó da matriz identidade
No* criarNo(int linha, int coluna, int valor) {
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->linha = linha;
    novoNo->coluna = coluna;
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

// Função para inserir um nó na matriz identidade
void inserirNo(No **matriz, int linha, int coluna, int valor) {
    No *novoNo = criarNo(linha, coluna, valor);
    novoNo->prox = matriz[linha];
    matriz[linha] = novoNo;
}

// Função para verificar se a matriz é identidade
int ehIdentidade(No **matriz, int ordem) {
    int i, j;
    for (i = 0; i < ordem; i++) {
        No *noAtual = matriz[i];
        for (j = 0; j < ordem; j++) {
            if (i == j && (noAtual == NULL || noAtual->coluna != j || noAtual->valor != 1)) {
                return 0;
            } else if (i != j && (noAtual != NULL && noAtual->coluna == j)) {
                return 0;
            }
            if (noAtual != NULL && noAtual->coluna == j) {
                noAtual = noAtual->prox;
            }
        }
    }
    return 1;
}

// Função para preencher a matriz com os valores fornecidos pelo usuário
void preencherMatriz(No **matriz, int ordem) {
    int i, j, valor;
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            printf("Digite o valor para a posição [%d][%d]: ", i, j);
            scanf("%d", &valor);
            if (valor != 0 && valor != 1) {
                printf("Valor inválido. Digite 0 ou 1.\n");
                j--;
            } else {
                inserirNo(matriz, i, j, valor);
            }
        }
    }
}

// Função para imprimir a matriz
void imprimirMatriz(No **matriz, int ordem) {
    int i, j;
    printf("Matriz:\n");
    for (i = 0; i < ordem; i++) {
        No *noAtual = matriz[i];
        for (j = 0; j < ordem; j++) {
            if (noAtual != NULL && noAtual->coluna == j) {
                printf("%d ", noAtual->valor);
                noAtual = noAtual->prox;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Função para mostrar os elementos que violam a propriedade da identidade
void mostrarViolacoes(No **matriz, int ordem) {
    int i, j;
    for (i = 0; i < ordem; i++) {
        No *noAtual = matriz[i];
        while (noAtual != NULL) {
            if (noAtual->valor != 0 && noAtual->valor != 1) {
                printf("Valor inválido na posição [%d][%d]: %d\n", noAtual->linha, noAtual->coluna, noAtual->valor);
            } else if (i == noAtual->coluna && noAtual->valor != 1) {
                printf("Valor diferente de 1 na diagonal principal na posição [%d][%d]: %d\n", noAtual->linha, noAtual->coluna, noAtual->valor);
            } else if (i != noAtual->coluna && noAtual->valor != 0) {
                printf("Valor diferente de 0 fora da diagonal principal na posição [%d][%d]: %d\n", noAtual->linha, noAtual->coluna, noAtual->valor);
            }
            noAtual = noAtual->prox;
        }
    }
}

// Função para liberar a memória alocada pela matriz identidade
void liberarMatriz(No **matriz, int ordem) {
    int i;
    for (i = 0; i < ordem; i++) {
        No *noAtual = matriz[i];
        while (noAtual != NULL) {
            No *proxNo = noAtual->prox;
            free(noAtual);
            noAtual = proxNo;
        }
    }
    free(matriz);
}

int main() {
    int ordem;
    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);

    // Criando a matriz identidade vazia
    No **matriz = (No**) malloc(ordem * sizeof(No*));
    for (int i=0; i<ordem;i++) {
        matriz[i] = NULL;
    }

    // Preenchendo a matriz com os valores fornecidos pelo usuário
    preencherMatriz(matriz, ordem);

    // Imprimindo a matriz
    imprimirMatriz(matriz, ordem);

    // Verificando se a matriz é identidade e mostrando as violações, se houverem
    if (ehIdentidade(matriz, ordem)) {
        printf("A matriz é identidade.\n");
    } else {
        printf("A matriz não é identidade.\n");
        mostrarViolacoes(matriz, ordem);
    }

    // Liberando a memória alocada pela matriz identidade
    liberarMatriz(matriz, ordem);

    return 0;

}
