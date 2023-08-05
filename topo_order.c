//TOPOLOGICAL ORDERING
#include<stdio.h>
#include<stdlib.h>
int visited[50],path[50],stack[50],top=-1,graph[50][50],flag,n;
void dfs(int n,int start,int parent)
{
    visited[start]=1;
    path[start]=1;
    for(int i=0;i<n;i++)
    {
        if(i!=parent && visited[i] && path[i] && graph[start][i])
        {
            flag=1;
            return;
        }
        if(visited[i]==0 && graph[start][i])
        dfs(n,i,start);
    }
    path[start]=0;
    stack[++top]=start;
}
void correctness()
{
    printf("Enter the Number of Vertices : ");
    scanf("%d",&n);
    printf("Enter the Adjacency Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
        visited[i]=0;
        path[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            dfs(n, i,-1);
    }
    if(flag)
    printf("Cycle Exists No Solution\n");
    else
    {
        printf("\nTopological Order:\n");
        for(int i=top;i>=0;i--)
        printf("%c---->\t",stack[i]+65);
    }
}

void analysis()
{
    WHILE RUNNING FOR PLOTING COMMENT OUT THE PRINTF INSIDE THE DFS FUNCTION
    FILE *fp=fopen("plot.txt","w");
    for(int m=2;m<=15;m++)
    {
        graphcount=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
            if(i==j)
            graph[i][j]=0;
            else
            graph[i][j]=1;
            }
        visited[i]=0;path[i]=0;
        }
        for(int i=0;i<m;i++)
        {
           if(visited[i]==0)
              dfs(m,i,-1);
        }
        fprintf(fp,"%d\t\t%d\n",m,graphcount);
    }
    fclose(fp);
}
void main()
{
  int ch;
  printf("1:Correctness\n"2:Analysis\nEnter your choice\n");
  scanf("%d",&ch);
  if(ch==1)
    correctness();
  else if(ch==2)
    analysis();
  else
    exit(1);
}   
