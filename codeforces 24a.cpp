#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> >graph[109];

int dfs(int i,int prev,int k)
{
    if(i==k) return 0;
    int ret=0;
    for(int f=0;f<graph[i].size();f++)
    {
        if(graph[i][f].first!=prev){
            ret+=dfs(graph[i][f].first,i,k)+graph[i][f].second;
        }
    }
    return ret;
}

int main()
{
    int n,a,b,c,arr[3][109]; cin>>n;
    for(int f=0;f<n;f++)
    {
        cin>>a>>b>>c;
        arr[0][f]=a;
        arr[1][f]=b;
        arr[2][f]=c;
        graph[a].push_back({b,0});
        graph[b].push_back({a,c});
    }
    int mini=1e9+9;
    for(int f=0;f<n;f++)
    {
        mini=min(mini,dfs(arr[1][f],arr[0][f],arr[0][f]));
        mini=min(mini,dfs(arr[0][f],arr[1][f],arr[1][f])+arr[2][f]);
    }
    cout<<mini<<endl;
}
