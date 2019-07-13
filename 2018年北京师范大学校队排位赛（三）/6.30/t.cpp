
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
char str[1005];
ll n,m;
ll used[10];
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
    mem(used,0);
    cin>>str;
    ll len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]>='0' && str[i]<='9')
            used[str[i]-'0']=1;
    }
    ll n1=0,n2=0,n3=0,ope=-5,deng=-5;
    ll s1=1,s2=1,s3=1;
ll st1=0,st2=0,st3=0;
        for(ll i=0;i<len;i++)
        {
            if(i==0)
            {
                if(str[i]=='-')
                {
                    s1=-1;
                    continue;
                }
            }
            if(i==ope+1)
            {
                if(str[i]=='-')
                {
                    s2=-1;
                    continue;
                }
            }
            if(i==deng+1)
            {
                if(str[i]=='-')
                {
                    s3=-1;
                    continue;
                }
            }
            if((str[i]<='9' && str[i]>='0' )||str[i]=='?')
            {
                if(ope==-5)
                    n1++;
                else if(deng==-5)
                {
                    n2++;
                }
                else n3++;
            }
            else if(str[i]=='=')
            {
                deng=i;
            }
            else
                ope=i;
        }


 ll fa=0;
// cout<<"n:"<<s1*n1<<" "<<s2*n2<<" "<<s3*n3<<" ope:"<<ope<<" deng"<<deng<<endl;

    if(s1<0)
        st1++;
    if(s2<0)
        st2++;
    if(s3<0)
        st3++;
    for(ll we=0;we<=9;we++)
    {
        if(used[we])
            continue;
        ll qian=1;
        ll a1=0,a2=0,a3=0;
        ll tq=1;

       // cout<<"st:"<<st1<<" "<<st2<<" "<<st3<<endl;
        for(ll i=st1;i<n1+st1;i++)//a1
        {

            if(str[i]=='?')
            {
               // ll no=str[i]-'0';
                if( we==0 && n1!=1 && i==st1)
                {
                    qian=0;
                }
                a1*=10;
                a1+=we;
            }
            else
            {
                ll no=str[i]-'0';
                //cout<<"no:"<<no<<endl;
                //ll no=str[i]-'0';
                if( no==0 && n1!=1 && i==st1)
                {
                    qian=0;
                }

                a1*=10;
                a1+=no;
            }
        }
//     if(qian==0)
//            cout<<"1111111"<<endl;
        tq=1;
        for(ll i=st2+ope+1;i<=n2+ope+st2;i++)//a2
        {
            if(str[i]=='?')
            {
                if( we==0 && n2!=1 && i==st2+ope+1)
                {
                    qian=0;
                }
                a2*=10;
                a2+=we;
            }
            else
            {
                ll no=str[i]-'0';
                if( no==0 && n2!=1 && i==st2+ope+1)
                {
                    qian=0;
                }

                a2*=10;
                a2+=no;
            }
        }
//        if(qian==0)
//            cout<<"222222"<<endl;
        tq=1;
        for(ll i=st3+deng+1;i<=deng+n3+st3;i++)//a3
        {
            if(str[i]=='?')
            {
                //ll no=str[i]-'0';
                if( we==0 && n3!=1 && i==st3+deng+1)
                {
                    qian=0;
                }


                a3*=10;
                a3+=we;
            }
            else
            {
                ll no=str[i]-'0';
                if( no==0 && n3!=1 && i==st3+deng+1)
                {
                    qian=0;
                }
                a3*=10;
                a3+=no;
            }
        }


        if(qian==0)//qiandao
            continue;
        a1=a1*s1;
        a2=a2*s2;
        a3=a3*s3;
        if(s1<0 && a1==0 || (s2<0 && a2==0 )|| (s3<0 && a3==0))//-0
        {   continue;

        }
       // cout<<"we"<<we<<" "<<a1<<" "<<a2<<" "<<a3<<endl;
        switch(str[ope])
        {
            case'+':if(a1+a2==a3)
                        fa=1;
                break;
            case '*':
                    if(a1*a2==a3)
                        fa=1;
                    break;
            case '-': if(a1-a2==a3)
                        fa=1;
                    break;
        }
        if(fa)
        {
            cout<<we;
            break;
        }
    }
     if(!fa)
        {
            cout<<-1;
        }
    if(ii!=t)
        cout<<"\n";


#ifdef used_t
}
#endif // used_t
}

