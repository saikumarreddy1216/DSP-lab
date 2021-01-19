#include<iostream>
using namespace std;
int front=0,rear=0;
void enqueue(int a[],int n,int item);
void dequeue(int a[],int n);


int main()
{
 int a[100],x,y,i;
 int n=5;// maximum index of the array is n-1 
 while(1)
{
	cout<<"do you want to enqueue if yes type 1 else considered as NO ";
	cin>>y;
	
	if(y==1)
	{
	cout<<"enter element you want to insert ";
	cin>>x;	
	enqueue(a,n,x);
	
	cout<<"elements after enqueuing  ";
	while(1)
	{  
		if(front<rear)
		{
		for(i=front+1;i<=rear;i++) cout<<a[i]<<" ";
		break;
		}
		else if( front > rear)
		{
			for(i=front+1;i<n;i++) cout<<a[i]<<" ";
			for(i=0;i<=rear;i++) cout<<a[i]<<" ";
			break;
		}
		else break;
	}
	
	cout<<endl;
	
    }
    else
    {
    cout<<"do you want to dequeue if yes type 1 or else considered as NO ";
	cin>>y;

	if(y==1)	
	{
		    dequeue(a,n);
		
			cout<<"elements after dequeuing\n";
	while(1)
	{
		if(front<rear)
		{
		for(i=front+1;i<=rear;i++) cout<<a[i]<<" ";
		break;
		}
		else if( front > rear)
		{
			for(i=front+1;i<n;i++) cout<<a[i]<<" ";
			for(i=0;i<=rear;i++) cout<<a[i]<<" ";
			break;
		}
		else break;
	}
	 cout<<endl;
	}
	else return 0;
	}
}
}
void enqueue(int a[],int n,int item)
{
	rear=(rear+1)%n;
	if(front==rear)
	{
		cout<<"queue is full\n ";
		if(rear==0) rear=n-1;
		else rear--;
	}
	else
	{
	a[rear]=item;	
	}
}
void dequeue(int a[],int n)
{
	if(front==rear)
	{
		cout<<"queue is empty\n ";
		
	}
	else
	{
		front=(front+1)%n;
	    cout<<"dequeued element "<<a[front]<<endl;
	}
}
