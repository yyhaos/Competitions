//Problem Web:  http://www.bnuoj.com/contest_show.php?cid=9478#problem/G
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
double s[105][100];
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

    while(cin>>n>>m)
    {
        mem(s,0);
        rep(i,1,n)
        {
            double sum=0;
            rep(j,1,m)
            {
                cin>>s[i][j];
                sum+=s[i][j];
                s[0][j]+=s[i][j];
            }
            sum/=m;
            s[i][0]=sum;
        }
        rep(i,1,n)
        {
            printf("%.2f",s[i][0]);
            if(i!=n)
                cout<<" ";
        }
        cout<<endl;
        rep(i,1,m)
        {
            printf("%.2f",s[0][i]/n);
            if(i!=m)
                cout<<" ";
        }
        cout<<endl;
        ll cnt=0;
        rep(i,1,n)
        {
            ll flag=1;
            rep(j,1,m)
            {
                if(s[i][j]< s[0][j]/n)
                {
                    flag=0;
                }
            }
            cnt+=flag;
        }
        cout<<cnt<<endl<<endl;
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}




