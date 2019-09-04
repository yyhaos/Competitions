//Problem Web:  https://vjudge.net/contest/288922#problem/G
//#include<bits/stdc++.h>
//#include<ext/rope>
#include<map>
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
char st[]="010010100110100101100001011011110111101001101000011101010011100000110111";
ll t,n,m;
//#define use_t 1
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
ll cnt=0;
for(int i=0;st[i];i++)
{
        cnt++;
}
//cout<<cnt;
    for(int k=0;k<72;k+=8)
    {
        char tmp=0;
        int tt=1;
        for(int i=7;i>=0;i--)
        {
            tmp+=tt*(st[i+k]-'0');
            tt*=2;
        }
        cout<<tmp;
    }

    cout<<endl;




#ifdef use_t
}
#endif // use_t
    return 0;
}
