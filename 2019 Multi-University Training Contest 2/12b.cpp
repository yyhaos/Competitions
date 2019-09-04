//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=849
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
ll N,C,K;
ll t,n,m;
ll a[100005];
ll cnt[100005];
map<ll,ll> used;
ll tmp[100005];
ll th=0;
ll dfs(ll l , ll r)
{
//    cout<<l<<" "<<r<<endl;
    if(r<l)
        return 0;
    if(r==l)
    {
        if(K<=1)
            return 1;
        return 0;
    }
    for(int i=l;i<=r;i++)
    {
        cnt[a[i]]=0;
    }
    for(int i=l;i<=r;i++)
    {
        cnt[a[i]]++;
    }
    ll ans=0;
    ll pre=l;
    int i;
    ll duan=0;
    for(i=l;i<=r;i++)
    {
        if(cnt[a[i]]<K)
        {
            duan++;
            ans=max(ans,dfs(pre,i-1));
            pre=i+1;
            continue;
        }
    }
    if(duan==0)
    {
        ans=r-pre+1;
    }
    else
        ans=max(ans,dfs(pre,r));
    return ans;
}
ll dfs2(ll l , ll r)
{
//    cout<<l<<" "<<r<<endl;
    if(r<l)
        return 0;
    if(r==l)
    {
        if(K<=1)
            return 1;
        return 0;
    }
    for(int i=l;i<=r;i++)
    {
        cnt[a[i]]=0;
    }
    for(int i=l;i<=r;i++)
    {
        cnt[a[i]]++;
    }
    ll ans=0;
    ll pre=l;
    int i;
    ll duan=0;
    for(i=l;i<=r;i++)
    {
        if(cnt[a[i]]<K)
        {
            duan++;
            ans=max(ans,dfs(pre,i-1));
            pre=i+1;
            continue;
        }
    }
    if(duan==0)
    {
        ans=r-pre+1;
    }
    else
        ans=max(ans,dfs(pre,r));
    return ans;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("in.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
//cout<<"100000 100000 10"<<endl;
//    for(int i=1;i<=100000;i++)
//    {
//        cout<<i<<" ";
//    }
//    cout<<endl;
//cout<<"100000 100000 10"<<endl;
//    for(int i=1;i<=100000;i++)
//    {
//        cout<<1<<" ";
//    }
//    cout<<endl;
//cout<<"100000 100000 10"<<endl;
//    for(int i=1;i<=100000;i++)
//    {
//        if(i%10)
//            cout<<1<<" ";
//        else
//            cout<<2<<" ";
//    }
//    cout<<endl;


    while(cin>>N>>C>>K)
    {
        for(int i=1;i<=N;i++)
        {
            scanf("%lld",a+i);
        }
        cout<<dfs(1,N)<<"\n";
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}

