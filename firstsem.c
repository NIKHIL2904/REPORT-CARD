#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct date
{
    int year;
    int month;
    int d1;
};
struct student
{
    char name[100];
    char eno[50];
    struct date d;
    char mname[100];
    char fname[100];
    float a;
    int mp;
    int mc;
    int mm;
    int me;
    int o;
    float avg;
}s[100];


int modify(int n)
{   char e[50];int ch1;int s1;
    int flag=1,i,j;
    printf("\n");
    printf("\t\t\tENTER THE ENROLLMENT NUMBER :");
    scanf("%s",e);
    for(i=0;i<n;i++)
    {
        for(j=0;e[j]!='\0';j++)
        {
            if(e[j]==s[i].eno[j])
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\t\t\tTHE ENROLLMENT NUMBER IS NOT FOUND");
        }
        else
        {
            while(1)
            {
            printf("\n\t\t\tPRESS.1 TO MODIFY THE NAME \n\t\t\tPRESS.2 TO MODIFY THE ATTENDANCE \n\t\t\tPRESS.3 TO MODIFY THE DATE OF BIRTH \n\t\t\tPRESS.4 TO CHANGE MARKS\n\t\t\tPRESS.5 TO CLOSE THE PORTAL\n");
            printf("\t\t\t");
            scanf("%d",&ch1);
            printf("\n");
            printf("\t\t\t=========================================================================");
            printf("\n");
            int j;
            switch(ch1)
            {
            case 1:printf("\t\t\tENTER THE NEW NAME :");
                       fflush(stdin);
                       scanf("%[^\n]s",s[i].name);
                       break;
                case 2:printf("\t\t\tENTER THE UPDATED ATTENDANCE :");
                       scanf("%f",&s[i].a);
                       break;
                case 3:printf("\t\t\tENTER THE UPDATED DATE OF BIRTH :");
                       scanf("%d %d %d",&s[i].d.d1,&s[i].d.month,&s[i].d.year);
                       break;
                case 4:
                      printf("\t\t\tPRESS.1 TO CHANGE MARKS OF PHYSICS");
                      printf("\n\t\t\tPRESS.2 TO CHANGE MARKS OF CHEMISTRY");
                      printf("\n\t\t\tPRESS.3 TO CHANGE MARKS OF MATHS");
                      printf("\n\t\t\tPRESS.4 TO CHANGE MARKS OF ENGLISH");
                      printf("\n\t\t\tPRESS.5 TO CHANGE MARKS OF OPTIONAL SUBJECT");
                      printf("\n");
                      printf("\t\t\t");
                      scanf("%d",&j);
                      switch(j)
                      {
                      case 1:
                        printf("\t\t\tENTER THE UPDATED MARKS OF PHYSICS :");
                        scanf("%d",&s[i].mp);
                        break;
                      case 2:
                        printf("\t\t\tENTER THE UPDATED MARKS OF CHEMISTRY :");
                        scanf("%d",&s[i].mc);
                        break;
                      case 3:
                        printf("\t\t\tENTER THE UPDATED MARKS OF MATHS :");
                        scanf("%d",&s[i].mm);
                        break;
                      case 4:
                        printf("\t\t\tENTER THE UPDATED MARKS OF ENGLISH :");
                        scanf("%d",&s[i].me);
                        break;
                      case 5:
                        printf("\t\t\tENTER THE UPDATED MARKS OF OPTIONAL SUBJECT :");
                       scanf("%d",&s[i].o);
                       break;
                      default:
                        printf("\t\t\tINVALID INPUT");
                      }
                      break;
                      case 5:
                       exit(0);
                        break;
                default:printf("\t\t\tWRONG INPUT");
                        exit(0);


            }
            printf("\n\t\t\tDATA MODIFIED :)\n");
                printf("\t\t\t=========================================================================");
              printf("\n");
              printf("\t\t\tPRESS 1. TO PRINT REPORT CARD\n");

              printf("\t\t\tPRESS 0. TO CONTINUE\n");
              printf("\t\t\t");
              scanf("%d",&s1);
              if(s1==1)
                printreportcard(n);
            }
    }
}
return 0;
}
int space(int n)
{
    int i;
    for(i=0;i<n;i++)
        printf(" ");
    printf("|\n");
    return 0;
}

void meritstu(int n)
{
    float t;printf("\t\t\t=========================================================================");
    SetColor(54);
    printf("\n\t\t\tENTER THE CUTOFF PERCENTAGE FOR THE MERITORIOUS STUENTS :");
    scanf("%f",&t);
    printf("\t\t\tTOPPER'S LIST :\n\n");
    int i1;
    for(i1=0;i1<n;i1++)
    {
        if(s[i1].avg>=t)
            printf("\t\t\t");
            printf("%s",s[i1].name);
            printf("\n");
    }
}



int fail(int n)
{
printf("\t\t\t=========================================================================");
int j;
    printf("\n\t\t\tSTUDENTS WHO FAILED :(");
    printf("\n\n");
    int c=0;
                       for(j=0;j<n;j++)
                       {
                           if(s[j].avg<33)
                           {
                            printf("\t\t\t");
                            printf("%s",s[j].name);
                            printf("\n");
                            c++;
                           }
                       }
if(c==0)
    printf("\t\t\tNO STUDENT FAILED");

}

void SetColor(int ForgC)
{
     WORD wColor;

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


int printreportcard(int n)
{   char en[50];
    int i,j,flag=0;
    printf("\t\t\tENTER THE ENROLLMENT NUMBER :");

    scanf(" %[^\n]s",en);
    for(i=0;i<n;i++)
    {
        for(j=0;en[j]!='\0';j++)
        {
            if(en[j]==s[i].eno[j])
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
        }


        if(flag==0)
        {
            printf("\t\t\tTHE ENROLLMENT NUMBER IS NOT FOUND");
        }
        else{
        printf("\n\n");
        char d='|';
        SetColor(100);int l;
        printf("\t\t\t ______________________________________________________________________");
            printf("\n\t\t\t|\t                REPORT CARD                                    |\n\t\t\t|\t\t\t\t\t\t\t\t       |\n");
            printf("\t\t\t|\tENROLLMENT NUMBER :%s",s[i].eno);l=space(44-strlen(s[i].eno));
            printf("\t\t\t|\tNAME              :%s",s[i].name);l=space(44-strlen(s[i].name));
            printf("\t\t\t|\tMOTHERS'S NAME    :%s",s[i].mname);l=space(44-strlen(s[i].mname));
            printf("\t\t\t|\tFATHERS'S NAME    :%s",s[i].fname);l=space(44-strlen(s[i].fname));
            printf("\t\t\t|\tDATE OF BIRTH     :%2d-%2d-%4d                                  |\n\t\t\t|\t\t\t\t\t\t\t\t       |\n\t\t\t|\t\t\t\t\t\t\t\t       |\n",s[i].d.d1,s[i].d.month,s[i].d.year);
            printf("\t\t\t|\tSUBJECT                  MARKS OBTAINED       MAXIMUM MARKS    |\n\t\t\t|\t\t\t\t\t\t\t\t       |\n");
            printf("\t\t\t|\tPHYSICS                       %3d                     100      |\n",s[i].mp);
            printf("\t\t\t|\tCHEMISTRY                     %3d                     100      |\n",s[i].mc);
            printf("\t\t\t|\tMATHS                         %3d                     100      |\n",s[i].mm);
            printf("\t\t\t|\tENGLISH                       %3d                     100      |\n",s[i].me);
            printf("\t\t\t|\tOPTIONAL SUBJECT              %3d                     100      |\n\t\t\t|\t\t\t\t\t\t\t\t       |\n",s[i].o);
            printf("\t\t\t|\tPERCENTAGE:%6.2f                                              |\n\t\t\t|\t\t\t\t\t\t\t\t       |\n",s[i].avg);
            if(s[i].avg<33)
            {
                printf("\t\t\t|\tSTATUS: PASS CERTIFICATE NOT AWARDED\t\t\t       |");
            }
            else
            {
                printf("\t\t\t|\tSTATUS: PASS CERTIFICATE AWARDED\t\t\t       |");
            }
        }

}
printf("\n\t\t\t|______________________________________________________________________|");
}



int main()
{   int n,choice;
    printf("\n");
    SetColor(34);
    printf("\t\t\t===============================WELCOME TO MY SCHOOL===================================");
    printf("\n\n\n");
    printf("\t\t\tNOTE: (THIS PORTAL IS USED FOR THE MAINTAINANCE OF STUDENT'S RECORD) ");
    printf("\n\n");
    printf("\t\t\tPLEASE GIVE THE FOLLOWING DETAILS :-");
    printf("\n\n");
    printf("\t\t\tPLEASE ENTER THE NUMBER OF STUDENTS IN THE CLASS:");
    scanf("%d",&n);
    printf("\n");
    int i;
    for(i=0;i<n;i++)
    {printf("\t\t\t**");
    printf("\n\n\t\t\tNAME OF STUDENT %d \t:",(i+1));
fflush(stdin);
    scanf("%[^\n]s",s[i].name);
    printf("\t\t\tENROLLMENT NUMBER \t:");
    scanf("%s",s[i].eno);
    printf("\t\t\tMOTHER'S NAME \t  \t:");
    scanf(" %[^\n]s",s[i].mname);
    printf("\t\t\tFATHERS'S NAME \t   \t:");
    scanf(" %[^\n]s",s[i].fname);
    printf("\t\t\tATTENDANCE(PERCENTAGE)  :");
    scanf("%f",&s[i].a);
    printf("\n");
    printf("\t\t\tENTER THE DATE OF BIRTH OF THE STUDENT(DATE,MONTH,YEAR) :\n");
    printf("\t\t\t");
    scanf("%d",&s[i].d.d1);
    printf("\t\t\t");
    scanf("%d",&s[i].d.month);
    printf("\t\t\t");
    scanf("%d",&s[i].d.year);
    printf("\n");
    printf("\t\t\tTHANK YOU FOR THE BASIC DETAILS");
    printf("\n");

    if(s[i].a>=75)
    {
    printf("\n\n\t\t\tENTER THE MARKS IN THE RESPECTIVE SUJECTS :\n");
    printf("\t\t\tENGLISH  :");
    scanf("%d",&s[i].me);
    printf("\t\t\tPHYSICS  :");
    scanf("%d",&s[i].mp);
    printf("\t\t\tCHMISTRY :");
    scanf("%d",&s[i].mc);
    printf("\t\t\tMATHS    :");
    scanf("%d",&s[i].mm);
    printf("\t\t\tOPTIONAL :");
    scanf("%d",&s[i].o);
    s[i].avg=(s[i].me+s[i].mp+s[i].mc+s[i].mm+s[i].o)/5.0;

    }
    else
    {
        printf("\n\t\t\t******************************\n");
        printf("\t\t\tWE ARE REALLY SORRY THE STUDENT IS RUNNING SHORT ON ATTENDANCE");
        printf("\n\n");
        printf("\t\t\tTHE STUDENT IS NOT ALLOWED TO GIVE THE EXAM");
        printf("\n\t\t\t******************************\n");
        exit(0);
    }
    }
    printf("\n");

    printf("\t\t\t=========================================================================");
     printf("\n\n\t\t\tPRESS.1 TO MODIFY THE DATA \n\t\t\tPRESS.2 TO FIND THE TOPPER'S LIST \n\t\t\tPRESS.3 TO FIND THE STUDENTS WHO FAILED\n\t\t\tPRESS.4 TO FIND PRINT THE REPORT CARD OF A STUDENT\n");
    printf("\t\t\t");
    scanf(" %d",&choice);
    switch(choice)
    {
        case 1:modify(n);
                break;
        case 2:meritstu(n);
               break;
        case 3:
              fail(n);
              break;
        case 4:printreportcard(n);
              break;

    }return 0;
}
