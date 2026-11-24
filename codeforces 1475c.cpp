#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int a, b, k; cin >> a >> b >> k;
        vector<int> x(k), y(k), cnt1(a + 1), cnt2(b + 1);
        for(int i = 0; i < k; i++) {
            cin >> x[i];
            cnt1[x[i]]++;
        }
        for(int i = 0; i < k; i++) {
            cin >> y[i];
            cnt2[y[i]]++;
        }
        long long ans = 0;
        for(int i = 0; i < k; i++) ans += k - (cnt2[y[i]] + cnt1[x[i]] - 1);
        cout << ans / 2 << endl;
    }
}