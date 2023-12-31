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
    int i=n-1;
    while(i!=0)
    {
        h[1]=h[i];
        i--;
        printf("%d id deleted\n",h[1]);
        heapify(h,i+1,1);
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
}

void analysis()
{
    srand(time(NULL));
    FILE *a, *b, *w,*ad,*bd,*ad;
    a = fopen("ha.txt", "a");
    b = fopen("hb.txt", "a");
    w = fopen("hw.txt", "a");
    ad = fopen("hda.txt", "a");
    bd = fopen("hdb.txt", "a");
    wd = fopen("hdw.txt", "a");
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
        delete(arr,n+1);
        fprintf(b, "%d  %d\n", n,count);
        fprintf(bd, "%d  %d\n", n,countd);
        
        // worst case
        count=0;
        countd=0;
        for(int i = 1; i<=n; ++i)
            arr[i] = i+1;
        sort(arr, n+1);
         delete(arr,n+1);
        fprintf(w, "%d  %d\n", n, count);
        fprintf(wd, "%d  %d\n", n,countd);
        
        // avg case
        count=0;
        countd=0;
        for(int i = 1; i<=n; ++i)
            arr[i] = rand()%100;
        sort(arr, n+1);
         delete(arr,n+1);
        fprintf(a, "%d  %d\n", n, count);
        fprintf(ad, "%d  %d\n", n,countd);
        
    }
    fclose(a);  fclose(b);  fclose(w);
}

void correctness()
{
       int n,i;
       printf("Enter the size of heap\n");
       scanf("%d",&n);
       int h[n+1];
       for(i=1;i<=n;i++)
         scanf("%d",&h[i]);
       sort(h,n+1);
       printf("Heapified version:\n");
       for(i=1;i<=n;i++)
           printf("%d   ",h[i]);
        printf("\n");
         delete(h,n+1);
}

void main()
{
    int ch;
    printf("Enter your choice\n"1:Correctness\n2:Analysis\n");
     scanf("%d",&ch);
    if(ch==1)
        correctness();
    else if(ch==2)
        analysis();
    else
        exit(1);
}

            
