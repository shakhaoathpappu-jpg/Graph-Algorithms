#include<bits/stdc++.h>
using namespace std;

int sz[1010], par[1010], c[1010];
bool vis[1010];

int find(int x)
{
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if(a != b) {
        par[a] = b;
        sz[b] += sz[a];
    }
}

int main()
{
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        sz[i] = 1;
        par[i] = i;
    }
    vector<int> w(k);
    for(int i = 0; i < k; i++) cin >> w[i];
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        merge(a, b);
    }
    for(int i = 0; i < k; i++) {
        c[i] = sz[find(w[i])];
        vis[find(w[i])] = true;
    }

    sort(c, c + k);
    for(int i = 1; i <= n; i++) {
        int x = find(i);

        if(vis[x]) continue;
        vis[x] = true;
        c[k - 1] += sz[x];
    }
    int ans = -m;
    for(int i = 0; i < k; i++) ans += c[i] * (c[i] - 1) / 2;
    cout << ans << endl;
}