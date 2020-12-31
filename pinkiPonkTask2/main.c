#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Waluta{
    char nazwa_waluty [20];
    float kurs_kupna;
    float kurs_sprzedazy;
};

int utworz(struct Waluta *array);
void drukuj(int size, struct Waluta *array);
void zapisz(int size, struct Waluta *array);
int wczytaj(struct Waluta *array);

int main()
 {
     int size,loadedSize;
     struct Waluta *generatedArray,*loadedArray;
    generatedArray = (struct Waluta *)calloc(2,sizeof(struct Waluta));
    loadedArray = (struct Waluta *)calloc(2,sizeof(struct Waluta));
     size = utworz(generatedArray);

     drukuj(size,generatedArray);
    zapisz(size,generatedArray);
    wczytaj(loadedArray);

    drukuj(2,loadedArray);

     free(generatedArray);
     return 0;
 }

int utworz(struct Waluta *array){
    int size = 2;

    printf("Tworzenie walut: \n");
    for(int i = 0 ; i < size; i++){
        printf("Podaj %d walute: \n",i+1);
        fflush(stdin);
        printf("\tPodaj nazwe: ");
        scanf("%s",&array[i].nazwa_waluty);
        printf("\tPodaj kurs sprzedazy: ");
        scanf("%f",&array[i].kurs_sprzedazy);
        printf("\tPodaj kurs kupna: ");
        scanf("%f",&array[i].kurs_kupna);

    }
    return size;
}
void drukuj(int size, struct Waluta *array){
    struct Waluta temp;
    printf("\nWyswietlanie walut: \n");
    for(int i = 0; i < size;i++){
        printf("Waluta %d: \n",i+1);

        printf("\tNazwa: %s\n",array[i].nazwa_waluty);

        printf("\tPodaj kurs sprzedazy: %f\n",array[i].kurs_sprzedazy);

        printf("\tPodaj kurs kupna: %f\n",array[i].kurs_kupna);

    }
}
void zapisz(int size, struct Waluta *array)
{
    FILE *plik = fopen("plik.txt","w");

    fwrite(array, sizeof(struct Waluta), size,plik);

    fclose(plik);
}
int wczytaj(struct Waluta *array){
    int i = 0;
    FILE *plik =fopen("plik.txt", "rb");
    struct Waluta temp;

    fread(array,sizeof(struct Waluta),2,plik);

    fclose(plik);
    return i;
}


