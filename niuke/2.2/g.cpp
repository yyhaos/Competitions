
#include<bits/stdc++.h>
using namespace std ;
#define ll long long
ll a,b;
ll aa[101];
ll bb[101];
void tr(ll xx[101],const ll &x)
{

    ll tx=x;
    //xx[100]=0;
    ll cnt=0;
    while(tx>0)
    {
        if(tx%2LL==1LL)
        {
            xx[cnt]=1LL;
        }
        else xx[cnt]=0;
        cnt++;
        tx/=2LL;
    }
    xx[100]=cnt;
    return ;
}
void show(ll xa[101])
{
    for(int i=0;i<xa[100];i++)
    {
        cout<<xa[i];
    }
    cout<<endl;
}
int main ()
{

    a=1;
   // for(b=100;b<=100;b++)
    while(~scanf("%lld%lld",&a , &b))
    {
       // cout<<a<<" "<<b<<endl;
       //tr(aa,a);
        //tr(bb,b);
       // show(aa);
       // show(bb);
        ll ans=b|a;
        //ll ta=a;
        tr(bb,ans);
        int k;
            for(k=0;k<bb[100];k++)
            {
                if(bb[k]==0)
                {
                    if((a|(1LL<<k))<=b)
                    {
                        ans=(ans|(1LL<<k));
                    }
                }
            }
       // cout<<"ans:"<<endl;
        cout<<ans<<endl;
      //  tr(aa,ans);
      //  show(aa);
//        ans=0;
//        for(ll i=a;i<=b;i++)
//        {
//            ans=ans|i;
//        }
//        cout<<ans<<endl;
    }
    return 0;
}
