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
ll a[1000005];
ll pre[1000005];
ll go[1000005];
ll figo(ll pos)
{
    if(pos==0)
    {
        pre[pos]--;
        return pos;
    }
//    pos=go[pos];
    if(go[pos]!=pos)
    {
       return go[pos]=figo(go[pos]);
    }

    if(pre[pos] >1+ a[pos-1])
    {
        pre[pos]--;
        return pos;
    }
    else
        if(pre[pos] > a[pos-1])
        {
            pre[pos]--;
            return go[pos]=go[pos-1];
        }
        else
                return go[pos]=figo( pos-1 );
}
//ll fipre(ll pos)
//{
//    pos=figo(pos);
//    ll kong=pre[pos];
//    while(pos>=1 && kong<=a[pos-1])
//    {
//        go[pos]=figo(pos-1);
//        pos=go[pos];
//        kong=pre[pos];
//    }
//    return kong;
//}
struct job
{
    ll d,p;
}jb[1000005];


bool cmp(job a,job b)
{
    return a.d<b.d;
}
bool cmp2(job a,job b)
{
    return a.p>=b.p;
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
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld%lld",&jb[i].d,&jb[i].p);
        if(jb[i].d>n)
        {
            n--;
            i--;
            ans+=jb[i+1].p;
        }
    }
//    cout<<n<<endl;
    sort(jb+1,jb+1+n,cmp);
    ll cnt=0;

    jb[n+1].d=-1;

    for(ll i=1;i<=n;i++)
    {
        if(jb[i].d!=jb[i+1].d)
        {
            pre[cnt]=jb[i].d;
            go[cnt]=cnt;
            a[cnt]=jb[i].d;
            cnt++;
        }
    }
    sort(jb+1,jb+1+n,cmp2);
//cout<<"cnt:"<<cnt<<endl;
//        cout<<figo(2)<<" "<<a[2]<<endl;
    for(ll i=1;i<=n;i++)
    {
//for(int ii=0;ii<cnt;ii++)
//{
//    cout<<"ii:"<<ii<<" "<<a[ii]<<" "<<pre[ii]<<endl;
//}
        ll pos=upper_bound(a,a+cnt,jb[i].d)-a;
        pos--;

        if(a[pos]  )
        {
            continue;
        }
        else
        {
            pos=figo(pos);
            ll kong=pre[pos]+1;
//cout<<"kong:"<<kong<<" pos:"<<pos<<endl;
//            pos=pre[pos];

            if(kong>=1) // ’“µ√µΩ
            {
//                cout<<kong<<" "<<jb[i].d<<" "<<jb[i].p<<endl;
                ans+=jb[i].p;
//                pre[pos]--;
//                figo(pos);
//                pre[pos]--;
            }
            else
            {

            }
        }
    }
    printf("%lld\n",ans);



#ifdef use_t
}
#endif // use_t
    return 0;
}

