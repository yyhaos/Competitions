//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=852
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
string str;
map<unsigned long long,bool> hs;
const unsigned ll z=37;
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
    hs.clear();
//    ll k;
//    cin>>n>>k;
    cin>>str;
    ll len=str.length();
    unsigned ll pre=0;
    unsigned long long bei=1;
    for(int i=0;i<len-1;i++)
    {

        pre+=str[i] * bei;
        bei=bei*z;

        cout<<i<<" "<<pre<<endl;
        hs[pre]=true;
    }
    pre=0;
    bei=1;
    ll ans=0;
    cout<<len<<endl;
    for(ll j=len-1;j>0;j--)
    {
        ll tmp=len-j;
        pre*=z;
        pre+=str[j];
        cout<<"check:"<<j<<" "<<pre<<" "<<tmp<<endl;
        if(hs[pre])
        {
            cout<<"has:"<<j<<" "<<pre<<" "<<tmp<<endl;
            ans+=tmp;
        }
    }
    cout<<ans<<endl;



#ifdef use_t
}
#endif // use_t
    return 0;
}


