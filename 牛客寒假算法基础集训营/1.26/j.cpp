//Problem Web:  https://ac.nowcoder.com/acm/contest/329/J
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q11q=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {

        b/=2LL;
    }
    return ans;
}

ll n,m;
const int mod=9983;
ll p,q,r,t;
ll mul[30];
ll in_dex[300];
void init()
{
    mul[0]=p;
    mul[1]=q;
    mul[2]=r;
    rep(i,0,25)
    {
        in_dex[i]=i*t+t;
    }
}
int get_hash(char *s)
{
    init();
    int ans=0,len=strlen(s+1);
    rep(i,1,len)
    {
        ans=(ans*mul[i%3]+in_dex[s[i]-'a'])%mod;
    }
    return ans;
}

char str1[100000];
char str2[100000];
ll aa[10000];
char ans[10000][30][6];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t

    cin>>p>>q>>r>>t;
    char tmp[6];
    rep(i,0,25)
    rep(j,0,25)
    rep(k,0,25)
    rep(l,0,25)
    {
        tmp[1]=i+'a';
        tmp[2]=j+'a';
        tmp[3]=k+'a';
        tmp[4]=l+'a';
        tmp[5]='\0';
        ll ha=get_hash(tmp);
        if(aa[ha]<30)
        {
            rep(pp,1,5)
            {
                ans[ha][aa[ha]][pp]=tmp[pp];
            }

            aa[get_hash(tmp)]++;
        }
    }
int ii=1;
ll tt;
cin>>tt;
for(ii=1;ii<=tt;ii++)
{
#endif // use_t
    scanf("%s",str1+1);
    ll ha=get_hash(str1);
   // cout<<ha<<endl;
    if(strcmp(str1+1,ans[ha][0]+1)==0)
    {
        cout<<ans[ha][1]+1<<endl;
    }
    else cout<<ans[ha][0]+1<<endl;
    //cout<<ans[ha][(1+ii+ii*3%20 +ii*487+str1[1]-'a'+123)%aa[ha]]+1<<endl;



#ifdef use_t
}
#endif // use_t
    return 0;
}
