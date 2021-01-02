#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Exercise1Lista();
}
Exercise1(){
    char napis[20];
    char z,x;
    int i, n, k=0;

    printf("Wpisz tekst ");
    gets(napis);

    printf("Wpisz znak ktory chcesz zamienic ");
    fflush(stdin);
    scanf("%c", &z);

    printf("Wpisz znak na jaki chcesz zamienic ");
    fflush(stdin);
    scanf("%c", &x);

    n=strlen(napis);

    for (i=0; i<n; i++)
        if (napis[i]==z){
            napis[i] = x;
        }
    printf("%s",napis);
    return 0;
}
Exercise2(){
    char imie[20], nazwisko[30], kierunek_studiow[30], dane[80];
    printf("Imie: ");
    gets(imie);
    printf("Nazwisko: ");
    gets(nazwisko);
    printf("Kierunek studiow: ");
    gets(kierunek_studiow);
    strcpy(dane, "Dane: \n");
    strcat(dane, imie); //wpisanie miasta do adres
    strcat(dane, " "); //dopisanie znaku nowego wiersza na koncu adresu(miasta)
    strcat(dane, nazwisko); //dopisanie ulicy na koncu adresu (w nowym wierszu)
    strcat(dane, "\n"); //dopisanie spacji na koncu adresu(ulicy)
    strcat(dane, "Kierunek: "); //dopisanie nr na koncu adresu(po spacji)
    strcat(dane, kierunek_studiow);
    printf(dane);
    // lub puts(adres); lub printf("%s", adres);
    printf("\n");
    return 0;
}
Exercise1Lista(){
    int n, attempts = 0;
    int yearTemp = -999, firstYear = 0, secondYear = 0, thirdYear = 0;
    char temp[20];

    printf("Podaj liczbe studentow do wpisania: ");
    scanf("%d",&n);


    char Lista[n][60];


    for(int i = 0; i < n; i++){ //Wczytywanie danych studentow

        fflush(stdin);
        printf("Podaj imie: ");
        gets(temp);
        strcpy(Lista[i],temp);
        strcat(Lista[i], " ");

        fflush(stdin);
        printf("Podaj nazwisko: ");
        gets(temp);
        strcat(Lista[i],temp);
        strcat(Lista[i], " ");

        while((yearTemp <= 0 || yearTemp > 3)){   //Sprawdza czy podany rok jest liczb¹ i jest poprawny

            fflush(stdin);
            if(yearTemp == -999){
                printf("Podaj rok: ");
            } else {
                printf("Zla podana wartosc, masz jeszcze %d prob: ",5-attempts);

            }

            gets(temp);
            yearTemp = atoi(temp);

            attempts++;

            if(attempts == 5){
                printf("Zbyt duzo prob!");
                return;
            }
        }

        yearTemp = -999;
        attempts = 0;

        if(yearTemp == 1){  //Przypisuje
            firstYear++;
        } else if(yearTemp == 2){
            secondYear++;
        } else {
            thirdYear++;
        }

        strcat(Lista[i], temp);

    }

    char firstYearArr[firstYear][60];
    char secondYearArr[secondYear][60];
    char thirdYearArr[thirdYear][60];

    for(int i = 0; i < n;i++){
        printf("Rok: b%d",atoi(Lista[i][strlen(Lista[i])-1]));

    }

    printf(Lista[0]);
}
