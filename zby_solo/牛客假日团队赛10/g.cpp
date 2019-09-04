//Problem Web:https://ac.nowcoder.com/acm/contest/1072#question
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

const ll N=1000000;
//f[]：可以取走的石子个数
//sg[]:0~n的SG函数值
//mhash[]:mex{}
int f[N+5],sg[N+5],mhash[N+5];
void getSG(int n)
{
    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=n;i++)
    {
        for(int i=0;i<=10;i++)
            mhash[i]=0;
//        memset(mhash,0,sizeof(mhash));
        ll maxx=0;ll minn=10;
        ll ti=i;
        while(ti)
        {
            maxx=max(maxx,ti%10);
            if(ti%10!=0)
                minn=min(minn,ti%10);
            ti/=10;
        }
        if(maxx!=0)
            mhash[sg[i-maxx]]=1;
        if(minn!=10)
            mhash[sg[i-minn]]=1;
        for(j=0;j<=n;j++)    //求mes{}中未出现的最小的非负整数
        {
            if(mhash[j]==0)
            {
                sg[i]=j;
                break;
            }
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

    getSG(1000000);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll tmp;
        cin>>tmp;
//        cout<<tmp<<endl;
        if(sg[tmp])
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}


