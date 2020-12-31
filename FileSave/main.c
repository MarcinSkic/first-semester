#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rekord
{
 char t[10];
 int w;
};
int main(int argc, char* argv[])
{
    FILE *p;
    struct rekord x;
    int wybor=1,i,j;
    printf("\t1.zalozenie bazy\n\t2.odczyt\n\t3.dopisanie\n\t0.koniec \n"); //\t tabulacja
    while(wybor)
    {
        printf("\nPodaj swoj wybor ");
        scanf("%d",&wybor);
        switch(wybor)
        {
            case 1:
                printf(" ile rekordów? ");
                scanf("%d", &j);
                p=fopen("wkj","wb");
                for (i=0; i<j; i++)
                {
                    fflush(stdin);
                    printf("tekst:");
                    gets(x.t);
                    printf("liczba:");
                    scanf("%d",&x.w);
                    fwrite(&x, sizeof(struct rekord), 1,p);
                }
                fclose(p);
                break;
            case 2:
                 p=fopen("wkj", "rb");
                 while ( !feof(p) )
                 {
                    if ( fread(&x,sizeof(struct rekord),1,p) )
                    printf("%s------%d\n",x.t, x.w);
                 }
                 fclose(p);
                 break;
            case 3:
                 p=fopen("wkj", "ab");
                 fflush(stdin);
                 printf("tekst:");
                 gets(x.t);
                 printf("liczba:");
                 scanf("%d",&x.w);
                 fwrite(&x, sizeof(struct rekord), 1,p);
                 fclose(p);
                 break;
            case 0:
                printf("KONIEC PROGRAMU\n");
                break;

        } // do switch
    } // do while
    return 0;
}
