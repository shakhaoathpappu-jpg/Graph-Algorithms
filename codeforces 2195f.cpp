#include<bits/stdc++.h>
using namespace std;

static void solve() {
    int n; cin >> n;
    vector<long long> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        if (a[i] != a[j]) return a[i] > a[j];
        if (b[i] != b[j]) return b[i] < b[j];
        return c[i] > c[j];
    });

    auto above = [&](int i, int j) -> bool {
        long long da = a[i] - a[j], db = b[i] - b[j], dc = c[i] - c[j];
        if (da == 0 && db == 0) return dc > 0;
        if (da == 0) return false;
        if (da < 0) return false;
        return db * db - 4 * da * dc < 0;
    };

    vector<int> up(n, 1), dn(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (above(ord[j], ord[i]))
                up[i] = max(up[i], up[j] + 1);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (above(ord[i], ord[j]))
                dn[i] = max(dn[i], dn[j] + 1);
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[ord[i]] = up[i] + dn[i] - 1;

    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
}

int main() 
{
    int t; cin >> t;
    while(t--) solve();
    return 0;
}