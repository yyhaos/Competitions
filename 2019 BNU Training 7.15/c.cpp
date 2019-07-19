
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2e7+12;
ll dp[maxn];

int main ()
{
    int n;
    cin>>n;
    memset(dp,0,sizeof(dp));

    ll pre=0,offset=1e7+2,tmp,ans=0;
    dp[0+offset]=1;
    while(n--)
    {
        scanf("%lld",&tmp);
        ans+=dp[tmp+pre+offset];
        ans%=999999LL;
        dp[tmp+pre+offset]++;
        pre+=tmp;
//        cout<<tmp<<" "<<pre<<" : "<<ans<<endl;
    }
    cout<<ans;
}
