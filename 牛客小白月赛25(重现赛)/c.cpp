//Problem Web:https://ac.nowcoder.com/acm/contest/5808/C
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
string str;
vector<int> M[110005];
int f[110005];
int si[110005];

int fi(int x){
    if(f[x]==x)return x;
    return f[x]=fi(f[x]);
}
void un(int a,int b){
    f[fi(a)]=b;
    fi(a);
    fi(b);
}

int main ()
{
    memset(si,0,sizeof(si));
    for(int i=0;i<=100004;i++){
        f[i]=i;
    }
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

    cin>>n;
    cin>>str;
    int a,b;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b );
        a--;b--;
        if(str[a]==str[b] && str[a]=='W')
        {
            un(a,b);
        }
        M[a].push_back(b);
        M[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        fi(i);
    }
    for(int i=0;i<n;i++){
        if(str[i]=='W')
            si[fi(i)]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int tsi=M[i].size();
        if(str[i]=='W')
            ans=max(ans,si[fi(i)]);
        else
        {
            int tmp=0;
            for(int j=0;j<tsi;j++){
                int nxt=M[i][j];
                tmp+=si[fi(nxt)];
            }
            tmp++;
            ans=max(ans,tmp);
        }

    }
    cout<<ans;






#ifdef use_t
}
#endif // use_t
    return 0;
}


