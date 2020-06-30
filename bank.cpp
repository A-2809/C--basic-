#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>
int login();
struct a {
	 char name[60];
    int acc_no;
    int age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct  dob;
	struct deposit;
    struct withdraw;
} add,check,transaction;
int main()
{
	char pass[10],password[10]="archana";
	int i,j;
	printf("\n\t\tENTER THE PASSWORD:\n\t\t");
	scanf("%s",&pass);
	if(strcmp(pass,password)==0)
	{
		printf("\t\tsuccesfull login.\n");
		login();
	}
	else
	{
		printf("\t\tINVALID PASSWORD.\n");
		printf("\n\t\tenter 0 to retry and 1 to exit.\n\t\t\t");
		scanf("%d",&i);
		switch(i)
		{
			case 0: system("cls");
					main();
					break;
			case 1: return 0;
					break;
		}
	}
}
int login()
{
	int j,create(),display(),transact();
	printf("1. enter 1 to create an account.\n");
	printf("2. enter 2 to see details of account.\n");
	printf("3. enter 3 to do transaction.\n");
	printf("4.enter 4 to exit.\n");
	printf("enter the choice: ");	
	scanf("%d",&j);
	switch(j)
	{
		case 1: create();
				break;
		case 2: display();
				break;
		case 3: transact();
				break;
		case 4:break;
	}
	return 0;
}
void create()
{
	int choice,flag=0;
    FILE *ptr;

    ptr=fopen("record.txt","a+");
    system("cls");
	printf("ADD RECORD\n");
    printf("\n\t\tEnter the account number: ");
    scanf("%d",&check.acc_no );
    while(fscanf(ptr,"%d %s %d %s %s %lf %s %f \n",&add.acc_no,add.name,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
				printf("\t\t\tAccount no. already in use!\n");
				sleep(5);
                login();
			 }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",&add.name);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",&add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",&add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",&add.acc_type);

    fprintf(ptr,"%d %s %d %s %s %lf %s %f \n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt);


    fclose(ptr);
    printf("\nAccount created successfully!\n");
   /* printf("to create another account enter 1: ");
    scanf("%d",&flag);
    if (flag==1)
    create();
    else*/
    login();
    
}
void display()
{
	FILE *view;
    view = fopen("record.txt","r");
    int test=0,main_exit;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\t\t\tAMOUNT\n");

    while(fscanf(view,"%d %s %d %s %s %lf %s %f",&add.acc_no,&add.name,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt)!=EOF)
       {
		   printf("\n%d\t %s\t\t\t%s\t\t%f\t\t%f",add.acc_no,add.name,add.address,add.phone,add.amt);
           
       }

    fclose(view);
   
    view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
        if (main_exit==1)
            login();
        else if(main_exit==0)
            main();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void transact()
{
	int choice,test=0,f;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d %s %s %lf %s %f ",&add.acc_no,&add.name,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_type,&add.amt)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0 || strcmpi(add.acc_type,"fixed2")==0 || strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    system("cls");
                    login();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d %s %s %lf %s %f\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d %s %s %lf %s %f\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d %s %s %lf %s %f\n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&f);
      system("cls");
      if (f==0)
        transact();
    else if (f==1)
        login();
    else if (f==2)
        main();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&f);
        system("cls");
        if (f==1)
            login();
        else
            main();
   }	
}
