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
 
void search(int item)
{
	int j=0,count=0;
	node* t=new node();
	t=head;
	while(t!=NULL)
	{
		count++;
		if(t->data==item) 
		{
		j=1;
		break;
		}
		t=t->link;
	}
	if(j==1) cout<<item<<" is found in list at "<<count<<" position "<<endl;
	else cout<<item<<" is not found in the list "<<endl;
}
void del(int item)//delete at end;
{
	int j=0;
	node* t=new node();
	t=head;
	while(t!=NULL)
	{
		if(t->data==item) 
		{
		j=1;
		break;
		}
		t=t->link;
	}
	if(j==1)
	{
		if(t==head) 
		{	
		head=t->link;
		t->link=NULL;
		}
		else
		{
			node* p=new node();
			p=head;
			while(p->link!=t) p=p->link;
			p->link=t->link;
			t->link=NULL;
		}
	}
	if(j==0) cout<<item<<" not found in the list "<<endl;
}

int main()
{
	head=NULL;
	cout<<"inserting elements at end from 1 to 6 "<<endl;
	add(1);
	display();
	
	add(2);
	display();
	
	add(3);
	display();
	
	add(4);
	display();
	
	add(5);
	display();
	
	add(6);
	display();

	cout<<endl;
	search(4);
	search(7);
	cout<<endl;

    cout<<"deleteing items 3 1 6 5 respectively "<<endl;
	del(3);
	display();
	
	del(1);
	display();
	
	del(6);
	display();
	
	del(5);
	display();
	
	return 0;
}
