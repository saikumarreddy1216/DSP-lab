#include<iostream>
#include<stdio.h>
using namespace std;
void merge_sort(int a[],int p,int r);
void merge(int a[],int p,int q,int r);
void find_start_and_end(int a[],int item,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==item)
		{
			cout<<"starting point is "<<i+1<<endl;
			i++;
			break;
		}
	}
	
	while(a[i]==item) i++;
	cout<<"end point is "<<i<<endl;
}
int main()
{
	int n,i;
	cout<<"no.of elements ";
	cin>>n;
	int a[n];
	cout<<"enter elements into array ";
	for(i=0;i<n;i++) cin>>a[i];
	merge_sort(a,0,n-1);
	cout<<"sorted array ";
	for(i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	int p;
	cout<<"enter the element for which u want to find start and end points ";
	cin>>p;
	find_start_and_end(a,p,n);
	
	return 0;
}
void merge_sort(int a[],int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}
void merge(int a[],int p,int q,int r)
{
	int x=q-p+1;
	int y=r-q;
	int L[x],R[y];
	int i,j;
	for(i=p;i<=q;i++) L[i-p]=a[i];
	for(j=q+1;j<=r;j++) R[j-q-1]=a[j];
	int k=p;
	i=0;
	j=0;
	
	while(k<=r)
	{ 
	if(i<x && j<y)
	  {
		if(L[i]>R[j]) 
		{
			a[k]=R[j];
			j++;
			k++;
		}
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
			k++;
		}
	 }
	 else if(i==x && j<y)
	 {
	 	while(j<y)
	 	{
	 	 a[k]=R[j];
		  j++;
		  k++;	
		}
	 }
	 else if(i<x && j==y)
	 {
	 	while(i<x)
	 	{
	 	a[k]=L[i];
		 i++;
		 k++;	
		}
	 }
	}
	
	
	
}
