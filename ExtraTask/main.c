#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int j, i, n, *x; // x wskaznik liczby calkowitej,to bedzie tablica liczb

    printf("Podaj ilosc elementow w tablicy: ");
    scanf("%d", &n);

    x=(int*)malloc(n*sizeof(int));// rezerwacja pamiêci dla n liczb calkowitych

    for(i=0; i<n ;i++)
    {
        printf("Podaj element %d: ",i+1);
        scanf("%d", x+i); // zapis wskaznikowy
    }
    printf("Wpisanie liczb z danej tablicy nalezacych do przedzialu <1,10> do nowej tablicy");
    int *NX; //deklaracja wskaznika dla nowej tablicy
    NX=(int*)malloc(sizeof(int)); // rezerwacja pamiêci dla 1 liczby calkowitej
    j=0; //zmienna j jest nr kolejnej przepisywanej liczby,
    //a jednoczeœnie inf. ile aktualnie liczb jest w nowej tablicy
    for(i=0; i<n; i++)
    {
        if(x[i]>=1 && x[i]<=10)
        {
            NX[j]=x[i];
            j++; //znalaz³a siê kolejna liczba, wiêc zwiêkszamy j
            NX=(int*)realloc(NX,j*sizeof(int));// zmiana rezerwacji dla NX
        } //-teraz rezerwacja dla j liczb calkowitych
    }
    if (j>0) //zmienna j jest inf. ile liczb wpisano do nowej tablicy
    {
        printf("\nelementy danej tablicy\n");
        for(i=0; i<n; i++)
            printf("%d\t", x[i]);
        printf("\nelementy nowej tablicy\n");
        for(i=0; i<j; i++) //w nowej tablicy jest j liczb, dlatego taki zakres pêtli
            printf("%d\t", NX[i]);
    }
    else
        printf("\nbrak liczb spelniajacych warunki\n");
    return 0;
}
int* FindNumbersInRange1to10(){

}
