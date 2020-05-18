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
string str;
ll l[300005];
ll r[300005];
ll used[300005];
ll ans=0;
void de(int x){
    if(x<0|| x>=n || used[x]==1){
        return ;
    }
  //  cout<<"de:"<<x<<endl;
    ll sl=l[x];

    if(sl>=0 && used[sl]==0){
        if(str[sl]==str[x]){
         //       cout<<"he le"<<x<<" "<<sl<<endl;
            used[x]=1;
            used[sl]=1;
            ans++;
            ll tr=r[x];
            ll tl=l[sl];
            if(tl >=0 && tr<n){
                l[tl]=tr;
                r[tr]=tl;
                de(tl);
                de(tr);
            }
            return ;
        }
    }
    ll sr=r[x];
    if(sr<n && used[sr]==0){
        if(str[sr]==str[x]){
              //  cout<<"he ri"<<x<<" "<<sr<<endl;
            used[x]=1;
            used[sr]=1;
            ans++;
            ll tr=r[sr];
            ll tl=l[x];
            if(tl>=0 && tr<n){
                r[tl]=tr;
                l[tr]=tl;
                de(tl);
                de(tr);
            }
        }
    }


}

int main ()
{
    memset(used,0,sizeof(used));
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

    cin>>str;
    n=str.size();
    for(int i=0;i<n;i++){
        r[i]=i+1;
        l[i]=i-1;
    }
    for(int i=0;i<n;i++){
        de(i);
    }
    if(ans*2==n)
        printf("0");
    else{
          //  cout<<"n:"<<n<<endl;
            for(int i=0;i<n;i++){
            if(used[i]==0){
                printf("%c",str[i]);
            }
        }
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}


