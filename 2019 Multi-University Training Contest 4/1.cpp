//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=851
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
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
//const ll maxn=1000;
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
const ll maxn=3981;
ll prime[maxn+5];
void getP()
{
    mem(prime,0);
    for(int i=2;i<=maxn;i++)
    {
        if(!prime[i])
            prime[++prime[0]]=i;
        for(int j=1;j<=prime[0] && prime[j]<=maxn/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
ll faa;
ll factor[100000][2];
int fatCnt;
int getFactors(ll x)
{
    faa=0;
    fatCnt=0;
    ll tmp=x;
    for(int i=1;prime[i]<=tmp/prime[i] && i<prime[0];i++)
    { //cout<<tmp<<endl;
        factor[fatCnt][1]=0;
        if(tmp%prime[i]==0)
        {
            factor[fatCnt][0]=prime[i];
            while(tmp%prime[i]==0)
            {
                factor[fatCnt][1]++;
                tmp/=prime[i];
            }
            fatCnt++;
        }
    }
//cout<<tmp<<endl;
    if(tmp!=1)
    {
        faa=1;
        factor[fatCnt][0]=tmp;
        factor[fatCnt++][1]=1;
    }
    return fatCnt;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
//    freopen("out.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    freopen("out2.txt","w",stdout);
#endif
getP();
//cout<<1000003LL*1000003LL*1000003LL<<endl;
//    cout<<prime[0]<<endl;
//cout<<50000<<endl;
//for(int i=1;i<=50000;i++)
//{
//    cout<<996491788296388609<<"\n";
//}
//cout<<998244353LL*998244353LL<<" "<<998244353LL*1000000007LL<<endl;
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
ll tmp;
//fa=0;
    scanf("%lld",&tmp);
    getFactors(tmp);
//    cout<<'a'<<endl;
    ll minn=1e18;
//    cout<<
    for(int i=0;i<fatCnt;i++)
    {
//        cout<<factor[i][0]<<" "<<factor[i][1]<<endl;
        if(i<fatCnt-1)
        minn=min(minn,factor[i][1]);
        else
        {
            if(factor[i][0]>31623LL)
            {
                continue;
            }
            else
            {
                minn=min(minn,factor[i][1]);
            }
        }
        if(minn==1)
            break;
    }

    if(minn>1 && faa==1)
    {
        ll last=factor[fatCnt-1][0];
//        cout<<"last:"<<last<<endl;
        ll sq= round(0.0000000001+sqrt(last));
        ll s3= round( 0.000000001+ pow(last,0.333333333));
        ll s4= round( 0.000000001+ pow(last,0.25));
//            cout<<"s3"<<s3<<" "<<pow(s3,3)<<endl;
//        cout<<"last:"<<sq<<endl;
        if(last==sq*sq) // x^2
        {
            minn=2;
        }
        else
        {

            if(last==s3*s3*s3)
            {
                minn=min(minn,3LL);
            }
            else if(last == s4*s4*s4*s4)
            {
                minn=min(minn,4LL);
            }
            else
                minn=1;
        }
    }

    printf("%lld\n",minn);

    //cout<<prime[prime[0]]<<endl;





#ifdef use_t
}
#endif // use_t
    return 0;
}


