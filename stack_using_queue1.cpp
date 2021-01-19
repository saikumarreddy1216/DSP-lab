//stack using queue
#include<iostream>
using namespace std;
int f1=0,r1=0,f2=0,r2=0;
void enqueue1(int q1[],int n,int item)//enqueuing queue1
{
	r1=(r1+1)%n;
	if(f1==r1)
	{
		cout<<"queue is full\n ";
		if(r1==0) r1=n-1;
		else r1--;
	}
	else
	{
	q1[r1]=item;	
	}
}

int dequeue1(int q1[],int n)//dequeuing queue1
{
	if(f1==r1)
	{
		cout<<"queue is empty\n ";
		return -1;
	}
	else
	{
		f1=(f1+1)%n;
	    return q1[f1];
	}

}

void enqueue2(int q2[],int n,int item) //enqueuing queue2
{
	r2=(r2+1)%n;
	if(f2==r2)
	{
		cout<<"queue is full\n ";
		if(r2==0) r2=n-1;
		else r2--;
	}
	else
	{
	q2[r2]=item;	
	}
}

int dequeue2(int q2[],int n) //dequeuing queue2
{
	if(f2==r2)
	{
		cout<<"queue is empty\n ";
		return -1;
		
	}
	else
	{
		f2=(f2+1)%n;
	    return q2[f2];
	}
}

void push(int q1[],int q2[],int n,int item)
{
	enqueue2(q2,n,item);// enqueing new item into queue2
	while(f1!=r1)// until queue1 becomes empty dequeuing each element from queue1 and enqueuing to queue2 
	{
		int t=dequeue1(q1,n);
		enqueue2(q2,n,t);
	}
	
	while(f2!=r2)// until queue2 becomes empty dequeuing each element from queue2 and enqueuing to queue1  (just like swapping arrays and setting their pointers)
	{
		int x=dequeue2(q2,n);
		enqueue1(q1,n,x);
	}
	
    cout<<"stack after pushing "<<item<<"    ";
	
	if(f1<r1) for(int i=f1+1;i<=r1;i++) cout<<q1[i]<<" ";
	else if (f1>r1)
	{
     for(int i=f1+1;i<n;i++) cout<<q1[i]<<" ";
     for(int i=0;i<=r1;i++) cout<<q1[i]<<" ";
    }
    else 
	{
	cout<<" .....stack is empty.....";
    }
	
	cout<<endl;
}

void pop(int q1[],int n)
{
	int p=dequeue1(q1,n);
	cout<<"stack after popping "<<p<<"    ";
	
	if(f1<r1) for(int i=f1+1;i<=r1;i++) cout<<q1[i]<<" ";
	else if (f1>r1)
	{
     for(int i=f1+1;i<n;i++) cout<<q1[i]<<" ";
     for(int i=0;i<=r1;i++) cout<<q1[i]<<" ";
    }
    else cout<<" .....stack is empty.....";
    
	cout<<endl;
}

int main()
{
	int n=10 ;//maximum size of queues
	int q1[n],q2[n],item;
	cout<<"\n\npushing elements 1 2 3 4 and 5 respectively\n\n";
	push(q1,q2,n,1);
	push(q1,q2,n,2);
	push(q1,q2,n,3);
	push(q1,q2,n,4);
	push(q1,q2,n,5);
	cout<<"\n\npopping each element one by one\n\n";
	pop(q1,n);
	pop(q1,n);
	pop(q1,n);
	pop(q1,n);
	pop(q1,n);
	
	return 0;
}
