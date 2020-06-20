
//Problem Web:https://ac.nowcoder.com/acm/contest/6013
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
ll k;
char str[1000005];
ll cnt[1000005][30];
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
    mem(cnt,0);
    cin>>n>>k;
    getchar();
    scanf("%s",str);

    for(int i=0;i<n;i+=k){
        for(int j=0;j<k;j++){
            cnt[j][ str[i+j]-'a' ]++;
        }
    }
    ll ans=n;
    for(int i=0;i<k;i++){
        ll tmp=0;
        for(int j=0;j<26;j++){
            tmp=max(tmp,cnt[i][j]);
        }
        ans-=tmp;
    }
    cout<<ans<<endl;

#ifdef use_t
}
#endif // use_t
    return 0;
}


