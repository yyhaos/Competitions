//Problem Web:https://codeforces.com/contests/102152
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
struct fil
{
    ll l,r;
    ll si;
    void show()
    {
        cout<<l<<"-"<<r<<" :"<<si<<endl;
    }
    friend bool operator <( fil a, fil b)
    {
        return a.si<b.si;
    }
}F[100005],kong[100005];

bool cmplxiao(fil& a, fil& b)
{
    return a.l<b.l;
}
bool cmpsida ( fil& a, fil& b)
{
    return a.si>b.si;
}
ll qian[100005];
bool cmp(fil& a, fil& b)
{
    if(a.si!=b.si)
        return a.si<b.si;
    else
        if(a.r!=b.r)
            return a.r>b.r;
        else
            return a.l>b.l;
}

    ll qianzhui[100005];
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
    ll mq;
    ll cnt=0;

    cin>>n>>m>>mq;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&F[i].l,&F[i].r);
    }
    sort(F,F+n,cmplxiao);
    ll st=1;
    ll l,r;
    for(int i=-1;i<n;i++)
    {
        //F[i].show();
        if(i==-1)
            l=1;
        else
            l=F[i].r+1;
        if(i==n-1)
            r=m;
        else
            r=F[i+1].l-1;

            //cout<<r<<" "<<l<<endl;
        if(r>=l)
        {
            kong[cnt].l=l;
            kong[cnt].r=r;
            kong[cnt].si=r-l+1;
            cnt++;
        }
    }

   // cout<<endl;
    sort(kong,kong+cnt,cmp);
//    for(int i=0;i<cnt;i++)
//    {
//        kong[i].show();
//    }

    mem(qian,0);
    ll maxx=0;
    for(int i=cnt-1;i>=0;i--)
    {
        qian[kong[i].si]=max(maxx,kong[i].r);
        maxx=max(maxx,kong[i].r);
    }

    ll qianxu=0;
    for(int i=1;i<=m;i++)
    {
        if(qian[i]!=0)
        {
            F[qianxu].l=-1;
            F[qianxu].r=qian[i];
            F[qianxu++].si=i;
        }
    }
    sort(F,F+qianxu);
    ll tsi;

//    for(int i=0;i<qianxu;i++)
//    {
//        F[i].show();
//    }

    while(mq--)
    {
        scanf("%lld",&tsi);
        fil tmp;
        tmp.si=tsi;
        tmp.r=-1;
        ll pos=lower_bound(F,F+qianxu,tmp)-F;
        //cout<<"si:"<<tsi<<" pos:"<<pos<<endl;
        if(pos!=qianxu && F[pos].si>=tmp.si || pos<0)
        {
            printf("%lld %lld\n",F[pos].r-tmp.si+1,F[pos].r);
        }
        else

        {
            printf("-1 -1\n");
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

