#include <stdio.h>
#include <stdlib.h>
int *copyToNX(int *x,int n,int *am);
int main()
{
    int n,amount = 0,*x,*temp ;
    printf("Podaj ilosc elementow tablicy: ");
    scanf("%d",&n);
    x = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n;i++){
        printf("Element %d: ",i+1);
        scanf("%d",x+i);
    }

    temp = copyToNX(x,n,&amount);

    printf("\n");
    for(int i = 0; i < amount;i++){
        printf("%d liczba spelniajaca warunek: %d\n",i+1,temp[i]);
    }
}
int *copyToNX(int *x,int n,int *am){
    int *NX;
    NX = (int*)malloc(sizeof(int));
    for(int i = 0; i < n;i++){
        if(x[i]>=1 && x[i]<=10){
            NX[*am] = x[i];
            (*am)++;
            NX=(int*)realloc(NX, ((*am)+1)*sizeof(int));
        }
    }
    return NX;

}
