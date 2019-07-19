

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
char str[200];


char de[128][128][200];
void getde()
{
    int ma=1;
    ll th=0;
    while(ma<=127)
    {
        th++;
        ma*=2;

        for(int i=1;i<=ma;i++)
        {
            if(__gcd(ma,i) !=1)
                continue;
            else
            {

          //  cout<<i<<" "<<ma<<endl;
                double tmp=1.0*i/ma;
                for(int th2=0;th2<=10;th2++)
                {
                    tmp=tmp*10;
                   // cout<<tmp<<" ";
                    int now=(int)tmp%10;
                    de[i][th][th2]=now+'0';
                }
                de[i][th][11]='\0';
           // cout<<de[i][th]<<endl;
            }
        }

    }
}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
#endif // yyhao


#ifdef used_t
ll t;
cin>>t;
getde();
//for(int i=1;i<=7;i++)
//{
//    for(int j=1;j<=(1<<i);j++)
//    {
//        if(__gcd((1<<i),j)==1)
//        {
//            printf("%d / %d = %s\n",j,(1<<i),de[j][i]);
//        }
//    }
//}
for(ll ii=1;ii<=t;ii++)
{
#endif // used_t

    scanf("%s",str);
    ll st=0;
    while( str[st] && str[st]!='.')
    {
        st++;
    }
    if(str[st]=='.')
    {
        //if(st>1 || st==1)
        ll tmp=0;
        for(int i=0;i<st;i++)
        {
            tmp=tmp*10;
            tmp+=str[i]-'0';
        }
        int be=0;
        if(tmp!=0)
        {
            cout<<tmp;
            be=1;
        }
        ll th;
        ll now=0;
        for(th=1;str[st+th];th++)
        {

        }
        th--;
        for(int i=st+1;str[i];i++)
        {
            now=now*10;
            now+=str[i]-'0';
        }
        now*=10;
        if(now!=0 )
        {
            if(be==1)
                cout<<" ";
            ll fa=0;
            for(int i=1;i<=7;i++)
            {
                if(fa)
                    break;
                for(int j=1;j<=(1<<i);j++)
                {
                    if(fa)
                        break;
                    if(__gcd((1<<i),j)==1)
                    {
                        //printf("%d / %d = %s\n",j,(1<<i),de[j][i]);
                        double tm=1.0*j/(1<<i);
                        ll big=(ll)(tm*ksm(10,th+1));

                    //    printf("%lld ",big);

                        if(big>now)
                        {
                            if(big-now<10)
                            {
                                cout<<j<<'/'<<(1<<i);
                                fa=1;
                                break;
                            }
                        }
                        else
                        {
                            if(now-big<10)
                            {

                                cout<<j<<'/'<<(1<<i);
                                fa=1;
                                break;
                            }
                        }
                       // cout<<tm<<" "<<big<<endl;
                    }
                }
            }
        }
       // cout<<"NOW:"<<now<<endl;
//        cout<<"th:"<<th<<endl;




        cout<<"\"";
    }
    else
    {
        ll tmp=0;
        for(int i=0;i<st;i++)
        {
            tmp=tmp*10;
            tmp+=str[i]-'0';
        }
        cout<<tmp;
        printf("\"");
    }
    printf("\n");




#ifdef used_t
}
#endif // used_t
}

