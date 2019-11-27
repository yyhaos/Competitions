#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll su[1000005];
//for(int i)
ll s[1000005];
int main ()
{
    memset(su,0,sizeof(su));
    int cnt=0;
    for(int i=2;i<=1000000;i++){
        if(su[i]==0)
        {
            s[cnt++]=i;
            for(int j=1;j*i<=1000000;j++){
                su[j*i]=1;
            }
        }
    }

    ll n;cin>>n;
    ll ans=n;
    ll pre=0;

    for(int i=0;s[i]<=n && i<cnt;i++){
        if(n%s[i]==0 && pre==0){
            while(n%s[i]==0)
            {
                ans=s[i];
                pre=s[i];
                n/=s[i];
            }
        }
        else if(n%s[i]==0)
        {
            ans=1;break;
        }
    }
    if(n>1 && pre!=0)
        ans=1;
    printf("%lld\n",ans);
    return 0;
}
