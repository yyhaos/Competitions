//Problem Web:http://www.bnuoj.com/contest_problem_merge.php?cid=9518
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
string str;
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
getchar();
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    getline(cin,str);
    cout<<"Problem #"<<ii<<endl;
//    cout<<str<<endl;

    double u,i,p;
    char tar[3]={'I','U','P'};
    char dan[3]={'A','V','W'};
    char dd[3]={'m','k','M'};
    double aaa[3]={-1.0,-1.0,-1.0};
    for(int j=0;j<3;j++)
    {
        char ta=tar[j];
        char tda=dan[j];
        char tdd=dd[j];
        for(int i=0;str[i];i++)
        {
            if(str[i]==ta && str[i+1]=='=')
            {
                i+=2;
                if(str[i]==0)
                    break;
//cout<<i<<" "<<ta<<endl;
                ll renshu=1,xiaoshu=0,rendanwei=0,renjieshu=0;
                ll youxiao=0;
                double ans=0;
                double bei=1;
//                ll xiaoshu=0;
char tmp,nxt;
                for(int j=0;str[j];j++)
                {
                    tmp=str[j+i];
                    nxt=str[j+i+1];
                    if(tmp<='9' && tmp>='0')
                    {
                        if(renshu==1  && xiaoshu==0)
                        {
                            ans*=10;
                            ans+=tmp-'0';
                        }
                        else if(renshu==1 && xiaoshu ==1)
                        {
                            bei/=10.0;
                            ans+=bei*(tmp-'0');
                        }
                        else break;
                        if(nxt<='9' && nxt>='0'  || (nxt=='.') || (nxt==tda) || (nxt=='m') || (nxt=='k') || (nxt)=='M' )
                        {
                            continue;
                        }
                        else
                            break;
                    }
                    else if(tmp=='.')
                    {
                        xiaoshu++;
                        if(renshu==1 && xiaoshu==1 && nxt<='9' && nxt>='0')
                        {
                            continue;
                        }
                        else
                            break;
                    }
                    else if(tmp==tda)
                    {
                        youxiao=1;
                        break;
                    }
                    else
                    {
                        renshu=0;
                        ll ta=0;
                        double bei=0;
                        for(int k=0;k<3;k++)
                        {
                            if(tmp==dd[k])
                            {
                                ta++;
                                if(k)
                                bei=pow(10,3*k);
                                else
                                    bei=0.001;
                                ans*=bei;

                                break;
                            }
                        }
                        if(ta && nxt==tda)
                            continue;
                        break;
                    }
                }
                if(youxiao)
                {
                    aaa[j]=ans;
                }
            }

        }
    }
//    for(int i=0;i<3;i++)
//    {
//        cout<<aaa[i]<<" ";
//    }
//    cout<<endl;

    for(int i=0;i<3;i++)
    {
        if(aaa[i]<0)
        {
            switch(i)
            {
                case 0: printf("I=%.2fA\n",aaa[2]/aaa[1]);
                break;
                case 1: printf("U=%.2fV\n",aaa[2]/aaa[0]);
                break;
                case 2: printf("P=%.2fW\n",aaa[1]*aaa[0]);
            }

            break;
        }
    }
cout<<"\n";



#ifdef use_t
}
#endif // use_t
    return 0;
}


