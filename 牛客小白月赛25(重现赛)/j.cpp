//Problem Web:https://ac.nowcoder.com/acm/contest/5808/J
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

#define ull long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ull i=x;i<=y;i++)
#define crep(i,x,y) for(ull i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ull INF = 100000000;
const ull maxn=1000;
const ull q=1e9+7;
ull ksm(ull a,ull b)
{
    ull ans=1ll;
    while(b>0)
    {
        if(b&1ll)
            ans=ans*a%q;
        a=a*a%q;
        b/=2ll;
    }
    return ans;
}

ull t,n,m;
ull a[200005];
ull cnt[256];
int main ()
{
    memset(cnt,0,sizeof(cnt));
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ull ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

//    cout<<(3^4^5^6)<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%lld",a+i);
    }
    for(int i=0;i<n;i++){
        ull tm=a[i];
        ull th=0;
        while(tm){
            cnt[th]+=tm%2;
            tm/=2;
            th++;
        }
    }

//    for(int i=0;i<64;i++){
//        if(cnt[i]){
//            cout<<"cnt:"<<i<<" = "<<cnt[i]<<endl;
//        }
//    }
    ull ans=0;
    for(int i=0;i<66;i++){
        ull tmp=0;
        if(cnt[i]>=1){
            ull yu=n-cnt[i];
            if(yu>1)
                tmp+=cnt[i]*yu%q*(yu-1)%q*ksm(2,q-2)%q;
        }
        if(cnt[i]>=3){
            tmp+=cnt[i]*(cnt[i]-1)%q*(cnt[i]-2)%q*ksm(6,q-2)%q;
        }
//        if(tmp!=0)
//        cout<<tmp<<" "<<(1LL<<i)%q<<endl;
        ans+=tmp*((1LL<<i)%q)%q;
        ans%=q;
    }
    cout<<ans;
    ans%=q;




#ifdef use_t
}
#endif // use_t
    return 0;
}




