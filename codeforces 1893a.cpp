#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n,k; cin >> n >> k;
        int b[n];
        for(int j = 0;j < n;++j) cin >> b[j];
        bool p[n];
        for(int u = 0;u < n;++u) p[u] = 0;
        p[0] = 1;
        int no = 0;
        int tpos = 0;
        for(int j = 0;j < k;++j)
        {
            if(b[(tpos+n-1)%n] > n)
            {
                no = 1;
                break;
            }
            else
            {
                tpos = (tpos + n - b[(tpos+n-1)%n])%n;
            }
            if(p[tpos]) break;
            else p[tpos] = 1;
        }
        cout << (no ? "No\n" : "Yes\n");
    }
}
