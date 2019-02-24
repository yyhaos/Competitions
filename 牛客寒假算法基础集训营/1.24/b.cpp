//Problem Web:  https://ac.nowcoder.com/acm/contest/327/B
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
ll zong[100005];

ll t,n,m;
map<string,ll> mp;
ll fenn[100005];
ll fen[10005][10];
ll kou[10005][10];
ll getf[10005][10];
const ll tf[10]={0,500,1000,1500,2000,2500};
ll you[10005];

string tmp;
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
    cin>>n>>m;
    rep(i,1,n)
    {
        cin>>tmp;
        //cout<<tmp<<endl;
        mp[tmp]=i;
        rep(j,1,5)
        {
            getf[i][j]=tf[j];
        }
    }
    ll time,th;
    char pr;
    char ve[20];
    char name[25];
    mem(fen,0);
    mem(you,0);
    mem(kou,0);
    rep(i,1,m)
    {
        scanf("%lld %s %c%s",&time,name,&pr,ve);
        string na=name;
        th=mp[na];
        ll pth=pr+1-'A';
        if(ve[0]=='A')
        {
            you[th]=1;
            fen[th][pth]=max(3*tf[pth]/10,tf[pth]-time*tf[pth]/250-50*kou[th][pth]);
            kou[th][pth]++;
        }
        else if(ve[0]=='C')
    {
        you[th]=1;
        fen[th][pth]=0;
    }
        else
        {
            you[th]=1;
            //getf[th][pth]-=50;
            kou[th][pth]++;
            fen[th][pth]=0;
        }
       // cout<<time<<" "<<name<<" "<<th<<" "<<pr<<" "<<ve<<endl;

    }

    rep(i,1,n)
    {
        fenn[i]=0;
        rep(j,1,5)
        {
            fenn[i]+=fen[i][j];
        }
    }
    if(you[mp["cnz"]]==0)
    {
        cout<<"-1";
    }
    else
    {
        ll sum=0,ans=0;
        cout<<fenn[mp["cnz"]]<<endl;
        rep(i,1,n)
        {
            if(you[i])
            {
                if(fenn[mp["cnz"]]<fenn[i])
                {
                    ans++;
                }
                sum++;
            }
        }
    cout<<ans+1;
        cout<<"/"<<sum;
//        rep(i,0,sum-1)
//        {
//            cout<<endl<<zong[i];
//        }
    }

#ifdef use_t
}
#endif // use_t
    return 0;
}
