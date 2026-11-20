#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a.begin() + 1, a.end());
        long long sum = 0, ans = a[n];
        for(int i = 1; i <= n; i++) {
            ans -= 1LL * (i - 1) * a[i] - sum;
            sum += a[i];
        }
        cout << ans << endl;
    }
}