//Problem Web:https://vjudge.net/contest/288637#problem/I
//#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include<map>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
//#define mp make_pair
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
map <string , ll> mp;
string trans(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    for(int i=0;str[i];i++)
    {
        for(int j=0;str[j];j++)
        {
            if(str[i]>str[j])
                swap(str[i],str[j]);
        }
    }
    return str;
}
ll cnt=0;
string a[1000005];
string b[1000005];
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

    string tmp;
    ll cnt=0;
    while(cin>>tmp)
    {
        if(tmp=="#")
            break;

        string trtmp=trans(tmp);
          //  cout<<tmp<<" "<<trtmp<<endl;

        if(mp[trtmp]==0)
        {
            a[cnt++]=tmp;
        }
        mp[trtmp]++;
    }

    ll c2=0;
    for(int i=0;i<cnt;i++)
    {
        if(mp[trans(a[i])]==1)
        {
            b[c2++]=a[i];
        }
    }
    sort(b,b+c2);
    for(int i=0;i<c2;i++)
    {
        cout<<b[i]<<endl;
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}
