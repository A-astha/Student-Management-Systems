#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//function declaration
	void menu();
	void add();
	void view();
	void search();
	void modify();
	void eraserec();
	void exit1(void);
//defining structure
struct student
{
    char name[30];
    char gender[10];
    int mobile, rollno;
    char address[30];
    char email[35];
    char streme[20];
};

//main function
  int main()
{
    printf("\n\n\n\t\t\"Student Record Management System\"\n");
       printf("\t\t_________________________________\n\n");
    printf("\t\tPress any key to continue.");
    getch();  			//to  hold screen
    menu();
    return 0;
}

// function to see menu
void menu()
{
    char choice;
    system("cls");		//screen clear function
    printf("\n\n\t\t\t\t ----Main Menu----\n\n");

//List to choose suitable option according to need of user
    printf("\t\ta)  Add Record\n");
    printf("\t\tb)  View Record\n");
    printf("\t\tc)  Search Record\n");
    printf("\t\td)  Modify Record\n");
    printf("\t\te)  Erase\n");
    printf("\t\tf)  Exit\n");
    printf("\n\n\t\tChoose from a to f.\n\t\t");
    scanf("%c",&choice);
    // USE OF SWITCH STATEMENT
    switch(choice)
    {
    case 'a':
    add();		//call add function
    break;
    case 'b':
    view();		//call view function
    break;
    case 'c':
	search();	//call search function
	break;
    case 'd':
    modify();	//call modify function
	break;
    case 'e':
    eraserec();	//call delete function
    break;
    case 'f':
    exit1();	//call exit function
    break;
    default:

    printf("\t\tInvalid Choice.");
    }
}

// functio to add detail of student
void add()
{
    FILE *fp; 		//file pointer
    struct student std;
    char another ='y';
    system("cls");
    fp = fopen("filere.txt","ab+");  	//opening file in append mode
    if(fp == NULL){
	printf("\n\n\tError opening file");
    exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
    printf("--:ADD RECORD:--\n\n");
    printf("Enter details of student.\n");
    printf("Enter Name : ");
    gets(std.name);
    printf("Gender : ");
    gets(std.gender);
    printf("Address : ");
    gets(std.address);
    printf("Mobile Number : ");
    scanf("%d",&std.mobile);
    fflush(stdin);
    printf("Roll No : ");
    scanf("%d",&std.rollno);
    fflush(stdin);
    printf("Email : ");
    gets(std.email);
    printf("Streme : ");
    gets(std.streme);
    fwrite(&std,sizeof(std),1,fp);  	///writing in a file
 	printf("Press 'y' to add another data otherwise 'any key'.");
    fflush(stdin);
    another = getch();
    system("cls");
    fflush(stdin);
    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();
    menu();
}

// function to view the whole record data of students

void view()
{
    FILE *fp;
    int i=1;
    struct student std;
    system("cls");
    printf("\t\t--:VIEW RECORD:--\n\n");
    printf("S.No Name of Student\t\tMobile No \tRoll No\t\tAddress\t\tEmail\t\t\tStreme\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    fp = fopen("filere.txt","rb+");
    if(fp == NULL){

    printf("\n\nError opening file.");
    exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
    fflush(stdin);
printf("%d>  %s\t\t%d\t  %d\t\t%s\t\t%s\t\t%s\n",i,std.name,std.mobile,std.rollno,std.address,std.email,std.streme);
        i++;
    }
    fclose(fp);
    printf("\n\nPress any key to continue.");
    getch();
    menu();
}

// function to search the record data
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls");

    printf("\n\n\t\t\t----:SEARCH RECORD:----\n\n");

    printf("\tEnter name of student :");
    fflush(stdin);
    gets(stname);
    fp = fopen("filere.txt","rb+");
    if(fp == NULL){

    printf("\n\n\t\tError opening file");
    exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
    if(strcmp(stname,std.name) == 0){
    printf("\n\n\tName			: %s\n",std.name);
    printf("\tGender			: %s\n",std.gender);
    printf("\tMobile Number  	: %d\n",std.mobile);
    printf("\tRoll No			: %d\n",std.rollno);
    printf("\tAddress			: %s\n",std.address);
    printf("\tEmail	 	    	: %s\n",std.email);
    printf("\tStreme			: %s\n",std.streme);
    }
    }
    fclose(fp);
    printf("\n\n\t\tPress any key to continue.");
    getch();
    menu();
}

//funnction to modify data
void modify()
{
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");

    printf("\n\t\t-----:MODIFY RECORD:-----\n");
    printf("\n\tEnter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("filere.txt","rb+");
    if(fp == NULL){
    printf("\n\n\t\tError opening file");
    exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
    if(strcmp(stname,std.name) == 0)//string compare
	{
    printf("\nEnter Name : ");
    gets(std.name);    
    printf("Gender : ");
    gets(std.gender);     
    printf("Address : ");
    gets(std.address);
    printf("Enter Mobile Number : ");
    scanf("%d",&std.mobile);
    printf("Enter Roll No : ");
    scanf("%d",&std.rollno);
	fflush(stdin);
    printf("Email : ");
    gets(std.email);
    printf("Streme : ");
    gets(std.streme);
    
    fwrite(&std,sizeof(std),1,fp);
    break;
        }
    }
    fclose(fp);

    printf("\n\n\t\tPress any key to continue.");
    getch();
    menu();
}

//function to delete record
void eraserec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    printf("\n\t\t--:ERASE RECORD:--");
    printf("\n\nEnter name of student to Erase record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("filere.txt","rb+");
    if(fp == NULL){

    printf("\n\n\t\tError opening file");
    exit(1);
    }
    ft = fopen("file2.txt","wb+");
    if(ft == NULL){
    printf("\n\n\t\tError opening file");
    exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
    if(strcmp(stname,std.name)!=0)
    fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("filere.txt");
    rename("file2.txt","filere.txt");

    printf("\n\n\t\tPress any key to continue.");
    getch();
    menu();
}
void exit1(void)//function to exit
{
	system("cls");
	printf("\n\n\n\n\t\t\tTHANKS FOR VISITING :"); 
	printf("\n\n\n\n\t\t\t\"Project on STUDENT RECORD MANAGEMENT\"");
	printf("\n\n\t\t\tBY:\n\t\t\t1.ARIK MANI ACHARYA\n\t\t\t2.SOURAB KHANAL\n\t\t\t3.BIPIN TIMALSINA\n\t\t\t4.SUMIRAN POKHREL \n\n\n"); 
	getch();
}

