#include<iostream>
using namespace std;
void push(int item);
void pop();
struct node
{
	int data;
	node* link;
};
node* head=new node();
int main()
{
	int item;
	head=NULL;
	cout<<"here iam inserting at begin and deleting at begin";
	cout<<"\npushing 4 elements\n";
	push(5);
	push(9);
	push(3);
	push(4);
	node* t=new node();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	cout<<"popping off each element one by one until stack becomes empty\n";
	pop();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
		pop();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
		pop();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
		pop();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
	cout<<"here i am popping when the stack is empty \n";
		pop();
	t=head;
	while(t!=NULL)
	{
		cout<<"a\n";
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	

	cout<<"pushing 2 elements \n";
	push(3);
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
	push(4);
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	return 0;
}
void push(int item)//insert at begin
{
	node* p=new node();
	p->data=item;
	p->link=head;
	head=p;
}
void pop()//delete at begin
{   
    if(head==NULL||head->link==NULL)
    {
	head=NULL;
    cout<<"stack is empty\n";
	}
     else 
	 {
	 head=head->link;
    }
}
