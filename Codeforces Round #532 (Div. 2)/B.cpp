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
int s[100005];
int used[100005];
int main ()
{
    mem(s,0);
    mem(used,0);
    #ifdef yyhaos
        freopen("test.txt", "r", stdin);
    #endif
    int n,m,t;
    cin>>n>>m;
    int k=0;
    int low=1;
    while(m--)
    {
        scanf("%d",&t);
        s[t]++;
        if(s[t]==1)
        {
            k++;
            if(k==n)
            {
                printf("1");
                for(int i=1;i<=n;i++)
                {
                    if(s[i]==1)
                        k--;
                    s[i]--;
                }
                continue;
            }
        }
        printf("0");
    }


    #ifdef yyhaos
        cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

