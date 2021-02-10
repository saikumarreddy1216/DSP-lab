#include<stdio.h>
#include<stdlib.h>
struct Edge
{
	int source;
	int dest;
	int weight;
};
void merge(struct Edge *in_edge,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	
	struct Edge left[n1],right[n2];
	
	for(int i=0;i<n1;i++)
		left[i]=in_edge[p+i];
	
	for(int i=0;i<n2;i++)
		right[i]=in_edge[q+1+i];
	
	int i=0,j=0,k=p;
	while(k<=r)
	{
		if(i>=n1 && j<n2)
		{
			in_edge[k++]=right[j++];
			continue;
		}	
		if(j>=n2 && i<n1)
		{
			in_edge[k++]=left[i++];
			continue;
	    }
		if(left[i].weight<=right[j].weight)
			in_edge[k++]=left[i++];
		else
			in_edge[k++]=right[j++];		
	}
}
void merge_sort(struct Edge *in_edge,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		merge_sort(in_edge,p,q);
		merge_sort(in_edge,q+1,r);
		merge(in_edge,p,q,r);
	}
}
int find_parent(int a,int *parent)
{
	if(parent[a]==a)
		return a;
		
    return find_parent(parent[a],parent);
}
void kruskal(struct Edge *in_edge,int V,int E)
{
	merge_sort(in_edge,0,E-1);
	
	struct Edge mst[V-1];
	
	int parent[V];
	for(int i=1;i<=V;i++)
		parent[i]=i;
		
	int count=0,i=0,cost=0;
	while(count!=V-1)
	{	
		int src_parent=find_parent(in_edge[i].source,parent);
		int dest_parent=find_parent(in_edge[i].dest,parent);
		
		if(src_parent!=dest_parent)
		{
			mst[count++]=in_edge[i];
			parent[src_parent]=dest_parent;
			cost+=in_edge[i].weight;
		}
		i++;
	}
	
	printf("\ndiplaying edges in MST \n");
	for(int j=0;j<V-1;j++)
		printf("%d %d %d\n",mst[j].source,mst[j].dest,mst[j].weight);
		
	printf("\ncost of MST is = %d\n",cost);
}
int main()
{
	int V,E;
	
	printf("\nenter no.of vertices and edges repectively : ");
	scanf("%d%d",&V,&E);
	
	struct Edge in_edge[E];
	
	printf("\nenter source destination and weight of each edge \n");
	for(int i=0;i<E;i++)
		scanf("%d%d%d",&in_edge[i].source,&in_edge[i].dest,&in_edge[i].weight);
    
	kruskal(in_edge,V,E);
		
	return 0;
}


