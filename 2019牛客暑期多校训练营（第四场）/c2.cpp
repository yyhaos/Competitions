//Problem Web:https://ac.nowcoder.com/acm/contest/884#countdown
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
ll a[3000005];
ll b[3000005];
ll sum_b[3000005];
ll tree[3000005*4];
void pushup(ll i)
{
    tree[i]=min(tree[i<<1],tree[i<<1|1]);
}
void build(ll i,ll l,ll r)
{
    if(l==r)
    {
        scanf("%lld",&tree[i]);
        return ;
    }
    ll mid=(l+r)/2;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
    pushup(i);
}

ll query(ll i,ll l,ll r,ll x,ll y)
{
    if(x<=l && r<=y)
        return tree[i];
    ll minn=1e7;
    ll mid=(l+r)/2;
    if(x<=mid)
        minn=min(minn,query(i<<1,l,mid,x,y));
    if(y>mid)
        minn=min(minn,query(i<<1|1,mid+1,r,x,y));
    return minn;
}
inline ll geta(ll l,ll r)
{
    return query(1,1,n,l,r);
}
inline ll getb(ll l,ll r)
{
    //if(l>0)
        return sum_b[r]-sum_b[l-1];
    //return b[r];
}
ll cnt;
ll fen[3000005];
ll fena[3000005];
ll fenb[3000005];
ll fenab[3000005];
inline ll sg(ll x)
{
    if(x>0)
        return 1;
    else
        return -1;
}
inline ll sg2(ll x)
{
    if(x<0)
        return -1;
    return 1;
}
inline ll sg3(ll x)
{
    if(x<0)return -1;
    if(x>0)return 1;
    return 0;
}
inline ll get(ll l,ll r)
{
    if(l<1)
        l=0;
    if(r>=l)
    return geta(l,r) * getb(l,r);
    return 4e18;
}
ll get()
{
    ll ans=-4e18;
    ll l,r;
    for(int i=0;i<cnt-1;i++)
    {
        l=fen[i];
        r=fen[i+1]-1;
        ans=max(ans,get(l,r));
    }

    ans=max(ans,get(fen[cnt-1],n));
    return ans;
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
    build(1,1,n);
    sum_b[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",b+i);
       // if(i)
            sum_b[i]=sum_b[i-1]+b[i];
//        else
//            sum_b[i]=b[i];
    }

    ll tn=1;

//    for(ll l=1;l<=n;l++)
//    {
//        for(ll r=l;r<=n;r++)
//        {
//            cout<<l<<" "<<r<<":"<<geta(l,r)<<" "<<getb(l,r)<<endl;
//        }
//    }

    ll ans=-4e18;
    for(int i=1;i<n;i++)
    {
        for(int k=0;k<=50;k++)
        {
//            ans=max(ans,get(i,i));
            if(i+k>n)
                break;
            ans=max(ans,get(i,i+k));
        }
    }
    ans=max(ans,get(n,n));

    for(int i=1;i<n;i++)
    {
        for(int k=0;k<=50;k++)
        {
//            ans=max(ans,get(i,i));
            if(i>n-k)
                break;
            ans=max(ans,get(i,n-k));
        }
    }
    ll pre=sg(a[1]);
    ll ca=0,cb=0;
    for(int i=2;i<=n;i++)
    {
        if(pre != sg(a[i]))
        {
            fena[ca++]=i;
        }
        pre=sg(a[i]);
    }
    ll l,r;
    for(int i=0;i<ca-1;i++)
    {
        l=fena[i];
        r=fena[i+1]-1;
        ans=max(ans,get(l,r));
    }
    ans=max(ans,get(fena[cnt-1],n));

    for(int i=2;i<=n;i++)
    {
        if(pre != sg(a[i]))
        {
            fena[ca++]=i;
        }
        pre=sg(a[i]);
    }

    for(int i=0;i<cb-1;i++)
    {
        l=fenb[i];
        r=fenb[i+1]-1;
        ans=max(ans,get(l,r));
    }
    ans=max(ans,get(fenb[cnt-1],n));

    ll ti=0,tj=0;
    cnt=0;
    while(ti<ca && tj<cb)
    {
        if(fena[ti]<fenb[tj])
        {
            fen[cnt++]=fena[ti];
            ti++;
        }
        else
        {

            fen[cnt++]=fenb[tj];
            tj++;
        }
    }
    while(ti<ca )
    {
            fen[cnt++]=fena[ti];
            ti++;
    }
    while(tj<cb)
    {
            fen[cnt++]=fenb[tj];
            tj++;
    }
    get();

    ll cab=0;

    pre=sg(a[1])+2*sg(b[1]);
    for(int i=2;i<=n;i++)
    {
        if(pre != sg(a[i])+2*sg(b[i]))
        {
            fenab[cab++]=i;
        }
        pre=sg(a[i])+2*sg(b[i]);
    }
    for(int i=0;i<cab-1;i++)
    {
        l=fenab[i];
        r=fenab[i+1]-1;
        ans=max(ans,get(l,r));
    }
    ans=max(ans,get(fenab[cab-1],n));

    ll pre_sum=b[1];
    pre=sg(b[1]);
    ca=0;
    for(int i=2;i<=n;i++)
    {
        pre_sum+=b[i];
        if(pre != sg(pre_sum))
        {
            fena[ca++]=i;
            i++;
            pre_sum=b[i];
        }
        pre=sg(pre_sum);
    }
    for(int i=0;i<ca-1;i++)
    {
        l=fena[i];
        r=fena[i+1]-1;
        ans=max(ans,get(l,r));
    }
    ans=max(ans,get(fena[ca-1],n));

    pre_sum=b[1];
    pre=sg2(b[1]);
    ca=0;
    for(int i=2;i<=n;i++)
    {
        pre_sum+=b[i];
//        cout<<pre_sum<<endl;
        if(pre != sg2(pre_sum))
        {
            fena[ca++]=i;
            i++;
            pre_sum=b[i];
        }
        pre=sg(pre_sum);
    }
    for(int i=0;i<ca-1;i++)
    {
        l=fena[i];
        r=fena[i+1]-1;
        ans=max(ans,get(l,r));
//        cout<<l<<" "<<r<<endl;
    }


    ans=max(ans,get(fena[ca-1],n));
//    cout<<ca-1<<" "<<n<<endl;

    cout<<ans;
//    cout<<" "<<get(2,4);




#ifdef use_t
}
#endif // use_t
    return 0;
}


