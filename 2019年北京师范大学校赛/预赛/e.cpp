//Problem Web:http://39.97.97.11/problem.php?cid=1003&pid=4
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
int ty(char a)
{
    if(a>='a' && a<='z')
        return 1;
    if(a>='A' && a<='Z')
        return 2;
    return 0;
}
ll t,n,m;
string str;
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

    cin>>str;
    int len=str.length();
    int flag=1;
    int cnt=0;
    if(len<=3)
        flag=0;
    else
    if(ty(str[1])!=1)
        flag=0;
    else
    for(int i=2;i<len-1;i++)
    {
        if(ty(str[i])==2)
        {
            cnt=1;
            if(ty(str[i+1]) ==2)
            {
                flag=0;
                break;
            }
        }
    }
    if(ty(str[len-1])!=1 || cnt==0)
        flag=0;
    if(flag==0)
    {
        cout<<str<<endl;
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            if(ty(str[i])!=1 && i!=0)
            {
                cout<<"_"<<char(str[i]-'A'+'a');
            }
            else if(ty(str[i])!=1)
            {
                cout<<char(str[i]-'A'+'a');
            }
            else
                cout<<str[i];
        }
        cout<<endl;
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}

