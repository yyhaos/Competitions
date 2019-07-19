
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
map<string , ll> sn;
struct pa
{
    int x,y,z;
    string name;
    pa(int _x=0,int _y=0,int _z=0,string _name="")
    {
        x=_x;
        y=_y;
        z=_z;
        name=_name;
    }
    double fa(double x)
    {
        return x*x;
    }
    double di(pa b)
    {
        return sqrt(fa(x-b.x)+fa(y-b.y)+fa(z-b.z));
    }
}P[100];
double dis[100][100];
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

    cin>>n;
    sn.clear();
    int x,y,z;
    string tmp;
    for(int i=0;i<n;i++)
    {
        cin>>tmp>>x>>y>>z;
        sn[tmp]=i;
        P[i]=pa(x,y,z,tmp);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
                dis[i][j]=0;
            dis[i][j]=dis[j][i]=P[i].di(P[j]);
        }
    }
    cin>>m;
    string t1,t2;
    while(m--)
    {
        cin>>t1>>t2;
        dis[sn[t1]][sn[t2]]=0;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    cin>>m;
    printf("Case %lld:\n",ii);
    while(m--)
    {
        cin>>t1>>t2;
        cout<<"The distance from "<<t1<<" to "<<t2<<" is ";

        printf("%d",(int)round(dis[sn[t1]][sn[t2]]));
        cout<<" parsecs.\n";
    }


#ifdef used_t
}
#endif // used_t
}

