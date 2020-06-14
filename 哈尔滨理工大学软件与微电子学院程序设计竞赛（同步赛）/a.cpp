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
const int PI=acos(-1.0);
const int eps=1e-8;
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
char  ans[3][50]={"Ming","Hong","Tie"};

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

    int v1,v2,t,s,l;
    cin>>v1>>v2>>t>>s>>l;

    if(v2>v1){
       printf("%s %d",ans[1],  l/v2);
        return 0;
    }
    if(v2==v1){
            printf("%s %d",ans[2],  l/v2);
        return 0;
    }


    int t2=l/v2;

    int t1=0;

    int n1=0,n2=0;
    while(1){
        t1++;
        n1+=v1;
        n2+=v2;

        if(n1>=l)
            break;
        if(n1-n2 >= t){
            t1+=s;
            n2+=s*v2;
        }
    }



// printf("%d %d\n",t1,t2);
    if(t1==t2){
        printf("%s %d\n",ans[2], t2);
    }
    else  if(t1<t2){
        printf("%s" , ans[0]);
        printf(" %d",t1);
    }
    else if(t1>t2){
        printf("%s %d\n",ans[1],t2);
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

