#include <stdio.h>
#include <stdlib.h>
float Funkcja1(int n,float x[],float *il);
float Funkcja2(int n,float x[],int *sred);
void Funkcja3(int n,float x[],int *changes);
void PrintArray(int N, float array[]);

int main()
{
    int n;
    float *p;
    printf("Podaj wielkosc tablicy: ");
    scanf("%d",&n);

    float x[n];
    for(int i = 0; i < n;i++)
    {
        printf("Podaj element %d tablicy: ",i+1);
        scanf("%f",&x[i]);
    }

    float iloczyn;
    int amount = 0;
    int changes = 0;

    printf("\nZadanie 1\n");
    printf("Suma liczb dodatnich: %f\n",Funkcja1(n,x,&iloczyn));
    printf("Iloczyn wszystkich liczb: %f\n",iloczyn);
    printf("\nZadanie 2\n");
    printf("Srednia arytmetyczna: %f\n",Funkcja2(n,x,&amount));
    printf("Ilosc liczb wiekszych od sredniej: %d\n",amount);
    Funkcja3(n,x,&changes);
    printf("\nZadanie 3\n");
    printf("Zmieniona tablica: ");
    PrintArray(n,x);
    printf("\nIlosc zastapien: %d",changes);
    printf("\n");    //Dla ladnego zakonczenia


}
float Funkcja1(int n,float x[],float *il){

    float iloczyn = 1;
    float sumDodatnich = 0;

    for(int i = 0; i < n;i++){
        if(x[i] > 0){
            sumDodatnich += x[i];
        }
        iloczyn *= x[i];
    }

    *il = iloczyn;
    return sumDodatnich;
}
float Funkcja2(int n,float x[],int *amount){

    float sum = 0,sr = 0;

    for(int i = 0; i < n; i++){
        sum += x[i];
    }
    sr = sum/n;

    for(int i = 0; i < n; i++){
        if(x[i] > sr){
            (*amount)++;
        }
    }
    return sr;
}
void Funkcja3(int n,float x[],int *changes){

    for(int i = 0; i < n; i++){
        if(x[i] < 0){
            x[i] = 0;
            (*changes)++;
        }
    }
}
void PrintArray(int N, float array[]){
    printf("[");
    for(int i = 0; i < N; i++){

        if(i != 0){
            printf(", ");
        }
        printf("%f",array[i]);
    }
    printf("]");
}
