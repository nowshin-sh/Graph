#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll num_of_nodes, num_of_edges;
vector<tuple<int, int, int>>adj(100);
ll inf = LONG_MAX;
ll dis[100];
bool ans;

void bellmanFord(ll startingNode)
{
    for(ll i = 1; i <= num_of_nodes; i++)
    {
        dis[i] = inf;
    }
    dis[startingNode] = 0;

    for(ll i = 1; i < num_of_nodes; i++)
    {
        for(ll j = 0; j < num_of_edges; j++)
        {
            ll u, v, w;
            tie(u, v, w) = adj[j];

            if(dis[u]+w < dis[v])
            {
                dis[v] = dis[u]+w;
            }
        }
    }

    for(ll j = 0; j < num_of_edges; j++)
    {
        ll u, v, w;
        tie(u, v, w) = adj[j];

        if(dis[u]+w < dis[v])
        {
            ans = true;
        }
    }
}

int main()
{
    cin>>num_of_nodes>>num_of_edges;
    ll j = 0;

    for(ll i = 0; i < num_of_edges; i++)
    {
        ll u, v, w;
        cin>>u>>v>>w;

        /// u & v are connected vertex and weight of edge w

        adj[i] = {u, v, w};
    }

    bellmanFord(1);

    if(ans)
    {
        cout<<"Negative Cycle Detected"<<endl;
    }
    else
    {
        cout<<"Vertex Distance from Source\n";
        for(ll i = 1; i <= num_of_nodes; i++)
        {
            cout<<i<<" ---> "<<dis[i]<<endl;;
        }
    }
    return 0;
}
