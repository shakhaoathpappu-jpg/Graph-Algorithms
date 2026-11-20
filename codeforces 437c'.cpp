#include<bits/stdc++.h>
using namespace std;
long long A[100009],id[10009];
long long ans = 0;
set<long long> G[1009];
bool cmp(const long long &a,const long long &b)
{
    return A[a] > A[b];
}
int main()
{
    long long N,M,i,j,k,T,cnt = 0,a,b,u;
    long long sum,lmt;
    cin >> N >> M;
    for(i = 1;i <= N;i++)
    {
        cin >> A[i];
        id[i] = i;
    }
    for(i = 0;i < M;i++)
    {
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }
    sort(id+1,id + 1 + N,cmp);
    for(i = 1;i <= N;i++)
    {
        u = id[i];
        for(auto v : G[u])
        {
            ans += A[v];
            G[v].erase(u);
        }
    }
    cout << ans << endl;
}
