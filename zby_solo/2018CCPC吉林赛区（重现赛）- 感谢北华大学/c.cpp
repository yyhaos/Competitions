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
//ll a[1000005];
ll c1[100005];
ll c2[100005];
ll n1,n2;
void q1(ll x)
{
    if(n1==0)
    {
        c1[n1++]=x;
        return ;
    }
    if(n1==1)
    {
        if(c1[n1-1]==x)
        {
            c1[n1-1]=x-1;
        }
        else
            c1[n1++]=x;
        return ;
    }
    if(c1[n1-1] == x)
    {
        c1[n1-1] = 0;
        n1--;
        q1(x-1);
        return ;
    }
    else
        c1[n1++]=x;
}
void q2(ll x)
{
    if(n2==0)
    {
        c2[n2++]=x;
        return ;
    }
    if(n2==1)
    {
        if(c2[n2-1]==x)
        {
            c2[n2-1]=x-1;
        }
        else
            c2[n2++]=x;
        return ;
    }
    if(c2[n2-1] == x)
    {
        c2[n2-1] = 0;
        n2--;
        q2(x-1);
        return ;
    }
    else
        c2[n2++]=x;
}

struct A
{
    ll v,pos;
    friend bool operator < (A a,A b)
    {
        return a.v<b.v;
    }
} a[100005];
ll aa[100005];
void s1()
{
    cout<<"c1: ";
    for(int i=0;i<n1;i++)
    {
        cout<<c1[i]<<" ";
    }
    cout<<endl;
}
void s2()
{
    cout<<"c2: ";
    for(int i=0;i<n2;i++)
    {
        cout<<c2[i]<<" ";
    }
    cout<<endl;
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

    cin>>n;
    n1=0,n2=0;
    mem(c1,0);
    mem(c1,0);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i].v);
        a[i].pos=i;
    }
    sort(a+1,a+1+n);
    ll now;
    for(int i=1;i<=n;i++)
    {

        A now=a[i];
        if(n1==0)
        {
            q1(now.v);
            aa[now.pos]=1;
        }
        else if(n2==0)
        {
            q2(now.v);
            aa[now.pos]=0;
        }
        else
        if(c1[n1-1]>=c2[n2-1])
        {
            q1(now.v);
            aa[now.pos]=1;
        }
        else
        {
            q2(now.v);
            aa[now.pos]=0;
        }
    }

//    s1();
//    s2();

    cout<<"Case "<<ii<<": ";




    if(c1[0]<=1 && c2[0]<=1)
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            printf("%lld",aa[i]);
        printf("\n");
    }
    else
    {
        cout<<"NO\n";
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}
