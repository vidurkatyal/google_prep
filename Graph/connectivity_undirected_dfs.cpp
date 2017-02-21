#include <bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int i,j,k,l,n,m,t,vis[100005];
void isConnected(int start , int vertices)
{
	if(vis[start]==1)
		return;
	vis[start]=1;
	for(int i=0;i<v[start].size();i++)
	{
		if(vis[v[start][i]]==0)
		{
			isConnected(v[start][i] , vertices);
		}
	}
}
int main() 
{
	int edge1,edge2;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>edge1>>edge2;
		v[edge1].push_back(edge2);
		v[edge2].push_back(edge1);
	}
	isConnected(1,n);
	int f=1;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			f=0;
			break;
		}
	}
	cout<<f;
	return 0;
}
