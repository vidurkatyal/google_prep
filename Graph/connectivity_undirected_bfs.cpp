//using bfs to check connectivity in an undirected graph
#include <bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int i,j,k,l,n,m,t,vis[100005];
int isConnected(int start , int vertices)
{
	queue<int>q;
	q.push(start);
	vis[start]=1;
	while(!q.empty())
	{
		l = q.front();
		q.pop();
		for(j=0;j<v[l].size();j++)
		{
			if(vis[v[l][j]]==0)
			{
				vis[v[l][j]]=1;
				q.push(v[l][j]);
			}
		}
	}
	int f=1;
	for(i=1;i<=vertices;i++)
	{
		if(vis[i]==0)
		{
			f=0;
			break;
		}
	}
	return f;
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
	cout<<isConnected(1,n)<<endl;
	return 0;
}
