//building a max heap in O(N) time 
#include <bits/stdc++.h>
using namespace std;
void max_heapify(int a[] , int position , int n)
{
	int largest = position;
	int firstele = 2*position+1;
	int secondele = 2*position+2;
	if(firstele<n && a[largest]<a[firstele])
		largest = firstele;
	if(secondele<n && a[largest]<a[secondele])
		largest = secondele;
	if(largest!=position)
	{
		int temp = a[largest];
		a[largest] = a[position];
		a[position] = temp;
		max_heapify(a,largest,n);
	}
}
void build_maxHeap(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		max_heapify(a , i , n);
	}
}
int main() 
{
	int size, i,j,k,l,n,m,arr[100005];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	build_maxHeap(arr,n);
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
