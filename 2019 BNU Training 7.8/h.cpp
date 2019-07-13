#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    scanf("%I64d%I64d",&n,&k);
//    ll m=n/3;
//    ll t=m/k;
//    ll ans=t*15;
//    ll left=n-k*t*3;
//    if(left<=2*k&&left!=0)
//    {
//        ans+=10;
//    }
//    else if(left>2*k)
//    {
//        ans+=15;
//    }
//    printf("%I64d\n",ans);

    ll maxn=min(n,2*k);
    ll sum=n*2;
    //cout<<maxn<<" "<<sum<<endl;
    cout<<((sum+maxn-1)/maxn)*5;
    return 0;
}
