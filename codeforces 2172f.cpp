#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n), g1(n), g2(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    g1 = a;
    g2 = a;
    for(int i = 1; i < n; i++) g1[i] = gcd(g1[i - 1], g1[i]);
    for(int i = n - 2; i >= 0; i--) g2[i] = gcd(g2[i], g2[i + 1]);
    long long ans = g2[0];
    int x = n - 2, y = 1;
    while(y <= x) {
        if(g1[x] < g2[y]) ans += g1[x--];
        else ans += g2[y++];
    }
    cout << ans << endl;
}