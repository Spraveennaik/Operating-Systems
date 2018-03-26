#include<stdio.h>
#include<stdlib.h>

int main()
{

	int n;
	printf("Enter the no. of requests\n");
	scanf("%d",&n);
	int a[n+1][2];
	printf("Enter the number of tracks\n");
	int i,h;

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i][0]);
		a[i][1]=0;
	}

	printf("Enter initial position of track\n");
	scanf("%d",&h);

	a[n][0]=h;
	a[n][1]=1;
	int min=a[n][0];
	int max=10000;
	int b[n+1],var=0,count=0;
	b[var++]=h;
	while(count!=n)
	{
		int j=-1;
		max=10000;
	for(i=0;i<n;i++)
	{
		if(abs(min-a[i][0])<max && a[i][1]==0)
		{
			max=abs(min-a[i][0]);
			j=i;
		}
	}

	b[var++]=a[j][0];
	a[j][1]=1;
	count++;
    }

    for(i=0;i<=n;i++)
    {
    	printf("%d ",b[i] );
    }
    printf("\n");
    
}