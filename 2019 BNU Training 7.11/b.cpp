//Problem Web:https://codeforces.com/gym/247802/problem/B
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
ll li[100005];
ll nli[100005];
ll cnt[100005];
vector<ll> D[100005];
vector<ll> s[100005];
bool cmp(ll a,ll b)
{
    return a>b;
}
struct sweet
{
    ll v,t;
    friend bool operator <(sweet a,sweet b)
    {
        return a.v>b.v;
    }
};
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
    for(int i=1;i<=m;i++)
    {
        cnt[i]=0;
        scanf("%lld",li+i);
       // nli[i]=li[i];
    }
        ll a,b;
    for(int i=1;i<=m;i++)
    {
        D[i].clear();

        s[i].clear();
        s[i].push_back(0);
    }

    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a,&b);
        cnt[b]++;
        D[b].push_back(a);
        s[b].push_back(0);
    }
    for(int i=1;i<=m;i++)
    {
        sort(D[i].begin(),D[i].end(),cmp);
    }
    for(int i=1;i<=m;i++)
    {
        ll si=s[i].size();
        for(int j=1;j<si;j++)
        {
            s[i][j]=s[i][j-1]+D[i][j-1];
        }

        nli[i]=li[i];
    }

//    for(ll i=1;i<=m;i++)
//    {
//        ll si=cnt[i]+1;
//        printf("%lld %lld:",i,si);
//        for(int j=0;j<si;j++)
//        {
//            printf("%lld ",s[i][j]);
//        }
//        printf("\n");
//    }

    sort(nli+1,nli+m+1);
    ll pre=-1;
    ll mu=1;
    ll zi=0;
    for(int i=1;i<=m;i++)
    {
        if(pre!=nli[i])
        {
            pre=nli[i];
//            cout<<pre<<endl;
            ll tmp=0;
            for(int j=1;j<=m;j++)
            {

                if(li[j]==1)
                {
                    tmp+=s[j][min(cnt[j],pre)];
                }
                else if(li[j]>min(cnt[j],pre) )
                    continue;
                //else if()
                else
                    tmp+=s[j][min(cnt[j],pre)];

            }
//            cout<<tmp<<"/"<<pre<<endl;
            if(tmp*mu > zi*pre)
            {
                zi=tmp;
                mu=pre;
            }
        }
        else
        {

        }
    }


    cout<<zi/__gcd(zi,mu)<<'/'<<mu/__gcd(zi,mu)<<"\n";
#ifdef use_t
}
#endif // use_t
    return 0;
}
