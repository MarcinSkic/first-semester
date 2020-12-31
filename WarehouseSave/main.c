#include <stdio.h>
#include <stdlib.h>

struct HURT{
    char name[20];
    char producerName [20];
    float price;
};
int SaveOption(){
    int decision = 2;

    printf("Czy chcesz zapisac wyniki do pliku?\n1 - tak\n0 - nie\nTwoj wybor: ");
    scanf("%d",&decision);

    return decision;
}
void CreateDataBase(FILE *baseFile, char fileName[]){
    int n;
    struct HURT produkt;

    printf("Ile HURT chcesz podac: ");
    scanf("%d",&n);

    baseFile=fopen(fileName,"wb");
    for(int i = 0; i < n; i++){

        printf("Podaj %d produkt: \n",i+1);
        printf("\tPodaj nazwe: ");
        fflush(stdin);
        gets(produkt.name);
        printf("\tPodaj nazwe producenta: ");
        fflush(stdin);
        gets(produkt.producerName);
        printf("\tPodaj cene: ");
        scanf("%f",&produkt.price);


        fwrite(&produkt, sizeof(struct HURT), 1,baseFile);
    }
    fclose(baseFile);
}
void ShowDataBase(FILE *baseFile, char fileName[]){
    int x;
    struct HURT produkt;

    printf("\nWyswietlenie produktow: ");
    baseFile=fopen(fileName, "rb");
    x = 1;

    while ( !feof(baseFile) )
    {
        if ( fread(&produkt,sizeof(struct HURT),1,baseFile) ){
            printf("\nProdukt nr: %d\n",x);
            printf("\tNazwa produktu: %s\n\tNazwa producenta: %s\n\tCena: %f\n",produkt.name, produkt.producerName,produkt.price);
            x++;
        }
    }
    fclose(baseFile);
}

void AddToDataBase(FILE *baseFile, char fileName[]){
    struct HURT produkt;

    baseFile = fopen(fileName, "ab");

    printf("Podaj produkt: \n");
    printf("\tPodaj nazwe: ");
    fflush(stdin);
    gets(produkt.name);
    printf("\tPodaj nazwe producenta: ");
    fflush(stdin);
    gets(produkt.producerName);
    printf("\tPodaj cene: ");
    scanf("%f",&produkt.price);

    fwrite(&produkt, sizeof(struct HURT),1,baseFile);

    fclose(baseFile);
}
void FindProductsByProducer(FILE *baseFile, char fileName[], char raportName[]){

    char searchedProducer[20] = "gg";
    struct HURT produkt;

    printf("\nPodaj jakiego producenta chcesz znalezc: ");
    fflush(stdin);
    gets(searchedProducer);

    baseFile=fopen(fileName, "rb");

    while ( !feof(baseFile) )
    {
        if ( fread(&produkt,sizeof(struct HURT),1,baseFile) ){
            if(!strcmp(produkt.producerName,searchedProducer)){
                printf("\nProdukt: \n");
                printf("\tNazwa produktu: %s\n\tNazwa producenta: %s\n\tCena: %f\n",produkt.name, produkt.producerName,produkt.price);
            }
        }
    }

    fclose(baseFile);
}
void FindProductsWithLowerPrice(FILE *baseFile, char fileName[], char raportName[]){

    char searchedProducer[20] = "gg";
    float givenPrice;
    struct HURT produkt;

    printf("\nPodaj szukana cene: ");
    scanf("%f",&givenPrice);

    baseFile=fopen(fileName, "rb");

    while ( !feof(baseFile) )
    {
        if ( fread(&produkt,sizeof(struct HURT),1,baseFile) ){
            if(produkt.price < givenPrice){
                printf("\nProdukt: \n");
                printf("\tNazwa produktu: %s\n\tNazwa producenta: %s\n\tCena: %f\n",produkt.name, produkt.producerName,produkt.price);
            }
        }
    }

    fclose(baseFile);
}
void FindMaxPriceProduct(FILE *baseFile, char fileName[], char raportName[]){

    float max = -5.0;
    struct HURT maxProdukt;
    struct HURT produkt;
    int saveOption = SaveOption();
    FILE *raportFile;



    baseFile=fopen(fileName, "rb");

    while ( !feof(baseFile) )
    {
        if ( fread(&produkt,sizeof(struct HURT),1,baseFile) ){
            if(produkt.price > max){
                maxProdukt = produkt;
                max = produkt.price;
            }
        }
    }

    fclose(baseFile);

    printf("\nProdukt z najwyzsza cena: \n");
    printf("\tNazwa produktu: %s\n\tNazwa producenta: %s\n\tCena: %f\n",maxProdukt.name, maxProdukt.producerName,maxProdukt.price);

    if(saveOption){
        raportFile=fopen(raportName, "wb");
        fwrite(&maxProdukt, sizeof(struct HURT), 1,raportFile);
        fclose(raportFile);
    }
}
void ChangeRecordPrice(FILE *baseFile, char fileName[]){
    int j,multiplayer = 10;
    float searchedPrice,newPrice;
    struct HURT produkt;

    baseFile=fopen(fileName, "r+b");

    printf("Jaka cene chcesz zmienic: ");
    scanf("%f",&searchedPrice);

    printf("Na jaka cene chcesz zmienic: ");
    scanf("%f",&newPrice);

    while ( !feof(baseFile) )
    {
        j = ftell(baseFile);

        if ( fread(&produkt,sizeof(struct HURT),1,baseFile) ){

            if(produkt.price == searchedPrice){
                produkt.price = newPrice;

                fseek(baseFile,j,SEEK_SET);

                fwrite(&produkt,sizeof(struct HURT),1,baseFile);

                fseek(baseFile,j+sizeof(struct HURT),SEEK_SET);
            }
        }
    }
}
void SpecialQuest(){
    #include "moj.h"
    float y;
    printf("Podaj liczbe: ");
    scanf("%f",&y);
    printf("Wynik: %f\n",F(y));
}
int main()
{
    int wybor = 1,n, x;
    char fileName[20] = "MainDataBase";
    char lastReportName[20] = "ReportFile";
    FILE *baseFile;

    while(wybor){
        printf("\nCo chcesz zrobic: \nStworzyc baze - 1\nWyswietlic baze - 2\nDodac produkt do bazy - 3\nWyswietlic produkty wedlug producenta - 4\nWyswietlic produkty z cena nizsza - 5\nWyswietlenie produktu o najwyzszym koszcie - 6"
               "\nZmien ostatni rekord - 7\nOtworz ostatnio zapisany raport - 8\nSpecjalne zadanie - 9\nWyjsc z programu - 0\nTwoj wybor: ");
        scanf("%d",&wybor);
        switch(wybor){
        case 1:
            CreateDataBase(baseFile,fileName);
            break;
        case 2:
            ShowDataBase(baseFile, fileName);
            break;
        case 3:
            AddToDataBase(baseFile, fileName);
            break;
        case 4:
            FindProductsByProducer(baseFile, fileName, lastReportName);
            break;
        case 5:
            FindProductsWithLowerPrice(baseFile, fileName, lastReportName);
            break;
        case 6:
            FindMaxPriceProduct(baseFile,fileName, lastReportName);
            break;
        case 7:
            ChangeRecordPrice(baseFile, fileName);
            break;
        case 8:
            ShowDataBase(baseFile,lastReportName);
            break;
        case 9:
            SpecialQuest();
        case 0:
            break;
        }
    }
}
