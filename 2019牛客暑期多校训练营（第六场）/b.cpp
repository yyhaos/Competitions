//Problem Web:https://ac.nowcoder.com/acm/contest/886#countdown
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
ll num[10][10];
char tr(ll x)
{
    if(x<10)
        return x+'0';
    else
        return x-10+'a';
}
ll t,n,m;
ll is0[10];
ll mark[10];


char tmp[10000];
string str;
string tmp2[100];
int main ()
{
//    cout<<(int)(':')<<" "<<(int)('0')<<" "<<(int)('a')<<endl;
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
    cout<<"Case #"<<ii<<": ";
    cin>>str;
//    cout<<str<<endl;
    mem(num,0);
    mem(is0,0);
    mem(mark,0);

    ll cnt=0;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
            {

                num[i][j]*=2;
                if(str[cnt]>='0' && str[cnt]<='9')
                {
                    num[i][j]+=str[cnt]-'0';
                }
                else
                {
                    num[i][j]+=str[cnt]-'a'+10;
                }
                cnt++;
            }
        }

    }

//    for(int i=1;i<=8;i++)
//    {
//        for(int j=1;j<=4;j++)
//        {
//            cout<<num[i][j];
//        }
//        if(i<8)
//        cout<<":";
//    }
//    cout<<endl;

    for(int i=1;i<=8;i++)
    {
        is0[i]=1;
        for(int j=1;j<=4;j++)
        {
            if(num[i][j])
                is0[i]=0;
        }
    }

    ll fi=1;

ll strc=0;
ll tc=0;
fi=0;


                tc=0;
                for(int i=1;i<=8;i++)
                {
                    if(mark[i])
                    {
                        if(fi==1)
                            continue;
                        fi=1;
                        tmp[tc++]=':';
                        tmp[tc++]=':';
                    }
                    else
                    {
                        if(i!=1 && mark[i-1]==0)
                        {
                            tmp[tc++]=':';
                        }
                        if(is0[i])
                        {
                            tmp[tc++]='0';
                        }
                        else
                        {
                            ll fi0=1;
                            for(int k=1;k<=4;k++)
                            {
                                if(fi0 && num[i][k]==0)
                                    continue;
                                tmp[tc++]=tr(num[i][k]);
                                fi0=0;
                            }
                        }
                    }
            //        cout<<endl;
                }
                fi=0;

                tmp[tc++]='\n';
                tmp[tc++]='\0';


                tmp2[strc++]=string(tmp);
    for(int i=8;i>=1;i--)
    {mem(mark,0);
        if(is0[i])
        {
            ll chang=1;
            for(int j=i-1;j>=1;j--)
            {
                if(is0[j])
                {
                    chang++;
                }
                else
                    break;
            }
            if(chang>1)
            {
                fi=0;
                for(int j=i;j>=i-chang+1;j--)
                {
                    mark[j]=1;
                }
                fi=0;


                tc=0;
                for(int i=1;i<=8;i++)
                {
                    if(mark[i])
                    {
                        if(fi==1)
                            continue;
                        fi=1;
                        tmp[tc++]=':';
                        tmp[tc++]=':';
                    }
                    else
                    {
                        if(i!=1 && mark[i-1]==0)
                        {
                            tmp[tc++]=':';
                        }
                        if(is0[i])
                        {
                            tmp[tc++]='0';
                        }
                        else
                        {
                            ll fi0=1;
                            for(int k=1;k<=4;k++)
                            {
                                if(fi0 && num[i][k]==0)
                                    continue;
                                tmp[tc++]=tr(num[i][k]);
                                fi0=0;
                            }
                        }
                    }
            //        cout<<endl;
                }
                fi=0;

                tmp[tc++]='\n';
                tmp[tc++]='\0';


                tmp2[strc++]=string(tmp);
//cout<<tmp2[strc-1];


                i-=chang-1;
            }
        }
    }

    ll mi=0;
    for(int i=1;i<strc;i++)
    {
        if( tmp2[mi].length() > tmp2[i].length()  )
        {
            mi=i;
        }
        if(tmp2[mi].length()==tmp2[i].length() &&tmp2[mi]>tmp2[i])
        {
            mi=i;
        }
    }
//    cout<<"ans:";
    cout<<tmp2[mi];







#ifdef use_t
}
#endif // use_t
    return 0;
}

