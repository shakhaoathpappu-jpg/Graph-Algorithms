#include<bits/stdc++.h>
using namespace std;
int s[200000][2],vis[200000],col[200000],flag;
vector<int>line[200000];

void dfs(int t){
	vector<int>::iterator it;
	vis[t]=1;
	s[t][0]=0;
	s[t][1]=0;
	s[t][col[t]]=1;
	for(it=line[t].begin();it!=line[t].end();it++)
	{
		if(vis[*it])
		{
			if(col[t]==col[*it])flag=1;
			continue;
		}
		col[*it]=col[t]^1;
		dfs(*it);
		s[t][0]+=s[*it][0];
		s[t][1]+=s[*it][1];
	}
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,m,i,u,v,ans;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>m;
		for(i=0;i<m;i++)
		{
			cin>>u>>v;
			line[u-1].push_back(v-1);
			line[v-1].push_back(u-1);
		}
		for(i=0;i<n;i++)vis[i]=0;
		ans=0;
		for(i=0;i<n;i++)
		{
			if(vis[i])continue;
			col[i]=0;
			flag=0;
			dfs(i);
			if(!flag)ans+=max(s[i][0],s[i][1]);
		}
		cout<<ans<<'\n';
		for(i=0;i<n;i++)line[i].clear();
	}
	return 0;
}