//Problem Web:  https://vjudge.net/contest/239087#problem/H
//#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<string.h>
//#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
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
ll M[105][105];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    ll a,b;
cin>>n>>m;
        mem(M,0);
    rep(i,1,m)
    {
        cin>>a>>b;
        M[a][b]=1;
    }
//
//    rep(i,1,n)
//    {
//        rep(j,1,n)
//            cout<<M[i][j]<<" ";
//        cout<<endl;
//    }
    rep(i,1,n)
    rep(j,1,n)
    rep(k,1,n)
    {
        if(M[j][i]+M[i][k]==2)
            M[j][k]=1;
    }

//    rep(i,1,n)
//    {
//        rep(j,1,n)
//            cout<<M[i][j]<<" ";
//        cout<<endl;
//    }
    ll ans=0;
    rep(i,1,n)
    {
        ll cnt=0;
        rep(j,1,n)
        {
            if(i==j)
                continue;
            if(M[i][j] || M[j][i])
                cnt++;
        }
        if(cnt==n-1)
            ans++;
    }

    cout<<ans<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}
