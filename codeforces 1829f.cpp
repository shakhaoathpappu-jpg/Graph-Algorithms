#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int>d(n + 1);
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            d[u]++;
            d[v]++;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int c = -1;
        for(int i = 1; i <= n; i++) {
            if(d[i] < 2) continue;
            bool ok = false;
            for(int j : adj[i]) {
                if(d[j] == 1) {
                    ok = true;
                    break;
                }
            }
            if(!ok) {
                c = i;
                break;
            }
        }
        int x = d[c];
        int mid = adj[c][0];
        int y = d[mid] - 1;
        cout << x << " " << y << endl;
    }
}