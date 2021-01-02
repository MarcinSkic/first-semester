#include <stdio.h>
#include <stdlib.h>
#define ile 2
struct waluty
{
    char nazwa[20];
    float skup;
    float sprzedaz;
};

void utworz(struct waluty *p);
void drukuj(struct waluty *p);
void zapisz(struct waluty *p);
void wczytaj(struct waluty *p);


int main()
{
    struct waluty *p;
    p = malloc(ile*sizeof(struct waluty));
    utworz(p);
    drukuj(p);
    zapisz(p);
    wczytaj(p);

    free(p);
    return 0;
}

void utworz(struct waluty *p)
{
  for(int i=0;i<ile;i++)
  {
    printf("Podaj walute nr.%d: ",i+1);
    scanf("%s",&p[i].nazwa);
    printf("Podaj cene skupu: ",i+1);
    scanf("%f",&p[i].skup);
    printf("Podaj cene sprzedazy: ",i+1);
    scanf("%f",&p[i].sprzedaz);
  }
}

void zapisz(struct waluty *p)
{
    FILE *plik = fopen("plik.txt","w");
    if(plik==NULL)
    {

    }
    for(int i=0;i<ile;i++)
    {
        fprintf(plik,"waluta: %s, skup: %0.1f, sprzedaz: %0.1f\n",p[i].nazwa,p[i].skup,p[i].sprzedaz);
    }
    fclose(plik);
}

void wczytaj(struct waluty *p)
{
    char tmp[255];
    FILE *plik = fopen("plik.txt","r");
    if(plik==NULL)
    {

    }

    for(int i=0;i<ile;i++)
    {
        fgets(tmp,255,plik);
        printf("%s",tmp);
    }

    fclose(plik);
}

void drukuj(struct waluty *p)
{
  for(int i=0;i<ile;i++)
    {
        printf("Waluta: %s\n",p[i].nazwa);
        printf("skup: %f\n",p[i].skup);
        printf("sprzedaz: %f\n",p[i].sprzedaz);
    }
}
