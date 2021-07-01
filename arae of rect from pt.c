#include<stdio.h>

void main()
{
	
	int i,b[100],a[50][50],s,q,z,c[100],m,n,j,l;
	
	printf("hello\nenter number of values=");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("enter %c%d=",120+j,i+1);
			scanf("%d",&a[i][j]);
		}					
	}

	q=0;
	for(i=0;i<n;i++)
	{
		j=0;
		l=0;
		for(s=0;s<n;s++)
		{
			if(a[i][j]==a[s][j] && s!=i && l!=4)
			{
				if(j==0)
				{
					b[q]=a[i][j+1]-a[s][j+1];
					if(b[q]<0)
					{
						b[q]=-b[q];
					}
					printf("%d\n",b[q++]);
					j=1;
				}
				else
				{
					b[q]=a[i][j-1]-a[s][j-1];
					if(b[q]<0)
					{
						b[q]=-b[q];
					}
					printf("%d\n",b[q++]);
					j=0;
				}
				i=s;
				l++;
				continue;
			}	
			if(s==n-1)
			{
				while(q%4!=0)
				{
					b[q++]=0;
					
				}
			}		
		}		
	}
	l=q;

	i=0;	
	for(q=0;q<l;q+=4)
	{
		if(b[q]==b[q+2] && b[q+1]==b[q+3])
		{
			c[i++]=b[q]*b[q+1];
		}
	}
	
	q=c[--i];
	for(i--;i>=0;i--)
	{
		if(q>c[i])
		{
			q=c[i];
		}
	}

	printf("%d",q);
	
	getch();
	
}
