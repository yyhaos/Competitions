//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=867
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
double E[105][2];
double dfs(ll i,ll j,double p)
{
    if(j==2)
    {
        i++;
        j=0;
    }
    if(i>=100)
        i=100,j=0;
    if(E[i][j]>=0)
        return E[i][j];
    else
    {
        if(i>=100)
        {
            j=0;
            i=100;
        }

        double tmp=0;
        tmp+=1;
        if(i!=100)
            tmp+=p/100.0*(100.0- i - 1.0*j*0.5)/100.0*dfs(i+2,j,p);
        tmp+=(1.0-p/100.0)*dfs(i+1,j+1,p);
        return E[i][j]=tmp;

    }
}
int main ()
{
    double p;
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
    for(int i=0;i<=100;i++)
        for(int j=0;j<2;j++)
            E[i][j]=-1;
    cin>>p;
    cout<<"Case "<<ii<<": ";
    //<<dfs(2,0,p)<<endl;
    E[100][0]=E[100][1]=100.0/p;
    printf("%.10f\n",dfs(2,0,p));





#ifdef use_t
}
#endif // use_t
    return 0;
}
