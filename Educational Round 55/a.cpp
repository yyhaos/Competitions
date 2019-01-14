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
int main ()
{
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        ll n,x,y,d,ans=9999999999999LL;
        scanf("%lld%lld%lld%lld",&n,&x,&y,&d);
        if(x==y)
        {
            ans=0;
        }
        else
        {
            if(abs(y-x)%d==0)
            {
                ans=(abs(y-x)/d);
            }
            else
            {
                ll a1=0,a2=0;
                a1+=(x+d-1)/d;
                a2+=(n-x+d-1)/d;
                if(abs(1-y)%d==0)
                {
                    a1+=abs(1-y)/d;
                }
                else
                    a1=9999999999999LL;
                if(abs(n-y)%d==0)
                {
                    a2+=abs(n-y)/d;
                }
                else
                    a2=9999999999999LL;
                ans=min(ans,min(a1,a2));
            }
        }
        if(ans<9999999999999LL)
            printf("%lld\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
