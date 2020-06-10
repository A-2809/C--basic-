#include<stdio.h>
#include<math.h>
int primeno(int, int);
int main()
{
	int num,check;
	printf("enter a number: ");
	scanf("%d",&num);
	check= primeno(num,num/2);
	if(check==1)
	{
		printf("%d is a prime number.",num);
	}
	else
	printf("%d is not a prime number.",num);
	return 0;
}
int primeno(int num,int i)
{
	if(i==1)
	{return 1; }
	else
	{
		if(num%i==0)
		return 0;
		else
		return primeno(num,i-1);
	}
}
