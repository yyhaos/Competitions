//Problem Web:https://ac.nowcoder.com/acm/contest/885#countdown
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
const ll q=998244353LL;
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
ll C[3005][3005];
//ll Cni[3005][3005];
ll k[3005];
ll nii[3005];
void init()
{
    for(int i=0;i<3005;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j]%=q;
//            Cni[i][j]=ksm(C[i][j],q-2);
        }
    }
}

//ll ni(ll x)
//{
//    return x;
//}
ll getC(ll n,ll m)
{
    //m=max(m,n-m);
//    if(C[n][m]==0)
//    {
//        return C[n][m]=k[n]*ni(k[m])%q*ni(k[n-m])%q;
//    }
//    else
//    {
        return C[n][m];
//    }
}

ll tt,n,m;
char s[3005],t[3005];
ll dp[3005][3005][2];// i j k sta
inline ll tr(char x)
{
    return x-'0';
}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;

//cout<<"3000 3000\n";
//for(int i=0;i<3000;i++)
//{
//    cout<<1;
//}
//cout<<endl;
//for(int i=0;i<3000;i++)
//{
//    cout<<1;
//}
//cout<<endl;
//init();
cin>>tt;
mem(C,0);
init();
//mem(nii,0);
k[1]=1;
k[0]=1;
for(ll i=2;i<=3000;i++)
{
    k[i]=i*k[i-1]%q;
}

for(ii=1;ii<=tt;ii++)
{
#endif // use_t

    scanf("%lld%lld",&n,&m);
    scanf("%s%s",s,t);
    ll ans=0;
//    mem(dp,0);
    for(ll i=0;i<m;i++)
    {
        for(ll j=i;j<n;j++)
        {
//                for(ll last=0;last<10;last++)
//                {
                for(ll sta=0;sta<2;sta++)
                    dp[i][j][sta]=0;
        }
    }
//    for(int i=0;i<n;i++)
//    {
//        for(int )
//    }
    if(n<m)
    {
        ans=0;
    }
    else
    {
        if(n>m)
        {
            ll yu=n-1;
            for(int i=0;i<n;i++)
            {
                yu=n-1-i;

                if(yu<m)
                {
                    break;
                }
                if(s[i]!='0')
                {
                    for(ll jia=m;jia<=yu;jia++)
                    {
                        ans=(ans+C[yu][jia])%q;
                    }
                }
            }
        }
ll tm,tn;
int sta;

//cout<<"ans1: "<<ans<<endl;
        for(int i=0;i<m;i++) // 前面的位数
        {
//            if(i)
            tm=tr(t[i]);
            for(int j=i;j<n;j++)// 只考虑前j位
            {
                tn=tr(s[j]);
                if(i==0) // 起始
                {
                    if(tn>0)
                    {
                        if(tn>tm)
                            dp[i][j][0]++;
                        else if(tn == tm)
                        {
                            dp[i][j][1]++;
                        }
                    }
//                    if(0==m-1)
//                        ans=(ans+dp[m-1][j][0]%q)%q;
                    for(sta=0;sta<2;sta++)
                    {
                        dp[i][j+1][sta]+=dp[i][j][sta];
//                        dp[i][j+1][sta]%=q;
                    }
                }
                else
                {

//                    cout<<"jin"<<" "<<i<<"-"<<j<<" "<<tn<<"-"<<tm<<endl;

//                    for(int last=0;last<10;last++) // 前j位中 末尾位是last
//                    {
//ll last=0;
//                    for(sta=0;sta<2;sta++)// 状态量 sta:0 前面未顶格 sta:1 前面顶格
//                    {

//                            ll prei=i-1;
//                    if(tn>0)
//                    {
                        if(tn>tm) // 大于 统统都加上
                        {
// cout<<"jin2"<<" "<<i<<"-"<<j<<" "<<tn<<"-"<<tm<<endl;
                            dp[i][j][0]+=dp[i-1][j-1][0]+dp[i-1][j-1][1];
//                            dp[i][j][0]%=q;
                        }
                        else if(tn<tm) // 小于 只能加已经超过的
                        {
//                            if(sta==0)
//                            {
                                dp[i][j][0]+=dp[i-1][j-1][0];
//                                dp[i][j][0]%=q;
//                            }
                        }
                        else // tn==tm 等于 只能加 已经超过的 ， 或者是加1状态的值
                        {
//                            if(sta==1)
//                            {
                                dp[i][j][1]+=dp[i-1][j-1][1];
//                                dp[i][j][1]%=q;
//                            }
//                            if(sta==0)
//                            {
                                dp[i][j][0]+=dp[i-1][j-1][0];
//                                dp[i][j][0]%=q;
//                            }
                        }
//                    }



//                    dp[i][j][0]%=q;
//                    dp[i][j][1]%=q;
//                    if(i==m-1)
//                    {
//                        ans=(ans+dp[m-1][j][0]%q)%q;
//                    }
                    for(sta=0;sta<2;sta++)
                    {
                        dp[i][j+1][sta]+=dp[i][j][sta];
                        dp[i][j+1][sta]%=q;
                    }

                }
//                for(int i=0;)

            }
        }

//        for(ll i=0;i<m;i++)
//        {
//            for(ll j=i;j<n;j++)
//            {
////                for(ll last=0;last<10;last++)
////                {
//                    for(ll sta=0;sta<2;sta++)
//                    {
//                        printf("%lld %lld  %lld = %lld\n",i,j,sta,dp[i][j][sta]);
//                    }
////                }
//            }
//        }

//        for(int j=0;j<n;j++)
//        {
////            for(int last=0;last<10;last++)
////            {
////                  ans=(ans+dp[m-1][j][0]%q)%q;
////            }
//        }
        ans=(ans+dp[m-1][n-1][0])%q;
       // printf("%lld\n",ans);
    }

    printf("%lld\n",ans);




#ifdef use_t
}
#endif // use_t
    return 0;
}

