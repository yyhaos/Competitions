//Problem Web:  http://codeforces.com/contest/1131/problem/B
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
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

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
ll cnt=1;
ll x=0,y=0;
ll a,b;
    cin>>n;
    while(n--)
    {
        scanf("%lld%lld",&a,&b);
       // cout<<a<<" "<<b<<"  "<<cnt<<endl;
        ll tmp=0;
        if(b<a)
        {
            if(x<b && y<b && x!=y)
            {
                tmp=b-max(x,y)+1;
            }
            else if(x<b && y<b)
            {
                tmp=b-max(x,y);
            }
            else if(x<b && y==b)
            {
                tmp++;
            }
            else if(x==b && y<b)
            {
                tmp++;
            }
            else if(x==b && y==b)
            {
                tmp=0;
            }
            else if(x>b)
            {
                tmp=0;
            }
        }
        else if(a<b)
        {
            if(x<a && y<a && x!=y)
            {
                tmp=a-max(x,y)+1;
            }
            else if(x<a && y<a)
            {
                tmp=a-max(x,y);
            }
            else if(y<a && x==a)
            {
                tmp=1;
            }
            else if(y==a && x<a)
            {
                tmp=1;
            }
            else if(y==a && x==a)
            {
                tmp=0;
            }
            else
            {
                tmp=0;
            }
        }
        else
        {
            if(x==y)
            {
                tmp=a-x;
            }
            else
            {
                tmp=a-max(x,y)+1;
            }
        }
        cnt+=tmp;

        //cnt+=max(0LL,min(a,b)-max(x,y));
        x=a,y=b;
    }
    cout<<cnt;




#ifdef use_t
}
#endif // use_t
    return 0;
}
