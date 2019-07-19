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

struct xx
{
    ll zuodao;ll zuozu;
    ll youdao;ll youzu;
    void show()
    {
        cout<<"×óµ½£º"<<zuodao<<" "<<zuozu<<"\tÓÒµ½: "<<youdao<<" "<<youzu<<endl;
    }
};
ll t,n,m;

ll dis[200005];
string a;
ll fi( ll st,char tar,xx& xingxi)
{
    xingxi.youdao=xingxi.youzu=xingxi.zuodao=xingxi.zuozu=0;
    for(ll i=st-1;i>=0;i--)
    {
        if( a[i]==tar )
        {
            if(i<st-1)
                xingxi.zuozu=1;
            xingxi.zuodao=1;
            break;
        }
        else
        {
            if(a[i]!='.')
                break;
        }
    }
    for(ll i=st+1;i<n;i++)
    {
        if(a[i]==tar)
        {
            if(i>st+1)
                xingxi.youzu=1;
            xingxi.youdao=1;
            break;
        }else
        {
            if(a[i]!='.')
                break;
        }
    }
}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("portals.in","r",stdin);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n;

    cin>>a;
//cout<<a<<" ";
ll st,ed;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='s')
            st=i;
        if(a[i]=='e')
            ed=i;
    }
    ll ans=0;
    xx st_o,ed_o,st_ed;
    fi(st,'o',st_o);
    fi(ed,'o',ed_o);
    fi(st,'e',st_ed);

//    cout<<"st_o ";
//
//    cout<<"st_o ";
//    st_o.show();
//    cout<<"ed_o ";
//    ed_o.show();
//    cout<<"st_ed ";
//    st_ed.show();
    if(st_ed.youdao)
    {
        st_o.youdao=0;
        st_o.youzu=0;
        ed_o.zuodao=ed_o.zuozu=0;
        if(st_ed.youzu==0)
        {
            ans=-1;
           // goto  aa;
        }
        else
        {
            ans++;
        }
    }
    if(st_ed.zuodao)
    {
        st_o.zuodao=st_o.zuozu=0;
        ed_o.youdao=ed_o.youzu=0;
        if(st_ed.zuozu==0)
        {
            ans=-1;
          //  goto aa;
        }
        else
        {
            ans++;
        }
    }

    ll tmp=0;
    if(ans==-1)
    {
        cout<<ans<<'\n';
        continue;
    }
    if((st_o.youdao || st_o.zuodao) && (ed_o.youdao || ed_o.zuodao))
    {
//        cout<<"------------"<<endl;
        ll tmp1=0,tmp2=0;
        if(st_o.youdao)
        {
            if(st_o.youzu==0)
                tmp1=10000;
            else
                tmp1=1;
        }
        if(st_o.zuodao)
        {
            if(st_o.zuozu==0)
            {
                tmp1=10000;
            }
            else
                tmp1++;
        }
        if(ed_o.youdao)
        {
            if(ed_o.youzu==0)
                tmp2=10000;
            else
                tmp2=1;
        }
        if(ed_o.zuodao)
        {
            if(ed_o.zuozu==0)
            {
                tmp2=10000;
            }
            else
                tmp2++;
        }
//        cout<<"tmp:"<<tmp1<<" "<<tmp2<<endl;
        ans+=min(tmp1,tmp2);
    }
    if(ans>10)
        ans=-1;
    aa:

    cout<<ans<<"\n";

#ifdef use_t
}
#endif // use_t
    return 0;
}
