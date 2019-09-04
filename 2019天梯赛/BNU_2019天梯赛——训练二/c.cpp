//Problem Web:  https://vjudge.net/contest/288922#problem/C
//#include<bits/stdc++.h>
//#include<ext/rope>
#include<map>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll unsigned short int
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair


ll n,m;
#define use_t 1
void sh(ll n)
{
    for(int i=0;i<=15;i++)
    {
        if(n%2==1)
            cout<<n%2;
        else
            cout<<0;
        n/=2;
    }
    cout<<endl;
}
bool ok(ll& n ,ll& m)
{
    ll tn;
    ll t2;
    rep(i,0,15)
    {
        tn=n<<i;
        t2=n>>(16-i);
        tn=tn|t2;
         //sh(tn);
        if(tn==m)
            return true;
    }
    return false;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int  ii=1;
int t;
scanf("%d",&t);
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    scanf("%hd%hd",&n,&m);
    if(ok(n,m))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    if(ii!=t)
        printf("\n");



#ifdef use_t
}
#endif // use_t
    return 0;
}
