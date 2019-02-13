#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20];
ll k[20];
ll f(ll pos,bool limit)
{
    if(pos==-1LL )
        return 1LL;
    if( !limit && dp[pos]!=-1LL)
        return dp[pos];
    ll ans=0LL;
    ll last=limit?k[pos]:9LL;
    for(ll i=0LL;i<=last;++i)
    {
        if(i==6LL)continue;
        ans+=f(pos-1LL,limit && i==last);
    }
  //6 6
   // cout<<"pos:"<<pos<<" ans:"<<ans<<endl;
    if(!limit)
        dp[pos]=ans;
    return ans;
}
ll fi(ll a)
{
    ll aa=a;
   // cout<<"a:"<<a<<endl;
    if(a<=5LL)
        return 0LL;
    if(a<=10)
        return 1LL;
    for(int i=0;i<20;i++)
        dp[i]=-1LL;
    ll  cnt=0LL;
    memset(k,0LL,sizeof(k));
    while(a>0LL)
    {
        k[cnt++]=a%10LL;
        a/=10LL;
    }
    return 1LL+aa-f(cnt-1LL,true);
}
int  main ()
{
    ll a,b;
    cin>>a>>b;
    if(a==0LL)
    {
        a=1LL;
    }
    if(b==0LL)
    {
        b=1LL;
    }
    //cout<<":::"<<fi(b)<<" "<<fi(a-1)<<endl;
    cout<<fi(b)-(fi(a-1LL));
    return 0;
}
