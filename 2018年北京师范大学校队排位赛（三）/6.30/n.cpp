//https://codeforces.com/gymRegistration/101653/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define used_t 1
const ll q=1e9+7;
const ll maxn= 100000;
const ll INF=1e16;
const double eps=1e-8;
const double PI=acos(-1);

ll ksm(ll a,ll b,ll qq=q)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%q;
        a=a*a%q;
        b/=2;
    }
    return ans;
}

ll n,m;
ll a[10005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
#endif // yyhao


#ifdef used_t
ll t;
cin>>t;
for(ll ii=1;ii<=t;ii++)
{
#endif // used_t

    cin>>n;
    mem(a,0);
    ll tmp;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&tmp);
        a[tmp]++;
    }
    ll ma=0;
    ll mn=0;
    for(ll i=1;i<=1000;i++)
    {
        if(a[i]>ma)
        {
            ma=a[i];
            mn=i;
        }
    }
    cout<<mn<<endl;




#ifdef used_t
}
#endif // used_t
}

