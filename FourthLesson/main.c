#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
int main()
{
    Exercise3();
}
void Exercise1()
{
    float A, B, K;
    printf("Podaj przedzia³ (.../...): ");
    scanf("%f/%f",&A,&B);
    printf("Podaj krok: ");
    scanf("%f",&K);
    while(B-A>=0)
    {
        printf("Wynik: %.1f ",pow(A,2)+A+1);
        A += K;
    }
}
void Exercise2()
{
    float p = 0.05, X, targetMoney;
    int i = 0;

    printf("Prosze podac wplacana kwote: ");
    scanf("%f",&X);
    targetMoney = X*2;

    do{
        X *= 1+(p/2);
        i++;
    } while(X < targetMoney);
    printf("Wyplata: %f, liczba odnowien: %d",X,i);
}
void Exercise3()
{
    bool itWasZero = false;
    int iloscDodatnich = 0;
    int iloscUjemnych = 0;
    int granicaDzialania = 20;
    int i = 1;
    float sumaDodatnich = 0;
    float sumaUjemnych = 0;
    float temp;

    do{
        if(itWasZero)
        {
            itWasZero = false;
        }

        printf("Podaj %d liczbe: ",i);
        scanf("%f",&temp);

        if(temp < 0.0){
            sumaUjemnych += temp;
            iloscUjemnych++;
            i++;
        } else if(temp > 0.0)
        {
            sumaDodatnich += temp;
            iloscDodatnich++;
            i++;
        } else
        {
            printf("To bylo zero, podaj jeszcze raz!\n");
            itWasZero = true;
        }
    }while(((iloscDodatnich != iloscUjemnych) && (granicaDzialania != iloscDodatnich+iloscUjemnych)) || itWasZero);

    printf("Suma dodatnich: %f, Suma ujemnych: %f",sumaDodatnich,sumaUjemnych);
}
