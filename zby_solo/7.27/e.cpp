//Problem Web:https://vjudge.net/contest/315213#problem/E
//#include<bits/stdc++.h>
//#include<ext/rope>
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
ll tr(ll x, ll y)
{
    return x*101+y;
}
ll fa[1000000];
ll fi(ll x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=fi(fa[x]);
}
ll un(ll x,ll y)
{
    fa[fi(x)]=fi(y);
    fi(x);fi(y);
    return 1;
}
ll used[1000000];

string M[105];
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
    {
        cin>>M[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        { fa[tr(i,j)]=tr(i,j);
            }
        }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j]=='W')
            {
                if(i+1<n)
                {
                    if(j+1<m)
                    {
                        if(M[i+1][j+1]=='W')
                        {
                            un(tr(i,j),tr(i+1,j+1));
                        }
                    }
                    if(M[i+1][j]=='W')
                    {
                        un(tr(i,j),tr(i+1,j));
                    }
                }
                if(j+1<m)
                {
                    if(M[i][j+1]=='W')
                    {
                        un(tr(i,j),tr(i,j+1));
                    }
                }
                if(i-1>=0)
                {
                    if(M[i-1][j]=='W')
                    {
                        un(tr(i,j),tr(i-1,j));
                    }
                }

                if(i-1>=0 && j+1<m)
                {
                    if(M[i-1][j+1]=='W')
                    {
                        un(tr(i,j),tr(i-1,j+1));
                    }
                }
            }
        }
    }
    ll ans=0;
    mem(used,0);
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            fi(tr(i,j));
        }}
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j]=='W')
            if(used[fi(tr(i,j))]==0)
            {
                used[fi(tr(i,j))]=1;
                ans++;
//                cout<<"aa:"<<fi(tr(i,j))<<endl;
            }
        }}

//        for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//        {
//            cout<<fi(tr(i,j))<<" ";
//            }
//            cout<<endl;
//        }

cout<<ans;

#ifdef use_t
}
#endif // use_t
    return 0;
}
