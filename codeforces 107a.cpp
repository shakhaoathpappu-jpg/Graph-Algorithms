#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> to(n, -1), in(n, -1), d(n);
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;

        to[u] = v;
        in[v] = u;
        d[u] = w;
    }

    vector<string> ans;
    vector<bool> vis(n);
    for(int i = 0; i < n; i++) {
        if(in[i] == -1 && to[i] != -1 && !vis[i]) {
            stringstream ss;
            int mn = 1e9, j;
            for(j = i; to[j] != -1; j = to[j]) {
                if(vis[j]) goto cont;
                vis[j] = true;
                mn = min(mn, d[j]);
            }
            ss << i + 1 << " " << j + 1 << " " << mn;
            ans.push_back(ss.str());
            cont:;
        }
    }
    cout << ans.size() << endl;
    for(auto s : ans) cout << s << endl;
}