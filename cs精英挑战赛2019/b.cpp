//Problem Web:http://www.bnuoj.com/contest_show.php?cid=9505#problem/B
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
string str[100];
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}

ll t,n,m;
ll dis[100][100];
struct pos
{
    ll x,y;
    pos(ll _x=0,ll _y=0)
    {
        x=_x;
        y=_y;
    }
    bool ok()
    {
        if(x<0 || y<0|| x>=n|| y>=m|| str[x][y]=='#')
            return false;
        return true;
    }
} dir[10]={{1,0},{-1,0},{0,1},{0,-1}};

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>str[i];
    ll x,y;
    //cout<<str[0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='@')
                x=i,y=j;
        }
    }
    mem(dis,0);
    queue<pos >qq;
    qq.push(pos(x,y));
    dis[x][y]=1;
    ll ans=1;
    while(!qq.empty())
    {
        pos tt=qq.front();
        qq.pop();
        cout<<tt.x<<" "<<tt.y<<endl;
        if(dis[tt.x][tt.y]!=0)
            continue;
        dis[tt.x][tt.y]=1;
        ans++;
        for(int i=0;i<4;i++)
        {
            pos nxt;
            nxt.x=tt.x+dir[i].x;
            nxt.y=tt.y+dir[i].y;
            if(nxt.ok())
            {
                if(dis[tt.x][tt.y]!=0)
            continue;
                qq.push(nxt);
            }
        }

    }
    cout<<ans<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}
