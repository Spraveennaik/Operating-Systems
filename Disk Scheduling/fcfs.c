#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,h;
	printf("enter the number of requests\n");
	scanf("%d",&n);
	int a[n];

	printf("enter the track request values\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("enter the value of disc head\n");
	scanf("%d",&h);

	int sum=0;
	sum = abs(h-a[0]);

	for(int j=0;j<n-1;j++)
	{
		sum = sum + abs(a[j] - a[j+1]);
	}

	printf("total seek length is %d\n",sum);
	printf("the sequence is\n");
	printf("%d ",h);

	for(int j=0;j<n;j++)
		printf("->%d",a[j]);
	
	printf("\n");
}