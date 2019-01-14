
#include<bits/stdc++.h>
#define ll long long
ll no(ll fi,ll n,ll m,ll &white,ll &black)//1 hei 0 bai
{
    ll k=n*m/2;
    if(n%2==1 && m%2==1)
    {
        if(fi==1)
        {
            black=k+1;
            white=k;
        }
        else
        {
            black=k;
            white=k+1;
        }
    }
    else
        black=white=k;
}
ll no2(ll a1,ll a2,ll b1,ll b2,ll &white,ll &black)
{
    ll nn=b1-a1+1;
    ll mm=b2-a2+1;
    ll start=(a1+a2)%2;
    return no(start,nn,mm,white,black);
}
ll x[4],y[4];
using namespace std;
int main ()
{
    ll t;
    ll n,m;
    cin>>t;
    ll change,tmp;
    for(ll i=1;i<=t;i++)
    {
        scanf("%lld%lld",&n,&m);//y x
        scanf("%lld%lld%lld%lld",&x[0],&y[0],&x[1],&y[1]);//b1 x b2 y
        scanf("%lld%lld%lld%lld",&x[2],&y[2],&x[3],&y[3]);
        ll b=0,w=0;
        no2(1,1,m,n,w,b);
        //cout<<w<<" "<<b<<endl;

        no2(x[0],y[0],x[1],y[1],tmp,change);
        w+=change;
        b-=change;
      //  printf("-%lld %lld\n",w,b);
        no2(x[2],y[2],x[3],y[3],change,tmp);
        w-=change;
        b+=change;
       // printf("-%lld %lld\n",w,b);
        if (max(x[0],x[1])<min(x[2],x[3]) || min(x[0],x[1])>max(x[2],x[3]) || max(y[0],y[1])<min(y[2],y[3]) || min(y[0],y[1])>max(y[2],y[3]))
            tmp=tmp;
        else
        {
            sort(x,x+4); sort(y,y+4);
     //   cout<<"+"<<x[0]<<x[1]<<x[2]<<x[3]<<endl;

            no2(x[1],y[1],x[2],y[2],tmp,change);
            w-=change;
            b+=change;
        }

        printf("%lld %lld\n",w,b);
    }
    return 0;
}
