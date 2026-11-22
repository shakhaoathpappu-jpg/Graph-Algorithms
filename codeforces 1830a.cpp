#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> > e[200005];
vector<int> S;
int nw,ans;

void dfs(int u,int fa)
{
	for(auto v:e[u])
	{
		if(v.first==fa) continue;
		int w=(v.second<S.back());
		S.push_back(v.second);
		nw+=w,ans=max(ans,nw);
		dfs(v.first,u);
		nw-=w,S.pop_back();
	}
}
void Diana()
{
	nw=ans=0;
	S.clear();
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	S.push_back(10000000);
	dfs(1,0);
	cout << ans << "\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while(T--) Diana();
	return 0;
}