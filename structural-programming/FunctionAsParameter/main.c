#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void F(char text[],int n, float arr[],float funkcja(int n,float x[])){
    printf("%s\n",text);
    printf("%f",funkcja(n,arr));
}
float S(int n,float arr[]){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}
float SR(int n, float arr[]){
    float sr = 0;
    for(int i = 0; i < n; i++){
        sr += arr[i];
    }
    sr /= n;
    return sr;
}
float IL(int n, float arr[]){
    float il = 1;
    for (int i = 0; i < n; i++){
        il *= arr[i];
    }
    return il;
}
int main()
{
    int n,option;
    char text[10];

    printf("Podaj wielkosc tablicy: ");
    scanf("%d",&n);

    float x[n];

    for(int i = 0; i < n;i++)
    {
        printf("Podaj element %d tablicy: ",i+1);
        scanf("%f",&x[i]);
    }

    fflush(stdin);
    printf("Wpisz tekst: ");
    gets(text);

    if(!strcmp(text,"suma")){
        option = 0;
    } else if(!strcmp(text,"srednia")){
        option = 1;
    } else if(!strcmp(text,"iloczyn")){
        option = 2;
    } else {
        printf("Zly tekst");
        return 0;
    }

    switch (option){
    case 0:
        F(text,n,x,S);
        break;
    case 1:
        F(text,n,x,SR);
        break;
    case 2:
        F(text,n,x,IL);
        break;
    default:
        printf("Nie mam pojecia jak program mogl sie tutaj dostac");
        break;
    }

}
