//Problem Web:https://ac.nowcoder.com/acm/contest/888/A
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
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
char a[3005][3005];
ll ans=0;
ll houzhui[3005][3005];
ll l[3005],s[3005];
ll used[3005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a[i]+1);
//        cout<<a[i+1]<<endl;
    }

    mem(houzhui,0);
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=1;j--)
        {
//            cout<<a[i][j]<<endl;
            if(a[j][i]=='1')
                houzhui[j][i]=houzhui[j+1][i]+1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<houzhui[i][j];
        }
        cout<<endl;
    }
ll top=0;
    for(ll i=1;i<=n;i++)
    {
        houzhui[i][n+1]=-1;
//        ans+=top;
        top=0;
        for(ll j=1;j<=m+1;j++)
        {

            l[j]=j;
            while(top>0 && houzhui[i][s[top]]>houzhui[i][j])
            {
                ans--;
                l[j]=l[s[top]];
                top--;
            }
            if(top>0 && houzhui[i][s[top]] == houzhui[i][j])
            {
//                ans--;
                l[j]=l[s[top]];
            }
            s[++top]=j;

                ans++;
        }
    }
    cout<<ans;
//ll ans=0;





#ifdef use_t
}
#endif // use_t
    return 0;
}


