#include<stdio.h>
int main()
{
	int a[3][3],b[3][3],c[3][3],i,j,l,p;
	p=0;printf("enter the number in a ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			
			scanf("%d",&a[i][j]);
		}
	}printf("enter the number in b ");
		for(j=0;j<3;j++)
	{
		for(l=0;l<3;l++)
		{
			
			scanf("%d",&b[j][l]);
		}
	}
	for(i=0;i<3;i++)
	{
			for(l=0;l<3;l++,p=0)
			{
			for(j=0;j<3;j++)
		p=p+a[i][j]*b[j][l];
	c[i][l]=p;
	printf("%d ",c[i][l]);
	}
	printf("\n");
}
}
