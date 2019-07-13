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
string a,b;
ll co[2000];
vector<ll> M[20000];
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
    cin>>a;
    cin>>b;
    for(int i=0;i<26;i++)
        co[i]=INF;
    for(int i=0;i<n;i++)
    {
        co[a[i]-'a']=min(co[a[i]-'a'],1LL*b[i]-'0');
    }
//    for(int i=0;i<10;i++)
//    {
//        cout<<(char)(i+'a')<<" "<<co[i]<<endl;
//    }

//    for(int i=0;i<26;i++)
//    {
//        ll si=M[i].size();
//        for(int j=0;j<si;j++)
//        {
//            cout<<" "<<M[i][j];
//        }
//        cout<<endl;
//    }
    cin>>a;
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        ans+=co[a[i]-'a'];
    }
    if(ans>=INF)
        ans=-1;
    cout<<ans<<'\n';





#ifdef use_t
}
#endif // use_t
    return 0;
}

