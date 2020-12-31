#include <stdio.h>
#include <stdlib.h>

//Wykonal Marcin Skic
float F(int rows, int columns, float input[][columns],int *amount);
int main()
{
    int w,k,amount=0;
    float *p,R;
    printf("Podaj ilosc wierszy tablicy: ");
    scanf("%d",&w);

    printf("Podaj ilosc kolumn tablicy: ");
    scanf("%d",&k);

    float input[w][k];

    for(int z = 0; z < w;z++)
    {
        for(int x = 0; x < k ; x++){
            printf("Podaj element tablicy w wierszu %d, kolumnie %d: ",z+1,x+1);
            scanf("%f",&input[z][x]);
        }
    }
    printf("Wartosc R: %f",F(w,k,input,&amount));
    printf("\nIlosc elementow wiekszych od R: %d",amount);
}
float F(int rows, int columns, float input[][columns],int *amount){

    float min = 999999, max = -999999, temp, R;
    for(int z = 0; z < rows;z++)
    {
        for(int x = 0; x < columns ; x++){
            temp = input[z][x];
            if(temp < min){
                min = temp;
            }
            if(temp > max){
                max = temp;
            }
        }
    }

    R = max-min;

    for(int z = 0; z < rows;z++)
    {
        for(int x = 0; x < columns ; x++){
            if(input[z][x] > R){
                (*amount)++;
            }
        }
    }

    return R;
}
