//BINARY SEARCH
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

void bs(int a[],int n,int l,int h,int key)
{
    int i,mid;
    count++;
    mid=(l+h)/2;
    if(a[mid]==key)
    {
     printf("%d is found at position:%d\n",key,mid);
     return;
    }
    if(a[mid]>key)
       bs(a,n,mid+1,h,key);
    else
       bs(a,n,l,mid-1,key);
}

void main()
{
    int i,j,l,h;
    FILE *b,*w,av;
    b=fopen("bsb.txt","a");
    w=fopen("bsw.txt","a");
    av=fopen("bsa.txt","a");
    for(i=10;i<=50000;i=(i<10000)?i*10:i+10000)
    {
        int a[i];
        srand(time(NULL));
        for(j=0;j<i;j++)
          a[i]=i+1;
        l=0;
        h=i-1;
        //best case
        count=0;
        int key=a[(l+h)/2];
        bs(a,i,l,h,key);
        fprintf(b,"%d\t%d\n",i,count);
        //worst case
        count=0;
        key=a[0];
        bs(a,i,l,h,key);
        fprintf(w,"%d\t%d\n",i,count);
        average case
        count=0;
        bs(a,i,l,h,(rand()%i));
        fprintf(av,"%d\t%d\n",i,count);
    }
    fclose(b);
    fclose(w);
    fclose(av);
}
