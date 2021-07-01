#include<stdio.h>

void main()
{

	int i,a[100],t,n,m,s,j,u,l;

	printf("hello\nenter number of values=");
	scanf("%d",&n);

	i=0;
	while(i<n)
	{
		printf("enter bracket%d=",i+1);
		scanf("%c",&a[i]);
		i++;
	}

	if(n%2!=0)
	{
		printf("cant be made balanced");
	}
	else
	{
		for(i=0;i<n-1;i++)
		{
			if(a[i]=='{' && a[i+1]=='}')
			{
				
			}
		}
	}
	getch();
}
