#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void header();
int program();
int key();

struct students
{
	char name[40];
	char id[20];
	char address[30];
	char faculty[30];
	char date[30];
	long long phone;
};
struct students sem1;

FILE *fp;
char line[100];
time_t t;
int k;
    
int main()
{
	key();
}
void header()
{
    system("color E0"); //changing the background and text color of console
    //Header...
	printf("%c",218); //printing top left corner part of box
	for(k=1;k<=91;k++)
	{
        printf("%c",196); //Printing upper line of box
	}
	printf("%c\n",191); //printin top right corner of box
	printf("%c",124); //printing left line of the box
	for(k=1;k<=34;k++)
	{
		printf(" "); //Used for proper indentation of Application Header
	}
	printf(" STUDENT RECORD SYSTEM ");
	for(k=1;k<=34;k++)
	{
		printf(" "); //Used for proper indentation of Application Header
	}
	printf("%c\n",124); //printing right line of box
	printf("%c",192); //printing lower left corner of box
	for(k=1;k<=91;k++)
	{
		printf("%c",196); //printing lower line of box
	}
	printf("%c\n",217); //printing lower right corner of box
	for(k=1;k<=93;k++)
	{
		printf("%c",45); //printing a line with -
	}
}
int program()
{
	int i=1,n,option;
	
	header();
	 //options
	printf("\nOPTIONS:");
	printf("\n\n1.Enter New Record.     2.Show Record\n\n3.Edit Record\t\t4.Exit\n\n"); 
	for(k=0;k<92;k++)
	{
	    printf("%c",196); //line separating the options 
	}
	printf("\n\nEnter Option Number Here:");
	scanf("%d", &option);
	switch (option)
	{
		case 1:
	       	printf("\nEnter the number of the students you want to entry:");
	        scanf("%d", &n);
	    	do
			{
			    fflush(stdin);
				printf("\nEnter Name:");
			    gets(sem1.name);
			    printf("\nEnter id number of %s:", sem1.name);
			    scanf("%s", &sem1.id);
			    fflush(stdin);
			    printf("\nEnter address of %s:", sem1.name);
			    gets(sem1.address);
			    printf("\nEnter the faculty of %s:", sem1.name);
			    gets(sem1.faculty);
			    printf("\nEnter phone number of %s:", sem1.name);
			    scanf("%lld", &sem1.phone);
			    printf("\nNow writing data to the file...");
			    fprintf(fp,"\n Name= %s\n Id=%s \n Address=%s\n Faculty=%s\n Phone=%lld\n", sem1.name, sem1.id, sem1.address, sem1.faculty, sem1.phone); //Writing file to txt file
			    time(&t);
				fprintf(fp," Date of Entry:%s",ctime(&t),sem1.date);    
				
				for(k=1;k<=55;k++)
			    {
					fprintf(fp, "%c",95, line); //printing line to seperate to records in txt file
				}
			    printf("\n \n");
			    printf("\nRecord is added successfully!\n");
			    i++;
			} while (i<=n);
	        
		    fclose(fp); 
		    printf("\n");
		    for(k=0;k<94;k++)
		    {
		        printf("%c", 45); //printing line  wit -- sign
		    }
		    printf("\n%s", ctime(&t)); //printing present time 
		    printf("press enter to go main menu again");
		    getch();
		    system("cls");
			program();
			getch();
			break;
	    	
		case 2:
	        printf("\n\nPlease, find and open StudentRecord.txt in the same directory as this program, to see the\nrecord!");
			printf("\n\nPress enter to go to main menu again!\n\n");	        
			getch();
			system("cls");
			program();
			getch();
			break;
	    case 3:
			printf("\n\nPlease, find and open StudentRecord.txt in the same directory as this program, to edit the\nrecord!");
			printf("\n\nPress enter to go to main menu again!\n\n");
			getch();
			system("cls");
			program();
			getch();
			break;
		case 4: 
	        exit(0);
	    	default:
	    	printf("Invalid Option. Please Enter the given option!"); //Add function so that application runs again!!
	    	break;
			getch();
	}   		
		
}
int key()
{
	char pass[15]={'t','e','S','t','#','3','2','1','\0'};
	char userpass[30];
	header();
	printf("\n\nPlease, Enter your password:");
    scanf("%s",userpass);
    if(strcmp(pass, userpass)==0)
    {
    	//creating txt file to store data
    	fp=fopen("StudentRecord.txt", "a+");   //creating a file for data storage    
    	if(fp==NULL)
    	{
        	printf("Sorry the program crashed!");
        	return 1;
    	}
    	else
    	{
    		system("cls");
			program(); 
		}
	
    }
	else
	{
		printf("Invalid Password! Please press enter to try again!\n");
    	getch();
		system("cls");	
		key();
	}	
}
    

