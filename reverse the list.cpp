#include<iostream>
using namespace std;
struct node
{
	int data;
	node* link;
};
node* head=new node();
void add(int item)//inserting at end;
{
	node* n=new node();
	n->data=item;
	if(head==NULL) 
	{
		n->link=NULL;
		head=n;
	}
	else
	{
		node* t=new node();
		t=head;
		while(t->link!=NULL) t=t->link;
		t->link=n;
		n->link=NULL;
	}
	
}

void display()
{
	node* t=new node();
	t=head;
	while(t!=NULL) 
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
}

void reverse()
{
	node *prev=new node();
	node *curr=new node();
	node *next=new node();
	
	prev=NULL;
	curr=head;
	next=NULL;
	
	while(curr!=NULL)
	{
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	
	head=prev;
}

int main()
{
	head=NULL;
	
	cout<<"inserting list at end from 1 to 6 "<<endl;
	add(1);
	add(2);
	add(3);
	add(4);
	add(5);
	add(6);
	display();
	
	cout<<endl<<"after reversing the single linked list "<<endl;
	reverse();
	display();
	
	
	return 0;
}
