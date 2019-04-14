//Problem Web:
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
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
char str[10000005];

ll cnt[1000000];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
char yuan[5]={'a','e','i','o','u'};
getchar();
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    gets(str);
    mem(cnt,0);
    for(int i=0;str[i];i++)
    {
        cnt[str[i]]++;
    }
    for(int i=0;i<5;i++)
    {
        cout<<yuan[i]<<":"<<cnt[yuan[i]]<<endl;
    }
    if(ii!=t)
    cout<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}




