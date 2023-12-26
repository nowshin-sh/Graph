#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll n, m;
char ar[12][12];
bool visit[12][12];
ll mov[12][12], cnt[12][12];
ll dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
ll dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
bool isValid(ll x, ll y)
{
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    if(visit[x][y])
        return false;

    return true;
}
void bfs(ll x, ll y)
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            visit[i][j] = false;
        }
    }
    queue<pair<ll, ll>>q;
    q.push({x, y});
    ll a = ar[x][y]-'0';
    ll depth = 0;
    cnt[x][y]++;
    visit[x][y] = true;
    //cout<<x<<" "<<y<<endl;
    while(!q.empty())
    {
        depth++;
        ll sz = q.size();
        while(sz--)
        {
            pair<ll, ll>p = q.front();
            q.pop();
            for(ll i = 0; i < 8; i++)
            {
                if(isValid(p.first+dx[i], p.second+dy[i]))
                {
                    //cout<<depth<<" pp "<<p.first+dx[i]<<" "<<p.second+dy[i]<<endl;
                    q.push({p.first+dx[i], p.second+dy[i]});
                    visit[p.first+dx[i]][p.second+dy[i]] = true;
                    cnt[p.first+dx[i]][p.second+dy[i]]++;
                    if(depth%a==0)
                        mov[p.first+dx[i]][p.second+dy[i]]+=(depth/a);
                    else
                        mov[p.first+dx[i]][p.second+dy[i]]+=((depth/a)+1);
                }
            }
        }
    }
}
int main()
{
    FastRead
    ll t = 1;
    cin>>t;
    ll p = 1;
    while(t--)
    {
        cin>>n>>m;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                cin>>ar[i][j];
                mov[i][j] = 0;
            }
        }
        ll sum = 0;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                if(ar[i][j] != '.')
                {
                    sum++;
                    bfs(i, j);
                }
            }
        }
        ll ans = 1e9;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                //cout<<mov[i][j]<<" ";
                if(cnt[i][j] == sum)
                {
                    ans = min(ans, mov[i][j]);
                }
                cnt[i][j] = 0;
            }
            //cout<<endl;
        }
        cout<<"Case "<<p<<": ";
        p++;
        if(ans == 1e9)
        {
            cout<<-1<<endl;
        }
        else
            cout<<ans<<endl;

    }
    return 0;
}
///https://lightoj.com/problem/rider
