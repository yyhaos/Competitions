
//Problem Web:
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
ll s[1000];
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

    mem(s,0);
    while(cin>>n)
    {mem(s,0);
        ll th=0;
        ll cnt=0;

        char tmp;
        //cin>>tmp;
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%c",&tmp);
//            cout<<tmp<<endl;
            s[tmp]++;
        }
        ll fenzi=s['a']*s['v']*s['i']*s['n'];

        ll fenmu=ksm(n,4);
//        cout<<fenzi<<" "<<fenmu<<endl;
        if(fenzi==0 || fenmu==0)
        {
            cout<<"0/1\n";
        }
        else
        {
            ll gc=__gcd(fenzi,fenmu);
            fenzi/=gc;
            fenmu/=gc;
            cout<<fenzi<<"/"<<fenmu<<endl;
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}
