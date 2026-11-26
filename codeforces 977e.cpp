#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10;
vector<int> adj[N];
bool vis[N];
bool is_cycle;

void dfs(int u) {
    vis[u] = true;
    if (adj[u].size() != 2) {
        is_cycle = false;
    }
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            is_cycle = true;
            dfs(i);
            if (is_cycle) {
                ans++;
            }
        }
    }
    
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}