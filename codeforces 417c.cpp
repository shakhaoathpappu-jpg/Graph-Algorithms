#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    if(n < 2 * k + 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << k * n << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            cout << i << " " << (i + j - 1) % n + 1 << endl;
        }
    }
}