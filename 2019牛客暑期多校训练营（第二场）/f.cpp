//Problem Web:https://ac.nowcoder.com/acm/contest/882#countdown
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
ll v[30][30];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
   // freopen("in.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{

#endif // use_t
//    for(int i=0;i<28;i++)
//    {
//        for(int j=0;j<28;j++)
//        {
//            if(i!=j)
//            cout<<i+j<<" ";
//            else cout<<0<<" ";
//        }
//        cout<<endl;
//    }
    int i,j;
    scanf("%lld",&n);
    for(i=0;i<2*n;i++)
    {
        for(j=0;j<2*n;j++)
        {
            scanf("%lld",&v[i][j]);
        }
    }
    ll cnt=6e6;
    ll tmp=0,ans=0;
    ll sta[30]={0};

    for(i=n;i<n*2;i++)
    {
        sta[i]=1;
    }
    ll t1=0,t2=0;
    ll a[20],b[20];
    t1=0,t2=0,tmp=0;
    for(i=0;i<2*n;i++)
    {
        if(sta[i]==0)
            a[t1++]=i;
        else
            b[t2++]=i;
    }
//    cout<<a[0]<<" "<<b[0]<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            tmp+=v[a[i]][b[j]];
        }
    }
    ans=max(ans,tmp);

    while(next_permutation(sta,sta+2*n))
    {
        if(cnt<1e6)
            {
                if(cnt<0)
                    break;
               if (!next_permutation(sta,sta+2*n))
                    break;
            }

            cnt--;
        if(sta[0]==1)
            break;
        t1=0,t2=0,tmp=0;
        for(i=0;i<2*n;i++)
        {
            if(sta[i]==0)
                a[t1++]=i;
            else
                b[t2++]=i;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                tmp+=v[a[i]][b[j]];
            }
        }
        ans=max(ans,tmp);
    }
    printf("%lld",ans);
#ifdef use_t
}
#endif // use_t
    return 0;
}

