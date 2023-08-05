//BFS
 #include <stdio.h> 
 #include <stdlib.h> 
 int graph[50][50], visited[50], path[50], isCyclic, d, path[50]; 
 int count, bfscall; 
 void bfs(int n, int start) 
 { 
     int queue[n], parent[n], parentnode, r = -1, f = -1; 
     visited[start] = 1; 
     queue[++r] = start; 
  
     parent[r] = -1; 
  
     count++; 
     while (r != f) 
     { 
         start = queue[++f]; 
  
         path[start] = 1; 
         parentnode = parent[f]; 
         printf("%c---->", start + 65); 
         for (int i = 0; i < n; i++) 
         { 
             if (d == 1) 
             { 
                 if (i != parentnode && visited[i] && graph[start][i] && path[i]) 
                     isCyclic = 1; 
             } 
             else 
             { 
                 if (i != parentnode && visited[i] && graph[start][i]) 
                     isCyclic = 1; 
             } 
             if (visited[i] == 0 && graph[start][i]) 
             { 
                 queue[++r] = i; 
                 parent[r] = start; // NOT parent node; 
                 visited[i] = 1; 
                 count++; 
             } 
         } 
         path[start] = 0; 
     } 
  
 } 
 void correctness() 
 { 
     int n; 
     printf("Enter the Number of Vertices : "); 
     scanf("%d", &n); 
     printf("Enter 1 if Graph is Directed Else 0 : "); 
     scanf("%d", &d); 
     printf("Enter the Adjacency Matrix\n"); 
     for (int i = 0; i < n; i++) 
     { 
         for (int j = 0; j < n; j++) 
         { 
             scanf("%d", &graph[i][j]); 
         } 
         visited[i] = 0; 
         path[i] = 0; 
     } 
     isCyclic = 0; 
     bfs(n, 0); 
     bfscall++; 
     if (isCyclic) 
         printf("\nGraph is Cyclic\n"); 
     else 
         printf("\nGraph is Acyclic\n"); 
     if (count == n) 
         printf("Graph is Connected\n"); 
     else 
     { 
         printf("Graph is NOT Connected\n"); 
         int start = 1; 
         while (count != n) 
         { 
             if (visited[start] == 0) 
             { 
                 printf("\n"); 
                 bfs(n, start); 
                 bfscall++; 
             } 
             start++; 
         } 
     } 
     printf("Number Of Connected Componenets is %d\n", bfscall); 
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
        bfs(m,0);
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
