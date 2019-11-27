//Problem Web:
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
ll a[100005];
ll len1[100005];
ll len2[100005];

ll ans[100005];
ll bad[100005];

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
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
    }
    for(int i=n;i>=1;i--)
    {
        if(i==n)
        {
            len1[i]=len2[i]=1;
        }
        else
        {
            if(a[i]<=a[i+1])
            {
                len2[i]=1;
                len1[i]=1+len1[i+1];
            }
            else
            {
                len2[i]=1+len2[i+1];
                len1[i]=1;
            }
        }
    }
//    for(int i=1;i<=n;i++){
//
//        cout<<len1[i]<<' ';
//    }
//    cout<<endl;
//    for(int i=1;i<=n;i++){
//        cout<<len2[i]<<' ';
//    }
//    cout<<endl;
ll tq;
    cin>>tq;

    for(int len=2;len<=n;len++)
    {
        //ll sta=1;
        ll ta=0;
        ll tb=0;

        ll th=1;
        while(th<=n)
        {
//            cout<<len<<" :"<<th<<" "<<ta<<" "<<tb<<" "<<sta<<endl;
            ta++;
            ll nxt;//=th+
            if(len1[th] >= len2[th])
            {
                if(len1[th] <=len)
                {

                    tb+=len-len1[th];
//                    cout<<"tb:"<<tb<<" "<<endl;
                    th+=len;
                    if(th>n)
                        tb-=th-n-1;
                }
                else
                {
                    th+=len1[th];
                }
            }
            else
            {
                if(len2[th] <=len)
                {

                    tb+=len-len2[th];
                    th+=len;
                    if(th>n)
                        tb-=th-n-1;
                }
                else
                {
                    th+=len2[th];
                }
            }
            //sta=1-sta;
        }

        ans[len]=ta;bad[len]=tb;
    }

    ll tmp;
    for(int i=1;i<=tq;i++)
    {
        scanf("%lld",&tmp);
        printf("%lld %lld\n",ans[tmp],bad[tmp]);
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}

