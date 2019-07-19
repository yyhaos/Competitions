//Problem Web:http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1009&cid=867
#include<bits/stdc++.h>
#include<ext/rope>
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
#define use_t 1
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
ll s1[100005];
ll s2[100005];
ll s2f[100005];
ll cnt;
ll ned[100005];
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
    mem(ned,0);
    mem(s1,0);
    mem(s2,0);
    mem(s2f,0);
    cnt=0;
//    mem(ned,0);
    ll fcnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&s1[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%lld",&s2[i]);
    }
    ll tmp=0;
    for(int i=0;i<m;i++)
    {
        scanf("%lld",&tmp);
        if(tmp)
        {
            s2f[cnt++]=s2[i];
            s2[i]=-1;
        }
    }
    sort(s2f,s2f+cnt);
    sort(s1,s1+n);
    sort(s2,s2+m);



    for(int i=0;i<cnt;i++)
    {
        ll now=s2f[i];
//        cout<<now<<" fangshou "<<endl;
        ll pos=lower_bound(s1,s1+n,now)-s1;
        ned[pos]++;
    }
    ll ac=0;
    for(ll i=0;i<=n;i++)
    {
//        if(ned[i])
//        {
//            cout<<i<<" : ned "<<ned[i]<<endl;
//        }
        while(ned[i])
        {
            ac=max(ac,i);
            s1[ac]=0;
            ac++;
            ned[i]--;
        }
    }
    if(ac>n)
    {
        cout<<"0\n";
        continue;
    }

    sort(s1,s1+n);

    printf("battle:\n");

    cout<<"guaiwu: :";
    for(int i=cnt;i<m;i++)
    {
        cout<<s2[i]<<" ";
    }
    cout<<endl;

    cout<<"gongji: ";
    for(int i=cnt;i<n;i++)
    {
        cout<<s1[i]<<" ";
    }
    cout<<endl;


    ll gp=m-1,ap=
    //sort(s2,s2+m);





#ifdef use_t
}
#endif // use_t
    return 0;
}
