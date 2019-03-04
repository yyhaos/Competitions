//Problem Web:
#include<bits/stdc++.h>
#include<ext/rope>
#include<cstdio>
#include<cstring>
#include<cstdlib>
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
ll dp[20][1000005];
ll kk=0;
ll t,n,m;
char M[20][25][25];
char aa[25][25][5];
ll dis[25][25];
ll fi(ll a,ll b)
{
    ll ans=0;
    rep(i,1,21)
    {
        rep(j,0,20)
        {
            if(M[a][i][j]!=M[b][i][j])
            {
              //  cout<<i<<"-"<<j<<'\t';
                ans++;
            }
        }
    }
    if(b==0)
    {
        return m;
    }
    if(a==0)
    {

        return ans;
    }
    if(ans<=dis[a][0]+dis[0][b])
    {
        if(b<10)
        {
            aa[a][b][0]='0'+b;
            aa[a][b][1]='\0';
        }
        else
        {
            aa[a][b][0]='1';
            aa[a][b][1]='0'+b%10;
            aa[a][b][2]='\0';
        }
        //aa[a][b][1]='\0';
        return ans;
    }
    else
    {
        aa[a][b][0]='*';
        aa[a][b][1]='\n';

        if(b<10)
        {
            aa[a][b][2]='0'+b;
            aa[a][b][3]='\0';
        }
        else
        {
            aa[a][b][2]='1';
            aa[a][b][3]='0'+b%10;
            aa[a][b][4]='\0';
        }

        return dis[a][0]+dis[0][b];
    }
    return ans;
}
ll used[20];
ll DP(ll pre,ll now)
{
    if(pre==0)
    {
        if(now==1)
        {
            return 0;
        }
        else
        {
            return 999999999LL;
        }
    }
    if(now==1)
        dp[pre][now]=0;
    else if(dp[pre][now]==-1)
    {
        ll tn=now-(1LL<<pre);
        for(int bp=0;bp<=n;bp++)
        {
            if( (tn & (1<<bp))==0)
                continue;
            if(dp[pre][now]==-1)
            {
                dp[pre][now]=DP(bp,tn)+dis[bp][pre];
            }
            else
            {
                dp[pre][now]=min(dp[pre][now],DP(bp,tn)+dis[bp][pre]);
            }
        }
    }
    //cout<<pre<<"-"<<now<<"="<<dp[pre][now]<<endl;
    return dp[pre][now];
}
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

    cin>>n>>m;
    rep(i,1,21)
    {
        rep(j,0,21)
        {
            M[0][i][j]='0';
        }
    }
    rep(i,1,n)
    {
        rep(j,1,21)
        {
            scanf("%s",M[i][j]);
        }
    }
    rep(i,1,n)
    {
        dis[0][i]=fi(0,i);
        dis[i][0]=m;
        if(i<10)
        {
            aa[0][i][0]='0'+i;
            aa[0][i][1]='\0';
        }
        else
        {
            aa[0][i][0]='1';
            aa[0][i][1]='0'+i%10;
            aa[0][i][2]='\0';
        }

    }
    rep(i,1,n)
    {
        rep(j,i+1,n)
        {
            dis[i][j]=fi(i,j);
            dis[j][i]=fi(j,i);
        }
    }
    rep(j,0,19)
    rep(i,0,1<<(n+1))
    {
        dp[j][i]=-1;
    }

    ll tar=(1<<(n+1))-1;
    dp[0][1]=0;
    rep(pre,1,n)
        DP(pre,tar);
    ll kk=999999999999LL;
    //cout<<tar<<endl;
    ll ji=-1;
    for(int i=1;i<=n;i++)
    {
        if(dp[i][tar]!=-1)
        kk=min(kk,dp[i][tar]);
        if(kk==dp[i][tar])
        {
            ji=i;
        }
    }
    cout<<kk<<endl;
    ll path[25];
    ll cnt=0;
    ll pre=ji;
    while(tar>1)
    {

        path[cnt++]=pre;
        ll tn=tar;
        tar=tn-(1LL<<pre);
        for(int bp=0;bp<=n;bp++)
        {
            if(bp==0 && tar !=1)
                continue;
            if( (tn & (1<<bp))==0)
                continue;
            if( dp[bp][tar] + dis[bp][pre] == dp[pre][tn] )
            {
                pre=bp;
                break;
            }
        }
    }
    ll po=0;
    crep(i,cnt-1,0)
    {
        cout<<aa[po][ path[i] ]<<endl;
        po=path[i];
    }

#ifdef use_t
}
#endif // use_t
    return 0;
}


