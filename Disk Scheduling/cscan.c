#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,h,m,d;
	printf("enter the number of requests\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the  number of tracks\n");
	scanf("%d",&m);
	int max = m-1;
	printf("enter the track request values\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i] > m-1)
		{
			printf("request exceeds track size... please enter valid track\n");
			i--;
		}
	}

	printf("enter the value of disc head\n");
	scanf("%d",&h);

	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			if(a[j]< a[i])
			{
			int k = a[i];
			a[i] = a[j];
			a[j] = k;
			}
		}
    printf("enter the direction 1.left  2.right\n");
    scanf("%d",&d);
    int stop;

     if(d==1)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(a[j]>h)
    		{
    			stop = j;
    			break;
    		}
    	}

    	int sum=0;
    	sum += abs(h-a[stop-1]);

    	for(int k=stop-1;k>0;k--)
    	{
    		sum += (a[k]-a[k-1]);	
    		printf("%d",a[k]);
    	}

    	printf("->%d->0->%d",a[0],max);
 
        sum+=(a[0]+a[0]);

    	sum+=(a[n-1]-a[0]);

        int value = 2*(max-a[n-1]);
    	sum+=value;

    	int k;
    	for(k=n-1;k > stop;k--)
    	{
    		sum += (a[k]-a[k-1]);	
    		printf("->%d",a[k]);
    	}
    	
    	printf("->%d",a[stop]);
    	printf("seek movement =%d",sum);
    	printf("\n");
    }
    else
    {
    	for(int j=0;j<n;j++)
    	{
    		if(a[j]>h)
    		{
    			stop = j;
    			break;
    		}
    	}
    	int sum = 0;
    	sum += abs(h-a[stop]);

    	printf("%d",a[stop]);
    	int k;
    	for(k=stop;k<n-1;k++)
    	{
    		sum+=(a[k+1]-a[k]);   		
   			printf("->%d",a[k+1]);
    	}

        int value = 2*(max-a[n-1]);
        sum+=value;

    	sum+=(a[n-1]-a[0]);
    	printf("%d->0->%d",max,a[0]);

        sum+=(a[0]+a[0]);

    	for(k=0;k<stop-1;k++)
    	{
    		sum+=(a[k+1]-a[k]);   		
   			printf("->%d",a[k+1]);
    	}

    	printf("seek movement =%d",sum);
    	printf("\n");

    }
}
