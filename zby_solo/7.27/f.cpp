//Problem Web:https://vjudge.net/contest/315213#problem/F
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
ll a[100005];
ll qian[100005];
ll hou[100005];
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
    mem(qian,0);
    mem(hou,0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",a+i);
    }

    ll pre=a[0];
    qian[0]=0;
    for(int i=1;i<n;i++)
    {
        qian[i]=qian[i-1];
        if(a[i]>=pre)
        {
            qian[i]=max(qian[i-1], a[i]-pre);
        }
        else
            pre=a[i];
//        cout<<qian[i]<<" ";
    }
    pre=a[n-1];
//    cout<<endl;
    hou[n-1]=0;
    hou[n]=0;
    for(int i=n-2;i>=0;i--)
    {
        hou[i]=hou[i+1];
//        cout<<"p:"<<pre <<" "<<a[i]<<endl;
        if(a[i]<=pre)
        {
            hou[i]=max(hou[i+1],pre-a[i]);
        }
        else
            pre=a[i];
//            cout<<hou[i]<<" ";
    }

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,qian[i]+hou[i+1]);
    }
cout<<ans<<"\n";
#ifdef use_t
}
#endif // use_t
    return 0;
}
