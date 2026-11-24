#include<bits/stdc++.h>
using namespace std;
int ans;
vector<pair<int,int>> adj[123];

void dfs(int u, int par, int sum)
{
    ans = max(ans, sum);
    for(auto x : adj[u]) {
        if(x.first != par)
            dfs(x.first, u, sum + x.second);
    }
}

int main()
{
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(0, -1, 0);
    cout << ans << endl;
}