//Problem Web:
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
struct sta{
    ll pos,th;
    friend bool operator < ( sta a, sta b)
    {
        return a.pos<b.pos;
    }
}a[200005],b[200005];

ll ans[200005];
ll ans2[200005];
ll ans3[200005];
ll ans4[200005];
ll ans5[200005];
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

    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].pos;
        a[i].th=i+1;
    }

    sort(a,a+n);

    for(int i=0;i<n;i++)
    {
         cin>>b[i].pos;
        b[i].th=i+1;
    }
    sort(b,b+n);

    ll ans0=0;
    for(int i=0;i<n;i++)
    {
        ll cha=a[i].pos-b[i].pos;
        cha=abs(cha);
        cha=min(cha,m-cha);
        ans0+=cha;
        ans[a[i].th]=b[i].th;
    }

    ll ans20=0;
    for(int i=0;i<n;i++)
    {
        ll cha=a[i].pos-b[(i+1)%n].pos;
        cha=abs(cha);
        cha=min(cha,m-cha);
        ans20+=cha;
        ans2[a[i].th]=b[(i+1)%n].th;
    }

ll ans30=0;
    for(int i=0;i<n;i++)
    {
        ll cha=a[i].pos-b[(i-1+n)%n].pos;
        cha=abs(cha);
        cha=min(cha,m-cha);
        ans30+=cha;
        ans3[a[i].th]=b[(i-1+n)%n].th;
    }

    ll ans40=0;
    for(int i=0;i<n;i++)
    {
        ll cha=a[i].pos-b[(i-2+2*n)%n].pos;
        cha=abs(cha);
        cha=min(cha,m-cha);
        ans40+=cha;
        ans4[a[i].th]=b[(i-2+2*n)%n].th;
    }
    ll ans50=0;
    for(int i=0;i<n;i++)
    {
        ll cha=a[i].pos-b[(i+2)%n].pos;
        cha=abs(cha);
        cha=min(cha,m-cha);
        ans50+=cha;
        ans5[a[i].th]=b[(i+2)%n].th;
    }


    if(ans0<= ans20 && ans0<= ans30 && ans0<=ans40&& ans0 <=ans50)
    {
        cout<<ans0<<endl;
        for(int i=1;i<n;i++)
        {

            cout<<ans[i]<<" ";
        }
        cout<<ans[n];
    }

  else   if(ans20<= ans0 && ans20<= ans30 && ans20<=ans40&& ans20 <=ans50)
    {
        cout<<ans20<<endl;
        for(int i=1;i<n;i++)
        {
            cout<<ans2[i]<<" ";
        }cout<<ans2[n];
    }
 else    if(ans30<= ans20 && ans30<= ans0 && ans30<=ans40 && ans30 <=ans50)
    {
        cout<<ans30<<endl;
        for(int i=1;i<n;i++)
        {
            cout<<ans3[i]<<" ";
        }
        cout<<ans3[n];
    }
    else if( ans40 <= ans20 && ans40<= ans0 && ans40<=ans30 && ans40 <=ans50 )
    {
        cout<<ans40<<endl;
        for(int i=1;i<n;i++)
        {
            cout<<ans4[i]<<" ";
        }
        cout<<ans4[n];
    }
    else
    {
cout<<ans50<<endl;
        for(int i=1;i<n;i++)
        {
            cout<<ans5[i]<<" ";
        }
        cout<<ans5[n];
    }









#ifdef use_t
}
#endif // use_t
    return 0;
}

