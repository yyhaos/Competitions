//Problem Web:Problem Web:http://39.97.97.11/problem.php?cid=1002&pid=3
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
ll k;
ll a[100005];
ll b[100005];
ll c[100005];
ll fi2(ll tar)
{
    ll d=lower_bound(c,c+k,tar)-c;

    c[0]=-10000000005LL;
    return min(abs(tar-c[d]) , abs(tar-c[d-1]));
}
ll fid(ll tar)
{
    ll d=lower_bound(b,b+m,tar)-b;
   // cout<<"d"<< d<<endl;
    b[0]=-20000000005LL;
    return min(abs(tar-b[d])+fi2(b[d]) , abs(tar-b[d-1])+fi2(b[d-1]));
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


    cin>>n>>m>>k;
    rep(i,1,n){
        scanf("%lld",a+i);
    }
    rep(i,1,m)
    scanf("%lld",b+i);
    rep(i,1,k)
    scanf("%lld",c+i);
    sort(a+1,1+a+n);
    sort(b+1,b+m+1);
    sort(c+1,c+k+1);
    ll ans=3;
    ll tmp=99999999999999999LL;
    int bb=1,cc=1;
    rep(i,1,n){
        tmp=min(tmp,fid(a[i]));
    }

    cout<<3+tmp<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}

