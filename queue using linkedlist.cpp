#include<iostream>
using namespace std;
void enqueue(int item);
void dequeue();
struct node
{
	int data;
	node* link;
};
node *head=new node();
node *tail=new node();
int main()
{
	head=NULL;
	tail=NULL;
	cout<<"here i am inserting at end and deleting at begin\n\n";
    cout<<"here i have enqueued 6 elements \n";
    enqueue(2);
    enqueue(3);
    enqueue(6);
    enqueue(7);
    enqueue(1);
    enqueue(4);
    	node* t=new node();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
    
    cout<<"now i am dequeuing each element one by one\n ";
    dequeue();
    t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
    dequeue();
    t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
    dequeue();
    t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
	dequeue();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
	dequeue();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
	dequeue();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
	cout<<"here i am dequeing empty queue\n";
	dequeue();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	

	cout<<"working on single element(enqueing and dequeing single element) \n";
	enqueue(2);
		t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
	dequeue();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
	cout<<"\n enqueing two elements and dequeuing 1 element \n";
    enqueue(3);
    enqueue(6);
    
    	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
		dequeue();
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	
	cout<<"\n enqueuing 3 elements\n";
	
    enqueue(7);
    enqueue(1);
    enqueue(4);

	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->link;
	}
	cout<<endl;
	return 0;
    
	
	
}
void enqueue(int item)//insert at end
{
	node *p=new node();
	p->data=item;
	p->link=NULL;
	if(head==NULL) 
	{
		head=p;
		tail=p;
	}
	else 
	{
	tail->link=p;
	tail=p;
	}
}
void dequeue()//delete from begin
{
	

	if((head==NULL)||(head->link==NULL))
	{
		head=NULL;
		tail=NULL;
		cout<<"queue is empty ";
	}
	else head=head->link;
}

