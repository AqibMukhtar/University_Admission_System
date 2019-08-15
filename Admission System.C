#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
#include<windows.h>
#define max 20
using namespace std;
struct data
{
 char name[30];
 char des[30];
 int number;
 int marks;
}student[max];

struct tdata
{
 char tname[30],tdes[30];
 int tnumber,tmarks;
}tstudent[max];


char S[30]="Software Engineering",M[30]="Mechanical Engineering",A[30]="Aeronautical Engineering",C[30]="Student canceled admission";
int aero,mech,soft,enrolled,failour;

void message (void)
{
    system("cls");
    printf("\t\tIn the name of Allah, most Gracious, most Compassionate\n\n\n");
    printf("O Allah, let Your Blessings come upon Muhammad (Peace Be Upon Him)\nand the family of Muhammad (Peace Be Upon Him), as you have blessed Ibrahim(A.H)and his family.\nTruly, You are Praiseworthy and Glorious.\nAllah, bless Muhammad(Peace Be Upon Him) and the family of\nMuhammad(Peace Be Upon Him), as you have blessed Ibrahim(A.H.) and his family.\nTruly, You are Praiseworthy and Glorious.\n");
    printf("\n\nThis is a dummy admission system similar to NEDUET\nto use it perfectly and for other information kindly read pdf file\nprovided with it\n\n\nPress any to begin...\n");
    getch();
}











void office_use()
{
 char pass[10],password[5]={'A','q','i','b','\0'};
 int i=-1,ans;
 system("cls");
 printf("Enter password to access office privacy\n(Press Tab key when you're done with password)\n");
 do
 {
  i++;
  pass[i]=getch();
 }
 while(pass[i]!='\t');
 pass[i]='\0';
 ans=strcmp(pass,password);
 if(ans!=0)
	exit(1);
 system("cls");
 printf("There are %d students to be enrolled kindly divide seats into\n Aeronautical,Mechanical & Software Engineering departments\n\n\n",max-failour);
 printf("\t\tAeronautical Engineering:   ");
 scanf("%d",&aero);
 printf("\t\tMechanical Engineering:     ");
 scanf("%d",&mech);
 printf("\t\tSoftware Engineering:       ");
 scanf("%d",&soft);
 if(aero+mech+soft == max-failour)
 {
	printf("Seats successfully divided!!!\n");
	getch();
 }
 else
 {
	printf("Recheck your data...\npress any key to continue");
	getch();
	office_use();
 }
}







void applicant_input (void)
{
 int i;
 system("cls");
 for(i=0; i<max; i++)
 {
	printf("Applicant no.%d\tenter your name:   ",i+1);
	gets(tstudent[i].tname);
 }
 system("cls");
 for(i=0; i<max; i++)
 {
	puts(tstudent[i].tname);
	printf("Kindly enter your Intermediate marks(out of 1100):\t");
	scanf("%d",&tstudent[i].tnumber);
	printf("Kindly enter your Aptitude test score(out of 100):\t");
	scanf("%d",&tstudent[i].tmarks);
 }
}







void applicant_checking()
{
    int i,j=0;
    system("cls");
    printf("Checking applicants data....\n\n\n");
    for(i=0; i<max; i++)
    {
        if(tstudent[i].tnumber>=363 && tstudent[i].tnumber<=1100 && tstudent[i].tmarks>=50 && tstudent[i].tmarks<=100)
        {
            student[j].number=tstudent[i].tnumber;
            student[j].marks=tstudent[i].tmarks;
            strcpy(student[j].name,tstudent[i].tname);
            printf("\n%s, is eligible\nPress any key...\n",student[j].name);
            getch();
            j++;
        }
        else
        {
            printf("\n%s, your data is either incorrect or your ineligible\nPress any key...\n",tstudent[i].tname);
            failour++;
            getch();
            continue;
        }
    }
            printf("\n\nChecking of data complete\n");
}








void applicant_sort(void)
{
 int i,j,k=0,temp,temp1;
 char ch[30];
 while(k<max-failour)
 {
 for(i=0; i<max-failour; i++)
 {
    if(student[i].number < student[i+1].number && student[i+1].number!=0)
    {
     temp=student[i].number;
     student[i].number=student[i+1].number;
     student[i+1].number=temp;
     temp1=student[i].marks;
     student[i].marks=student[i+1].marks;
     student[i+1].marks=temp1;
     strcpy(ch,student[i].name);
     strcpy(student[i].name,student[i+1].name);
     strcpy(student[i+1].name,ch);
    }
    else if(student[i].number == student[i+1].number)
    {
       if(student[i].marks < student[i+1].marks && student[i+1].marks!=0)
       {
	temp1=student[i].marks;
	student[i].marks=student[i+1].marks;
	student[i+1].marks=temp1;
	temp=student[i].number;
	student[i].number=student[i+1].number;
	student[i+1].number=temp;
	strcpy(ch,student[i+1].name);
	strcpy(student[i+1].name,student[i].name);
	strcpy(student[i].name,ch);
       }


     }//inside else if
}//for loop body
 k++;
}//outer loop
k=0;
while(k<max-failour)
{
for(i=0; i<max-failour; i++)
{
 if((student[i].number == student[i+1].number) && (student[i].marks == student[i+1].marks))
 {
  for(j=0; j<30; j++)
  {
  if(student[i].name[j] == student[i+1].name[j])
	continue;
  else if(student[i].name[j] < student[i+1].name[j])
	break;
  else
       {
	temp1=student[i].marks;
	student[i].marks=student[i+1].marks;
	student[i+1].marks=temp1;
	temp=student[i].number;
	student[i].number=student[i+1].number;
	student[i+1].number=temp;
	strcpy(ch,student[i+1].name);
	strcpy(student[i+1].name,student[i].name);
	strcpy(student[i].name,ch);
	break;
       }
    }
  }
}
k++;
}//2nd while loop


}//main







void applicant_list (void)
{
 int i;
 system("cls");
 printf("                       APPLICANTS OREDER LIST\n");
 printf("\n================================================================================");
 printf("\nMARKS\tTEST SCORE\tNAMES\n");
 printf("________________________________________________________________________________\n");
 for(i=0; i<max-failour; i++)
 {
  printf(" %d\t",student[i].number);
  printf("  %d\t\t",student[i].marks);
  puts(student[i].name);
  printf("________________________________________________________________________________");
 }
 printf("\nPress any key to begin admission");
 getch();
}







void applicant_desciplin()
{
 int a=aero,m=mech,s=soft,i=0;
 char field;
 while(i<max-failour)
 {
  system("cls");
  printf("Respected candidate remember\n A=Aeronautical Engineering\n M=Mechanical Engineering\n S=Software Engineering\n N=Cancellation of admission process\n");
  printf("________________________________________________________________________________");
  printf("Remaining seats for:\nAeronautical=%d\nMechanical=%d\nSoftware=%d\n",a,m,s);
  printf("________________________________________________________________________________");
  puts(student[i].name);
  printf("Chose your field:");
  field=getche();
  switch(field)
  {
   case 'A':
   case 'a':
	if(a>0)
	{
	 a--;
	 printf("\n\nSuccessfully registered in Aeronautical Engineering!!\n");
	 enrolled++;
	 strcpy(student[i].des,A);
	 i++;
	 break;
	}
	else
	{
	 printf("\n\nAeronautical is closed.Make another decision\n");
	 break;
	}
   case 'M':
   case 'm':
	if(m>0)
	{
	 m--;
	 printf("\n\nSuccessfully registered in Mechanical Engineering!!\n");
	 enrolled++;
	 strcpy(student[i].des,M);
	 i++;
	 break;
	}
	else
	{
	 printf("\n\nMechanical is closed.Make another desicion\n");
	 break;
	}
   case 'S':
   case 's':
	if(s>0)
	{
	 s--;
	 printf("\n\nSuccessfully registered in Software Engineering!!\n");
	 enrolled++;
	 strcpy(student[i].des,S);
	 i++;
	 break;
	}
	else
	{
	 printf("\n\nSoftware is closed.Make another decision\n");
	 break;
	}
   case 'N':
   case 'n':
	printf("\n\nYour admission process canceled...THANK YOU\n");
	strcpy(student[i].des,C);
	i++;
	break;
   default:
	printf("\n\nInvalid choice. Chose you field again.\n");

  }
  printf("\nPress any key....");
  getch();
 }//while body
}









void applicant_data()
{
 int i;
 system("cls");
 printf("                                   RESULTS\n");
 printf("\n  Date:%s\tTime:%s\t\tCandidates enrolled:%d/%d\n\n",__DATE__,__TIME__,enrolled,max-failour);
 printf("______________________________________________________________________________\n");
 printf("        DEPARTMENT\t\t\tMARKS\tSCORE\tSTUDENT NAME\n");
 printf("______________________________________________________________________________\n");
 for(i=0; i<max-failour; i++)
 {
  printf("    %s\t\t%d\t%d\t%s\n",student[i].des,student[i].number,student[i].marks,student[i].name);
  printf("______________________________________________________________________________\n");
 }
 getch();
}






void applicant_record()
{
 char inp;
 int i=0;
 printf("Enter Y if you want to save data as text file.\n Press any key otherwise.");
 inp=getch();
 if(inp == 'y' || inp == 'Y')
 {
 printf("The file will be created with the name: Record");
 FILE *fptr;
 system("cls");
 fptr=fopen("Record.txt","w");
 if(fptr == NULL)
 {
  printf("ERROR CREATING FILE");
  exit(1);
 }
 fprintf(fptr,"%37s\n\n","RESULTS");
 fprintf(fptr,"\n  Date:%s\tTime:%s\t\t\t\t\t\tCandidates enrolled:%d/%d\n\n",__DATE__,__TIME__,enrolled,max-failour);
 fprintf(fptr,"        DEPARTMENT\t\t\tMARKS\tSCORE\tSTUDENT NAME\n");
 fprintf(fptr,"_____________________________________________________________________________________________________________________________\n");
  for(i=0; i<max-failour; i++)
 {
  fprintf(fptr,"    %s\t\t%d\t%d\t%s\n",student[i].des,student[i].number,student[i].marks,student[i].name);
  fprintf(fptr,"_____________________________________________________________________________________________________________________________\n");
 }
 fclose(fptr);
 printf("File successfully created!!");
 }
}









int main ()
{
 system("cls");
 message();
 applicant_input();
 applicant_checking();
 office_use();
 applicant_sort();
 applicant_list();
 applicant_desciplin();
 applicant_data();
 applicant_record();
 getch();
 return 0;
}
