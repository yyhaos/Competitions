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
double ang[100000];
bool zh(double tar,double d)
{
    double t=tar/d;
    ll ta=tar/d;
    while( t-ta >=1)
        ta++;
    if(t-ta > eps)
        return false;
    return true;
}
int main ()
{
    #ifdef yyhaos
        freopen("test.txt", "r", stdin);
    #endif
    double danwei;
    double sum=0,maxn;
    int flag;
    int t;
    cin>>t;
   // cout<<t<<endl;
    double tar;
    while(t--)
    {
        cin>>tar;
        //cout<<tar<<endl;
        flag=0;
        for(double i=3;i<=380;i++)
        {
            sum=(i-2)*180;
            danwei = sum/i/(i-2);

            maxn = danwei*(i-2);
            //cout<<i<<" danwei:"<<danwei<<endl;
            if(maxn+eps>=tar && zh(tar,danwei))
            {
                printf("%.0f\n",i);
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("-1\n");
    }


    #ifdef yyhaos
        cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

