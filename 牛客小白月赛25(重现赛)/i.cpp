//Problem Web:https://ac.nowcoder.com/acm/contest/5808/I
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
vector< int>a[1000005];
ll cl[1000005];
ll cr[1000005];
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

    cin>>n>>m;
int tmp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            scanf("%d",&tmp);
            a[i].push_back(tmp);
        }
    }

    for(int i=0;i<n;i++){
        ll tmp=0;
        for(int j=0;j<m;j++){
            tmp+=a[i][j];
        }
        cr[i]=tmp;
    }

        for(int j=0;j<m;j++){ ll tmp=0;
for(int i=0;i<n;i++){
            tmp+=a[i][j];
        }
        cl[j]=tmp;
    }

//    for(int i=0;i<n;i++){
//
//        cout<<cr[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0;i<m;i++){
//        cout<<cl[i]<<" ";
//    }
//    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j!=0)printf(" ");
            printf("%lld",cl[j]-a[i][j]+cr[i]);

        }
        printf("\n");
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}



