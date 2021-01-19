#include<iostream>
using namespace std;

int top1=-1,top2=-1;
void push1(int s1[],int n,int item)//pushing elemts to stack 1
{
	top1++;
	if(top1==n-1) cout<<"queue is full "<<endl;
	else s1[top1]=item;
}
int pop1(int s1[],int n)//popping elements from stack1
{
	if(top1==-1) return -1;
	else 
	{
    int q=s1[top1];
	top1--;
	return q;
    }
}
void push2(int s2[],int n,int item)//pushing elemts to stack 2
{
	top2++;
	if(top2==n-1) cout<<"queue is full "<<endl;
	else s2[top2]=item;
}
int pop2 (int s2[],int n)//popping elements from stack2
{
	if(top2==-1) return -1;
	else{
int q=s2[top2];
	top2--;
	return q;
}
}
void enqueue(int s1[],int s2[],int n,int item)
{
	while(top1!=-1) //poping from stack1 and pushing it into stack2 until stack1 becomes empty
	{
		int q=pop1(s1,n);
		push2(s2,n,q);
	}
	
	push1(s1,n,item);// pushing new element into stack1
	
	while(top2!=-1)//poping from stack2 and pushing it into stack1 until stack2 becomes empty
	{
		int p=pop2(s2,n);
		push1(s1,n,p);
	}
	
	int i=top1;
	cout<<"after enqueuing element "<<item<<" in to queue    ";
	for(i=top1;i>-1;i--) cout<<s1[i]<<" ";
	cout<<"\n";
}
void dequeue(int s1[],int n)
{ 
    int t=pop1(s1,n);//popping from stack1
	if(top1>-1)
	{
	cout<<"after dequeuing element "<<t<<" in to queue    ";
	for(int i=top1;i>-1;i--) cout<<s1[i]<<" ";
	cout<<"\n";
	} 
	else if(t!=-1)
	{
	cout<<"after dequeuing element "<<t<<" in to queue    ";
	cout<<"......queue is empty....... "<<endl;
    }
    else cout<<"no element in queue to dequeue......queue is empty....... "<<endl;
}

int main()
{
int n=10;//max no.of elements in stack
int s1[n],s2[n];

cout<<"\nenqueuing 5 elements\n\n";
enqueue(s1,s2,n,1);
enqueue(s1,s2,n,2);
enqueue(s1,s2,n,3);
enqueue(s1,s2,n,4);
enqueue(s1,s2,n,5);

cout<<"\n\ndequeuing each element one by one\n\n";
dequeue(s1,n);
dequeue(s1,n);
dequeue(s1,n);
dequeue(s1,n);
dequeue(s1,n);


return 0;

}
