/** Dionatan Rodrigues */
#include <stdio.h>

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y){
    if((x >= x0)&&(x <= x1)&&(y >= y0)&&(y <= y1)){
        return 1; 
    }else{ 
        return 0;
    }
}

int main()
{
    int x , y ,x0 = 1 , y0 = 1, x1 = 7, y1 = 3, flag;

    printf("Digite x do ponto: ");
    scanf("%d",&x);
    printf("Digite y do ponto: ");
    scanf("%d",&y);

    flag = dentro_ret(x0,y0,x1,y1,x,y);

    if(flag)
        printf("Ponto dentro do retângulo\n");
    else 
        printf("Ponto fora do retângulo\n");   


    return 0;

}

