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
vector <ll> M[100005];
ll num[100005];

ll cc[100005];
ll cnt=0;

void dfs_cnt(ll th)
{
    if(cc[th]==1)
        return ;
    cnt++;
    cc[th]=1;
    ll si=M[th].size();
    for(int i=0;i<si;i++)
    {
        int nxt=M[th][i];
        if(cc[nxt]==0)
        dfs_cnt(nxt);
    }
}
ll dp[100005][3];

ll dfs_co(ll th,ll co,ll st)
{
   // cout<<th<<" "<<co<<" "<<st<<endl;

    if(dp[th][co]!=-1)
        return dp[th][co];

    ll si=M[th].size();
    ll cnt=2-co;
    for(int i=0;i<si;i++)
    {
        ll nt=M[th][i];
        if(nt==st)
        {
            continue;
        }
        else
        {
            if(co==1)
                cnt+=dfs_co(nt,2,th);
            else
                cnt+=max(dfs_co(nt,1,th),dfs_co(nt,2,th));
        }
    }
    //num[th]=0;
    return dp[th][co]=cnt;
}

ll fi(ll th)
{
    //cnt=0;
    dfs_cnt(th);
    //ll si=cnt;

    return max(dfs_co(th,2,-1),dfs_co(th,1,-1));
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
    for(int i=0;i<100005;i++)
    {
        for(int j=0;j<3;j++)
            dp[i][j]=-1;
    }
    cin>>n>>m;
    mem(cc,0);
    ll u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%lld%lld",&u,&v);
        M[u].push_back(v);
        M[v].push_back(u);
    }
    ll ans=0;
    ll tmp=0;
    mem(num,0);
    while(1)
    {
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(M[i].size()<=1 && cc[i]==0)
            {
                //cout<<"fi:"<<i<<" "<<cc[i]<<endl;
                ans+=fi(i);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }


//    ans=0;
//    for(int i=1;i<=n;i++)
//    {
//        if(num[i]==1)
//            ans++;
//        cout<<num[i]<<" ";
//    }
    //cout<<endl;


    printf("%lld",ans);





#ifdef use_t
}
#endif // use_t
    return 0;
}

