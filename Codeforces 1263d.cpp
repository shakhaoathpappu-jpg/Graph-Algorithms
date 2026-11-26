#include<bits/stdc++.h>
using namespace std;
int par[200000];

int find(int x)
{
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(par[a] > par[b])
        par[a] = b;
    else {
        if(par[a] == par[b])
            par[a]--;

        par[b] = a;
    }
}

int main()
{
    int n; cin >> n;
    memset(par, -1, n * sizeof(int));
    vector<int> p(26, -1);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(auto c : s) {
            int x = c - 'a';

            if(p[x] != -1) merge(p[x], i);
            p[x] = i;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(par[i] < 0)
            ans++;
    }
    cout << ans << endl;
}