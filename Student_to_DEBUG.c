//should be debugged
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct selector
{
    int no_stu,no_cour;
    struct studentdetails *SL;
    struct coursedetails *CL;
    
};
typedef struct selector *SN;

struct studentdetails
{
    char name[50],branch[30],USN[12];
    int regno,semester,ncourses;
    char course[20];
    struct studentdetails *RL;
    struct studentdetails *LL;

};
typedef struct studentdetails *SD;

struct coursedetails
{
 char cname[50],ccode[10];
    int credits,nstudents;
    struct coursedetails *rl;
    struct studentdetails *ll;
   
};
typedef struct coursedetails *CD;

SN createnode()
{
    SN NN;
    NN=(SN)malloc(sizeof(struct selector));
    
    return NN;

}

CD createcrnode()
{
    CD NN;
    NN=(CD)malloc(sizeof(struct coursedetails));
    
    return NN;

}
SD createstnode()
{
    SD NN;
    NN=(SD)malloc(sizeof(struct studentdetails));
    
    return NN;

}
void courselist(SN PH,int CA)
{ 
    int i;
    CD ncd,TP;
    for (i=1;i<=CA;i++)
    {
     ncd=createcrnode();
     printf("enter course name\n");
     scanf("%s",ncd->cname);
     printf("enter course code\n");
     scanf("%s",ncd->ccode);
     printf("enter number of credits\n");
     scanf("%d",&ncd->credits);
     ncd->nstudents=0;
     if(i==1)
     {
         PH->CL=ncd;
         TP=ncd;
     }
     else
       {
         TP->rl=ncd;
         TP=ncd;
         if(i==CA)
          ncd->rl=NULL;
       }
       PH->no_cour++;
    }
         
}
void Registerdetails(SN PH,int SR)
{
    int i,j,t;
    SD TP,sd,CP,crn,chkp,cdt;
    CD ctp;
    
    printf("Enter %d students details\n",SR);
    for(i=1;i<=SR;i++)
    {
      
      printf("Enter details of student %d\n",i);  
      printf("--------------------------------------\n");
      sd=createstnode();
      sd->LL=NULL;sd->RL=NULL;
      printf("enter name\n");
      scanf("%s",sd->name);
      printf("enter branch\n");
      scanf("%s",sd->branch);
      if(i==1)
      {
          PH->SL=sd;
          TP=sd;
          
      }
      else
      {
          TP->LL=sd;
      }
      Z:printf("Enter USN:\n");
      scanf("%s",sd->USN);
      if(i!=1)
      {
        CP=PH->SL;
        while(CP!=NULL)
        {
           if(strcmp(CP->USN,sd->USN)==0)
           {
               printf("USN CANNOT BE SAME FOR MORE THAN ONE STUDENT-YOUR USN MATCHES WITH THE USN OF OTHER STUDENT-ENTER YOUR OWN USN\n");
               goto Z;
           }
           CP=CP->LL;
        }
      }
     printf("enter current semester\n");
     scanf("%d",&sd->semester);
     sd->regno=i;
     TP=sd;
     A:printf("enter number of courses you would like to register for:  (NOTE:student can register for a maximum of 10 courses and minimum can be zero)\n");
     scanf("%d",&sd->ncourses);
     if(sd->ncourses<0 || sd->ncourses>10)
     {
        printf("invalid entry-enter again\n");
        goto A;
     }
     if(sd->ncourses==0)
      return;
     //display course names
     printf("enter course name to register\n");
     for(j=1;j<=sd->ncourses;j++)
     {
        crn=createstnode();
        crn->LL=NULL;
        strcpy(crn->name,sd->name);
        strcpy(crn->branch,sd->branch);
        strcpy(crn->USN,sd->USN);
        crn->semester=sd->semester;
        crn->regno=sd->regno;
        crn=TP->RL;
        ctp=PH->CL;
        Y:printf("enter course\n");
        scanf("%s",crn->course);
        if(j!=1)
        {
            chkp=TP->RL;
            while(chkp!=NULL)
            {
                if(strcmp(chkp->course,crn->course)==0)
                {
                    printf("you have already registered for this course-enter any other\n");
                    goto Y;
                }
                chkp=chkp->RL;
            }
        }
        while(ctp!=NULL)
        {
            if(strcmp(ctp->cname,crn->course)==0)
            {
                if(ctp->nstudents==0)
                {
                 ctp->ll=crn;
                 ctp->nstudents++;
            
                }
                else if(ctp->nstudents==1)
                {
                    cdt=ctp->ll;
                    cdt->LL=crn;
                    ctp->nstudents++;
                }
                else
                {
                    cdt=ctp->ll;
                    for(t=1;t<ctp->nstudents;t++)
                      cdt=cdt->LL;
                    cdt->LL=crn;
                    ctp->nstudents++;
                }
            }
            else
            {
                printf("entered course doesnot exist-enter proper course name\n");
                goto Y;
            }
            ctp=ctp->rl;
        }
      }
      PH->no_stu++;
    } 
}

void DisplayAlstu(SN PH)
{   
    int i;
    SD LTP,STP;
    LTP=PH->SL;
    while(LTP!=NULL)
    {
        STP=LTP->RL;
        printf("details of student %d are \n",LTP->regno);
        printf("----------------------------------------");
        printf("Name:%s\n",LTP->name);
        printf("Branch:%s\n",LTP->branch);
        printf("semester:%d\n",LTP->semester);
        printf("USN:%s\n",LTP->USN);
        printf("%s has registered for %d courses:\n",LTP->name,LTP->ncourses);
        for(i=1;i<=LTP->ncourses;i++)
        {
            printf("\t%d:%s\n",i,STP->course);
            STP=STP->RL;
        }
        LTP=LTP->LL;

    }
        
}

void DispalyAlcour(SN PH)
{
    int i;
    CD CTP;
    SD LTP;
    CTP=PH->CL;
    if(CTP->nstudents==0)
    {
        printf("NO students has registered for this course\n");
        return;
        
    }
    while(CTP!=NULL)
    {
        LTP=CTP->ll;
        printf("course details are :\n");
        printf("course name:%s || course code:%s || credits:%d\nstudents registered are:\n",CTP->cname,CTP->ccode,CTP->credits);
        printf("--------------------------------------------------------------------------\n");
        printf("reg_no name\t\tusn\tsemester branch\n");
        printf("-----------------------------------------------------------------\n");
        for(i=1;i<=CTP->nstudents;i++)
        {
            printf("%3d  %s\t%s  %d\t%s\n",LTP->regno,LTP->name,LTP->USN,LTP->semester,LTP->branch);
            printf("-------------------------------------------------------------------\n");
            LTP=LTP->LL;
        }
        CTP=CTP->rl;
    }
}



void main()
{
    int CA,SR,ch;
    SN HEAD;
    HEAD=createnode();
    HEAD->no_cour=HEAD->no_stu=0;
    printf("enter the number of courses:\n");
    scanf("%d",&CA);
    courselist(HEAD,CA);
    printf("enter no of students\n");
    scanf("%d",&SR);
    for(;;)
    {
        printf("operations:\n1:register student details\n2:display all students details\n3:display all courses details\n0:exit\nenter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:Registerdetails(HEAD,SR);break;
            case 2:DisplayAlstu(HEAD);break;
            case 3:DispalyAlcour(HEAD);break;
            default: exit(1);
        }
    }
}
