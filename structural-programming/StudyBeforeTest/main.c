#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x,*lower,amount = 0,temp = 5,i = 0;
    printf("Podawaj liczby do tablicy (koniec jeœli podasz zero): ");

    x = (int*)malloc(sizeof(int));

    while(temp != 0){
        printf("\nPodaj liczbe: ");
        scanf("%d",x+i);
        i++;
        x = (int*)realloc(x,(i+1)*sizeof(int));

        temp = x[i-1];
        printf("Aktualna liczba: %d",x[i-1]);
    }
    /*for (int z = 0; z < 5; z++){

    }*/
    for(int y = 0; y < i; y++){
        printf("\nElement %d tablicy: %d",y+1,x[y]);
    }

    printf("\nPierwsza czesc za nami");

    lower = (int*)malloc(sizeof(int));

    for(int y = 0; y < i; y++){
        printf("\nSprawdzana liczba: %d",x[y]);
        if(x[y] <= 0){
            lower[amount] = x[y];
            amount++;

            lower = (int*)realloc(lower,(amount+1)*sizeof(int));

        }
    }
    for(int y = 0; y < amount; y++){
        printf("\nElement %d tablicy: %d",y+1,lower[y]);
    }
}
