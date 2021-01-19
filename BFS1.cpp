#include<stdio.h>
int graph[20][20];
int visited[20];
int n,front,rear;
int a[50];
void enqueue(int item)
{
	a[++rear]=item;
}
int dequeue()
{
	return a[++front];
}
int is_all_visited()
{
	for(int i=0;i<n;i++)
		if(visited[i]==0)
			return 0;
			
	return 1;
}
void BFS(int v)
{
	front=0;
	rear=0;
	for(int i=0;i<n;i++)
		visited[i]=0;
	
	visited[v]=1;
	printf("node %d is visited\n",v);
	
	while(1)
	{
		for(int i=0;i<n;i++)
		{
		    if((graph[i][v]==1||graph[v][i]==1) && visited[i]==0) 
		    {
			    enqueue(i);
			    visited[i]=1;
			    printf("node %d is visited\n",i);
		    } 
	    }
		if(front==rear || is_all_visited()) break; 
		v=dequeue();
	}
}
int main()
{
	int i,j,y,a,b,d;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			graph[i][j]=0;
			
	printf("\n**** NOTE: For any input consider STARTING NODE INDEX as '0' ****\n\n");
	printf("if your graph is undirected graph then enter 1 else it is considered as directed graph ");
    scanf("%d",&d);
    
	printf("\nno.of nodes = ");
	scanf("%d",&n);
    printf("\ndo you want to input edge: if yes enter 1 else it is considered as no more edges for input ");
    scanf("%d",&y);
    
    if(d==1)  /*undirected graph*/
    {
        while(1)
        {
    	    if(y==1) 
    	    {
    		    scanf("%d%d",&a,&b);
    		    graph[a][b]=1;
    		    graph[b][a]=1;
    		    printf("\ndo you want to input edge: if yes enter 1 else it is considered as no more edges for input ");
    		    scanf("%d",&y);
		    }
		    else break;
	    }
    }
    else /*directed graph*/
    {
    	while(1)
        {
    	    if(y==1) 
    	    {
    		    scanf("%d%d",&a,&b);
    		    graph[a][b]=1;
    		    printf("\ndo you want to input edge: if yes enter 1 else it is considered as no more edges for input ");
    		    scanf("%d",&y);
		    }
		    else break;
	    }
	}
	printf("\nThe given graph in matrix form is\n");
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    	printf("%d ",graph[i][j]);
	    	
		printf("\n");
    }
    printf("\nThe order of visiting nodes in BFS is as follows\n");
    BFS(0);
	return 0;
}
