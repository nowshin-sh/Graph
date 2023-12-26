#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define white 1
#define grey 2
#define black 3

ll color[1000];
vector<vector<ll> >adj(100);

void dfsVisit(ll x)
{
    color[x] = grey;

    for(ll i = 0; i < adj[x].size(); i++)
    {
        cout<<x<<" up --> "<<adj[x][i]<<endl;
        if(color[adj[x][i]] == white)
        {
            dfsVisit(adj[x][i]);
        }
        cout<<x<<" down --> "<<adj[x][i]<<endl;
    }

    color[x] = black;
}

void dfs(ll n)
{
    for(ll i = 0; i < n; i++)
    {
        color[i] = white;
    }

    for(ll i = 0; i < n; i++)
    {
        if(color[i] == white)
        {
            cout<<i<<" xx --> "<<endl;
            dfsVisit(i);
        }
    }
}

int main()
{
    //freopen("dfs input.txt", "r", stdin);
    ll num_of_nodes, num_of_edges;
    cin>>num_of_nodes>>num_of_edges;

    ///undirected and unweighted graph

    for(ll i = 0; i < num_of_edges; i++)
    {
        ll u, v;
        cin>>u>>v;

        /// u & v are connected vertex

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(ll i = 0; i < num_of_nodes; i++)
    {
        cout<<i<<"--> ";
        for(ll j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    /// DFS implement using recursion
    dfs(num_of_nodes);

    for(ll i = 0; i < num_of_nodes; i++)
    {
        cout<<color[i]<<" ";
    }
    cout<<endl;
    return 0;
}
