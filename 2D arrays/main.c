#include <stdio.h>
#include <stdlib.h>

//Wykonal Marcin Skic
int main()
{
    int i,j;
    float *p;
    printf("Podaj ilosc wierszy tablicy: ");
    scanf("%d",&i);

    printf("Podaj ilosc kolumn tablicy: ");
    scanf("%d",&j);

    float input[i][j];

    for(int z = 0; z < i;z++)
    {
        for(int x = 0; x < j ; x++){
            printf("Podaj element tablicy w wierszu %d, kolumnie %d: ",z+1,x+1);
            scanf("%f",&input[z][x]);
        }
    }
    printf("\n");
    for(int z = 0; z < i;z++)   //wyœwietlanie
    {
        for(int x = 0; x < j ; x++){
            printf("%f\t", input[z][x]);
        }
        printf("\n");
    }
    printf("\n");

    Exercise4(i,j,input);
}
void Exercise1(int rows, int columns, float input[][columns]){

    int choosenColumn;
    float suma = 0,result;
    printf("Podaj dla ktorej kolumny chcesz srednia arytmetyczna: ");
    scanf("%d",&choosenColumn);

    if(choosenColumn > columns && choosenColumn > 0){
        printf("Zly indeks kolumny");
        return;
    }

    for(int z = 0; z < rows;z++)
    {
        suma += input[z][choosenColumn-1];
    }
    result = suma/rows;

    printf("Œrednia arytmetyczna wynosi: %f",result);
}
Exercise2(int rows, int columns, float input[][columns]){

    float temp;

    for(int x = 0; x < columns; x++){
        temp = input[0][x];
        input[0][x] = input[rows-1][x];
        input[rows-1][x] = temp;
    }

    printf("Wyswietlenie tablicy z zamienionymi liczbami: \n");

    for(int z = 0; z < rows;z++)   //wyœwietlanie
    {
        for(int x = 0; x < columns ; x++){
            printf("%f\t", input[z][x]);
        }
        printf("\n");
    }
}
Exercise3(int rows, int columns, float input[][columns]){

    printf("Sprawdzam czy wystepuje zero w tablicy\n");

    for(int z = 0; z < rows;z++)   //wyœwietlanie
    {
        for(int x = 0; x < columns ; x++){
            if(input[z][x] == 0){
                printf("Jest w tablicy zero, przerywam szukanie\n");
                return;
            }
        }
    }
    printf("W tej tablicy nie ma zera\n");
}
Exercise4(int rows, int columns, float input[][columns]){

    printf("Sprawdzam czy tablica jest symetryczna\n");

    for(int z = 0; z < rows;z++)   //wyœwietlanie
    {
        for(int x = 0; x < columns/2 ; x++){
            if(input[z][x] != input[z][columns-x-1]){
                printf("Ta tablica nie jest symetryczna, przerywam sprawdzanie\n");
                return;
            }
        }
    }
    printf("Ta tablica jest symetryczna");
}
