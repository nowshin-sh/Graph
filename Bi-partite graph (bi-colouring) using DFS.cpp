#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<vector<ll> >adj(2005);
bool visited[2005];
int color[2005];
int n, m;
bool dfs(ll u)
{
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++)
    {
        if(visited[adj[u][i]] == false)
        {
            if(color[u] == 1)
            {
                color[adj[u][i]] = 2;
                if(dfs(adj[u][i]) == false)
                {
                    return false;
                }
            }
            else
            {
                color[adj[u][i]] = 1;
                if(dfs(adj[u][i]) == false)
                {
                    return false;
                }
            }
        }
        else
        {
            if(color[u] == color[adj[u][i]])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    FastRead
    ll t = 1;
    cin>>t;

    ll p = 1;

    while(t--)
    {
        cin>>n>>m;
        int u, v;
        for(int i = 0; i < m; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans;
        for(ll i = 1; i < n; i++)
        {
            if(visited[i] == false)
            {
                color[i] = 1;
                ans = dfs(i);
                if(ans == false)
                {
                    break;
                }
            }
        }
        if(ans == true)
        {
            cout<<"Scenario #"<<p<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        }
        else
        {
            cout<<"Scenario #"<<p<<":"<<endl;
            cout<<"Suspicious bugs found!"<<endl;
        }
        p++;
        for(ll i = 1; i <= n; i++)
        {
            adj[i].clear();
            visited[i] = false;
            color[i] = 0;
        }
    }
    return 0;
}
///BUGLIFE -SPOJ problem
