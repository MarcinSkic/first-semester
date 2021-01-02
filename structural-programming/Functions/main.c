#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sumaWierszy(int rowLength,float row[]);
float D(float a,float b, float c);
float F4(int N, float x[]);
void F5(int N, float x[],float y[],float z[]);
int F6(int N, float x[],float y[],float z[]);
void PrintArray(int N, float array[]);

int main()
{
    int size,rows,columns;

    printf("Podaj wielkosc tablic jak chcesz stworzyc: ");
    scanf("%d",&size);

    float x[size],y[size],z[size];

    for(int i = 0; i < size;i++){
        printf("Podaj %d element tablicy x: ",i+1);
        scanf("%f",&x[i]);
    }

    for(int i = 0; i < size;i++){
        printf("Podaj %d element tablicy y: ",i+1);
        scanf("%f",&y[i]);
    }

    printf("Zadanie 3:\nDelta = %f\n",D(4,4,-4));

    printf("Zadanie 4:\nSuma dodatnich liczb tablicy: %f\n",F4(size,x)); //dodac zabezpieczenie w razie 0

    F5(size,x,y,z);
    printf("Zadanie 5:\nTablica Z(czyli z = x + y): ");
    PrintArray(size,z);

    int xAmount = F6(size,x,y,z);
    printf("\nZadanie 6:\nTablica wejsciowa x: ");
    PrintArray(size,x);
    printf("\nTablica y (czyli y = x^2: ");
    PrintArray(size,y);
    printf("\nTablica z (czyli z = x^3: ");
    PrintArray(size,z);
    printf("\nIlosc x dodatnich: %d\n",xAmount);

    printf("Dodatkowe zadanie\n");
    printf("Podaj ilosc wierszy: ");
    scanf("%d",&rows);
    printf("Podaj ilosc kolumn: ");
    scanf("%d",&columns);

    float array2D [rows][columns];

    for(int i = 0; i < rows;i++){
        for(int x = 0; x < columns;x++){
            printf("Podaj element w wierszu %d kolumnie %d: ",i+1,x+1);
            scanf("%f",&array2D[i][x]);
        }
    }

    printf("Podaj który wiersz chcesz zsumowaæ: ");

    printf("%f",sumaWierszy(columns,array2D[0]));
}

float sumaWierszy(int rowLength,float row[]){

    float suma = 0;
    for(int i = 0; i < rowLength; i ++){
        suma += row[i];
    }

    return suma;
}

float D(float a,float b, float c){
    return (b*b)-(4*a*c);
}

float F4(int N,float x[]){

    float suma = 0;

    for(int i = 0; i < N; i++){
        if(x[i] > 0){
            suma += x[i];
        }
    }
    return suma;

}

void F5(int N, float x[],float y[],float z[]){
    for(int i = 0; i < N;i++){
        z[i] = x[i] + y[i];
    }
}
int F6(int N, float x[],float y[],float z[]){

    int amount = 0;
    for(int i = 0; i < N; i++){
        y[i] = pow(x[i],2);
        z[i] = pow(x[i],3);
        if(x[i] > 0){
            amount++;
        }
    }

    return amount;
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
