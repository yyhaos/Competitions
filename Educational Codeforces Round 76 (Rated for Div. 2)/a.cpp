//https://codeforces.com/contests/1257
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll q=1e9+7;
ll ksm(ll a, ll b){
    ll ans=1;while(b){
        if(b&1){
            ans=ans*a%q;
        }a=a*a%q;b/=2;
    }return ans;
}

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,a,b;
        scanf("%d%d%d%d",&n,&x,&a,&b);
        if(a>b)swap(a,b);
        ll ans=abs(a-b);

    }
    return 0;
}
