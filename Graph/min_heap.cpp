//building a min heap in O(N) time 
#include <bits/stdc++.h>
using namespace std;
void min_heapify(int a[] , int position , int n)
{
	int smallest = position;
	int firstele = 2*position+1;
	int secondele = 2*position+2;
	if(firstele<n && a[smallest]>a[firstele])
		smallest = firstele;
	if(secondele<n && a[smallest]>a[secondele])
		smallest = secondele;
	if(smallest!=position)
	{
		int temp = a[smallest];
		a[smallest] = a[position];
		a[position] = temp;
		min_heapify(a,smallest,n);
	}
}
void build_minHeap(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		min_heapify(a , i , n);
	}
}
int main() 
{
	int size, i,j,k,l,n,m,arr[100005];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	build_minHeap(arr,n);
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
