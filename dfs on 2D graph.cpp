#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll n, m;
char ar[1002][1002];
bool visit[1002][1002];
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
ll ans = 0;
bool isValid(ll x, ll y)
{
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    if(visit[x][y])
        return false;

    return true;
}
void dfsVisit(ll x, ll y)
{
    visit[x][y] = true;
    for(ll i = 0; i < 4; i++)
    {
        if(isValid(x+dx[i], y+dy[i]))
        {
            dfsVisit(x+dx[i], y+dy[i]);
        }
    }
}
void dfs()
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            if(!visit[i][j])
            {
                ans++;
                dfsVisit(i, j);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            cin>>ar[i][j];
            if(ar[i][j] == '#')
                visit[i][j] = true;
        }
    }
    dfs();
    cout<<ans<<endl;
    return 0;
}
///https://cses.fi/problemset/task/1192
