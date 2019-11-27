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
const double eps=1e-3;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
ll t,n,m;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
        {
            if(n/ans<a)
            {
                return n+1;
            }
            ans=ans*a;
        }
        if(n/a<a)
        {
            a=n+1;
        }
        else
            a=a*a;
        b/=2LL;
    }
    return ans;
}
ll tksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
        {

            ans=ans*a;
        }

            a=a*a;
        b/=2LL;
    }
    return ans;
}


ll aa[1000];
ll ab[1000];
ll ax[1000];
int main ()
{

//    cout<<tksm(2,59)<<endl;
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll a=tksm(2,4)*tksm(17,1);
    cout<<a<<endl;
    n=a;//tksm(13,4)*tksm(12,6);
#else
    freopen("little.in","r",stdin);
    freopen("little.out","w",stdout);

cin>>n;

#endif

#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
ll flag=0;
ll ta=0;
    for(int i=0;(1LL<<i) <=n ;i++)
    {
        if((1LL<<i) == n)
        {
            flag=1;
        }
    }
    if(flag)
    {
        printf("-1");
        return 0;
    }
    else
    {
        for(ll len=1;len<=64;len++)
        {
            for(ll a=1;a<=(len);a++)
            {
                ll b=len-a;
                ll l=2,r=n;
//                cout<<len<<" "<<a<<" "<<l<<" "<<r<<" "<<n<<endl;
                while(l<r)
                {
//                    cout<<l<<" "<<r<<endl;
                    ll mid=(l+r)/2;
    ll x1=ksm(mid,a),x2=ksm(mid+1,b);
    ll top;
    if(n/x1 < x2)
    {
        top=n+1;
    }
    else top=x1*x2;//sm(mid+1,b)) ;

                    //double topdb=pow(mid*1.0,a*1.0) * pow(mid+1.0,b*1.0);
//printf("topdb:%f\n",topdb);
                    if( top==n )
                    {
//                        printf("%lld",len);
//                        for(int i=1;i<=a;i++)
//                        {
//                            printf(" %lld",mid);
//                        }
//                        for(int i=1;i<=b;i++)
//                        {
//                            printf(" %lld",mid+1);
//                        }
//                        printf("\n");
                        break;
                    }
                    else if(top<n)
                    {
                        l=mid+1;
                    }
                    else
                        r=mid-1;
                }ll mid=(l+r)/2;
                  ll x1=ksm(mid,a),x2=ksm(mid+1,b);
    ll top;
    if(n/x1 < x2)
    {
        top=n+1;
    }
    else top=x1*x2;//sm(mid+1,b)) ;

//printf("topdb:%f\n",topdb);
                if( top==n )
                {
                    ta++;
                    aa[ta-1]=a;
                    ab[ta-1]=b;
                    ax[ta-1]=mid;
                }
            }

        }
    }
    printf("%lld\n",ta);
        for(int i=0;i<ta;i++)
        {
              printf("%lld",aa[i]+ab[i]);
                    for(int j=1;j<=aa[i];j++)
                    {
                        printf(" %lld",ax[i]);
                    }
                    for(int j=1;j<=ab[i];j++)
                    {
                        printf(" %lld",ax[i]+1);
                    }
                    printf("\n");
        }


#ifdef use_t
}
#endif // use_t
    return 0;
}


