#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff first;
#define ss second;
#define white 1
#define grey 2
#define black 3
double PI = 3.14159265358979323846;
vector<vector<pair<int, ll>>>adj(100006);
ll inf = 1e18;
vector<vector<ll>>dis(100006);
int n, m, k;

void dijkstra(int st)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            dis[i].push_back(inf);
        }
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> >pq;

    pq.push({0, st});


    while(!pq.empty())
    {
        int x = pq.top().second;
        ll y = pq.top().first;
        //cout<<x<<" "<<y<<endl;
        pq.pop();

        if(y > dis[x][k-1])
        {
            continue;
        }

        for(int i = 0; i < adj[x].size(); i++)
        {
            int v = adj[x][i].first;
            ll w = adj[x][i].second;

            if(dis[v][k-1] > y+w)
            {
                dis[v][k-1] = y+w;
                pq.push({dis[v][k-1], v});
                sort(dis[v].begin(), dis[v].end());
            }
        }
    }
}

int main()
{
    FastRead
    int t = 1;
    //cin>>t;

    //ll p = 1;

    while(t--)
    {
        cin>>n>>m>>k;

        for(int i = 0; i < m; i++)
        {
            int a, b;
            ll c;
            cin>>a>>b>>c;

            adj[a].push_back({b, c});
        }
        dijkstra(1);

        /*for(int i = 1; i <= n; i++)
        {
            cout<<i<<" --> ";
            for(int j = 0; j < k; j++)
            {
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }*/

        for(ll i = 0; i < dis[n].size(); i++)
        {
            cout<<dis[n][i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

