//Problem Web:  http://codeforces.com/contest/1131/problem/E
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}

ll t,n,m;
    ll ans=1;
string str[100005];
void dfs(ll th,ll be,ll fr, char fro,char beh)
{

    ll len1=str[th].size();
    char tfro = str[th][0];
    char tbeh = str[th][len1-1];
    rep(i,0,len1-1)
    {
        if(str[0][i]==fro)
            fr++;
        else
            break;
    }

    crep(i,len1-1,0)
    {
        if(str[0][i]==beh)
            be++;
        else
            break;
    }
    if()
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n;

    rep(i,1,n)
    {
        cin>>str[i];
    }

    rep(i,1,n)
    {
        ll len=str[i].size();
        ll tmp=1;
        char tar=str[i][0];
        rep(j,1,len-1)
        {
            if(str[i][j]==tar)
            {
                tmp++;
            }
            else
            {
                ans=max(ans,tmp);
                tar=str[i][j];
                tmp=1;
            }
        }
        ans=max(ans,tmp);
    }
    ll len1=str[0].size();
    fro = str[0][0];
    beh = str[0][len1-1];
    dfs(0,0,0,fro,beh);



#ifdef use_t
}
#endif // use_t
    return 0;
}
