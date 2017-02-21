//checking whether the given graph is bipartite or not
#include <bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int i,j,k,l,n,m,t,vis[100005],color[100005];
int isBipartite(int start)
{
	int check=1;
	queue<int>q;
	q.push(start);
	color[start]=1;
	while(!q.empty())
	{
		int vertex = q.front();
		q.pop();
		vis[vertex]=1;
		for(int i=0;i<v[vertex].size();i++)
		{
			if(vis[v[vertex][i]]==0)
			{
				q.push(v[vertex][i]);
				color[v[vertex][i]]=-color[vertex];
			}
			else if(vis[v[vertex][i]]==1 && color[vertex]==color[v[vertex][i]])
			{
				check = 0;
			}
		}
	}
	return check;
}
int checkBipartite(int vertices)
{
	int isBi = 1;
	for(int i=1;i<=vertices;i++)
	{
		if(vis[i]==0)
			isBi = isBipartite(i);
		if(isBi==0)
			break;
	}
	return isBi;
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
	cout<<checkBipartite(n)<<endl;
	return 0;
}
