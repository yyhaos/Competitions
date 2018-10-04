#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p[180];
int main ()
{
    p[1]=10;
    for(int i=2;i<=18;i++)
    {
        p[i]=10*p[i-1];
    }
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,x;
        scanf("%lld%lld",&n,&x);
        ll th=log(x)/log(10);
        ll ans=0;
        th++;
        while(1)
        {
            ll ned=th*(p[th]-x);
          //  cout<<n<<" "<<x<<" "<<ned<<endl;

            if(ned<=n)
            {
                n-=ned;
                ans+=p[th]-x;
                x=p[th];
                th++;
            }
            else
            {
                if(n%th==0)
                {
                    ans+=n/th;
                    break;
                }
                else
                {
                    ans=-1;
                    break;
                }
            }
        }
       // printf("%lld %lld\n",n,x);
        printf("%lld\n",ans);
    }
    return 0;
}
