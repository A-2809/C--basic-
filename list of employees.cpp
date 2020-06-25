#include<stdio.h>
int details();
struct employee
{
	char name[20];
	int age;
	int phone;
	float salary;
};
int main()
{
	struct employee e[20];
	int i;
	for(i=0;i<20;i++)
	{			
		printf("Enter the details:\n");
		printf("Name: ");
		scanf("%s",&e[i].name);
		printf("age: ");
		scanf("%d",&e[i].age);
		printf("phone no.: ");
		scanf("%d",&e[i].phone);
		printf("salary: ");
		scanf("%f",&e[i].salary);	
	}
	printf("NAME\tAGE\tPHONE NO.\tSALARY\n");
	for(i=0;i<20;i++)
	{
		printf("%s\t%d\t%d\t%f\n",e[i].name,e[i].age,e[i].phone,e[i].salary);
	}
	return 0;
}

