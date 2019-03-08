//Problem Web:  http://www.bnuoj.com/contest_show.php?cid=9146#problem/C
#include<bits/stdc++.h>
#include<ext/rope>
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
ll cnt=0;
ll su[100005];
ll t,n,m;
ll ss[100005];
double ans[100005];
int main ()
{
//    rep(i,2,100005)
//    {
//        if(su[i]==0)
//        {
//            ss[cnt++]=i;
//            rep(j,1,100000/i)
//            {
//                su[j*i]=1;
//            }
//        }
//    }
    ans[1]=0;
    mem(ans,0);
    rep(i,2,100002)
    {
        double sum=0;
        double se=0;
        ll ma=(ll)sqrt(i);

        rep(j,1,ma)
        {
            if(i%j==0)
            {
                sum++;
                se+=1+ans[j];
                if(i/j!=j)
                {
                    sum++;
                    se+=1+ans[i/j];
                }
            }
        }
        //cout<<i<<" "<<ma<<" "<<se<<" "<<sum<<endl;
       // sum--;
        ans[i]=se/(sum-1);
        //cout<<ans[i]<<" ";
    }
    //ans[1]=1;
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

    scanf("%lld",&n);
    cout<<"Case "<<ii<<": ";
    printf("%.10f\n",ans[n]);




#ifdef use_t
}
#endif // use_t
    return 0;
}
