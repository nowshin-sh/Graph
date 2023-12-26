#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define white 1
#define grey 2
#define black 3

// value of INT_MIN = -2147483648

ll num_of_nodes, num_of_edges;

ll color[1000];
vector<vector<ll> >adj(100);
ll parent[100];
ll dis[100];

void bfs(ll startingNode)
{
    for(ll i = 0; i < num_of_nodes; i++)
    {
        color[i] = white;
        dis[i] = INT_MIN;
        parent[i] = -1;
    }
    dis[startingNode] = 0;

    queue<ll>q;
    q.push(startingNode);

    while(!q.empty())
    {
        ll x = q.front();
        q.pop();
        color[x] = grey;
        cout<<x<<" ";
        for(ll i = 0; i < adj[x].size(); i++)
        {
            if(color[adj[x][i]] == white)
            {
                q.push(adj[x][i]);
                parent[adj[x][i]] = x;
                dis[adj[x][i]] = dis[x]+1;
            }
        }
        color[x] = black;
    }
}

int main()
{
    //freopen("dfs input.txt", "r", stdin);
    //ll num_of_nodes, num_of_edges;
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

    /// BFS implement using queue
    /// Here zero is source node
    bfs(0);
    cout<<endl;

    /// parent node and distance from starting node
    for(ll i = 0; i < num_of_nodes; i++)
    {
        cout<<"parent of "<<i<<"--> ";
        cout<<parent[i];
        cout<<endl;
    }

     for(ll i = 0; i < num_of_nodes; i++)
    {
        cout<<"dis of "<<i<<"--> ";
        cout<<dis[i];
        cout<<endl;
    }
    return 0;
}
