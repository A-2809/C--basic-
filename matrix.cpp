#include<stdio.h>
#include<math.h>
int main()
{
	int matrix[3][3];
	int i=0,j=0,sum=0;
	printf("INPUT ELEMENT IN THE MATRIX:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("element-[%d][%d]:",i,j);
			scanf("%d",&matrix[i][j]);
			if(i==j)
			{
				sum=sum+matrix[i][j];
			}
		}
	}
	printf("The matrix is: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	printf("sum of all daigonal elements: %d",sum);
	return 0;
}
