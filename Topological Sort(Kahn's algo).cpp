#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define white 0
#define grey 1
#define black 2
int n, m;
vector<vector<int>>adj(10005);
int inDegree[10005];
vector<int>ans;
void kahns_topologicalSort()
{
    priority_queue<int, vector<int>, greater<int> >pq;
    for(int i = 1; i <= n; i++)
    {
        if(inDegree[i] == 0)
        {
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        ll u = pq.top();
        ans.push_back(u);
        pq.pop();
        for(ll i = 0; i < adj[u].size(); i++)
        {
            inDegree[adj[u][i]]--;
            if(inDegree[adj[u][i]] == 0)
            {
                pq.push(adj[u][i]);
            }
        }
    }
}
int main()
{
    FastRead
    ll t = 1;
    //cin>>t;

    //ll p = 1;

    while(t--)
    {
        cin>>n>>m;
        for(int i = 1; i <= m; i++)
        {
            ll u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            inDegree[v]++;
        }
        kahns_topologicalSort();
        if(ans.size() != n)
        {
            cout<<"Sandro fails."<<endl;
        }
        else
        {
            for(int i = 0; i < ans.size(); i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
///SPOJ - TOPOSORT

