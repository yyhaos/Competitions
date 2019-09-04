//Problem Web:https://ac.nowcoder.com/acm/contest/887#question
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
const ll q=998244353LL;
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
ll C[4005][4005];
void getc()
{
    for(int i=0;i<=4000;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j]%=q;
        }
    }
}

ll CC(ll n,ll k)// x1+x2+...+xk == n
{
    return C[n+k-1][k-1];
}
ll myCC(ll n,ll k) // x1+x2+...+xk <= n
{
    return C[n+k][k];
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
getc();
//cout<<C[5][2]<<endl;
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    cin>>n>>m;
    ll ans=0;
    for(ll k=1;k*m <=n;k++)
    {
        ll top=n-k*m;
        ll tmp=0;

        tmp= 2* myCC(k,top)%q;
        ll tong=top/k+1; // 完全一样就不能乘2
        tmp-=tong;
        tmp=(tmp+q)%q;

        ll xiecnt=2*k-1;
        ll used=0;
        ll fi=0;
        ll xie=0;
        if(k>1)
            for(ll st=0;1;st++ )
            {
                ll cha=2;
                fi=cha*(k-1)+st;
//                used= k * ( st+ fi)*xiecnt/2LL;
                cout<<"st:"<<st<<" used:"<<used<<" fi:"<<fi<<endl;
                if(fi<=top)
                    xie++;
                else
                    break;
                for(ll cha=4;cha;cha+=2)
                {
                    fi=cha*(k-1)+st;
//                    used= k * ( st+ fi)*xiecnt/2LL;
                    if(fi<=top)
                        xie++;
                    else
                        break;
                }
    //            if()
            }
        tmp+=xie*4;
        tmp%=q;
        cout<<"K:"<<k<<" tmp:"<<tmp<<" tong:"<<tong<<" top:"<<top<<" xie:"<<xie<<endl;

         ans=(ans+tmp)%q;
    }
    cout<<ans<<"\n";




#ifdef use_t
}
#endif // use_t
    return 0;
}



