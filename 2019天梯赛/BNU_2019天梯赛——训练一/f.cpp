//Problem Web:https://vjudge.net/contest/288637#problem/F
//#include<bits/stdc++.h>
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
string tar;
    cin >>tar;
transform(tar.begin(), tar.end(), tar.begin(), ::toupper);
string st;

getchar();
    getline(cin,st);
transform(st.begin(), st.end(), st.begin(), ::toupper);
    ll L1=tar.length();
    ll L2=st.length();
   // cout<<L1<<L2<<endl;
    int cnt=0;
    ll ans=0;
    ll flag=1;
   // cout<<tar<<endl<<st<<endl;
    for(int i=0;i<L2;i++)
    {
      //  cout<<"i:"<<i<<endl;
        ll now;
        if(i>0)
        {
            if(st[i-1] !=' ')
                continue;
        }
        for(int j=0;j<L1;j++)
        {
            now=i+j;
          //  cout<<now<< " : "<<tar[j]<<" "<<st[now]<<endl;
            if(tar[j] == st[now])
            {
            //    cout<<j<<" "<<L1-1<<endl;
                if(j==L1-1 && (st[now+1]=='\0'|| st[now+1]==' '))
                {
              //      cout<<"8888"<<endl;
                    if(flag)
                        cnt=i;
                    ans++;
                    flag=0;
                }
                else if(j==L1-1)
                {
                    break;
                }
            }
            else
            {
                now=i;
                break;
            }
        }
        i=now;
    }

    if(ans)
        cout<<ans<<" "<<cnt;
    else
        cout<<"-1";


#ifdef use_t
}
#endif // use_t
    return 0;
}
