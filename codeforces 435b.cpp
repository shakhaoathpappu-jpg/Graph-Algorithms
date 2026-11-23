#include<bits/stdc++.h>
using namespace std;

bool e[401][401], vis[401];
int n, m, ord[401], cnt, scc[401];
string p, q;

int num(int x, int y)
{
    return m * x + y;
}

void dfs(int a)
{
    vis[a] = true;

    for(int i = 0; i < n * m; i++) {
        if(e[a][i] && !vis[i])
            dfs(i);
    }

    ord[++cnt] = a;
}
void dfs2(int a)
{
    scc[a] = 1;
    for(int i = 0; i < n * m; i++) {
        if(e[i][a] && !scc[i])
            dfs2(i);
    }
}

int main()
{
    cin >> n >> m; cin >> p >> q;
    for(int i = 0; i < n; i++) {
        if(p[i] == '>') {
            for(int j = 0; j < m - 1; j++)
                e[num(i, j)][num(i, j + 1)] = true;
        }
        else {
            for(int j = 0; j < m - 1; j++)
                e[num(i, j + 1)][num(i, j)] = true;
        }
    }
    for(int i = 0; i < m; i++) {
        if(q[i] == 'v') {
            for(int j = 0; j < n - 1; j++)
                e[num(j, i)][num(j + 1, i)] = true;
        }
        else {
            for(int j = 0; j < n - 1; j++)
                e[num(j + 1, i)][num(j, i)] = true;
        }
    }
    for(int i = 0; i < n * m; i++) {
        if(!vis[i]) dfs(i);
    }
    dfs2(ord[cnt]);
    int i;
    for(i = 0; i < n * m; i++) {
        if(!scc[i]) break;
    }
    if(i == n * m) cout << "YES" << endl;
    else cout << "NO" << endl;
}