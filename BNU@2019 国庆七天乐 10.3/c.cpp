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
char s[1000005];
ll dis[256][256];

char yuan[]={'a','e','i','o','u','w','y'};
ll cy=7;
ll nc[256];
ll ncnt=1;
ll cn[256];
ll sta[30];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("consonant.in","r",stdin);
    freopen("consonant.out","w",stdout);
#endif

#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    scanf("%s",s);
    mem(cn,0);
    mem(nc,0);
    for(int i='a';i<='z';i++)
    {
        ll ff=1;
        for(int j=0;j<cy;j++)
        {
            if(i==yuan[j])
                ff=0;
        }
        if(ff==0)
            continue;
        cn[i]=ncnt;
        nc[ncnt++]=i;
    }

    mem(dis,0);
    for(int i=0;s[i+1];i++)
    {
        dis[ cn[s[i]]] [ cn[s[i+1]] ]++;
        dis[cn[s[i+1]]] [ cn[s[i]]] ++;
    }

    ll ans=0;
    ll aaa=0;
    for(int i=(1<<19)-1;i>=0;i--)
    {
        ll ti=i;
        ll th=1;
        mem(sta,0);
        while(ti)
        {
            sta[th++]=ti%2;
            ti/=2;
        }
//        cout<<"th:"<<th<<endl;
        ll tmp=0;
        for(int i=1;i<=19;i++)
        {
            for(int j=i+1;j<=19;j++)
            {
                if(sta[i]!=sta[j])
                {
                    tmp+=dis[i][j];
                }
            }
        }
        ans=max(ans,tmp);
        if(ans==tmp)
        {aaa=i;
        }
    }

    ll ti=aaa;
    ll th=1;
    while(ti)
    {
        sta[th++]=ti%2;
        ti/=2;
    }

//    printf("%lld\n",ans);
    for(int i=0;s[i];i++)
    {
        if(sta[ cn[s[i]]] ==1)
            printf("%c",s[i]+'A'-'a');
        else

            printf("%c",s[i]);
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


