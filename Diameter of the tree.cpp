#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll n;
vector<vector<ll> >adj(10002);
bool visit[10002];
ll maxD, maxNode;
void dfsVisit(ll x, ll d)
{
    visit[x] = true;
    if(d > maxD)
    {
        maxD = d;
        maxNode = x;
    }
    for(ll i = 0; i < adj[x].size(); i++)
    {
        if(!visit[adj[x][i]])
        {
            dfsVisit(adj[x][i], d+1);
        }
    }
}
int main()
{
    cin>>n;
    ll u, v;
    for(ll i = 1; i < n; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    maxD = -1;
    dfsVisit(1, 0);

    memset(visit, false, sizeof(visit));
    maxD = -1;
    dfsVisit(maxNode, 0);
    cout<<maxD<<endl;
    return 0;
}
///https://youtu.be/Tszillh1yXo
///https://www.spoj.com/problems/PT07Z/en/

