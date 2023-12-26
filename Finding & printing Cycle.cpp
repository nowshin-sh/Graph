#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<vector<int>>adj(10005);
bool visited[10005];
int parent[10005] = {-1};
vector<ll>circle;
bool dfs(ll u)
{
    visited[u] = true;
    circle.push_back(u);
    for(ll i = 0; i < adj[u].size(); i++)
    {
        if(visited[adj[u][i]] == false)
        {
            parent[adj[u][i]] = u;
            if(dfs(adj[u][i]) == true)
            {
                return true;
            }
        }
        else
        {
            if(parent[u] != adj[u][i])
            {
                circle.push_back(adj[u][i]);
                return true;
            }
        }
    }
    circle.pop_back();
    return false;
}
int main()
{
    FastRead
    ll t = 1;
    //cin>>t;

    //ll p = 1;

    while(t--)
    {
        int n, m, u, v;
        cin>>n>>m;

        for(int i = 0; i < m; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool store = dfs(1);
        if(store == true)
        {
            cout<<"Exist cycle in graph"<<endl;
            ll sz = circle.size();
            cout<<sz<<endl;
            for(ll i = sz-1; i >= 0; i--)
            {
                if(i != sz-1 && circle[i] == circle[sz-1])
                {
                    break;
                }
                cout<<circle[i]<<" ";
            }
        }
        else
        {
            cout<<"Cycle does not exist"<<endl;
        }
    }
    return 0;
}
///Input
/*
5 5
1 5
1 4
2 4
2 3
3 4
*/

