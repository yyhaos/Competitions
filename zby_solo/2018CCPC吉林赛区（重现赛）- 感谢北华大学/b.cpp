//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=867
#include<bits/stdc++.h>
#include<ext/rope>
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
#define use_t 1
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
map<string,ll> sq;
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
sq["London"]=0;
sq["Beijing"]=8;
sq["Washington"]=-5;
sq["Moscow"]=3;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    char mm[5];
    ll h;
    scanf("%lld:%lld %s",&h,&m, mm);
//    cout<<mm<<endl;
    h%=12;
    if(mm[0]=='P')
    {
        h+=12;
    }
    cout<<"Case "<<ii<<": ";
    string a,b;
    cin>>a>>b;
    ll cha=sq[a]-sq[b];
//    cout<<cha<<endl;
    ll hn=h-cha;
//    cout<<hn<<endl;

    if(hn >=24 )
    {
        hn-=24;
        cout<<"Tomorrow ";
    }
    else if(hn<0)
    {
        hn+=24;
        cout<<"Yesterday ";
    }
    else
    {
        cout<<"Today ";
    }


    ll hh=hn%12;
    if(hh==0)
        hh=12;
    printf("%lld:%02lld ",hh,m);
    if(hn>=12)
    {
        //hn-=12;
        cout<<"PM\n";
    }
    else
        cout<<"AM\n";
  //  cout<<a<<" "<<b<<endl;



#ifdef use_t
}
#endif // use_t
    return 0;
}
