#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fi(ll m)
{
    for(ll i=2;i<=m;i++)
    {
        if(m%i!=0)
            continue;
        int flag=0;
        for(ll k=2;k<=sqrt(i);k++)
        {
            if(i%k==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            continue;
        return i;
    }
}
ll fi2(ll m)
{
    //cout<<m<<endl;
    if(m==2)
        return 2;
    if(m==0)
        return 0;
    if(m%2==0)
        return 2LL;
    for(ll k=3LL;k<=sqrt(m);k+=2LL)
    {
        if(m%k==0)
            return k;
    }
    return m;
}
int main ()
{
//    for(ll i=2;i<=10000;i++)
//    {
//        ll cnt=0;
//        ll tmp=i;
//        while(tmp!=0)
//        {
//            ll cha=fi(tmp);
//            tmp-=cha;
//            cnt++;
//        }
//
//        ll cnt2=0;
//        ll tmp2=i;
//        while(tmp2!=0)
//        {
//            ll cha2=fi2(tmp2);
//            tmp2-=cha2;
//            cnt2++;
//        }
//        printf("%lld %lld %lld\n",i,cnt,cnt2);
//    }
    ll n;
    cin>>n;

        ll cnt=0;
        ll tmp=n;
        while(tmp!=0)
        {
            if(tmp%2==0)
            {
                cnt+=tmp/2;
                break;
            }
            ll cha=fi2(tmp);
            tmp-=cha;
            cnt++;
        }
        printf("%lld",cnt);

    return 0;
}
