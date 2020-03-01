//Problem Web:https://vjudge.net/contest/355936#problem/D
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
char pa[200005][55];
ll f[200005];
ll fi(ll x)
{
    if(f[x]==x)return x;
    return f[x]=fi(f[x]);
}
ll u(ll x,ll y)
{
//    fi(x);fi(y);
    if(fi(x)!=fi(y))
    f[fi(x)]=y;
    fi(x);fi(y);
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
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%s",pa[i]);
//        cout<<pa[i]<<endl;
    }

    for(int i=0;i<n;i++)
        f[i]=i;
    int st=-1;
    for(int i='a';i<='z';i++)
    {
        st=-1;
        for(int j=0;j<n;j++)
        {
//            cout<<"j"<<j<<endl;
            for(int k=0;pa[j][k];k++)
            {
//                cout<<"k"<<k<<endl;
//                for(int i=0;i<n;i++)
//                {
//                    cout<<f[i]<<" ";
//                }
//                cout<<endl;
                if(pa[j][k]==i)
                {
                    if(st==-1)
                    {
                        st=j;
                        break;
                    }
                    else
                    {
//                        cout<<"un"<<st<<" "<<j<<endl;
                        u(st,j);break;
                    }
                }
            }
        }
    }
//    cout<<"s"<<endl;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(f[i]!=i)
        {
            ans++;
        }
    }
    cout<<n-ans;




#ifdef use_t
}
#endif // use_t
    return 0;
}

