//Problem Web:https://ac.nowcoder.com/acm/contest/889#countdown

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
struct sta
{
    ll type;
    double h;
    sta(){}
    sta(ll _t,double _h)
    {
        type=_t;
        h=_h;
    }
    friend bool operator < (sta a,sta b)
    {
        return a.h<b.h;
    }

}ss[1000005];
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
    ll cnt=0;
    ll L,R;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&L,&R);
        double mid=1.0*L + 1.0*R;
        mid/=2.0;
        ss[cnt].type=1;
        ss[cnt++].h=L;
        ss[cnt].type=1;
        ss[cnt++].h=R;
        ss[cnt].type=2;
        ss[cnt++].h=mid;
    }
    sort(ss,ss+cnt);
    ll ans=0;
    double sudu=0;
    ll maxx=0;
    for(ll i=0;i<cnt;i++)
    {
//        cout<<ss[i].type<<" "<<ss[i].h<<" "<<ans<<" "<<sudu<<endl;
        if(i)
        {
            ans=ans+(ll)(sudu*(ss[i].h-ss[i-1].h));
            maxx=max(maxx,ans);
        }
//        if(ss[i].type==0)
//        {
//            sudu+=2;
//        }
        if(ss[i].type==2)
        {

            sudu-=4;
        }
        else
        {
            sudu+=2;
        }
    }
cout<<maxx<<endl;




#ifdef use_t
}
#endif // use_t
    return 0;
}


