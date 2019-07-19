//Problem Web:https://codeforces.com/gym/225575
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
ll fw;
map < string , ll > nv;
map<ll,string> vn;
ll dp[1005][2005];
ll w[1005];
ll aa[10000];
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
    cin>>fw>>m;
    //cout<<fw<<m<<endl;
    string t1;ll t2;

ll maa=0;
ll mai;
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2;
       // cout<<t1<<" "<<t2<<endl;
        nv[t1]=i;
        vn[i]=t1;
        w[i]=t2;
       // maa+=w[i];
    }

    mem(dp,0);
    for(int i=0;i<=m;i++)
    dp[i][0]=1,
    dp[i][2001]=0;
    //cout<<m<<endl;
    for(int i=1;i<=m;i++)
    {

       // maa+=w[i];
        //dp[i][1001]=0;
        //dp[i][0]=1;
        for(int j=0;j<=1000;j++)
        {
           if(dp[i-1][j]==1)
            {
                dp[i][j]=dp[i-1][j];

                //cout<<i<<" "<<j<<endl;
                if(j+w[i]<=2000)
                    dp[i][j+w[i]]=1;

            }
        }
    }
//    for(int i=1;i<=m;i++)
//    {
//        for(int j=0;j<=35;j++)
//        {
//            printf("%lld ",dp[i][j]);
//        }
//        printf("\n");
//    }


    ll req=0;
    cin>>req;
   // cout<<req<<endl;
    ll tc;
    ll ans=0;

    while(req--)
    {
        ans=0;
        scanf("%lld",&tc);
        tc=(tc+1)/2-fw;
        ll now=tc;
        if(tc<0)
            tc=0;
        //cout<<maa<<" "<<tc<<endl;

        for(tc;tc<2001;tc++)
        {
            if(dp[m][tc]!=0)
                break;
        }
        if(tc>=2001)
        {
            cout<<"-1\n";
                continue;
        }

        //cout<<now;
        now=tc;

            for(int i=m;i>=1;i--)
            {
                //cout<<now<<" "<<i<<endl;
                if(now-w[i]>=0)
                {
                    if(dp[i-1][now-w[i]]==1)
                    {
                        now-=w[i];
                        aa[ans++]=i;
                    }
                }
            }

        cout<<ans;
        for(int i=0;i<ans;i++)
        {
            cout<<' '<<vn[aa[i]];
        }

        printf("\n");
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

