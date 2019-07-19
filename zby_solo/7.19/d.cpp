//Problem Web:
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
ll a[35][35];
ll b[35][35];
ll ta[35][35];
void R()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ta[i][j]=a[n-j-1][i];
        }
    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            cout<<ta[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=ta[i][j];
        }
    }

}
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
    while(cin>>n)
    {
        if(!n)
            return 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%lld",&a[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%lld",&b[i][j]);
            }
        }

        ll ans=0,tmp;
        for(int i=0;i<4;i++)
        {
//            for(int i=0;i<n;i++)
//            {
//                for(int j=0;j<n;j++)
//                {
//                    cout<<a[i][j]<<" ";
//                }
//                cout<<endl;
//            }
            tmp=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[i][j]==b[i][j])
                        tmp++;
                }
            }
                ans=max(ans,tmp);
            R();
        }
        cout<<ans<<"\n";

    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


