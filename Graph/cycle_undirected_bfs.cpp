//detecting cycle in an undirected graph using bfs
#include <bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int i,j,k,l,n,m,t,vis[100005];
int isCycle(int start)
{
	int cycle = 0,par[100005];
	queue<pair<int,int> >q;
	q.push(make_pair(start,-1));
	while(!q.empty())
	{
		int vertex = q.front().first;
		int parent = q.front().second;
		par[vertex]=parent;
		q.pop();
		vis[vertex]=1;
		for(int i=0;i<v[vertex].size();i++)
		{
			if(vis[v[vertex][i]]==0)
				q.push(make_pair(v[vertex][i],vertex));
			else
			{
				if(parent==par[v[vertex][i]])
					cycle=1;
			}
		}
	}
	return cycle;
}
int checkCycle(int vertices){
	
	int check=0;
	for(int i=1;i<=vertices;i++)
	{
		if(vis[i]==0)
		{
			check = isCycle(i);
			if(check==1)
				break;
		}
	}
	return check;
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
