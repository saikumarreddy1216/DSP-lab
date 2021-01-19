#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct stack
{
	int top;
	struct node *a[100];
};
void push(struct node *nde,struct stack *p)
{
	p->a[++p->top]=nde;
}
struct node* pop(struct stack *p)
{
	return p->a[p->top--];
}
void build_BST(struct node *root,int a[],int n)
{
	
	root->data=a[0];
	root->left=NULL;
	root->right=NULL;
	for(int i=1;i<n;i++)
	{
		struct node *curr=(struct node*) malloc(sizeof(struct node));
		curr=root;
		struct node *prev=(struct node*) malloc(sizeof(struct node));
		struct node *q=(struct node*) malloc(sizeof(struct node));
		q->data=a[i];
		while(curr!=NULL)
		{
			if(q->data<=curr->data) 
			{
				prev=curr;
				curr=curr->left;
			}
			else 
			{
				prev=curr;
				curr=curr->right;
			}
		}
		if(q->data<=prev->data) 
		{
			prev->left=q;
			q->left=NULL;
			q->right=NULL;
		}
		else
		{
			prev->right=q;
			q->left=NULL;
			q->right=NULL;
		}
	}
}
void preorder(struct node *t)
{
	if(t!=NULL)
	{
		printf("%d ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(struct node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
}
void postorder(struct node *root,struct stack *stack1,struct stack *stack2)
{
    if(root==NULL) return;
    push(root,stack1);
    struct node *q=(struct node*) malloc(sizeof(struct node));
    while(stack1->top!=-1)
    {
	    q=pop(stack1);
	    push(q,stack2);
	    if(q->left!=NULL) push(q->left,stack1);
	    if(q->right!=NULL) push(q->right,stack1);	
    }
    while(stack2->top!=-1)
    {
	    q=pop(stack2);
	    printf("%d ",q->data);
    }
}

int main()
{
    struct node *root=(struct node*) malloc(sizeof(struct node));
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) scanf("%d",&a[i]);	
    build_BST(root,a,n);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");

    struct stack *stack1=(struct stack*) malloc(sizeof(struct stack));
    struct stack *stack2=(struct stack*) malloc(sizeof(struct stack));
    stack1->top=-1;
    stack2->top=-1;

   postorder(root,stack1,stack2);
   return 0;
}