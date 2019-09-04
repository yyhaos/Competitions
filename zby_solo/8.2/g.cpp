//Problem Web:www.bnuoj.com/contest_show.php?cid=9519#info
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
string str[1005];
ll cnt=1;
ll num[1005][1005];
ll si[1005][1005];
int main ()
{
    mem(num,0);
    mem(si,0);
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
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>str[i+1];
    }
    for(int i=0;)
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='0')
            {
                ll pre1,pre2;
                if(i)
                {
                    if(num[i-1][j] != 0 && si[i-1][j]<5)
                    {
                        num[i][j]=num[i-1][j];
                        si[i-1][j]++;
                        si[i][j]=si[i-1][j];
                    }
                }
                else
                {

                }
            }
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

