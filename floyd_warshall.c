#include<stdio.h>
#define I 9999 /* infinity */ 
int graph[10][10];
int V,E; /* no.of vertices and edges respectively */
int min(int a, int b)
{
	if(a>b) 
	    return b;
	else 
	    return a;
}
void floyd_warshall()
{
	int previous_matrix[V][V],current_matrix[V][V];
	
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V;j++)
			previous_matrix[i][j]=graph[i][j];
	
	for(int k=1;k<=V;k++)
	{
		for(int i=1;i<=V;i++)
			for(int j=1;j<=V;j++)
				current_matrix[i][j]=min(previous_matrix[i][j], (previous_matrix[i][k]+previous_matrix[k][j]) );
		
		for(int i=1;i<=V;i++)
			for(int j=1;j<=V;j++)
				previous_matrix[i][j]=current_matrix[i][j];
	}
	
	printf("\nAll pairs shortest path and I stands for INFINITY\n");
	for(int i=1;i<=V;i++)
	{
	    for(int j=1;j<=V;j++)
	    {
			if(previous_matrix[i][j]!=I) 
			    printf("%d   ",previous_matrix[i][j]);  
			else 
			    printf("I   ");
	    }
		printf("\n");
    }
}
int main()
{
	int a,b,d,weight;
	
	printf("**** NOTE: For any input consider STARTING VERTEX as '1' ****\n");
	
	printf("\nno.of vertices = ");
	scanf("%d",&V);
	
	printf("no.of edges = ");
	scanf("%d",&E);
	
	for(int i=1;i<=V;i++)
	{
		for(int j=1;j<=V;j++)
		{
			if(i==j)
			    graph[i][j]=0;
			else 
			    graph[i][j]=I;
	    }
    }
    
	printf("\nif your graph is undirected graph then enter 1 else it is considered as directed graph ");
    scanf("%d",&d);
    
    if(d==1)  /*undirected graph*/
    {
        for(int i=1;i<=E;i++)
        {
    	    printf("\nEnter starting and ending points of edge respectively : ");
    		scanf("%d%d",&a,&b);
    		printf("Enter weight for the above entered edge : ");
    		scanf("%d",&weight);
    		graph[a][b]=weight;
    		graph[b][a]=weight;
	    }
    }
    else /*directed graph*/
    {
    	for(int i=1;i<=E;i++)
        {
    		printf("\nEnter starting and ending points of edge respectively : ");
    		scanf("%d%d",&a,&b);
    		printf("Enter weight for the above entered edge : ");
    		scanf("%d",&weight);
    		graph[a][b]=weight;
	    }
	}
	
	printf("\nThe given graph in matrix form is and I stands for INFINITY\n");
	for(int i=1;i<=V;i++)
	{
	    for(int j=1;j<=V;j++)
	    {
			if(graph[i][j]!=I) 
			    printf("%d   ",graph[i][j]);  
			else 
			    printf("I   ");
	    }
		printf("\n");
    } 
    
    floyd_warshall();
    
    return 0;
}
