#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
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
		struct node *q=(struct node*) malloc(sizeof(struct node));//new node
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
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int height(struct node *t)
{
	if(t==NULL) return 0;
    else return(max(height(t->left),height(t->right))+1);
}
int main()
{
   struct node *root=(struct node*) malloc(sizeof(struct node));
   int n,i;
   scanf("%d",&n);
   if(n==0) 
   {
      printf("0");
      return 0;
   }
   int a[n];
   for(i=0;i<n;i++) scanf("%d",&a[i]);	
   build_BST(root,a,n);
   printf("%d",height(root));
   return 0;
}