#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q=1e9+7;
ll ksm(ll a,ll b)
{
    if(a==0)
        return 0LL;
    if(a==1LL)
        return 1LL;
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL==1)
        {
            ans=ans*a%q;
        }
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}
ll gcd(ll a,ll b)
{
    if(a<b)
        return gcd(b,a);
    if(b==0LL)
        return a;
    if(a%b==0)
        return b;
    return gcd(a,a%b);
}
//Å·À­º¯Êý
ll phi(ll x){
    ll ans = x;
    for(ll i = 2LL; i*i <= x; i++){
        if(x % i == 0){
            ans = ans / i * (i-1LL);
            while(x % i == 0LL) x /= i;
        }
    }
    if(x > 1LL) ans = ans / x * (x-1LL);
    return ans;
}

int main ()
{
    ll ans=0;
    //cout<<gcd(81,72);
    //cout<<ksm(2,3);
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    //cout<<phi(n)<<endl;
    cout<<(a+b)%q*ksm(k,(phi(n)/2LL)*n%q)%q;
    return 0;
}
