#include<iostream>
//#define INT_MIN -1000
using namespace std;
int src[100],dest[100],aux[100];//stacks
int n ;//no.of disks
int top_src=0,top_dest=0,top_aux=0;//initialising top of all stacks

void push_src(int item)
{
	top_src++;
	src[top_src]=item;
}
int pop_src()
{
	if(top_src==0) return INT_MIN;
	else
	{
		int q;
		q=src[top_src];
		top_src--;
		return q;
	}
}

void push_dest(int item)
{
	top_dest++;
	dest[top_dest]=item;
}
int pop_dest()
{
	if(top_dest==0) return INT_MIN;
	else
	{
		int q;
		q=dest[top_dest];
		top_dest--;
		return q;
	}
}

void push_aux(int item)
{
	top_aux++;
	aux[top_aux]=item;
}
int pop_aux()
{
	if(top_aux==0) return INT_MIN;
	else
	{
		int q;
		q=aux[top_aux];
		top_aux--;
		return q;
	}
}

void move_disk_between_src_dest(char s,char d)
{
	int a=pop_src();
	int b=pop_dest();
	
	if(a==INT_MIN)
	{
		push_src(b);
		cout<<"moving disk "<<b<<" from "<<d<<" to "<<s<<endl;
	}
	else if(b==INT_MIN)
	{
		push_dest(a);
		cout<<"moving disk "<<a<<" from "<<s<<" to "<<d<<endl;
	}
	else if(a>b)
	{
		push_src(a);
		push_src(b);
		cout<<"moving disk "<<b<<" from "<<d<<" to "<<s<<endl;
	}
	else if(a<b)
	{
		push_dest(b);
		push_dest(a);
		cout<<"moving disk "<<a<<" from "<<s<<" to "<<d<<endl;
	}
}

void move_disk_between_dest_aux(char d,char auxi)
{
	int a=pop_aux();
	int b=pop_dest();
	
	if(a==INT_MIN)
	{
		push_aux(b);
		cout<<"moving disk "<<b<<" from "<<d<<" to "<<auxi<<endl;
	}
	else if(b==INT_MIN)
	{
		push_dest(a);
		cout<<"moving disk "<<a<<" from "<<auxi<<" to "<<d<<endl;
	}
	else if(a>b)
	{
		push_aux(a);
		push_aux(b);
		cout<<"moving disk "<<b<<" from "<<d<<" to "<<auxi<<endl;
	}
	else if(a<b)
	{
		push_dest(b);
		push_dest(a);
		cout<<"moving disk "<<a<<" from "<<auxi<<" to "<<d<<endl;
	}
	
}

void move_disk_between_src_aux(char s,char auxi)
{
	int a=pop_src();
	int b=pop_aux();
	
	if(a==INT_MIN)
	{
		push_src(b);
		cout<<"moving disk "<<b<<" from "<<auxi<<" to "<<s<<endl;
    }
    else if(b==INT_MIN)
	{
		push_aux(a);
		cout<<"moving disk "<<a<<" from "<<s<<" to "<<auxi<<endl;
	}
	else if(a>b)
	{
		push_src(a);
		push_src(b);
		cout<<"moving disk "<<b<<" from "<<auxi<<" to "<<s<<endl;
	}
	else if(a<b)
	{
		push_aux(b);
		push_aux(a);
		cout<<"moving disk "<<a<<" from "<<s<<" to "<<auxi<<endl;
    } 
}


int main()
{
	cout<<"enter no.of disks ";
	cin>>n;
	int i;
	
	int total_moves=1;
	for(i=1;i<=n;i++) total_moves=total_moves*2; //calculating total no.of moves
	
	total_moves=total_moves-1;
	
	for(i=n;i>=1;i--) push_src(i); //initialising source
	
	char s='S',d='D',a='A',temp;
	cout<<"\nS->source rod     D->destination rod      A->auxilary rod \n\n";
	
	if(n%2==0)
	{
		temp=a;
		a=d;
		d=temp;
	}
	
	for(i=1;i<=total_moves;i++)
	{
    	if(i%3==1) move_disk_between_src_dest(s,d); //finding movement between dest and src i.e, either src->dest or dest->src
		else if(i%3==2) move_disk_between_src_aux(s,a);
		else if(i%3==0) move_disk_between_dest_aux(d,a);
	}
	return 0;
}

