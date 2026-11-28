#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    vector<pair<pair<int, int>, int>> edges;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({{x, y}, z});
    }
    vector<bool> f(n + 1, false);
    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        f[x] = true;
    }
    int ans = 1e9 + 11;
    for(int i = 0; i < m; i++) {
        int x = edges[i].first.first;
        int y = edges[i].first.second;
        if(f[x] != f[y]) {
            ans = min(ans, edges[i].second);
        }
    }
    if(ans == 1e9 + 11) ans = -1;
    cout << ans << endl;
}