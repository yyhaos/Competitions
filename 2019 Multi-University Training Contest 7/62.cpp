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

ll t,n,m;
ll k;
inline ll get(ll x)
{
     if(x<k || x>n)
        return INF;
    ll y= m/(1+x-k);
    while(y<=m/(1+x-k))
        y++;
    return x*y;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
ll ax=0;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
//ll k;
    scanf("%lld%lld%lld",&n,&m,&k);
    if(n==k )
    {
        printf("%lld\n",get(n));
    }
    else
    {
        ll cnt=4000;
        ll ans=get(k);
//        for(int i=k;i<=n;i++)
//        {
//            ans=min(ans,get(i));
//        }
//        cout<<"12"<<ans<<endl;
//        ans=k*(m+1);
        for(ll ii=k;ii*ii <= n;ii++)
        {
            ans=min(ans,get(ii));
//            if(ans==get(ii))
//                ax=ii;
            cnt--;
            if(!cnt)
                break;
        }
        cnt+=2000;
        for(ll ii=sqrt(n)+1;ii*ii >=1;ii--)
        {
            ans=min(ans,get(ii));
//            if(ans==get(ii))
//                ax=ii;
            cnt--;
            if(!cnt)
                break;
        }


        cnt=6000;
        ll tii= sqrt(n);
        for(ll ii = tii ;ii>=1;ii-- )
        {
          //  ii = m/(1+x-k);
//          m ~ ( 1+x-k * ii<= , <i+x-k * (ii+1))
            ll m_=m/ii;

            ll txx=m_ +k-1;
//            if((txx+1-k)>0 &&m/(txx+1-k) == ii )
//            {
//                ans=min(ans,get(txx));
//            }
            for(int tx=txx;tx<= txx+1;tx++)
            {

                ans=min(ans,get(tx));
            }

            cnt--;
            if(!cnt)
                break;
//            for(ll tx= )
        }
        cnt+=1000;
         for(ll ii = 1 ;ii<=tii;ii++ )
        {
          //  ii = m/(1+x-k);
//          m ~ ( 1+x-k * ii<= , <i+x-k * (ii+1))
            ll m_=m/ii;

            ll txx=m_ +k-1;
//            if((txx+1-k)>0 &&m/(txx+1-k) == ii )
//            {
//                ans=min(ans,get(txx));
//            }
            for(int tx=txx;tx<= txx+1;tx++)
            {

                ans=min(ans,get(tx));
            }

            cnt--;
            if(!cnt)
                break;
//            for(ll tx= )
        }
        ans=min(ans, get( m+k ) );

       printf("%lld\n",ans);
//        cout<<ax<<"-----"<<endl;
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}

