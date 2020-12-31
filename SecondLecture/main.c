#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void Exercise1()
{
    float x,w;
    scanf("%f",&x);
    if(x>0)
    {
        w = 2*sqrt(x);
    } else
    {
        w = x+1;
    }
    printf("%.3f",w);
}
void Exercise2()
{
    float x,w;
    scanf("%f",&x);
    if(x<=0)
        w = sin(x) + cos(x);
    else if(x>1)
        w = 2*x;
    else
        w = sqrt(pow(x,3));
    printf("%.3f",w);

}
void Exercise3()
{
    float x,y,w;
    printf("Wpisz dwie liczby rzeczywiste x i y(.../...)\n");
    scanf("%f/%f",&x,&y);
    if(y>0)
        w = x+sqrt(y);
    else
        w = x+y;

    printf("%f\n",w);

    if(x == -2*y)
        w = -x;
    else
        w = (2*x+y)/(x+2*y);

    printf("%f",w);

}
void Exercise4()
{
    float pensja = 1000,premia,brutto;
    if(pensja > 2000)
        brutto = pensja*0.8;
    else
        brutto = pensja*0.9;

    printf("Wyplata brutto: %.2f",brutto);
}
void Exercise5()
{
    float cenaHurtowa = 5,kosztKlienta;
    int iloscTowaru = 120,x,decision;
    char decyzja;
    bool badDecision = true;
    printf("Ile towaru chce pan/pani zamowic?\n");
    scanf("%i",&x);
    if(iloscTowaru < x)
    {
        printf("Niestety brakuje nam towaru na skladzie ale mamy: %i towaru, czy chce pan/pani zamowic? (Tak - 1/Nie - 0)\n",iloscTowaru);


        while(badDecision)
        {
            fflush(stdin);
            scanf("%c",&decyzja);

            switch(decyzja){
            case 'T':
                x = iloscTowaru;
                badDecision = false;
                break;

            case 'N':
                printf("Dziekujemy za skorzystanie z naszego magazynu");
                badDecision = false;
                break;
            default:
                printf("Zly wybor, prosze podac jeszcze raz\n");
            }
        }
    }
    if(x<100)
    {
        kosztKlienta = x*5*1.2;

    }
    else
    {
        kosztKlienta = x*5;
    }
    printf("Zaplaci pan/pani: %f",kosztKlienta);

}
int main()
{
    Exercise5();
    return 0;
}
