#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float *Input();

int main()
{
    Exercise2(Input());
    return 0;
}
float *Input()
{
    int n;
    float *p;
    printf("Podaj wielkosc tablicy: ");
    scanf("%d",&n);

    float x[n+1];
    x[0] = n;
    for(int i = 0; i < n;i++)
    {
        printf("Podaj element %d tablicy: ",i+1);
        scanf("%f",&x[i+1]);
    }
    p = &x[0];

    return p;
}
void Exercise1(float *p)
{
    int length = p[0];
    float suma;
    bool anyNumberAdded = false;

    for(int i = 0; i < length;i++)
    {
        if(p[i+1]<p[1]+p[length])
        {
            suma += p[i+1];
            anyNumberAdded = true;
        }
    }
    if(anyNumberAdded){
        printf("%.3f",suma);
    } else {
        printf("Suma rowna zero");
    }
}
void Exercise2(float *x)
{
    int n = x[0];
    printf("%f, ",x[1]);
    for(int i = 0; i < n;i++)
    {
        if(x[i+1] < 0){
            x[i+1] = 0;
        }
    }

    printf("%f, ",*x);

    for (int i = 0; i < n ; i++){
        printf("%.0f ",x[i+1]);
    }
}

/*void Exercise3(float *x){

    int n;
    float suma = 0;
    bool anyNumberAdded = false;

    printf("Podaj wielkosc tablicy: ");
    scanf("%d",&n);

    float x[n];
    float y[n];

    for(int i = 0; i < n;i++)
    {
        printf("Podaj element %d tablicy: ",i+1);
        scanf("%f",&x[i]);
        y[i] = x[i]*x[i];
    }
    /*for(int i = 0; i < n;i++){
        y[i] = x[i]*x[i];
    }
    for (int i = 0; i < n ; i++){
        printf("%.0f ",y[i]);
    }
}
void Exercise4(float *x){
    int n;
    float suma = 0,max;
    bool anyNumberAdded = false;

    printf("Podaj wielkosc tablicy: ");
    scanf("%d",&n);

    float x[n];
    float y[n];

    for(int i = 0; i < n;i++)
    {
        printf("Podaj element %d tablicy: ",i+1);
        scanf("%f",&x[i]);

        if(i == 0){
            max = x[0];
        }

        if(max < x[i]){
            max = x[i];
        }
    }

    /*for (int i = 0; i < n;i++){
        if(max < x[i]){
            max = x[i];
        }
    }
    printf("%.0f",max);*/
//}
