#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define white 1
#define grey 2
#define black 3

// value of INT_MIN = -2147483648

ll num_of_nodes, num_of_edges;
vector<vector<pair<ll, ll> > >adj(100);
ll dis[100];
ll inf = LONG_MAX;

void dijkstra(ll startingNode)
{
    for(ll i = 1; i <= num_of_nodes; i++)
    {
        dis[i] = inf;
    }
    dis[startingNode] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> >pq;

    pq.push({0, startingNode});

    while(!pq.empty())
    {
        ll x = pq.top().second;
        ll y = pq.top().first;
        pq.pop();

        if(y > dis[x])
        {
            continue;
        }

        for(ll i = 0; i < adj[x].size(); i++)
        {
            ll v = adj[x][i].first;
            ll w = adj[x][i].second;
            /// If there is shorted path to v through u.
            if(dis[v] > dis[x]+w)
            {
                ///Updating distance of v
                dis[v] = dis[x]+w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main()
{
    cin>>num_of_nodes>>num_of_edges;

    ///undirected and unweighted graph

    for(ll i = 0; i < num_of_edges; i++)
    {
        ll u, v, w;
        cin>>u>>v>>w;

        /// u & v are connected vertex and weight of edge w

        adj[u].push_back({v, w});
    }

    for(ll i = 1; i <= num_of_nodes; i++)
    {
        cout<<i<<"--> ";
        for(ll j = 0; j < adj[i].size(); j++)
        {
            pair<ll,ll>p = adj[i][j];
            cout<<"{"<<p.first<<", "<<p.second<<"} ";
        }
        cout<<endl;
    }
    dijkstra(1);

    cout<<"Vertex Distance from Source\n";
    for(ll i = 1; i <= num_of_nodes; i++)
    {
        cout<<i<<" ---> "<<dis[i]<<endl;;
    }
    return 0;
}
