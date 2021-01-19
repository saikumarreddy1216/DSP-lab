#include<stdio.h>
int power(int a,int b)
{
	int i;
	int p=1;
	for(i=1;i<=b;i++) p=p*a;
	return p;
}

int prime(int n)
{
    if(n==1) return 0;
    if(n==2||n==3) return 1;
    
    int i,flag=1;
    
    for(i=2;i<=n/2;i++)
    {
	    if(n%i==0)
	   {
		flag=0;
		break;
	   }
	}
	 if(flag==0) return 0;
	 else return 1;
    
}

int main()
{
	int n,k;
	scanf("%d",&n);
	if(n<=0)
	{
		printf("-1");
		return 0;
	}
	k=n;
	int count=0;
	while(k!=0)
	{
		count++;
		k=k/10;
	}
	int count1=count;
	int flag,p=0;
	while(count1!=0)
	{
		int q=prime(n);
		if(q==0) 
		{  
		    flag=0;
			break;
		}
		else if(q==1) flag=1;
		
		int r=n%10;//remainder
		int quo=n/10;//quotient
		n=power(10,count-1)*r+quo;
		
		count1--;
	}
	
	if(flag==1) printf("1");
	else if(flag==0) printf("0"); 
	
	return 0;
}