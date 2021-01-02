#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Wykonal Marcin Skic
    int w,k;
    printf("Podaj ilosc wierszy: ");
    scanf("%d",&w);
    printf("Podaj ilosc kolumn: ");
    scanf("%d",&k);

    float T[w][k];
    float targetArray[w+1][k];

    for(int i = 0; i < w; i ++){
        for(int x = 0; x < k; x++){
            printf("Podaj element w %d wierszu %d kolumnie: ",i+1,x+1);
            scanf("%f",&T[i][x]);
        }
    }

    for(int i = 0; i < w; i ++){
        for(int x = 0; x < k; x++){
            targetArray[i][x] = T[i][x];

            if(i == 0){
                targetArray[w][x] = T[i][x];
            } else {
                targetArray[w][x] = targetArray[w][x] + T[i][x];
            }
        }
    }

    printf("\nStara tablica: \n");
    for(int i = 0; i < w; i ++){
        for(int x = 0; x < k; x++){
            printf("%f ",T[i][x]);
        }
        printf("\n");
    }

    printf("\nNowa tablica: \n");
    for(int i = 0; i < w+1; i ++){
        for(int x = 0; x < k; x++){
            printf("%f ",targetArray[i][x]);
        }
        printf("\n");
    }
}
