#include<bits/stdc++.h>
using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, b;
        cin >> n >> a >> b;
        a--;
        b--;
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            x--;
            y--;
            g[x].emplace_back(y, z);
            g[y].emplace_back(x, z);
        }
        auto Calc = [&](int s) {
            vector<int> d(n, -1);
            function<void(int, int)> Dfs = [&](int v, int p) {
                for (auto [to, w]: g[v]) {
                    if (to == p || to == b) {
                        continue;
                    }
                    d[to] = d[v] ^ w;
                    Dfs(to, v);
                }
            };
            d[s] = 0;
            Dfs(s, -1);
            return d;
        };
        vector<int> da = Calc(a), db = Calc(b);
        string ans = "NO";
        if (db[a] == 0) {
            ans = "YES";
        }
        db[b] = -2;
        set<int> s(db.begin(), db.end());
        for (int i: da) {
            if (i != -1 && s.count(i)) {
                ans = "YES";
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}