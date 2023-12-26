#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll n, m;
vector<vector<ll> >adj(10002);
bool visit[10002];
ll parent = -1;
bool dfsVisit(ll x)
{
    visit[x] = true;

    for(ll i = 0; i < adj[x].size(); i++)
    {
        if(!visit[adj[x][i]])
        {
            parent = x;
            if(dfsVisit(adj[x][i]))
                return true;
        }
        else
        {
            if(adj[x][i] != parent)
                return true;
        }
    }
    return false;
}
bool dfs()
{
    if(dfsVisit(1))
        return true;

    for(ll i = 2; i <= n; i++)
    {
        if(!visit[i])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    ll u, v;
    for(ll i = 0; i < m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(m == n-1)
    {
        bool ans = dfs();
        if(ans)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
///https://youtu.be/SKUOVLqcR9s
///https://www.spoj.com/problems/PT07Y/en/
/// Tree characteristics
//Connected Components
//Acyclic (means no cycle in graph)
