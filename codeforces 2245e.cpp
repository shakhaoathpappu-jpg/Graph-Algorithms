#include <bits/stdc++.h>
using namespace std;
const int c=500005;
int n, deg[c];
vector<int> sz[c];
bool v[c];
long long cnt, ans;
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (deg[x]%2) {
            cnt++;
        } else if (!v[x]) {
            dfs(x);
        }
    }
}
void solve() {
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        deg[i]=sz[i].size();
    }
    for (int i=1; i<=n; i++) {
        if (!v[i] && deg[i]%2==0) {
            dfs(i);
            ans=ans+cnt*(cnt-1)/2;
            cnt=0;
        }
    }
    for (int i=1; i<=n; i++) {
        if (deg[i]%2) {
            for (auto x:sz[i]) {
                if (deg[x]%2 && i<x) {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";

    ans=0, cnt=0;
    for (int i=0; i<=n; i++) {
        deg[i]=0, sz[i].clear(), v[i]=0;
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
}
