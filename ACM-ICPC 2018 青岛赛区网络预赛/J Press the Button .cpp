
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

int main ()
{
    int tt;
    //freopen("test.txt","r",stdin);
    scanf("%d",&tt);
    while(tt--)
    {
        ll a,as,b,bs,v,t;
        scanf("%lld%lld%lld%lld%lld%lld",&a,&as,&b,&bs,&v,&t);
        ll lcm=b*a/gcd(a,b);
        ll ta=lcm/a;
        ll tb=lcm/b;
        ll tha=0;
        ll thb=0;
        ll cnta1=0;
        ll cntb1=0;
        ll cnta2=0;
        ll cntb2=0;
        //printf("%lld %lld %lld %lld %lld %lld\n",a,as,b,bs,v,t);
        if(v>=a || v>=b )
        {
            ll ans=0;
            ans=(t/a+1)* as+(t/b+1)*bs-1;
            printf("%lld\n",ans);
            continue;
        }

        ll ans=0;
        if(t/lcm>0)
        {
            for(tha=0;tha<ta;tha++)
            {
                while(tha*a >thb*b+v && thb<tb)
                    thb++;
                if(tha*a >= thb*b && tha*a<= thb*b+v)
                {
                    cnta1++;
                }
                else
                    cnta2++;
            }
            tha=0;
            for(thb=0;thb<tb;thb++)
            {
                while(thb*b >tha*a+v && tha<ta)
                    tha++;
                if(thb*b >= tha*a && thb*b<= tha*a+v)
                {
                    cntb1++;
                }
                else
                    cntb2++;
            }

            ans +=cnta1*as;
            ans +=cntb1*bs;
            ans +=cnta2*(as-1);
            ans +=cntb2*(bs-1);
            ans*= t/lcm;
            ans-=t/lcm;
        }
        ll cta1=0;
        ll cta2=0;
        ll ctb1=0;
        ll ctb2=0;
        for(thb=t/lcm*tb,tha=t/lcm*ta ; thb*b<=t;thb++)
        {
            while(thb*b >tha*a+v && tha*a<t)
                tha++;
            if(thb*b >= tha*a && thb*b<= tha*a+v)
                ctb1++;
            else
                ctb2++;
        }
        for(thb=t/lcm*tb,tha=t/lcm*ta ; tha*a<=t;tha++)
        {
            while(tha*a >thb*b+v && thb*b<t)
                thb++;
            if(tha*a >= thb*b && tha*a<= thb*b+v)
                cta1++;
            else
                cta2++;
        }
        ans +=cta1*as;
        ans +=ctb1*bs;
        ans--;
        ans +=cta2*(as-1);
        ans +=ctb2*(bs-1);
        printf("%lld\n",ans);
    }
    return 0;
}
