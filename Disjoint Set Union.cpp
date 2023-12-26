///Cycle Detection in Undirected Graph using DSU
///https://www.youtube.com/watch?v=YZ40AZQi0bk&t=247s

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

    vector<pair<ll, ll>>edge;
    for(ll i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        edge.push_back({u, v});
    }
    bool cycle = false;
    for(ll i = 0; i < m; i++)
    {
        int u = edge[i].first;
        int v = edge[i].second;
        int x = find_set(u);
        int y = find_set(v);
        if(x == y)
        {
            cycle = true;
        }
        else
        {
            union_set(u, v);
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        cout<<parent[i]<<" "<<i<<endl;
    }
    if(cycle)
    {
        cout<<"Cycle is found"<<endl;
    }
    else
    {
        cout<<"Does not contain a cycle"<<endl;
    }
    return 0;
}

