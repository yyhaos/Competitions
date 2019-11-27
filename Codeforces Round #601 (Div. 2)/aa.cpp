#include<bits/stdc++.h>
//#include<ext/rope>
//using namespace __gnu_cxx;
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define int long long
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define pb push_back
#define fi first
#define se second
//#define use_t 1
const double pi=acos(-1.0);
const double eps=1e-8;
const ll inf = 0x3f3f3f3f;
const ll maxn=1e5+7;
const ll mod=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)ans=ans*a%mod;
        a=a*a%mod;
        b/=2LL;
    }
    return ans;
}

int vis[maxn]={0};
int a[maxn][2]={0};

signed main ()
{

#ifdef yyhaos
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif



#ifdef use_t
ll t;
ll tt=1;
cin>>t;
for(tt=1;tt<=t;tt++)
{
#endif // use_t


int n;
scanf("%lld",&n);
for(int i=1;i<=n;++i){
	int k;
	scanf("%lld",&k);
	int tmp=0;
	if(k==1){
		scanf("%lld",&tmp);
	}
	if(k>1){
		for(int j=1;j<=k;++j){
			scanf("%lld",&tmp);
			a[tmp][0]=1;a[tmp][1]+=k;
		}
	}
}
int m;
scanf("%lld",&m);

vector<int> ans;
ans.clear();
for(int i=1;i<=m;++i){
	int b;
	scanf("%lld",&b);
	if(a[b][0]==0)ans.push_back(b);
}
int sz=ans.size();
for(int i=0;i<sz;++i){
	if(!vis[ans[i]])
    {
        if(i!=0)printf(" ");
        printf("%05lld",ans[i]);
    }
	vis[ans[i]]=1;
}


if(sz==0)printf("No one is handsome");
printf("\n");









#ifdef use_t
}
#endif // use_t
return 0;
}
