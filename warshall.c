//WARSHALL's ALGORITHM
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cnt=0;
int a[100][100],tc[100][100];

void warshall(int v)
{
    int i,j,k;
    for(k=0;k<v;k++)
    {
       for(i=0;i<v;i++)
       {
           cnt++;
           if(tc[i][k]==1)
           {
               for(j=0;j<v;j++)
               {
                   cnt++;
                   tc[i][j]=(tc[i][j]||(tc[i][k]&&tc[k][j]));
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
        printf("enter 1 for vertices adjacent to vertex:%d and 0 for vertices not adjacent\n",i+1);
        for(j=0;j<v;j++)
        {
           scanf("%d",&a[i][j]);
           tc[i][j]=a[i][j];
        }
    }
    warshall(v);
    printf("transitive closure is:\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
           printf("%d   ",tc[i][j]);
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
              if((v%2)==0)
              {
                  if((i+j)%2==0)
                    a[i][j]=1;
                  else
                    a[i][j]=0;
              }
              else
              {
                  if((i+j)%2==0)
                    a[i][j]=0;
                  else
                    a[i][j]=1;
              }
              tc[i][j]=a[i][j];
           }
        }
        cnt=0;
        warshall(v);
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
