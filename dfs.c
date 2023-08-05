//DFS
#include<stdio.h>
#include<stdlib.h>
int visited[50],path[50],d,graph[50][50],iscyclic,count,dfscall,graphcount;
void dfs(int n,int start,int parent)
{
    visited[start]=1; path[start]=1;
    count++;
    printf("%c---->",start+65);
    for(int i=0;i<n;i++)
    {
        if(d==1)
        {
            if(i!=parent && visited[i] && graph[start][i] && path[i])
            iscyclic=1;
        }
        else
        {
            if(i!=parent && visited[i] && graph[start][i])
            iscyclic=1;
        }
        graphcount++;
        if(visited[i]==0 && graph[start][i])
        {
            dfs(n,i,start);
        }
    }
    path[start]=0;
}
void analysis()
{
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
        dfs(m,0,-1);
        fprintf(fp,"%d\t\t%d\n",m,graphcount);
    }
    fclose(fp);
}
  void correctness()
{
    printf("Enter the Number of vertices : ");int n,start;scanf("%d",&n);
    printf("Enter 1 if the Graph is Directed else 0 :");scanf("%d",&d);
    printf("Enter the Adjacency Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        scanf("%d",&graph[i][j]);
        visited[i]=0;path[i]=0;
    }
    dfs(n,0,-1);
    dfscall++;
    if(iscyclic)
    printf("\nGraph is Cyclic\n");
    else
    printf("\nGraph is Acyclic\n");
    if(count==n)
    printf("Graph is Connected\n");
    else
    {
        printf("Graph is NOT Connected\n");
        while(count!=n)
        {
            start=1;
            if(visited[start]==0)
            {
                printf("\n");
                dfs(n,start,-1);
                dfscall++;
            }
            start++;
        }
    }
    printf("\nNumber of Conned Componenets is : %d\n",dfscall);
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
  
