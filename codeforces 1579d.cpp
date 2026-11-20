#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        priority_queue<pair<int,int>> pq;
        for(int i = 1; i <= n; i++) {
            int a; cin >> a;
            if(a > 0) pq.push({a, i});
        }
        vector<pair<int,int>> res;
        while(pq.size() >= 2) {
            auto [a1, i1] = pq.top(); pq.pop();
            auto [a2, i2] = pq.top(); pq.pop();
            res.push_back({i1, i2});
            if(--a1 > 0) pq.push({a1, i1});
            if(--a2 > 0) pq.push({a2, i2});
        }
        cout << res.size() << endl;
        for(auto p : res) cout << p.first << " " << p.second << endl;
    }
}