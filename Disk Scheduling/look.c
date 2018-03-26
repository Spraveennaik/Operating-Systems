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

    	printf("->%d->%d",a[0],a[stop]);

    	
    	sum+=(a[stop]-a[0]);
    	
    	int k;
    	for(k=stop;k<n-1;k++)
    	{
    		sum+=(a[k+1]-a[k]);   		
   			printf("->%d",a[k+1]);
    	}
    	
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

    	
    	printf("->%d",a[stop-1]);

    	sum+=(a[n-1]-a[stop-1]);

    	for(int k=stop-1;k>0;k--)
    	{
    		sum += (a[k]-a[k-1]);	
    		printf("->%d",a[k-1]);
    	}


       printf("\n");

       printf("seek movement = %d\n",sum);



    }
    

}