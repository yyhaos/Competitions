//Problem Web:http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1006&cid=850
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
const ll maxn=1000;
const ll q=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1)
            ans=ans*a%q;
        a=a*a%q;
        b/=2;
    }
    return ans;
}

ll t,n,m;
ll dp[5][2005][15];
ll a[2005];
ll ta[2005];

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

    cin>>n>>m;
    mem(a,0);
    mem(dp,0);
    mem(ta,0);
//cout<<n<<" "<<m<<endl;
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        ta[i]=a[i];
        ans=max(ans,a[i]);
    }
    sort(ta+1,ta+n+1);



    map<ll,ll> nt;
    nt.clear();
    ll cnt=1;
    for(ll i=1;i<=n;i++)
    {
        if(nt[ta[i]]==0)
        {
            nt[ta[i]]=cnt++;
//            i+=2;
           // cout<<ta[i]<<" "<<cnt-1<<endl;
        }

    }
    cnt--;
    for(ll i=1;i<=n-2;i++)
    {
        if(a[i] > a[i+1] && a[i] <a[i+2] && a[i+1]<a[i+2])
        {
//            cout<<"swap"<<i<<endl;
            swap(a[i+1],a[i+2]);
//            i+=2;
        }
       else if(a[i] < a[i+1] && a[i] >a[i+2] && a[i+1]>a[i+2])
            swap(a[i+1],a[i+2]);
    }

//    cout<<cnt<<endl;
    mem(dp,0);
//    m++;
    for(ll i=0;i<n;i++)
    {

        ll th=nt[a[i+1]];
//        cout<<a[i+1]<<":"<<th<<endl;
        ll tii=i%2;
        for(ll k=1;k<=cnt;k++)
        {
            if(i==0)
            {
//                cout<<"-----"<<k<<" "<<th;
                if(k>=th)
                    dp[tii][k][1]=a[i+1];
                else
                    dp[tii][k][1]=0;
            }
            else
                for(ll now=1;now<=m;now++)
                {
                    dp[tii][k][now]=max(dp[tii][k][now],dp[1-tii][k][now]);
                    if(now>1)
                        dp[tii][k][now]=max(dp[tii][k][now],dp[tii][k][now-1]);

                    if(th >= k)
                    {
                        dp[tii][th][now]=max(dp[tii][th][now],dp[1-tii][k][now]+a[i+1]);
                    }
                    if(now>1)
                        dp[tii][th][now]=max(dp[tii][th][now],dp[1-tii][k][now-1]+a[i+1]);
//                    if(now+1<=m)
 //                    dp[tii][k][now]=max(dp[tii][k][now],dp[1-tii][k][now]);
//                    if(th >= k)
//                    {
//                        dp[tii][th][now]=max(dp[tii][th][now],dp[1-tii][k][now]+a[i+1]);
//                    }
//                    if(now+1<=m)
//                        dp[tii][th][now+1]=max(dp[tii][th][now+1],dp[1-tii][k][now]+a[i+1]);

//                    if(now+1<=m)
//                        ans=max(ans,dp[tii][k][now+1]),ans=max(ans,dp[tii][th][now+1]);

                }
        }
        for(int j=1;j<=cnt;j++)
        {
            for(int now=1;now<=m;now++)
            {
                ans=max(ans,dp[tii][j][now]);
            }
        }

//        for(ll ti=0;ti<=1;ti++)
//        {
//            for(ll jj=1;jj<=cnt;jj++)
//            {
//                cout<<dp[tii][jj][1]<<" ";
//            }
//            cout<<endl<<"2"<<endl;
//            for(ll jj=1;jj<=cnt;jj++)
//            {
//                cout<<dp[tii][jj][2]<<" ";
//            }
//            cout<<endl<<"3"<<endl;
//            for(ll jj=1;jj<=cnt;jj++)
//            {
//                cout<<dp[tii][jj][3]<<" ";
//            }
//            cout<<endl<<"1"<<endl;
//        }
//        cout<<"\n\n";
//        for(ll ti=1;ti<=n;ti++)
//        {
//            for(ll jj=1;jj<=cnt;jj++)
//            {
//                cout<<dp[ti][jj][2]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<"\n";

    }

//    for(int i=1;i<=2;i++)
//    {
//        for(int j=1;j<=cnt;j++)
//        {
//            for(int now=m;now<=m;now++)
//            {
//                ans=max(ans,dp[i%2][j][now]);
//            }
//        }
//    }

cout<<ans<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}


