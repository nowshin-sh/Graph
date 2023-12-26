///Kruskal's Algorithm
///https://www.youtube.com/watch?v=J7nUacHWtsM&t=6s

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N = 1e5+6;
vector<int>parent(N);
vector<int>sz(N);

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v)
{
    if(v == parent[v])
    {
        return v;
    }
    else
    {
        return parent[v] = find_set(parent[v]);
    }
}
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
        if(sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a]+=sz[b];
    }
}
int main()
{
    for(ll i = 0; i < N; i++)
    {
        make_set(i);
    }
    int n, m;
    cin>>n>>m;

    vector<pair<ll, pair<ll, ll>>>edge;
    for(ll i = 0; i < m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edge.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(edge.begin(), edge.end());
    int cost = 0;
    for(ll i = 0; i < m; i++)
    {
        int w = edge[i].first;
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        int x = find_set(u);
        int y = find_set(v);
        if(x == y)
        {
            continue;
        }
        else
        {
            cout<<u<<" "<<v<<endl;
            cost+=w;
            union_set(u, v);
        }
    }
    cout<<cost<<endl;
    return 0;
}


