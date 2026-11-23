#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() 
{
    int t; cin >> t;
    auto solve = [&]() {
        int n; cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        vector<int> vis(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            int len = 0;
            for (int j = i; !vis[j]; j = p[j]) {
                vis[j] = true;
                len++;
            }
            ans += (len - 1) / 2;
        }
        cout << ans << '\n';
    };

    while (t--) {
        solve();
    }
    return 0;
}
