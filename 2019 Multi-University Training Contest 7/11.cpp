//Problem Web:http://acm.hdu.edu.cn/userloginex.php?cid=854
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
ll ni(ll x)
{
    return ksm(x,q-2);
}
ll t,n,m;
ll _(ll x)
{
    while(x<0)
    {
        x+=(-x/q+1)*q;
    }
    return x%q;
}
struct fenshu
{
    ll fz,fm;
    fenshu(){fz=0,fm=1;};
    void biao()
    {
 ll g=__gcd(fz,fm);
        fz/=g;
        fm/=g;
    }
    fenshu(ll z,ll m)
    {
        fz=z;fm=m;biao();
    }
    fenshu(ll z)
    {
        fz=z;fm=1;biao();
    }
    fenshu operator - (fenshu b)
    {
//        ll z=_( fz*b.fm -fm*b.fz );
//        ll m=_(fm*b.fm);
        return fenshu(_( fz*b.fm -fm*b.fz ),_(fm*b.fm));
    }
    fenshu operator + (fenshu b)
    {
//        ll z=_( fz*b.fm +fm*b.fz );
//        ll m=_(fm*b.fm);
        return fenshu(_( fz*b.fm +fm*b.fz ),_(fm*b.fm));
    }
    fenshu operator * (fenshu b)
    {
//        ll z=_( fz*b.fz );
//        ll m=_(fm*b.fm);
        return fenshu(_( fz*b.fz ),_(fm*b.fm));
    }
//    fenshu operator / (fenshu b)
//    {
//        ll z=_( fz*b.fm );
//        ll m=_(fm*b.fz);
//        return fenshu(z,m);
//    }
}E[500005];
ll r[500005];
ll s[500005];
ll x[500005];
ll a[500005];
int main ()
{


#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
scanf("%lld",&t);
ll qq;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    scanf("%lld%lld",&n,&qq);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld%lld",&r[i],s+i,x+i,a+i);
    }
    E[1]=fenshu(0);
    for(int i=2;i<=1+n;i++)
    {
        if(r[i-1] != s[i-1])
        {
            //ll chu=fenshu(r[i-1],s[i-1]);
            E[i]=E[i-1] + fenshu(a[i-1]) - ( fenshu(s[i-1]-r[i-1],s[i-1]) * E[x[i-1]] );
            E[i]=E[i]*fenshu(s[i-1],r[i-1]);
//            fenshu jiao = (fenshu(a[i-1]) + E[i-1])*fenshu(s[i-1]);
            // E[r] = jiao + r/s * ( E[r] - E[ x[r-1]] )
            // E[r] * (s-r) = jiao * s - r * E[ x[r-1]]
//            jiao= jiao * ;
//            fenshu x2 = fenshu(s[i-1]-r[i-1])*E[x[i-1]];
//            cout<<"x2"<<":"<<x2.fz<<" "<<x2.fm<<endl;
//            cout<<"x1"<<":"<<jiao.fz<<" "<<jiao.fm<<endl;
//            E[i]=((fenshu(a[i-1])+E[i-1])*fenshu(s[i-1])-fenshu(r[i-1],s[i-1])*(E[x[i-1]]))*fenshu(s[i-1],s[i-1]-r[i-1]);
            // (s-r)/s E[r]= jiao - r/s * E[x[i-1]]
//            E[i]=(  (fenshu(a[i-1]) + E[i-1]*fenshu(s[i-1]) ) + fenshu(r[i-1],s[i-1])*E[x[i-1]] ) * fenshu(s[i-1],s[i-1]-r[i-1]);
        }
        else
        {
            E[i] = E[i-1]+fenshu(a[i-1]);
        }
//        cout<<i<<":"<<E[i].fz<<" "<<E[i].fm<<endl;
    }
    ll l,r;
    while(qq--)
    {
        scanf("%lld%lld",&l,&r);
        fenshu daan=E[r]-E[l];
//        cout<<"daan"<<":"<<daan.fz<<" "<<daan.fm<<" "<<ni(daan.fm)<<endl;
//        cout<<(daan.fz)%q<<endl;
        printf("%lld\n",((daan.fz)*ni(daan.fm)%q ));
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


