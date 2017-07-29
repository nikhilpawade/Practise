#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

count_data();

void main()
{
   // calling function
   count_data();
   getch();
}
count_data() // function for count no of words,lines & characters.
{
   FILE *fp,*fp_rep;
   char ch,ch1,temp_str[50],rep_str[10],new_str[10];
   int count=0; // counter
   clrscr();


   fp=fopen("c:\\windows\\desktop\\input.txt","r");
   fp_rep=fopen("c:\\windows\\desktop\\input1.txt","w");

   printf("\nEnter String to find:");
   scanf("%s",rep_str);
   printf("\nEnter String to replace:");
   scanf("%s",new_str);

   while((ch=getc(fp))!=EOF)
   {
     if(ch==' ')
      {
    temp_str[count]='\0';
    if(strcmp(temp_str,rep_str)==0)
     {
      printf("Do u want to replace(y/n):");
      ch1=getche();
      if(ch1=='y')
 {
       fprintf(fp_rep," %s",new_str);
       count=0;
      }
      else
       { fprintf(fp_rep," %s",temp_str);count=0;}
     }
    else
     {
       fprintf(fp_rep," %s",temp_str);
       count=0;
      }
      }else
      {
    temp_str[count++]=ch;
      }
    }
      if(strcmp(temp_str,rep_str)==0)
     {

      printf("Do u want to replace(y/n):");
      ch1=getche();
      if(ch1=='y')
      {
       fprintf(fp_rep,"%s ",new_str);
       count=0;
      }
      else
       {
        fprintf(fp_rep,"%s ",temp_str);
        count=0;
       }
     }else
      {
       fprintf(fp_rep,"%s ",temp_str);
      }

    fclose(fp);
    fclose(fp_rep);
    remove("c:\\windows\\desktop\\input.txt");
    rename("c:\\windows\\desktop\\input1.txt","c:\\windows\\desktop\\input.txt");
    fflush(stdin);
}
