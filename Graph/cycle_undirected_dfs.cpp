//detecting cycle in an undirected graph using dfs
#include <bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int i,j,k,l,n,m,t,cycle=0,vis[100005];
void isCycle(int start , int parent)
{
	vis[start]=1;
	for(int i=0;i<v[start].size();i++)
	{
		if(vis[v[start][i]]==0)
			isCycle(v[start][i] , start);
		else if(v[start][i] != parent)
			cycle = 1;		
	}
	return;
}
int checkCycle(int vertices)
{
	for(int i=1;i<=vertices;i++)
	{
		if(vis[i]==0)
			isCycle(i,-1);
		if(cycle==1)
			break;			
	}
	return cycle;
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
	cout<<checkCycle(n);
	return 0;
}
