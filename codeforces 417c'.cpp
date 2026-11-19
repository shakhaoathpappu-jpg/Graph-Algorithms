#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, k, a[N][N], cnt[N];
vector<int> v[N];

int main()
{
    cin >> n >> k;
    int m = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && a[i][j] != 1 && a[i][j] != 1 && cnt[i] < k){
                cnt[i] += 1;
                a[i][j] = 1;
                a[j][i] = 1;
                v[i].push_back(j);
                m++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(cnt[i] < k){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << m << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < v[i].size(); j++){
            cout << i + 1 << ' ' << v[i][j] + 1 << endl;
        }
    return 0;
}
