//Problem Web:  https://vjudge.net/contest/288922#problem/H
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
#include<math.h>
#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair

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
#define use_t 1
string st;
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
getchar();
for(ii=1;ii<=t;ii++)
{
#endif // use_t


    getline(cin,st);
    //cout<<st<<endl;
    char pre;
    for(int i=0;st[i];i++)
    {
        if(st[i]>='0' && st[i]<='9')
        {
            for(int j=0;j<st[i]-'0';j++)
            {
                printf("%c",pre);
            }
        }
        else
        {
            printf("%c",st[i]);
            pre=st[i];
        }
    }
    cout<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}
