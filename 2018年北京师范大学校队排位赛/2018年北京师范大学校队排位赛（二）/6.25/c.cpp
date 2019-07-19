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
 ll a;
ll t,n,m;
char qr[20][25][25];
ll dis[20][20];
ll way[20][20];
ll Di(ll i,ll j)
{
    if(i==j)
    {
        way[i][j]=-1;
        return 0;
    }
    if(j==0)
    {
        return a;
    }
    ll cnt=0;
    if(i==0)
    {

        for(int ii=0;ii<=20;ii++)
        {
            for(int jj=0;jj<=20;jj++)
            {
                if(qr[j][ii][jj]=='1')
                {
                    cnt++;
                }
            }
        }
        //cout<<"00"<<cnt<<endl;
        return cnt;
    }
    for(int ii=0;ii<=20;ii++)
    {
        for(int jj=0;jj<=20;jj++)
        {
            if(qr[i][ii][jj]!=qr[j][ii][jj])
            {
                cnt++;
            }
        }
    }


    //cout<<cnt<<endl;
    ll tmp=Di(i,0)+Di(0,j);
    if(tmp<cnt)
    {
        way[i][j]=0;
        return tmp;
     }
    else
    {
        way[i][j]=1;
        return cnt;
    }

}

ll dp[1<<19][20];

ll path[20];
ll be[1<<19];
void dfs(ll tar, ll mi)
{
    //cout<<"tar:"<<tar<<" mi:"<<mi<<endl;
    if(tar==0)
        return ;
    ll fi;
    ll bef=tar-(1<<mi);
    for(fi=0;fi<n;fi++)
    {
        if(((1<<fi) & tar)==0)
            continue;
        if(dis[fi+1][mi+1]+dp[bef][fi]==dp[tar][mi])
            break;
    }

    dfs(bef,fi);
    if(way[fi+1][mi+1]==1)
    {
        printf("%lld\n",mi+1);
    }
    else
    {
        if(bef!=0)
            printf("*\n");
        printf("%lld\n",mi+1);
    }

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
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    cin>>n>>a;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=20;j++)
        {
            cin>>qr[i][j];
           // cout<<qr[i][j]<<endl;
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dis[i][j]=Di(i,j);
        }
    }

//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;j<=n;j++)
//        {
//            cout<<dis[i][j]<<"\t";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;j<=n;j++)
//        {
//            cout<<way[i][j]<<"\t";
//        }
//        cout<<endl;
//    }


    ll ans=INF;
    ll tar=(1<<n)-1;
    for(ll i=0;i<=tar;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    for(ll now=0;now<tar;now++)
    {
        if(now==0)
        {
            for(ll nxt=0;nxt<n;nxt++)
                {

                        ll tnxt=(1<<nxt)+now;

                       // cout<<nxt<<" "<<tnxt<<" "<<now<<endl;
                        dp[tnxt][nxt]=dis[0][nxt+1];
                        be[tnxt]=0;

                }
        }
        else
            for(ll fi=0;fi<n;fi++)
            {
                if((1<<fi) & now)
                {
                    for(ll nxt=0;nxt<n;nxt++)
                    {
                        if(((1<<nxt) & now)==0)
                        {
                            ll tnxt=(1<<nxt)+now;
                            if(dp[tnxt][nxt]!=-1)
                            {
                                dp[tnxt][nxt]=min(dp[tnxt][nxt],dp[now][fi]+dis[fi+1][nxt+1]);
                                if(dp[tnxt][nxt]==dp[now][fi]+dis[fi+1][nxt+1])
                                    be[tnxt]=fi;
                            }
                            else
                            {
                                dp[tnxt][nxt]=dp[now][fi]+dis[fi+1][nxt+1];
                                be[tnxt]=fi;
                            }
                        }
                    }
                }
                else
                {
                    continue;
                }
            }
    }
    ll mi=0;
//    for(int now = 1 ;now <=tar;now++)
//    {
//        cout<<"now:"<<now<<":"<<endl;
//        for(int fi=0;fi<n;fi++)
//        {
//            cout<<"fi:"<<fi<<" "<<dp[now][fi]<<endl;
//        }
//    }
//    cout<<tar<<" "<<n<<endl;
    for(int i=0;i<n;i++)
    {
        ans=min(ans,dp[tar][i]);
        if(ans==dp[tar][i])
            mi=i;
    }

    cout<<ans<<endl;

    dfs(tar,mi);

#ifdef use_t
}
#endif // use_t
    return 0;
}

