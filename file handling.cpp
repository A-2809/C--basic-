#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *fp1,*fp2;
	char r[1000],w[1000];
	int begin,end,count=0;
	fp1= fopen("file.txt","r");
	fp2=fopen("file1.txt","w");
	fgets(r,1000,fp1);
	while(r[count]!='\0')
	{
	count++;
	end=count-1;}
	for(begin=0;begin<count;begin++)
	{
		w[begin]=r[end];
		end--;
	} 
	r[begin]='\0';
	printf("%s\n",w);
	fprintf(fp2,"%s",w);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
