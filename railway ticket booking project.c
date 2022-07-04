#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int welcomepage();
int loginpage();
void adminpage();
void addtrain();
void displaytrain();
void adminpage2();
void userpage();
void displaytrainuser();
void displayticket();
void bookticket();
void userpage2();

int welcomepage()
{
	int op;
	printf("\t\tWelcome to\n");
	printf("\tRailway Ticket Booking System\n\n\n\n");
	
	printf("Press 1 to continue\t");
	scanf("%d",&op);
	return op;
}

int loginpage()
{
	int op;
	system("cls");
	printf("Press 1 for Admin Login\nPress 2 for User Login\nPress 3 for Exit\n\n");
	scanf("%d",&op);
	return op;
}

void adminpage()
{
	char uname[10]="admin",password[10]="admin",unm[10],pass[10];
	int cmp_unm,cmp_pass,len,i;
	
	system("cls");
	start:
	printf("Enter Login Credentials\n\n\n");
	printf("Enter username -\t");
	scanf("%s",unm);
	cmp_unm=strcmp(uname,unm);	
	if(cmp_unm!=0)
	{
		printf("\nWrong Username. Enter again.\n--------------------\n\n\n");
		goto start;
	}
	len=strlen(password);
	
	pass:
	printf("\nEnter password -\t");
	for(i=0;i<len;i++)
	{
		pass[i]=getch();
		printf("*");
	}
	cmp_pass=strcmp(password,pass);	
	if(cmp_pass!=0)
	{
		printf("\nWrong Password. Enter again.\n--------------------\n\n\n");
		goto pass;
	}
	adminpage2();
}

void addtrain()
{
	struct train
	{
		int tno; 
		char tname[20];
		char bpoint[20];
		char dpoint[20];
	}s;
	
	printf("Enter Train Information\n\n");
	printf("Enter Train Name -\t");
	scanf(" %[^\n]s",s.tname);
	printf("Enter Train Number -\t");
	scanf("%d",&s.tno);
	printf("Enter Train Boarding Point -\t");
	scanf(" %[^\n]s",s.bpoint);
	printf("Enter Train Destination Point -\t");
	scanf(" %[^\n]s",s.dpoint);
	
	FILE *fptr;
    fptr = fopen("train details.txt", "a+");
    fprintf(fptr, "%d   \t", s.tno);
    fprintf(fptr, "%s\t", s.tname);
	fprintf(fptr, "%s\t\t\t", s.bpoint);
	fprintf(fptr, "%s\n\n\n", s.dpoint);
    fclose(fptr);
    printf("\n\n\nTrain Details inserted successfully!");
    printf("\n\n\nPress any key to continue");
    getch();
    adminpage2();
}

void displaytrain()
{
	printf("Train Number\tTrain Name\t\tBoarding Point\t\tDestination Point\n");
	printf("__________________________________________________________________________________\n\n");
	FILE *fptr;
	fptr = fopen("train details.txt","r");
    if (fptr == NULL)
    {
        printf("Cannot find file. \n");
        exit(0);
    }
    char ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf ("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\n\nPress any key to continue");
    getch();
    adminpage2();
}

void adminpage2()
{
	int op;
	system("cls");
	page2:
	printf("Press 1 to Add Train Details\nPress 2 to Display All Train Details");
	printf("\nPress 3 to Exit\n\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			addtrain();
			break;
		case 2:
			displaytrain();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("\nWrong Input. Enter again.\n--------------------\n\n\n");
			goto page2;	
	}
}

void userpage()
{
	char uname[10]="user",password[10]="user",unm[10],pass[10];
	int cmp_unm,cmp_pass,len,i;
	
	system("cls");
	start2:
	printf("Enter Login Credentials\n\n\n");
	printf("Enter username -\t");
	scanf("%s",unm);
	cmp_unm=strcmp(uname,unm);	
	if(cmp_unm!=0)
	{
		printf("\nWrong Username. Enter again.\n--------------------\n\n\n");
		goto start2;
	}
	len=strlen(password);
	
	pass2:
	printf("\nEnter password -\t");
	for(i=0;i<len;i++)
	{
		pass[i]=getch();
		printf("*");
	}
	cmp_pass=strcmp(password,pass);	
	if(cmp_pass!=0)
	{
		printf("\nWrong Password. Enter again.\n--------------------\n\n\n");
		goto pass2;
	}
}

void displaytrainuser()
{
	printf("Train Number\tTrain Name\t\tBoarding Point\t\tDestination Point\n");
	printf("____________________________________________________________________________________\n\n");
	FILE *fptr;
	fptr = fopen("train details.txt","r");
    if (fptr == NULL)
    {
        printf("Cannot find file. \n");
        exit(0);
    }
    char ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf ("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\n\nPress any key to continue");
    getch();
    userpage2();
}

void displayticket()
{
	printf("Train Ticket\n");
	printf("_____________________\n\n");
	FILE *fptr;
	fptr = fopen("train ticket.txt","r");
    if (fptr == NULL)
    {
        printf("Cannot find file. \n");
        exit(0);
    }
    char ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf ("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\n\nPress any key to continue");
    getch();
    userpage2();
}

void bookticket()
{
	int i;
	struct ticket
	{
		int tno; 
		int no_of_pass;
		char date[20];
	};
	
	struct passenger
	{
		int age;
		char name[20];
		char gender;
	};
	
	struct ticket t;
	printf("Book Ticket\n----------------------\n\n");
	printf("Enter Train Number -\t");
	scanf("%d",&t.tno);
	printf("Enter Number of passengers -\t");
	scanf("%d",&t.no_of_pass);
	printf("Enter Date of travel (dd-mm-yy) -\t");
	scanf(" %s",t.date);
	
	struct passenger p[t.no_of_pass];
	for(i=0;i<t.no_of_pass;i++)
	{
		printf("\n\nEnter Passenger [%d] Name -\t",i+1);
		scanf(" %[^\n]s",p[i].name);
		printf("Enter Passenger [%d] Age -\t",i+1);
		scanf("%d",&p[i].age);
		printf("Enter Passenger [%d] Gender (M/F) -\t",i+1);
		scanf(" %c",&p[i].gender);
	}
	
	FILE *fptr;
    fptr = fopen("train ticket.txt", "w+");
    fprintf(fptr, "Train Number = %d\n", t.tno);
    fprintf(fptr, "Number of passengers = %d\n", t.no_of_pass);
	fprintf(fptr, "Date of travel = %s\n\n", t.date);
	for(i=0;i<t.no_of_pass;i++)
	{
		fprintf(fptr, "\n\nPassenger [%d] Name -\t%s",i+1,p[i].name);
		fprintf(fptr, "\nPassenger [%d] Age -\t%d",i+1,p[i].age);
		fprintf(fptr, "\nPassenger [%d] Gender (M/F) -\t%c",i+1,p[i].gender);
	}
    fclose(fptr);
    printf("\n\n\nTicket Booked Successfully!");
    printf("\n\n\nPress any key to continue....");
    getch();
    userpage2();
} 

void userpage2()
{
	int op;
	system("cls");
	userpage2:
	printf("Press 1 to Book Train\nPress 2 to Display Available Trains");
	printf("\nPress 3 to View Ticket\nPress 4 to Exit\n\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			bookticket();
			break;
		case 2:
			displaytrainuser();
			break;
		case 3:
			displayticket();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\nWrong Input. Enter again.\n--------------------\n\n\n");
			goto userpage2;	
	}
}

void main()
{
	int op;
	op=welcomepage();
	
	if(op==1){
		op=loginpage();
		if(op==1){
			adminpage();
		}	
		else if(op==2){
			userpage();	
			userpage2();
		}
		else{
			exit(0);
		}
	}else{
		exit(0);
	}
	
	getch();
}
