#include<stdio.h>
#include<math.h>
int HCF(int x,int y);
int main()
{
	int i,j,z,LCM;
	printf("Input first number:");
	scanf("%d",&i);
	printf("Input second number: ");
	scanf("%d",&j);
	z=HCF( i,j);
	LCM=(i*j)/z;
	printf("LCM of %d and %d = %d.",i,j,LCM);
	return 0;
}
int HCF(int x,int y)
{
	if(y==0)
	{
		return x;
	}
	else 
	return HCF(y,x%y);
}
