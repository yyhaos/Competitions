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
const int inf=0x3f3f3f3f;
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

int mm[1000][1000];

void floyd()
{
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                mm[i][j]=min(mm[i][k]+mm[k][j],mm[i][j]);
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


while(cin>>n && n){
mem(mm,inf);
for(int i=1;i<=n;++i){
    mm[i][i]=0;
}

for(int i=1;i<=n;++i){
    cin>>m;
    for(int j=1;j<=m;++j){
        int a,b;
        cin>>a>>b;
        mm[i][a]=b;
    }
}


floyd();

int ans=inf;
int pos=-1;
for(int i=1;i<=n;++i){
    int ans1=0;
    for(int j=1;j<=n;++j){
        ans1=max(ans1,mm[i][j]);

    }
    if(ans1<ans){
            ans=ans1;
        pos=i;

    }

}

if(ans<inf){
    cout<<pos<<' '<<ans<<endl;
}
else cout<<"disjoint"<<endl;



}







#ifdef use_t
}
#endif // use_t
    return 0;
}

