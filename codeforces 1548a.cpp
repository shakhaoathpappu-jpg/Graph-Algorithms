#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int cnt = n;
    vector<int> lab(n + 1);
    auto add = [&](int u, int v) {
        if(u > v) swap(u, v);
        lab[u]++;
        if(lab[u] == 1) cnt--;
    };
    auto del = [&](int u, int v) {
        if(u > v) swap(u, v);
        lab[u]--;
        if(lab[u] == 0) cnt++;
    };
    while(m--) {
        int u, v; cin >> u >> v;
        add(u, v);
    }
    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int u, v; cin >> u >> v;
            add(u, v);
        }
        else if(op == 2) {
            int u, v; cin >> u >> v;
            del(u, v);
        }
        else cout << cnt << endl;
    }
}