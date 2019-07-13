//https://codeforces.com/gymRegistration/101653/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define used_t 1
const ll q=1e9+7;
const ll maxn= 100000;
const ll INF=1e16;
const double eps=1e-8;
const double PI=acos(-1);

ll ksm(ll a,ll b,ll qq=q)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%q;
        a=a*a%q;
        b/=2;
    }
    return ans;
}

ll n,m;
map < string , ll > sn;
map < ll,string > ns;
ll used[1000005];
string t1[1000005];
char tmp[10];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
#endif // yyhao


#ifdef used_t
ll t;
cin>>t;
for(ll ii=1;ii<=t;ii++)
{
#endif // used_t
    ll th=0;
    sn.clear();
    ns.clear();
    cin>>n;
    //getchar();
    for(int i=1;i<=n;i++)
    {
        scanf("%s",tmp);
        string tm=string(tmp);
       // cout<<tm<<" "<<th<<endl;
        t1[th]=tm;
        ns[th]=tm;
        sn[tm]=th;
        th++;
        //used[i]=1;
    }
    ll cnt=0;
    ll rong=0;
    ll be=0;
    int fi=1;
    //getchar();
    for(int i=1;i<=n;i++)
    {
        ll bef=sn[t1[i-1]];
        used[bef]++;

        if(used[bef]==1)
            cnt++;
        else
            cnt--;

        scanf("%s",tmp);
        string tm=string(tmp);
        ll now=sn[tm];

        //cout<<t1[i]<<"-"<<now<<" "<<tm<<"+"<<bef<<endl;

        used[now]--;
        if(used[now]==-1)
            cnt++;
        else cnt--;

        if(cnt==0)
        {
            if(fi)
            printf("%lld",i-be);
            else
                printf(" %lld",i-be);
            fi=0;
            be=i;
        }

        //used[i]=1;
    }
    printf("\n");




#ifdef used_t
}
#endif // used_t
}

