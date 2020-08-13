#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    FILE *fpp;
    char name[500];
    int roll[500];
    char address[500];
    float marks[500];
    char line[500];
    char feedback[100];
    int n, i=1, o;
    time_t t;
    fp=fopen("marks.txt", "a");       
    if(fp==NULL)
    {
        printf("Sorry the program crashed!");
        return 1;
    }
    else
    {
        system("color C0");
        printf("________________________________| Marks Entry System |___________________________________|\n");
    for(int k=0;k<46;k++)
    {
        printf("--");
    }
    }
    printf("\nOPTIONS:");
    printf("\n1.Enter New Record.\n2.View the Existing Database(We are still working on this feature) \n3.Give feedback(We are still working)");
    printf("\n \n ");
    printf("Enter Options Number here:\t");
    scanf("%d", &o);
    if(o==1)
    {
    printf("\nEnter the number of the students:");
    scanf("%d", &n);

    do
    {
        fflush(stdin);
    printf("\n Enter Name:");
    gets(name);
    printf("\n Enter Roll number of %s:", name);
    scanf("%d", &roll);
    fflush(stdin);
    printf("\n Enter the address of %s:", name);
    gets(address);
    printf("\n Enter the marks obtained by %s:", name);
    scanf("%f", &marks);
    printf("\n Now writing data to the file...");
    fprintf(fp, "\n___________________________________________________", line);
    fprintf(fp,"\n Name= %s,\n Roll=%d \n address=%s \n marks=%.2f", name, roll, address, marks);
    fprintf(fp, "\n___________________________________________________", line);
    printf("\n \n");
    printf("\nCompleted!");
    i++;
    } while (i<=n);
    
    fclose(fp); 
    time(&t);
    printf("---------------------");
    printf("\n%s", ctime(&t));
    }
    else if(o==2)
    {
        printf("we are working on this feature... Sorry for inconvienece");
        //How to open a txt file directly with c program!!
    }
    else
    {
        printf("Please write your feedback here:\t");
        gets(feedback); //why is it not prompting the user to write?
        fpp=fopen("feedback.txt", "a");
        fprintf(fpp, "", feedback);
        printf("Thank you for your valuable feedback!");

    }
    

}



