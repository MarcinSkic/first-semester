#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct HURT{
    char name[20];
    char producerName [20];
    float price;
};
struct SKLEP{
    char producerName[20];
    float marza;
};
int main()
{
    int n,k;
    printf("Ile produktow chcesz podac: ");
    scanf("%d",&n);

    struct HURT produkty[n];

    printf("Ile producentow chcesz podac: ");
    scanf("%d",&k);

    struct SKLEP producenci[k];

    printf("\nWyjasnienie: Podajac producentow pamietaj ze takich samych bedziesz musial uzyc przy podawaniu produktow!\n\n");
    for(int i = 0; i < k; i++){

        printf("Podaj %d producenta: \n",i+1);
        printf("\tPodaj nazwe: ");
        fflush(stdin);
        gets(producenci[i].producerName);
        printf("\tPodaj marze: ");
        scanf("%f",&producenci[i].marza);

    }
    printf("\nWyjasnienie: Podajac produkty pamietaj zeby uzyc takich samych producentow!\n\n");
    for(int i = 0; i < n; i++){

        printf("Podaj %d produkt: \n",i+1);
        printf("\tPodaj nazwe: ");
        fflush(stdin);
        gets(produkty[i].name);
        printf("\tPodaj nazwe producenta: ");
        fflush(stdin);
        gets(produkty[i].producerName);
        printf("\tPodaj cene: ");
        scanf("%f",&produkty[i].price);
    }
    printf("\nWyswietlanie ceny + marzy: \n");
    for(int i = 0; i < n; i++){
        float temp;
        bool producerExist = false;

        printf("Cena z marza dla produktu %s:\n", produkty[i].name);

        for(int x = 0; x < k; x++){
            if(!strcmp(produkty[i].producerName,producenci[x].producerName)){
                producerExist = true;
                temp = producenci[x].marza;
                break;
            }
        }
        if(!producerExist){
            printf("\tNie istnieje producent takiego produktu\n");
            continue;
        }
        printf("\t%f\n",temp+produkty[i].price);

    }

    /*printf("\nWyswietlanie kontrolne: \n");
    for(int i = 0; i < k; i++){
        printf("Dane %d producenta: \n",i+1);
        printf("\tNazwa: %s\n",producenci[i].producerName);
        printf("\tMarza: %f\n",producenci[i].marza);
    }*/
}
