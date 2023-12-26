#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define white 1
#define grey 2
#define black 3
ll mat[1000][1000];
ll inf = INT_MAX;
ll num_of_nodes, num_of_edges;

void floyd()
{
    for(ll i = 1; i <= num_of_nodes; i++)
    {
        mat[i][i] = 0;
    }

    for(ll k = 1; k <= num_of_nodes; k++)
    {
        for(ll i = 1; i <= num_of_nodes; i++)
        {
            for(ll j = 1; j <= num_of_nodes; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
    }
}

int main()
{
    //freopen("dfs input.txt", "r", stdin);
    cin>>num_of_nodes>>num_of_edges;

    for(ll i = 1; i <= num_of_nodes; i++)
    {
        for(ll j = 1; j <= num_of_nodes; j++)
        {
            mat[i][j] = inf;
        }
    }

    ///undirected and unweighted graph

    for(ll i = 0; i < num_of_edges; i++)
    {
        ll u, v, w;
        cin>>u>>v>>w;

        /// u & v are connected vertex & w is weight

        mat[u][v] = w;
    }

    /// floyd implement using recursion
    floyd();

    for(ll i = 1; i <= num_of_nodes; i++)
    {
        cout<<i<<"--> ";
        for(ll j = 1; j <= num_of_nodes; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
