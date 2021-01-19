#include<iostream>
using namespace std;
int top=-1;//starting of array is at index 0
int maximum=4; // maximum no.of elements in stack
void push(int a[],int n);
void pop(int a[]);
int main()
{
	int a[100],i,n,y;
	while(1)
	{
		cout<<"do u want to push element if yes type 1 else considered as NO ";
		cin>>y;
		if(y==1) 
		{
			cout<<"enter element you want to push ";
			cin>>n;
			push(a,n);
			cout<<"elements in stack are ";
			for(i=0;i<=top;i++) cout<<a[i]<<" ";
			cout<<endl<<endl;
		}
		else
		{
			cout<<"do u want to pop element if yes type 1 else considered as NO ";
			cin>>y;
			if(y==1) 
			{
	            pop(a);
			 	cout<<"elements in stack are ";
			    for(i=0;i<=top;i++) cout<<a[i]<<" ";
			    cout<<endl<<endl;
			}
	         
			else return 0;
		}	
	}
}
void push(int a[],int n)
{
	if(top == (maximum-1)) cout<<"stack overflow ";
	else
	{
		top++;
		a[top]=n;
	}
}
void pop(int a[])
{
	if(top==-1) cout<<"stack underflow ";
	else
	{
		cout<<"element "<<a[top]<<" is poping off \n";
		top--;
	}
}

