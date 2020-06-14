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

    string str1;
    cin>>str1;
    int s1=str1.length();
    string str2;
    cin>>str2;
    int s2=str2.length();
    if(s1>s2){
            printf(">");return 0;

    }
    else if(s1<s2){
        printf("<");return 0;
    }

    int  deng=0;
    for(int i=0;str1[i];i++){
        if(str1[i]>str2[i]){
            printf(">");
            return 0;
        }
        else if(str1[i]<str2[i]){
            printf("<");
            return 0;
        }
    }
    printf("=");
    return 0;




#ifdef use_t
}
#endif // use_t
    return 0;
}



