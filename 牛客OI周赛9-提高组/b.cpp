//Problem Web:https://ac.nowcoder.com/acm/contest/697/B
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
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

ll t,n,m;ll b;

char str[2000005];
ll bei[20000005];
ll tb[20000005];
ll tbni[20000005];
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

    cin>>n>>m>>b;
//cout<<n<<endl;
    ll bb=1;
    scanf("%s",str);
    ll ty;
    for(int i=0;i<n;i++){
        tb[i]=bb;
        tbni[i]=ksm(bb,q-2);
        bei[i]=tb[i]*(str[i]-'a')%q;
        bb=bb*b%q;
        //cout<<tb[i]<<" "<<tbni[i]<<endl;
    }
    while(m--){

            ll l,r;
            ll pos;
            char tmp;
        scanf("%lld",&ty);
        if(ty==0){
            scanf("%lld%lld",&l,&r);
            l--,r--;
            ll sum=0;
            for(int i=l;i<=r;i++){
                sum+=bei[i];
            }
            sum=sum*tbni[l];
            cout<<sum<<endl;
        }
        else{
            scanf("%lld %c",&pos,&tmp);
            //cout<<tmp<<endl;

        }
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}
