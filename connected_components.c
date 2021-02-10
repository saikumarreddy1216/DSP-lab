#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link; 
};
struct node* adjlist[10];
void add_edge(int src,int dest)
{
	struct node* new_node=(struct node*) malloc(sizeof(struct node));
	new_node->data=dest;
	new_node->link=NULL;
	
	if(adjlist[src]==NULL)
		adjlist[src]=new_node;
	else 
	{
		struct node *temp=adjlist[src];
		
		while(temp->link!=NULL)
			temp=temp->link;
		
		temp->link=new_node;
	}
}
void print_graph(int V)
{
	for(int i=0;i<V;i++)
	{
		struct node *temp=adjlist[i];
		
		printf("adjlist[%d]->",i);
		
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->link;
		}
		
		printf("NULL\n");
	}
}
void DFS(int vertex,int visited[])
{
	visited[vertex]=1;
	
	struct node *temp=adjlist[vertex];
	
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
			DFS(temp->data,visited);
			
		temp=temp->link;
    }
}
void connected_components(int V)
{
	int visited[V];
	
	for(int i=0;i<V;i++)
		visited[i]=0;
	
	int count=0;
	
	for(int i=0;i<V;i++)
	{
		if(visited[i]==0)
		{
			DFS(i,visited);
			count++;
		}
	}
    
    printf("\nno.of connected components: %d\n",count);
}
int main()
{
	int V,E;
	
	FILE *fp;
	fp=fopen("input.txt","r");
    if(fp==NULL)
    {
	    printf("\nError: input file is not present ");
   	    exit(1);
    }
    fscanf(fp,"%d%d",&V,&E);
	
	for(int i=0;i<V;i++)
	    adjlist[i]=NULL;
	
	for(int i=0;i<E;i++)
	{
		int src,dest;
		fscanf(fp,"%d%d",&src,&dest);
		add_edge(src,dest);
		add_edge(dest,src); // undirected graph
	}
	printf("\nThe given undirected graph in adjacency list form\n");
	print_graph(V);
	
	connected_components(V);
	
	return 0;
}

