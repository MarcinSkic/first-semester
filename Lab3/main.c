#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float * Input();
void Exercise1();
void Exercise2();
void Exercise3();
void Exercise4();
void Exercise5();
void Exercise6();
void Test();
int main()
{
    Test();
}
float * InputArrayNumbers(int count)
{
    float x;

    float *numbers = malloc(count);
    if(!numbers)
        return NULL;

    for(int i = 0;i < count;i++)
    {
        printf("Podaj liczbe %d: ",i+1);
        scanf("%f" , &x);
        numbers[i] = x;
    }

    return numbers;
}
void Test()
{
    int n;

    printf("Prosze podac ile liczb zamierzasz podac: ");
    scanf("%d",&n);

    float *p = InputArrayNumbers(n);

    printf("Got here\n");

    printf("%f",p[0]);

    free (p);
}
void Exercise1()
{
    /*float *p;
    p = Input();*/
    int n;

    printf("Prosze podac ile liczb zamierzasz podac: ");

    scanf("%d",&n);

    float s;
    float x;
    float numbers[n];



    for(int i = 0;i < n;i++)
    {
        printf("Podaj liczbe %d: ",i+1);
        scanf("%f" , &x);
        s += pow(x,2);
    }

    printf("%f",s);

    /*for(int i;i < n; i++)
    {
        printf("%f" , &numbers[i]);
    }*/
}
void Exercise2()
{
    int n;

    printf("Prosze podac ile liczb zamierzasz podac: ");

    scanf("%d",&n);

    float s,x,amount;
    float numbers[n];



    for(int i = 0;i < n;i++)
    {
        printf("Podaj liczbe %d: ",i+1);
        scanf("%f" , &x);
        if(x < 0)
        {
            s+=x;
            amount++;
        }
    }
    if(amount != 0)
    {
        s /= amount;
        printf("%f",s);
    }
    else
    {
        printf("Brak liczb ujemnych");
    }



}
void Exercise3()
{
    int n;

    printf("Prosze podac ile liczb zamierzasz podac: ");

    scanf("%d",&n);

    float s,x;
    float numbers[n];



    for(int i = 0;i < n;i++)
    {
        printf("Podaj liczbe %d: ",i+1);
        scanf("%f" , &x);
        if(x >= 0 && x <= 10)
        {
            s += x;
        }
    }

    printf("%f",s);
}
void Exercise4()
{
    int n;

    printf("Prosze podac ile liczb zamierzasz podac: ");

    scanf("%d",&n);

    float s = 1,x;
    float numbers[n];



    for(int i = 0;i < n;i++)
    {
        printf("Podaj liczbe %d: ",i+1);
        scanf("%f" , &x);
        if(i % 2 == 0)
        {
            s *= x;
        }
    }
    printf("%f",s);
}
void Exercise5()
{
    int n,temp;

    printf("Prosze podac ile liczb zamierzasz podac: ");

    scanf("%d",&n);

    float sNieParz = 0 , sParz = 0 ,x;
    float numbers[n];



    for(int i = 0;i < n;i++)
    {
        printf("Podaj liczbe %d: ",i+1);
        scanf("%f" , &x);
        temp = x;
        if(temp % 2 == 0)
        {
            sParz += x;
        }
        else
        {
            sNieParz += x;
        }
    }
    printf("Suma liczb parzystych: %f\n",sParz);
    printf("Suma liczb nieparzystych: %f",sNieParz);

}
void Exercise6()
{
    int n,badNumbers = 0;

    printf("Prosze podac ile liczb zamierzasz podac: ");

    scanf("%d",&n);

    float x,r,previousCorrectNumber;  //r - roznica ciagu, badNumbers - liczba nie pasujacych

    float numbers[n];



    for(int i = 0;i < n;i++)
    {

        printf("Podaj liczbe %d: ",i+1);
        scanf("%f" , &x);
        if (i == 0)
        {
            previousCorrectNumber = x;
        }
        else if(i == 1)
        {
            r = x - previousCorrectNumber;
            previousCorrectNumber = x;
        }
        else
        {
            if(r != x - previousCorrectNumber)
            {
                badNumbers++;
                printf("Zla liczba!\n");
            }
            else
            {
                previousCorrectNumber = x;
            }

        }

    }
    if (badNumbers == 0)
    {
        printf("Jest to ciag arytmetyczny");
    }
    else
    {
        printf("Jest %d zlych liczb czyli to nie jest ciag arytmetyczny",badNumbers);
    }
}
