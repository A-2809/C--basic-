#include<stdio.h>
#include<math.h>
int add_digits(int n);
int main()
{
	int n,result;
	printf("enter any number: ");
	scanf("%d",&n);
	result=add_digits(n);
	printf("output: %d",result);
	return 0;
}
int add_digits(int n)
{
	int sum=0;
	if(n==0)
	{
		return 0;
	}
	sum = n%10+add_digits(n/10);
	return sum;
}
