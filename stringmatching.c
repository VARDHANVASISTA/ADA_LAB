//STRING MATCHING
#include<stdio.h>
#include<stdlib.h>

int count=0;

void sm(char *t,char *p,int n,int m)
{
    int i,j;
    for(i=0;i<n-m;i++)
    {
        j=0;
        while(j<m)
        {
            count++;
            if(*(p+j) == *(t+i+j))
               j++;
            else
            {
                printf("Not matched\n");
                return;
            }
        }
    }
    printf("Matched\n");
}

void correctness()
{
    char *p,t[10];
    int i,j;
    for(i=0;i<10;i++)
      t[i]='a';
    for(i=1;i<=10;i++)
    {
        p=(char *)malloc(i*sizeof(char));
        printf("enter a pattern of length: %d\n",i);
        scanf("%s",p);
        sm(t,p,10,i);
    }
}

void analysis()
{
    FILE *b,*w;
    int i,j;
    char t[1000],*p;
    b=fopen("smb.txt","a");
    w=fopen("smw.txt","a");
    for(i=0;i<1000;i++)
      t[i]='a';
    for(i=10;i<1000;i=(i<100)?i+10:i+100)
    {
        p=(char *)malloc(i*sizeof(char));
        //BEST CASE
        for(j=0;j<i;j++)
          p[j]='a';
        count=0;
        sm(t,p,1000,i);
        fprintf(b,"%d\t%d\n",i,count);
        //WORST CASE
        for(j=0;j<i-1;j++)
          p[j]='a';
        p[j]='b';
        count=0;
        sm(t,p,1000,i);
        fprintf(w,"%d\t%d\n",i,count);
    }
    fclose(b);
    fclose(w);
}

void main()
{
    int ch;
    for(;;)
    {
        printf("choices are:\n1:show correctness\n2:give analysis\nEnter your choice\n");
        scanf("%d",&ch);
        if(ch==1)
          correctness();
        else if(ch==2)
          analysis();
        else
          exit(1);
    }
}
