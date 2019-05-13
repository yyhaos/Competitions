//Problem Web:https://vjudge.net/contest/301379#problem
//#include<bits/stdc++.h>
//#include<ext/rope>
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
ll s[800005];
void push_up(ll k)
{
    if(k==1)
        return ;
    if(s[k/2]<s[k])
        s[k/2]=s[k];
   // push_up(k/2);
}
void up(ll k)
{
    if(k==1)
        return ;
    ll a=k/2;
    s[a]=max(s[a*2],s[a*2+1]);
    up(a);
}
ll qu(ll l ,ll r)
{
   // cout<<l<<" "<<r<<endl;
    if(l==r)
        return s[l];
    if(l>r)
        return -1000000;
    ll ml=l/2;
    ll mr=r/2;
    ll ans=-100000000LL;
    if(l == ml*2)
    {
        l=ml;
    }
    else{
        ans=max(ans,s[l]);
        l=ml+1;
    }
    if(r == mr*2+1)
    {
        r=mr;
    }
    else{
        ans=max(ans,s[r]);
        r=mr-1;
    }
    ans=max(ans,qu(l,r));
    return ans;

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
    while(cin>>n>>m)
    {
        for(int i=0;i<=n*3;i++)
            s[i]=-1000000;
        rep(i,n+1,2*n)
            scanf("%lld",s+i);
        crep(i,2*n,1)
            push_up(i);

        char t;
        ll l,r;
        while(m--)
        { getchar();
            scanf("%c %lld%lld",&t,&l,&r);
          //  cout<<t<<l<<r<<"   123"<<endl;
            if(t=='Q')
            {
                printf("%lld\n",qu(l+n,r+n));
            }
            else
            {
                s[l+n]=r;
                up(l+n);
            }
        }
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}
