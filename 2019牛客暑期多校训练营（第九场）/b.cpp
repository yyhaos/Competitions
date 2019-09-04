//Problem Web:https://ac.nowcoder.com/acm/contest/889#countdown

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
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll p=1e9+7;
ll ksm(ll a,ll b,ll qq=p)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%qq;
        a=a*a%qq;
        b/=2LL;
    }
    return ans;
}
//ll w,ok;
ll t,n,m;
ll w;
struct field{//扩域 x实部 y虚部
    ll x,y;
    field(ll a=0,ll b=0){
        x=a;y=b;
    }
};
field operator*(field a,field b)
{return field(a.x*b.x%p+a.y*b.y%p*w%p,a.x*b.y%p+a.y*b.x%p);}
ll ran(){//随机数种子
    static ll seed=23333;
    return seed=((((((ll)seed^20030927)%p+330802)%p*9410)%p-19750115+p)%p^730903)%p;
}
ll pows(ll a,ll b)
{
    ll base=1;	while(b)
    {
        if(b&1) base=base*a%p;		a=a*a%p;b/=2;
    }
    return base;
}
field powfield(field a,ll b)
{//扩域快速幂
    field base=field(1,0);
    while(b)
    {
        if(b&1) base=base*a;
        a=a*a;b/=2;
    }
    return base;
}
ll legander(ll x)
{//勒让德记号 //返回-1时x不为二次剩余//返回1时x为二次剩余//返回0时p整除x
    ll a=pows(x,(p-1)/2);
    if(a+1==p) return -1;
    return a;
}
ll surplus(ll x)
{//求b.x*b.x==x(mod p)时的b.x//即给定x，求x为二次剩余时的解b.x//x为非二次剩余时返回0 while(1)期望次数两次
    ll a;
    if(legander(x)==-1) return 0;
    while(1)
    {
        a=ran()%p;
//        cout<<a<<endl;
        w=((a*a-x)%p+p)%p;
        if(legander(w)==-1) break;
    }
    field b=field(a,1);
    b=powfield(b,(p+1)/2);
    return b.x;
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
ll b,c;

    cin>>b>>c;
    ll q=p;
    ll tar=(b*b%q-(4LL*c)%q+q)%q;
//    cout<<"tar: "<<tar<<endl;
    if(legander(tar)==1)
    {
        ll x_y[5];
        x_y[1]=(q*q-surplus(tar))%q;
        x_y[2]=(q-x_y[1])%q;
        ll fa=0;
        for(ll i=1;i<=2;i++)
        {
            ll tx_y=x_y[i];
//            cout<<"cha: "<<x_y<<endl;
            if(tx_y>=0)
            {
                ll a[2];
                a[0]=(b+tx_y)/2;
                a[1]=(b-a[0]+q)%q;

//                cout<<a[0]<<" "<<a[1]<<endl;
                sort(a,a+2);
                if(a[0]*a[1] %q==c)
                {
                    cout<<a[0]<<" "<<a[1]<<endl;
                    fa=1;
                    break;
                }
            }
        }

        if(fa==0)
        {
            cout<<-1<<" "<<-1<<endl;
        }
    }
    else
    {
        if(b%2==0)
        {
            if(b*b/4==c)
            {
                cout<<b/2<<" "<<b/2<<endl;
                continue;
            }
        }
        cout<<"-1 -1\n";

    }



#ifdef use_t
}
#endif // use_t
    return 0;
}


