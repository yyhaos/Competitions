//Problem Web:http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1003&cid=868
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
//const ll q=1e9+7;
//ll ksm(ll a,ll b)
//{
//    ll ans=1LL;
//    while(b>0)
//    {
//        if(b&1LL)
//            ans=ans*a%q;
//        a=a*a%q;
//        b/=2LL;
//    }
//    return ans;
//}

ll t,n,m;
ll a[2005];
ll cnt[100005];
ll su[100005];
ll used[100005];
ll C(ll x)
{
    if(x<=1)
        return 0;
    return 1;
}
double p,q;
ll L;
//ll qianzhui[1300][10050];
double E[100005];
double Elost[100005];
double _q[100005];
double _tt[100005];
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


//    cout<<ns<<endl;
//    for(int i=0;i<=100;i++)
//    {
//        cout<<su[i]<<" ";
//    }

    while(cin>>L>>p>>q)
    {
        if(q==1)
        {
            cout<<L<<endl;
            continue;
        }
        double now=1-q;
        _q[0]=1;
        for(int i=1;i<=L+2;i++)
        {
            _q[i]=_q[i-1]*now;
        }
        for(int i=0;i<=L;i++)
            Elost[i]=E[i]=0;
        for(int i=0;i<L;i++)
        {
//            for(int j=i;j<L;j++)
//            {
//                Elost[i]+=2.0*(j-i)*q*_q[j-i];
//            }
            ll tm=L-i-1;
            double tt=1-q;
            Elost[i]+=2.0*q*(tt*(1-_q[tm])/(1-tt)-tm*_q[tm+1])/(1-tt);
            Elost[i]+=2.0*(L-i)*_q[L-i];
        }
//        for(int i=0;i<=L;i++)
//        {
//            cout<<i<<" :L "<<Elost[i]<<endl;
//        }
        E[L]=0;
        for(int i=L-1;i>=0;i--)
        {
            E[i]=((1-p)*(1+E[i+1])+p*Elost[i])/(1-p);
        }
        printf("%.10f\n",E[0]);
    }






#ifdef use_t
}
#endif // use_t
    return 0;
}

