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
ll a[40];
ll tmp[100];
ll ke[1<<19+5];
struct ss
{
    ll pos,v;
    friend bool operator < (ss a, ss b)
    {
        return a.v<b.v;
    }
}yke[1<<19+5];
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
ll tar;
    cin>>n>>tar;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    ll qian=n/2;
//    cout<<qian<<endl;
    ll hou=n-n/2;
    ll cnt=0;
    ll th=0;
    for(int i=0;i< (1<<(qian)) ;i++)
    {
        th=0;
        ll ti=i;
        ll tmp=0;
        while(ti)
        {
            if(ti&1)
            {
                tmp+=a[th];
            }
            th++;
            ti/=2;
        }
        yke[cnt].pos=i;
        yke[cnt].v=tmp;
        ke[cnt++]=tmp;

//        cout<<ke[cnt-1]<<endl;
    }
sort(ke,ke+cnt);
sort(yke,yke+cnt);
    for(int i=0;i< (1<<(hou)) ;i++)
    {
        th=qian;
        ll ti=i;
        ll tmp=0;
        while(ti)
        {
            if(ti&1)
            {
                tmp+=a[th];
            }
            th++;
            ti/=2;
        }
//        cout<<tmp<<endl;
        ll pos=lower_bound(ke,ke+cnt,tar-tmp)-ke;


        if(ke[pos]+tmp==tar )
        {
            pos=yke[pos].pos;
//            cout<<pos<<endl;
            for(int j=0;j<qian;j++)
            {
                if(pos&1)
                {
                    cout<<"1";
                }
                else
                    cout<<"0";
                pos/=2;
            }
            ll ti=i;
            for(int j=0;j<hou;j++)
            {
                if(ti&1)
                {
                    cout<<"1";
                }
                else
                    cout<<"0";
                ti/=2;
            }
            return 0;
        }
    }








#ifdef use_t
}
#endif // use_t
    return 0;
}

