#include<iostream>
using namespace std;
struct node
{
	int data;
	node* link;
};
node* head=new node();

void add(int item) //circular linked list
{
	node* n= new node();
	node* t= new node();
	n->data=item;
	if(head==NULL)
	{
		head=n;
		n->link=head;
	}
	else
	{
		t=head;
		while(t->link!=head) t=t->link;
		t->link=n;
		n->link=head;
	}
}

void display()
{
	node* t=new node();
	t=head;
	cout<<t->data<<" ";
	t=t->link;
	while(t!=head)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
}
void del(int k)
{
	node* t= new node();
	int count=1;
	t=head;
	cout<<"the order of killing ";
	while(head->link!=head)
	{
		if(count==k)
		{
			count=1;
			cout<<t->data<<" ";
			if(t==head)
			{
				node *prev=new node();
            	prev=t;
            	while(prev->link!=t) prev=prev->link;
             	prev->link=t->link;	
            	head=prev->link;
			}
			else
			{
				node *prev=new node();
            	prev=t;
            	while(prev->link!=t) prev=prev->link;
             	prev->link=t->link;	
			}		
	    }
	
	    else count++; 
	    
		t=t->link;	
    }
}
int main()
{
	int i,n,k;
	cout<<"enter no.of persons ";
	cin>>n;
	cout<<"enter a number of positions to skip ";
	cin>>k;
	head=NULL;
	for(i=1;i<=n;i++) add(i);
	del(k);
	cout<<endl<<"the saved person position is ";
	display();
	return 0;
}
