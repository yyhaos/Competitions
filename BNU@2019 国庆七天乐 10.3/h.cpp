//Problem Web:
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


ll fa[1000005];
struct tree{
    ll geng,ngeng,nzi;
//    vector<ll> zi;
    ll gong=0;
}tr[100005];
ll ru[100005];
ll gg[100005];
ll used[100005];
ll trcnt=0;
ll fa2[100005];
ll fi(ll x)
{
    if(fa2[x]==0)
        return x;
    else
        return fa2[x]=fi(fa2[x]);
}
vector<ll> M[100005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif

#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    cin>>n;
    mem(fa,0);
    mem(ru,0);
    mem(gg,0);
    mem(used,0);
    for(int i=2;i<=n;i++)
    {
        scanf("%lld",fa+i);
        fa2[i]=fa[i];
        ru[fa[i]]++;
    }
    queue<ll> qq;
    for(int i=1;i<=n;i++)
    {
        if(ru[i]==0)
        {
            qq.push(i);
        }
    }
    while(!qq.empty())
    {
        ll now=qq.front();
        qq.pop();
        cout<<now<<" "<<fa[now]<<endl;
        ll faa=fa[now];
        if(faa==0)
        {
            tr[trcnt].geng=now;
            tr[trcnt].gong=gg[now];
            tr[trcnt].ngeng=1-used[now];
            tr[trcnt].nzi=M[now].size();
            trcnt++;
        }
        else
        {
            if(used[ faa ]== 0 && used[now]==0)
            {
                used[faa]=1;used[now]=1;
                gg[now]++;

            }
            else
            {
                if(used[now]==0)
                {
                    M[fi(now)].push_back(now);
                }
            }
            gg[faa]+=gg[now];
            if(0==--ru[faa])
                qq.push(faa);
        }
    }

    cout<<trcnt<<endl;
    for(int i=0;i<trcnt;i++)
    {
//        cout<<i<<endl;
        cout<<"geng:"<<tr[i].geng<<" gong"<<tr[i].gong<<" ngeng"<<tr[i].ngeng<<" nzi"<<tr[i].nzi<<endl;
        for(int j=0;j<tr[i].nzi;j++)
        {
            printf("%lld ",M[i][j]);
        }
        cout<<endl;
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}


