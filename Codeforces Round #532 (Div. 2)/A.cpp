//	yyhaos
//  Problem:

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define mem(a,b) memset(a, b, sizeof(a))
const ll q=1e9+7;
ll power(ll a,ll e){ll ans=1LL;while(e){if(e&1)ans=(ans*a)%q;a=a*a%q;e>>=1;}return ans%q;}
ll gcd(ll a,ll b){return b ? gcd(b, a%b) : a;}
const double eps=1e-8;
const ll maxn=1e6;

int main ()
{
    #ifdef yyhaos
        freopen("test.txt", "r", stdin);
    #endif
    int n;
    cin>>n;
    int k;
    cin>>k;
    int f[105];
    for(int i=1;i<=n;i++)
        cin>>f[i];
    int cnt1=0;
    int cnt0=0;
    for(int i=1;i<=n;i++)
    {
        if(f[i]==1)
            cnt1++;
        else
            cnt0++;
    }
    //cout<<cnt1<<" "<<cnt0<<endl;
    int ans=-1;
    for(int st=1;st<=k;st++)
    {
        int sub1=0,sub2=0;
        for(int j=0;st+k*j<=n;j++)
        {
            if(f[j*k+st]==1)
                sub1++;
            else
                sub2++;
        }
        //cout<<sub1<<" "<<sub2<<endl;
        ans=max(ans,cnt1-sub1-cnt0+sub2);
        ans=max(ans,-cnt1+sub1+cnt0-sub2);
    }
    cout<<ans;


    #ifdef yyhaos
        cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}
