#include<bits/stdc++.h>
using namespace std;
string a;
int c[100005];
char b[100005];
#define ll long long
ll q=1000000007LL;
ll q2=1000000006LL;

ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
        {
            ans=(ans*a)%q;
        }
        a=(a*a)%q;
        b/=2LL;
    }return ans%q;
}
int main ()
{
    //cout<<q;
    //string b;
    cin>>b>>a;
    int len=strlen(b);
    //cout<<len;
    ll zhi=0;
    for(int i=0;i<len;i++)
    {
        c[i]=b[len-i-1]-'0';
      //  cout<<c[i];
    }
    ll now=1LL;
    for(int i=0;i<len;i++)
    {
        zhi=(zhi+(c[i]*now)%q2)%q2;
        //zhi=zhi%q;
        now=(now*10LL)%q2;
    }

    cout<<ksm(2LL,zhi);

    return 0;
}
