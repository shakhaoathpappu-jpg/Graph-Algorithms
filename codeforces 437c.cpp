#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> p(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> p[i];

    int sum = 0;

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        sum += min(p[x], p[y]);
    }

    cout << sum << endl;
}