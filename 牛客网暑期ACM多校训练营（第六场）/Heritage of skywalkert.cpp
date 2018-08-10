#include <bits/stdc++.h>
using namespace std;

typedef unsigned ll;
typedef unsigned long long ull;
ll x,y,z;
const int maxn=16;
ll a[10000006];
ll m[maxn];
ll tang(){
    ll t;
    x ^= x<<16;
    x ^= x>>5;
    x ^= x<<1;
    t = x;
    x = y;
    y = z;
    z = t^x^y;
    return z;
}

unsigned long long gcd(unsigned long long a,unsigned long long b){
    return b==0? a:gcd(b,a%b);
}
unsigned long long lcm(unsigned long long a,unsigned long long b){
    if(gcd(a,b)==0)
        return 0;
    return a/gcd(a,b)*b;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--){
        int n;
        memset(m,0,sizeof(m));
        cin>>n>>x>>y>>z;
        ull m1=0,m2=0;
         ull ans=0;
        //int a1=0,a2=0;
        for (int i=0;i<n;i++){
            a[i] = tang();
            //printf("%d\n",a[i]);
            for(int j=0;j<maxn&&j<n;j++)
            {
                if(m[j]<a[i])
                {
                    for(int k=min(maxn-1,n-1);k>=j+1;k--)
                    {
                        m[k]=m[k-1];
                    }
                    m[j]=a[i];
                    break;
                }
            }
        }
        for(int i=0;i<maxn && i<n ;i++)
        {
            //cout<<" "<<m[i];
            for(int j=i+1;j<maxn && j<n;j++)
            {
                ans=max(ans,lcm((ull)m[i],(ull)m[j]));
            }
        }
        //printf("Case #%d: %lld\n",++cas,lcm(m1,m2));
        cout<<"Case #"<<++cas<<": "<<ans;
/*
        ans=0;
        ull a1,a2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans<lcm((ull)a[i],(ull)a[j]))
                {
                    ans=max(ans,lcm((ull)a[i],(ull)a[j]));
                    a1=(ull)a[i];
                    a2=(ull)a[j];
                }
            }
        }
        cout<<"  ans = "<<ans;//<<" "<<(ans>lcm(m1,m2))<<" "<<a1<<" "<<a2<<" "<<gcd(a1,a2)<<" "<<m1<<" "<<m2;
*/
        printf("\n");
    }

    return 0;
}
