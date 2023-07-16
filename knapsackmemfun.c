//KNAPSACK PROBLEM USING MEMORY FUNCTION
#include <stdio.h>
#include <stdlib.h>

int V[100][100], val[100], wt[100],n,W,i,j;

int max(int a, int b)
{
	return (a>b) ? a : b;
}

void initialize(int n,int W)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0||j==0)
             V[i][j]=0;
            else
             V[i][j]=-1;
        }
    }
}

void optimal(int n,int W)
{
    int rc=W;
    j=0;
    printf("Optimal set is: { \n");
	for(i=n;i>0;i--)
	{
		if (V[i][rc] != V[i-1][rc])
		{
			printf("%d, ",i);
			rc-=wt[i];
		}
		if (rc==W) break;
	}
    printf("}\n");
}


int knapsack(int i, int j)
{
	if (V[i][j]==-1)
	{
		if (j<wt[i])
			V[i][j] = knapsack(i-1,j);
		else
			V[i][j] = max(knapsack(i-1,j),val[i]+knapsack(i-1,j-wt[i]));
	}
	return V[i][j];

}

void main()
{
	printf("Enter the number of items\n ");
	scanf("%d",&n);
	printf("Enter the weight and valueof each item\n");
	for(i=1;i<n+1;i++)
		scanf("%d\t%d",&wt[i],&val[i]);
	printf("Enter the knapsack capacity\n ");
	scanf("%d",&W);
	initialize(n+1,W+1);
	printf("Maximum value: %d\n",knapsack(n+1,W+1));
	optimal(n+1,W+1);
}
