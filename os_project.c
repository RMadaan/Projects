#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

//***Main Block***//
int main()
{
	printf("*************Welcome to the Student & Faculty query handling system*************\n");
	printf("Please type one of the following option number to perform the desired operation:\n");
	printf("1->Log in\n2->Exit\nYour selection:- ");
	int in;
	scanf("%d",&in);
	
	if(in==1){
	void login();
	login();
	}
	
	else if(in==2){
	printf("\nHave a nice day.\n");
	exit(0);
	}
	return 0;
}

//***Login Block***//
	void login()
{
	int hours,minutes,seconds;
	time_t curr;                 // time_t type variable
	time(&curr);
	struct tm *loc = localtime(&curr);     
	hours= loc->tm_hour;
	minutes= loc->tm_min;
	seconds= loc->tm_sec;
	
	if(hours>=10 && hours<=12){
	char uname[100];
	char password[100];
	printf("\nEnter your user name: ");
	scanf("%s",uname);
	printf("Enter your password: ");
	scanf("%s",password);
	
	if(hours<12){
	if(strcmp(uname,"sudesh_sharma")==0 && strcmp(password,"admin123")==0)
	{
	printf("You have logged in successfully!\n");
	printf("Current time: %02d:%02d:%02d AM",hours,minutes,seconds);
	void alogin();
	alogin();
	}
	else{
	printf("\nSorry wrong user name or password, please try again.\n");
	login();}
}
	else if(hours>=12){
	if(strcmp(uname,"sudesh_sharma")==0 && strcmp(password,"admin123")==0)
	{
	printf("You have logged in successfully!\n");
	printf("Current time: %02d:%02d:%02d PM",hours,minutes,seconds);
	void alogin();
	alogin();
	}
	else{
	printf("\nSorry wrong user name or password, please try again.\n");
	login();}
	}

}
	else
	{
	printf("\nLogin time is between 10 AM to 12 PM, but ");
	if(hours>=12){
	printf("Current time is: %02d:%02d:%02d PM\n",hours,minutes,seconds);}
	if(hours<12){
	printf("Current time is: %02d:%02d:%02d AM\n",hours,minutes,seconds);}
	}
}

//***After Login Block***//
	void alogin()
{
	void student();
	void faculty();
	int input;
	printf("\n\nPlease type one of the following option numbers to enter a particular category or type 3 to exit:\n1->Students queries\n2->Faculty queries\n3->Exit\nYour selection:- ");
	scanf("%d",&input);
	if(input==1){student();}
	else if (input==2){faculty();}
	else if(input==3)
	{
	printf("\nThankyou for using this system.\n");
	exit(0);
	}
}

//***Students Query Block***// 
	void student()
{
	double avg=0;
	void q1();
	void q2();
	int a=2;
	printf("\n**** Student's Queries****\n");
	printf("Pending Queries: %d\n",a);
	
	while(1)
{
	clock_t start1, end1;
	start1 = clock();
	q1();
	end1 = clock();
	double time_tk = (double)(end1-start1) / (double)(CLOCKS_PER_SEC);  //Get the time in double data type
	avg=time_tk;
	if(time_tk>=45){
		printf("\nSorry the time slice has expired, as the time consumed is: %.3f seconds\n",time_tk);
		avg=avg-time_tk;
		break;
	}
	printf("-> Time consumed on the query: %.3f seconds\n",time_tk);
	break;
}

	while(1)
{
	clock_t start2, end2;
	start2 = clock();
	q2();
	end2 = clock();
	double time_tk = (double)(end2-start2) / (double)(CLOCKS_PER_SEC);
	avg=avg+time_tk;
	if(time_tk>=30){
		printf("\nSorry the time slice has expired, as the time consumed is: %.3f seconds\n",time_tk);
		avg=avg-time_tk;
		break;
	}
		
	printf("-> Time consumed on the query: %.3f seconds\n",time_tk);
	break;
}
	printf("\n**Summery**\n");
	printf("-> Total time consumed (without queries with expired time slice): %.3f seconds\n",avg);
	printf("-> Average time consumed in resolving students queries: %.3f seconds\n",(avg/2));
	void alogin();
	alogin();
}

	void q1()
{
	long long int i = 100000;
	char input [i];
	printf("\nTime Allocated: 45 seconds\nQ1. what do you mean by an operating system?\n");
	printf("Solution: ");
	int n;
	n=read(0,input,i);
}

	void q2()
{
	long long int i2 = 100000;
	char input2 [i2];
	printf("\nTime Allocated: 30 seconds\nQ2. what do you mean by CPU memory?\n");
	printf("Solution: ");
	int n;
	n=read(0,input2,i2);
}

//***Faculty Query Block***//
	void faculty()
{
	double avg=0;
	void fq1();
	void fq2();
	void fq3();
	printf("\n**** Faculty's Queries****\n");
	int a=3;
	printf("Pending Queries: %d\n",a);

	while(1)
{
	clock_t start, end;
	start = clock();
	fq1();
	end = clock();
	double time_tk = (double)(end-start) / (double)(CLOCKS_PER_SEC);
	avg=time_tk;
	if(time_tk>20){
		printf("\nSorry the time slice has expired, as the time consumed is: %.3f seconds\n",time_tk);
		avg=avg-time_tk;
		break;
	}
	printf("-> Time consumed on the query: %.3f seconds\n",time_tk);
	break;
}
	
	while(1)
{
	clock_t start, end;
	start = clock();
	fq2();
	end = clock();
	double time_tk = (double)(end-start) / (double)(CLOCKS_PER_SEC);
	avg=avg+time_tk;
	if(time_tk>15){
		printf("\nSorry the time slice has expired, as the time consumed is: %.3f seconds\n",time_tk);
		avg=avg-time_tk;
		break;
	}
	printf("-> Time consumed on the query: %.3f seconds \n",time_tk);
	break;
}
	
	while(1)
{
	clock_t start, end;
	start = clock();
	fq3();
	end = clock();
	double time_tk = (double)(end-start) / (double)(CLOCKS_PER_SEC);
	avg=avg+time_tk;
	if(time_tk>25){
		printf("\nSorry the time slice has expired, as the time consumed is: %.3f seconds\n",time_tk);
		avg=avg-time_tk;
		break;
	}
	printf("-> Time consumed on the query: %.3f seconds \n",time_tk);
	break;
}
	
	printf("\n**Summery**\n");
	printf("-> Total time consumed (without queries with expired time slice): %.3f seconds\n",avg);
	printf("-> Average time consumed in resolving faculty's queries: %.3f seconds\n",(avg/3));
	void alogin();
	alogin();
}

	void fq1()
{
	long long int i = 100000;
	char input [i];
	printf("\nTime Allocated: 20 seconds\nQ1. what is the registration number of the student named 'Ram gopal'?\n");
	printf("Solution: ");
	int n;
	n=read(0,input,i);
}

	void fq2()
{
	long long int i2 = 100000;
	char input2 [i2];
	printf("\nTime Allocated: 15 seconds\nQ2.How many MTE sheets are left unchecked?\n");
	printf("Solution: ");
	int n;
	n=read(0,input2,i2);
}

	void fq3()
{
	long long int i3 = 100000;
	char input3 [i3];
	printf("\nTime Allocated: 25 seconds\nQ3.What is the room number for the OS class?\n");
	printf("Solution: ");
	int n;
	n=read(0,input3,i3);
}
