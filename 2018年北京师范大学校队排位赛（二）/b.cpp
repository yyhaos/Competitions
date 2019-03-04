//Problem Web:  https://codeforces.com/gym/225575/problem/B
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1005;
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
char name[1005][20];
ll we[1005];
ll dp[2005][2005];
int item[1005];
ll ans=0;
void FindWhat(int i,int j)//寻找解的组成方式
{
    if(i>=0)
    {
        if(dp[i][j]==dp[i-1][j])//相等说明没装
        {
            item[i]=0;//全局变量，标记未被选中
            FindWhat(i-1,j);
        }
        else if( j-we[i]>=0 && dp[i][j]==dp[i-1][j-we[i]]+we[i] )
        {
            ans++;
            item[i]=1;//标记已被选中
            FindWhat(i-1,j-we[i]);//回到装包之前的位置
        }
    }
}
ll aa[1005];
int main ()
{

#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("in.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
//    rep(i,1,1000)
//    {
//        char s1='a'+i%26;
//        char s2='a'+i*2%26;
//        char s3='a'+i*3%26;
//        char s4='a'+i*4%26;
//        char s5='a'+i*5%26;
//        cout<<s1<<s2<<s3<<s4<<s5<<" "<<i<<endl;
//    }
    ll wkit;
    scanf("%lld %lld\n",&wkit,&m);
    rep(i,1LL,m)
    {
        scanf("%s %lld\n",&name[i],&we[i]);
        //cout<<name[i];
    }
    rep(i,0LL,1000LL)
    {
        rep(j,0LL,1000LL)
        {
            dp[i][j]=0LL;

        }
    }

    dp[0][0]=0LL;
    rep(i,1LL,m)
    {
        rep(j,1LL,2000LL)
        {
            if(j<we[i])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                if(dp[i-1][j]>dp[i-1][j-we[i]]+we[i])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j-we[i]]+we[i];
                }
            }
//            if(i<=10)
//                cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    dp[m][2001]=0;
    dp[m][2002]=0;
    dp[m][2003]=0;
    dp[m][2004]=0;
    dp[m-1][2001]=0;
    dp[m-1][2002]=0;
    dp[m-1][2003]=0;
    dp[m-1][2004]=0;
    scanf("%lld\n",&n);
    ll tmp;

    while(n--)
    {
        scanf("%lld",&tmp);
        ll yuan=tmp;
        tmp=(tmp+1LL)/2LL-wkit;
       // cout<<tmp<<endl;
        rep(i,tmp,2001LL)
        {

            //cout<<i<<endl;
            tmp=i;
            if(dp[m][i]==i)
            {
                break;
            }
        }
//cout<<tmp<<endl;
        if(tmp>=2001LL)
        {
            printf("-1");
        }
        else
        {
            ans=0;
            FindWhat(m,tmp);

            printf("%lld",ans);
            for(ll i=1;i<=m;i++)
            {
                if(item[i]==1)
                printf(" %s",name[i]);

            }

            //cout<<'\n';
        }
        if(n)
            printf("\n");
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}
