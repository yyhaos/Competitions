//Problem Web:
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
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
ll flag[1005]={};
char s[1005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("boolean.in","r",stdin);
    freopen("boolean.out","w",stdout);
#endif

#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    scanf("%s",s);
    ll cnt=0;
    ll sta=1;
    ll hasfei=0;
//    ll cnt=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='|')
        {
            continue;
        }
        else
        {
            if(s[i]=='~')
            {
                sta=0;
            }
            else
            {
                if(sta==0){
                    if(flag[s[i]]==0)
                    {
                        flag[s[i]]=1;
                        cnt++;
                    }
                    else if(flag[s[i]]==2)
                    {
                        hasfei=1;
                    }
                }
                else
                {
                    if(flag[s[i]]==1)
                    {
                        hasfei=1;
                    }
                    else if(flag[s[i]]==0)
                    {
                        flag[s[i]]=2;
                        cnt++;
                    }
                }
                sta=1;
            }
        }
    }


    if(hasfei)
    {
        printf("%lld\n",(1LL)<<cnt);
    }
    else
        printf("%lld\n",((1LL)<<cnt)-1);





#ifdef use_t
}
#endif // use_t
    return 0;
}


