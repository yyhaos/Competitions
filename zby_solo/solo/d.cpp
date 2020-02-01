//Problem Web:https://vjudge.net/contest/353524
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
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
//#define mp make_pair
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
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
ll ans;
char mp[55][55];
int fx[4]={0,0,-1,1};
int fy[4]={-1,1,0,0};
int vis[55][55];
void dfs(ll x,ll y)
{int smell=0;if(vis[x][y]!=0)return ;vis[x][y]=1;
    if(mp[x][y]=='G')ans++;
    for(int i=0;i<4;i++)
    {
        if(mp[x+fx[i]][y+fy[i]]=='T')
        {
            smell=1;
        }
    }
    if(smell==0)
    {
        for(int i=0;i<4;i++)
        {
            if(mp[x+fx[i]][y+fy[i]]!='#')
            {
                dfs(x+fx[i],y+fy[i]);
            }
        }
    }
}
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
    while(cin>>n>>m)
    {ans=0;memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            scanf("%s",mp[i]);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[i][j]=='P')
                {
                    dfs(i,j);
                }
            }
        }
        cout<<ans<<"\n";
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}



