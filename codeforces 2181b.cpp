#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100000], b[100000];

void solve() {
    priority_queue<int> pq[2];
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pq[0].push(a[i]);
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        pq[1].push(b[i]);
    }
    int i = 0;
    while (!pq[0].empty() && !pq[1].empty()) {
        int b = pq[i ^ 1].top(); pq[i ^ 1].pop();
        b = b - pq[i].top();
        if (b > 0) pq[i ^ 1].push(b);
        i ^= 1;
    }
    if (pq[0].empty()) cout << "Bob\n";
    else cout << "Alice\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}