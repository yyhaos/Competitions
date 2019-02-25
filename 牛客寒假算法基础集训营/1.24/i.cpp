//Problem Web:  https://ac.nowcoder.com/acm/contest/327/I
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

ll fl[1000005];
ll su[1000005];
ll cnt=0;
ll a[30005];
vector<pair<ll , ll> > A[20005];
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
    mem(fl,0);
    rep(i,2,30000)
    {
        if(fl[i]==0)
        {
            su[cnt++]=i;
            rep(k,1,1000000/i)
            {
                fl[i*k]=1;
            }
        }
    }
//    cout<<cnt<<endl;
//    rep(i,0,cnt-1)
//    {
//        cout<<su[i]<<" ";
//    }
    cin>>n;
    rep(i,1,n)
    {
        scanf("%lld",&a[i]);
        ll tmp=a[i];
        rep(j,0,cnt-1)
        {
            if(tmp%su[j]==0)
            {
                ll s=0;
                while(tmp%su[j]==0)
                {
                    s++;
                    tmp/=su[j];
                }
                A[i].push_back(make_pair(su[j],s));
            }
            if(sqrt(tmp)<su[j])
                break;
        }
        if(tmp>1)
        {
            A[i].push_back(make_pair(tmp,1));
        }
//        cout<<a[i]<<endl;
//        rep(j,1,A[i].size())
//        {
//            cout<<A[i][j-1].first<<" "<<A[i][j-1].second<<endl;
//        }
    }
    ll ans=0;
    rep(i,1,n)
    {
        rep(j,i+1,n)
        {
            ll s=1;
            ll x=0,y=0;
            while(x<A[i].size() && y<A[j].size())
            {
                if(A[i][x].first<A[j][y].first)
                {
                    s*=A[i][x++].second+1;
                }
                else if(A[i][x].first>A[j][y].first)
                {
                    s*=A[j][y++].second+1;
                }
                else
                {
                    s*=A[i][x++].second+A[j][y++].second+1;
                }
            }
            while(x<A[i].size())
            {
                s*=A[i][x++].second+1;
            }
            while(y<A[j].size())
            {
                s*=A[j][y++].second+1;
            }
            if(s<=10)
            {
                //cout<<a[i]<<" "<<a[j]<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;



#ifdef use_t
}
#endif // use_t
    return 0;
}
