/** Dionatan Eduardo Correa Rodrigues **/
#include <stdio.h>
#include <math.h> // used round() in function converter
#include <stdlib.h> // used malloc() in function le_arq
#include <ctype.h> // used isspace in function ignoreComments
#include <stdbool.h>
#include <string.h> // used in main() //leitura do caminho de imagens

typedef struct RGB{
    int red;
    int green;
    int blue;
} RGB;

typedef struct IMG{
    char variante[2];
    int linha, coluna;
    int intensidade;
    RGB *mat;
    int *matrix;
    bool p3;
}IMG;

//le uma posicao da matriz
void leitura(FILE *arq, RGB *p){
    fscanf(arq, "%d", &p->red);
    fscanf(arq, "%d", &p->green);
    fscanf(arq, "%d", &p->blue);

}
//Auto explicativa
void ignoreComments(FILE *arq){
    int ch;
    char line[100];
    ch = fgetc(arq);
    while ((ch  != EOF) && isspace(ch)){
    printf("%c", ch);
    ch = fgetc(arq);
    }
    if (ch == '#') {
        fgets(line, sizeof(line), arq);
        ignoreComments(arq);
    }
    else{
        fseek(arq, -1, SEEK_CUR);
    }
}
//le top do  arquivo
void le_arq(FILE *arq, IMG *p){
    if(arq == NULL){
        printf("ERRO AO ABRIR O ARQUIVO");
    }else{

        ignoreComments(arq);
        fscanf(arq, "%[^\n]\n", p->variante);
        p->p3 = p->variante[1] == '3';
        ignoreComments(arq);
        fscanf(arq, "%d %d", &p->linha, &p->coluna);
        ignoreComments(arq);
        RGB * ptr  = malloc(sizeof(RGB)*(p->linha*p->coluna));
        fscanf(arq, "%d", &p->intensidade);
        ignoreComments(arq);
        for(int i=0;i<(p->linha*p->coluna);i++){
            leitura(arq, &ptr[i]);            
        }
        p->mat = ptr;
    }

    fclose(arq);
    
}
//imprime um pixel da matriz
void imp_pix(RGB *p, FILE *saida){
    fprintf(saida,"%d ",p->red);
    fprintf(saida,"%d ",p->green);
    fprintf(saida,"%d ",p->blue);
}
//imprime todos dados da img
void imprime_img(IMG img){
    FILE *saida;
    saida = fopen("resultado","wt");
    if(img.p3){
        fprintf(saida,"%c",img.variante[0]);
        fprintf(saida,"%c\n",img.variante[1]);
    }else{
        fprintf(saida,"P2\n");
    }
    fprintf(saida,"%d %d\n",img.linha, img.coluna);
    fprintf(saida,"%d\n",img.intensidade);
    for(int i=0;i<(img.linha*img.coluna);i++){
        if(i%(img.coluna)==0){
            fprintf(saida,"\n");
        }
        imp_pix(&img.mat[i],saida);
        fprintf(saida,"\t");
    }
    fprintf(saida,"\n");
    fclose(saida);
}
//Copia uma matriz para vetor
void copia(int colum, RGB m[][colum],IMG *p){
    for(int i=0;i<p->linha;i++){
        for(int j=0;j<p->coluna;j++){
            p->mat[(p->coluna*i)+j] = m[i][j];
        }
    }
}
//Auto explicativa
void rotaciona90(IMG *p){
    RGB m[p->coluna][p->linha];
    for(int i=0;i<p->linha;i++){
        for(int j=0;j<p->coluna;j++){  
            m[j][p->linha-1-i] = p->mat[(p->coluna*i)+j];
        }
    }
    copia(p->coluna,m,p);
}
//Auto explicativa
void greenscreen(IMG *p, IMG *p_down, int r, int g, int b){
    for(int i=0;i<p->linha;i++){
      for(int j=0;j<p->coluna;j++){
        if((p->mat[(p->coluna*i)+j].red==r)&&(p->mat[(p->coluna*i)+j].green==g)&&(p->mat[(p->coluna*i)+j].blue==b)){
            //p_down->mat[(p->coluna*i)+j] = p->mat[(p->coluna*i)+j];
        //nao faz nada img de fundo permanece
        }else{
            p_down->mat[(p->coluna*i)+j] = (p->mat[(p->coluna*i)+j]);
        }
      }
    }
}
//imprime img convertida para P2
void imprime_matrix(IMG img){
    FILE * saida;
    saida = fopen("P2resultado","wt");
    fprintf(saida,"P2\n");   
    fprintf(saida,"%d %d\n",img.linha, img.coluna);
    fprintf(saida,"%d\n",img.intensidade);
    for(int i=0;i<(img.linha*img.coluna);i++){
        if(i%(img.coluna)==0){
            fprintf(saida,"\n");
        }
        fprintf(saida,"%d ",img.matrix[i]);
    }
    fprintf(saida,"\n");
}
//Converte Colorido -> Preto.Branco
void converter(IMG *p){
    p->matrix = malloc(sizeof(int)*(p->linha*p->coluna));
    for(int i=0;i<p->linha;i++){
      for(int j=0;j<p->coluna;j++){
        p->matrix[(p->coluna*i)+j] = round(((p->mat[(p->coluna*i)+j].red)+(p->mat[(p->coluna*i)+j].green)+(p->mat[(p->coluna*i)+j].blue))/3);
      }
    }
}
void retalhar(IMG *p, int x1, int y1, int x2, int y2){
    int m[(p->linha-(x1-1))*(y2)];
    int cont=0;

    for(int i=(x1-1);i<x2;i++){
        for(int j=(y1-1);j<y2;j++){
            m[cont] = p->matrix[(p->coluna*i)+j];
            cont++;
        }
    }

    for(int i=0;i<(cont-2);i++){
        p->matrix[i] = m[i];
    }
    p->linha = p->linha-(x1-1);
    p->coluna = y2;
}
void retalharRGB(IMG *p, int x1, int y1, int x2, int y2){
    RGB m[(p->linha-(x1-1))*(y2)];
    int cont=0;

    for(int i=(x1-1);i<x2;i++){
        for(int j=(y1-1);j<y2;j++){
            m[cont] = p->mat[(p->coluna*i)+j];
            cont++;
        }
    }

    for(int i=0;i<(cont-2);i++){
        p->mat[i] = m[i];
    }
    p->linha = p->linha-(x1-1);
    p->coluna = y2;
}


int main()
{
    IMG stIMG;
    IMG stTWO; 
    IMG *ptr_img = &stIMG; 
    IMG *ptr_two = &stTWO;
    FILE *in_front, *in_down;
    stIMG.p3=false;
    stTWO.p3=false;
    int op=3, rot, r, g, b, x1, y1, x2, y2, recorte=0;
    char frente[100], fundo[100];

    printf("QUAL OPÇÃO DESEJA ESCOLHER\n\n");
    printf("(1)Inserir duas imagens P3 e realizar(GREENSCREN/ROTAÇÃO)\n");
    printf("(2)Inserir uma imagem P3 e convertela para P2\n");
    printf("Digite: ");
    while(op != 1 && op != 2){
        scanf("%d",&op);
    }
    printf("Digite 1 se deseja recorte na imagem e 0 se não\n");
    scanf("%d",&recorte);
    if(recorte==1){
        printf("Digite x e y do primeiro ponto de recorte: ");
        scanf("%d%d",&x1, &y1);
        printf("Digite x e y do segundo ponto de recorte: ");
        scanf("%d%d",&x2, &y2);
    }
    
    switch(op){
        case 1:
            printf("Digite o caminho da imagem da FRENTE: ");
            scanf("%s",frente);
            printf("Digite o caminho da imagem do FUNDO: ");
            scanf("%s",fundo);
            printf("Digite rotação deseja(90||180||270): ");
            scanf("%d",&rot);
            printf("Digite o padrão RGB da cor desejada como mascara: ");
            scanf("%d %d %d",&r, &g, &b);

            in_front = fopen(frente,"rt");
            le_arq(in_front,ptr_img);

            in_down = fopen(fundo,"rt");
            le_arq(in_down,ptr_two);

            //TESTE TAMANHO IMAGENS 
            if((ptr_img->linha <= ptr_two->linha)&&(ptr_img->coluna <= ptr_two->coluna)){
                switch(rot){
                    case 90:
                        rotaciona90(ptr_img);
                        break;
                    case 180:
                        rotaciona90(ptr_img);
                        rotaciona90(ptr_img);
                        break;
                    case 270:
                        rotaciona90(ptr_img);
                        rotaciona90(ptr_img);
                        rotaciona90(ptr_img);
                        break;
                }
                greenscreen(ptr_img,ptr_two,r,g,b);
                if(recorte==1)
                    retalharRGB(ptr_two,x1,y1,x2,y2);
                //Gera um arquivo
                imprime_img(stTWO);
            }else{
                printf("\n\n\nERRO TAMANHO INVALIDO\n");
            }
            break;
        case 2:
            printf("Digite o caminho da imagem P3: ");
            scanf("%s",frente);
            in_front = fopen(frente,"rt");
            le_arq(in_front,ptr_img);
            converter(ptr_img);
            if(recorte==1)
                retalhar(ptr_img,x1,y1,x2,y2);
            //gera um arquivo
            imprime_matrix(stIMG);
            break;
    }

    return 0;  
}
  





