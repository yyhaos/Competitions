//Problem Web:https://pintia.cn/problem-sets/994805046380707840/problems/994805073643683840
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
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
ll M[505][505];
ll N[505][505];
ll g[505];
ll s,d;
ll dp[505];

ll dfs(ll th)
{
    if(th==s)
        return 1;
    //cout<<th<<endl;
    ll ans=0;
    rep(i,0,n-1)
    {
        if(i==th)
            continue;
        if(M[s][i]+N[i][th]==M[s][th])
        {
                ans+=dfs(i);
        }
    }
    return ans;
}
vector<ll > path;
ll dfs2(ll th)
{
    if(dp[th]!=-1)
        return dp[th];
    ll ans=-9999999999999LL;
    if(th==s)
        return g[s];
    ll ff=-1;
    rep(i,0,n-1)
    {
        if(i==th)
            continue;
        if(M[s][i]+M[i][th]==M[s][th])
        {
            ans=max(ans,g[th]+dfs2(i));
            if(ans==g[th]+dfs2(i))
            {
                ff=i;
            }
        }
    }
    path.push_back(ff);
    return dp[th]=ans;
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

    cin>>n>>m>>s>>d;
    rep(i,0,n-1)
    {
        dp[i]=-1;
        rep(j,0,n-1)
        {
            N[i][j]=M[i][j]=9999999999999LL;
        }
        N[i][i]=M[i][i]=0;
    }
    rep(i,0,n-1)
    {
        scanf("%lld",&g[i]);
    }
    ll u,v,l;
    rep(i,1,m)
    {
        scanf("%lld%lld%lld",&u,&v,&l);
        M[u][v]=M[v][u]=l;
        N[u][v]=N[v][u]=l;
    }
    rep(k,0,n-1)
    {
        rep(i,0,n-1)
        {
            rep(j,0,n-1)
            {
                if(M[i][j]>M[i][k]+M[j][k])
                {
                    M[i][j]=M[i][k]+M[j][k];
                }
            }
        }
    }
//    rep(k,0,n-1)
//    {
//        rep(i,0,n-1)
//        {
//            cout<<M[k][i]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<dfs(d)<<" "<<dfs2(d)<<endl;
    //cout<<endl<<s;
    rep(i,0,path.size()-1)
    {
        if(i)
            cout<<" ";
        cout<<path[i];
    }
    cout<<" "<<d;

#ifdef use_t
}
#endif // use_t
    return 0;
}
