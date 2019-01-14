#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll q=1e9+7;

ll ksm(ll a,ll k)
{
    if(a==0)
        return 0;
    ll ans=1;
    while(k>0)
    {
        if(k%2==1)
        {
            ans=ans*a%q;
        }
        a=a*a%q;
        k/=2;
    }
    return ans;
}
char str[100005];
int cnt[100005];
int main ()
{
    memset(cnt,0,sizeof(cnt));
    ll n;
    scanf("%lld",&n);
    scanf("%s",str);
    int lian=0;
    int th=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='S')
        {
            cnt[th++]=i;
        }
    }
    if(th==0)
    {
        printf("%lld",n);
        return 0;
    }
    if(th==n)
    {
        printf("%lld",0LL);
        return 0;
    }
    if(th==n-1)
    {
        printf("%lld",1LL);
        return 0;
    }
    if(th==1)
    {
        printf("%lld",n-1);
        return 0;
    }
    ll ans=0;
    ll pre=-1;
    for(int i=1;i<th;i++)
    {
        //cout<<i<<endl;
        ans=max(ans,cnt[i]-pre-1);
        pre=cnt[i-1];
    }
    if(ans>n-th)
        ans=n-th;
    cout<<ans;
    return 0;
}
