//LINEAR SEARCH
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

void ls(int a[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        count++;
        if(a[i]==key)
        {
         printf("%d found at position %d\n",n,i);
         return;
        } 
    }
}

void main()
{
    int i,j;
    FILE *b,*w,*av;
    b=fopen("lsb.txt","a");
    w=fopen("lsw.txt","a");
    av=fopen("lsa.txt","a");
    for(i=10;i<50000;i=(i<10000)?i*10:i+10000)
    {
        int a[i];
        srand(time(NULL));
        for(j=0;j<i;j++)
          a[i]=rand()%i;
        //best case
        count=0;
        ls(a,i,a[0]);
        fprintf(b,"%d\t%d\n",i,count);
        //worst case
        count=0;
        ls(a,i,-99999);
        fprintf(w,"%d\t%d\n",i,count);
        //average case
        count=0;
        ls(a,i,rand()%i);
        fprintf(av,"%d\t%d\n",i,count);
    }
    fclose(b);
    fclose(w);
    fclose(av);
}
