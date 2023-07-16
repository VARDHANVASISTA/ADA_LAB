//FLOYD's ALGORITHM
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cnt=0;
int a[100][100],d[100][100];

int min(int a,int b)
{
    if(a<b)
      return a;
    else
      return b;
}

void floyd(int v)
{
    int i,j,k,temp;
    for(k=0;k<v;k++)
    {
       for(i=0;i<v;i++)
       {
           temp=d[i][k];
           {
               for(j=0;j<v;j++)
               {
                   cnt++;
                   if(d[i][j]>temp)  //*
                      d[i][j]=min(d[i][j],(temp+d[k][j]));
               }
           }
       }
    }
}

void correctness()
{
    int v,i,j;
    printf("enter the number of vertices\n");
    scanf("%d",&v);
    printf("enter the adjacency matrix\n");
    for(i=0;i<v;i++)
    {
        printf("enter weights of vertices adjacent to vertex:%d and -1 for vertices not adjacent\n",i+1);
        for(j=0;j<v;j++)
        {
           /*if(i==j)
             a[i][j]=0;
           else */
             scanf("%d",&a[i][j]);
           if(a[i][j]==-1)
             a[i][j]=9999;
           d[i][j]=a[i][j];
        }
    }
    floyd(v);
    printf("all-pairs shortest path matrix is:\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
           printf("%d   ",d[i][j]);
        }
        printf("\n");
    }
}

void analysis()
{
    int v,i,j;
    FILE *b=fopen("wb.txt","a");
    for(v=4;v<=8;v++)
    {
        srand(time(NULL));
        for(i=0;i<v;i++)
        {
           for(j=0;j<v;j++)
           {
              if(i==j)
                a[i][j]=0;
              else if((v%2)==0)
              {
                  if((i+j)%2==0)
                    a[i][j]=rand()%10;
                  else
                    a[i][j]=9999;
              }
              else
              {
                  if((i+j)%2==0)
                    a[i][j]=9999;
                  else
                    a[i][j]=rand()%10;
              }
              d[i][j]=a[i][j];
           }
        }
        cnt=0;
        floyd(v);
        fprintf(b,"%d\t%d\n",v,cnt);
    }
    fclose(b);
}

void main()
{
    int ch;
    for(;;)
    {
        printf("choices are:\n1:prove correctness\n2:show analysis\nenter your choice\n");
        scanf("%d",&ch);
        if(ch==1)
         correctness();
        else if(ch==2)
         analysis();
        else
         exit(1);
    }
}
