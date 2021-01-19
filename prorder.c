#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int index;
	struct node *left;
	struct node *right;
};
struct node *root;
int find_index(int in[],int item,int n)
{
	int i;
	for(i=0;i<n;i++) if(in[i]==item) return i;
}

void construct_tree(int in[],int post[],int n)
{
	int i;
	for(i=n-2;i>=0;i--)
	{
		struct node *t=(struct node*) malloc(sizeof(struct node));
		t=root;
		struct node *curr=(struct node*) malloc(sizeof(struct node));
		int q=find_index(in,post[i],n);
		struct node *p=(struct node*) malloc(sizeof(struct node));
		p->data=post[i];
		p->index=q;
		while(t!=NULL)
		{
			if(q>t->index) 
			{
				curr=t;
				t=t->right;
			}
			else if(q<t->index)
			{
				curr=t;
				t=t->left;
			}
		}
		if(q>curr->index) 
		{
		    curr->right=p;
		    p->left=NULL;
		    p->right=NULL;
	    }
	    else if(q<curr->index)
	    {
	    	curr->left=p;
	    	p->left=NULL;
	    	p->right=NULL;
		}  
    }
}

void  preorder(struct node *t)
{
	if(t!=NULL)
	{
		printf("%d ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int in[n],post[n];
	
	for(i=0;i<n;i++) scanf("%d",&in[i]);
	for(i=0;i<n;i++) scanf("%d",&post[i]);
	
	root=(struct node*) malloc(sizeof(struct node));
	root->data=post[n-1];//assigning last element to root
	int q=find_index(in,post[n-1],n);//finding index in inorder array
	root->index=q;
	root->left=NULL;
	root->right=NULL;
	
	construct_tree(in,post,n);
	
	preorder(root);
	
	return 0;
}