//Problem Web:https://ac.nowcoder.com/acm/contest/882#countdown
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
ll v[30][30];
ll tmp,ans;
ll a[20];
ll b[20];
//ll tmp;
void dfs(ll na,ll nb,ll th,ll now)
{

//    cout<<na<<" "<<nb<<" "<<th<<" "<<now<<endl;
    if(na+nb==m)
    {
        ans=max(ans,now);
//        cout<<"now:"<<now<<endl;
//        for(int i=0;i<na;i++)
//        {
//            cout<<a[i]<<" ";
//        }
//        cout<<endl;
//        for(int i=0;i<na;i++)
//        {
//            cout<<b[i]<<" ";
//        }
//        cout<<endl;

        return ;
    }
    if(th==0)
    {
        a[na]=th;
        ll tmp=0;
        for(int i=0;i<nb;i++)
        {
            tmp+=v[th][b[i]];
        }
        now+=tmp;
//        cout<<"tmp111:"<<tmp<<endl;
        dfs(na+1,nb,th+1,now);
        //now-=tmp;
        return ;
    }
    if(na<n)
    {
        a[na]=th;
       ll  tmp=0;
        for(int i=0;i<nb;i++)
        {
            tmp+=v[th][b[i]];
        }
        now+=tmp;
//        cout<<"tmp1:"<<tmp<<endl;
        dfs(na+1,nb,th+1,now);
        now-=tmp;
    }
    if(nb<n)
    {
        b[nb]=th;
        tmp=0;
        for(int i=0;i<na;i++)
        {
            tmp+=v[a[i]][th];
        }
        now+=tmp;
//        cout<<"tmp2:"<<tmp<<endl;
        dfs(na,nb+1,th+1,now);
        now-=tmp;
    }
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
   // freopen("in.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{

#endif // use_t
//    for(int i=0;i<28;i++)
//    {
//        for(int j=0;j<28;j++)
//        {
//            if(i!=j)
//            cout<<i+j<<" ";
//            else cout<<0<<" ";
//        }
//        cout<<endl;
//    }
    int i,j;
    scanf("%lld",&n);
    m=2*n;
    for(i=0;i<2*n;i++)
    {
        for(j=0;j<2*n;j++)
        {
            scanf("%lld",&v[i][j]);
        }
    }
    //ll cnt=6e6;
    tmp=0,ans=0;
    //ll sta[30]={0};
   // ll t1=0,t2=0;

    dfs(0,0,0,0);

    printf("%lld",ans);
#ifdef use_t
}
#endif // use_t
    return 0;
}

