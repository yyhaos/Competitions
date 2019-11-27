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
int a[5][200005];
int main ()
{
    int k[5];
    for(int i=1;i<=3;i++)scanf("%d",i+k);
    for(int i=1;i<=3;i++){
        for(int j=1;j<=k[i];j++){
            scanf("%d",&a[i][j]);
        }
    }

    return 0;
}



