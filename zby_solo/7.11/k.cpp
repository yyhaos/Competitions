
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
ll a[100005];
set<ll> qian;
set<ll> ans;
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
    ans.clear();
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qian.clear();
    qian.insert(a[0]);
    ans.insert(a[0]);
    for(int i=1;i<n;i++)
    {
        set <ll > tn;
        ll now=a[i];
        for(auto j : qian)
        {
        //    cout<<"qian:"<<j<<" "<<(j|now)<<endl;
            tn.insert(j|now);
            ans.insert(j|now);
        }
        qian.clear();
        qian.insert(now);
        ans.insert(now);
        for(auto j : tn)
        {
        //    cout<< j <<"-"<<j<<endl;
            qian.insert(j);
        }
        tn.clear();
    }
//    for(auto x : ans)
//    {
//        cout<<" "<<x;
//    }
//    cout<<endl;
    ll ansa=ans.size();
    cout<<ansa<<"\n";


#ifdef use_t
}
#endif // use_t
    return 0;
}

