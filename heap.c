//HEAP SORT
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int countd=0;

void heapify(int h[],int n,int i)
{
    while(1)
    {
        int lg=i,lt=2*i,rt=2*i+1;
        if(lt<=n)
        {
            countd++;
            if(h[lt]>h[rt])
            lg=lt;
        }
        if(rt<=n)
        {
            countd++;
            if(h[rt]>h[lt])
            lg=rt;
        }
        if(lg!=i)
        {
            int temp=h[i];
            h[i]=h[lg];
            h[lg]=temp;
            i=lg;
        }
        else
            break;
    }
}

void delete(int h[],int n)
{
    int i=n;
    while(i!=0)
    {
        h[1]=h[i-1];
        i--;
        heapify(h,i,1);
    }
}

void sort(int h[], int n)
{
   int i,pi,pv,heap,ci;
   for(i=n/2;i>=1;i--)
   {
       pi=i;pv=h[pi];heap=0;
       while(!heap && (2*pi)<=n)
       {
           ci=2*pi;
           if(ci<n)
           {
               count++;
               if(h[ci+1]>h[ci])
                 ci+=1;
           }
           count++;
           if(pv>h[ci])
             heap=1;
           else
           {
               h[pi]=h[ci];
               pi=ci;
           }
       }
       h[pi]=pv;
   }
   delete(h,n);
}

void main()
{
    srand(time(NULL));
    FILE *a, *b, *w;
    a = fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");
    int n;
    for(int n = 100; n<10000; n=(n<1000)?n+100:n+1000)
    {
       int arr[n+1];

        // best case
        count=0;
        countd=0;
        for(int i = 1; i<=n; ++i)
            arr[i] = n-i;
        sort(arr, n+1);
        fprintf(b, "%d  %d  %d\n", n,count,countd);
        
        // worst case
        count=0;
        countd=0;
        for(int i = 1; i<=n; ++i)
            arr[i] = i+1;
        sort(arr, n+1);
        fprintf(w, "%d  %d  %d\n", n, count,countd);

        // avg case
        count=0;
        countd=0;
        for(int i = 1; i<=n; ++i)
            arr[i] = rand()%100;
        sort(arr, n+1);
        fprintf(a, "%d  %d  %d\n", n, count,countd);
        
    }
    fclose(a);  fclose(b);  fclose(w);
}
