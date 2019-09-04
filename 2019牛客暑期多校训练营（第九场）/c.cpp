//Problem Web:
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

string s;
ll n;

stack< char > ss;
stack<ll > sn;
char ope[100005];
ll num[100005];
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

    ll tmp;
    char tope;

    ll n1=0,n2=0;
    while(scanf("%lld",&tmp))
    {
        num[n1++]=tmp;
        scanf("%c",& tope);
        ope[n2++]=tope;
        if(tope=='\n')
            break;
    }
    ll a1=num[0];
    for(int i=1;i<n1;i++)
    {
        if(ope[i-1]=='*')
        {
            a1*=num[i];
        }
        else
        {
            a1+=num[i];
        }
    }

    ll a2=0;

    ll th[10000];
    th['*']=2;
    th['+']=1;
    th['\n']=0;

    th['_']=0;
    ss.push('_');
    sn.push(num[0]);
    for(int i=1;i<=n1;i++)
    {
//        cout<<i<<" "<<ss.top()<<" "<<sn.top()<<endl;

        ll topth=th[ ss.top() ];
        ll noth=th[ ope[i-1]];
//        cout<<topth<<" "<<noth<<endl;
        while(!ss.empty() && topth > noth)
        {

//            noth=th[ ope[i-1]];
            ll pre=sn.top();
            sn.pop();
            ll pre2=sn.top();
            sn.pop();
            char to= ss.top();
            ss.pop();
//            cout<<pre2<<to<<pre<<endl;
            if(to=='+')
            {
                sn.push(pre+pre2);
            }
            else if(to=='*')
            {
                sn.push(pre*pre2);
            }
            if(ss.empty())
                break;

             topth=th[ ss.top() ];
//            cout<<topth<<endl;
        }

        ss.push(ope[i-1]);
        if(i<n1)
            sn.push(num[i]);
    }
    a2=sn.top();



cin>>n;

    if(a1==n && a2==n)
    {
        cout<<"U";
    }
    else if(a1==n)
    {
        cout<<"L";
    }
    else if(a2==n)
    {
        cout<<"M";
    }
    else
        cout<<"I";









#ifdef use_t
}
#endif // use_t
    return 0;
}

