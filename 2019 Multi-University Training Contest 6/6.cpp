//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=853
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
struct so
{
    ll x,y,k,t;
}s[15];
ll x[15];
ll y[15];

struct xie
{
    ll k,t;
}zx[15],yx[15];
ll gett(ll cha,ll t,ll k)
{
    ll tmp=t+cha;
    tmp+= k * -1* (tmp/k);
    while(tmp<0)
        tmp+=k;
    return tmp%k;
}



ll getju(ll duan,ll chang,ll k,ll t)
{
    ll tmp=0;
    if(t<duan)
    {
        ll top=t+1;
        ll ceng=1+(duan-top-1)/k;
        ll bottom=t+1+(ceng-1)*k;
        tmp+=ceng*(bottom+top)/2;
    }
    t+=duan;
    t%=k;
//cout<<"tmp1:"<<tmp<<endl;
    if(t < chang-duan )
    {
        ll ceng=1+(chang-duan)/k;
        tmp+=ceng*duan;
    }
//cout<<"tmp2:"<<tmp<<endl;
    t+=chang-duan;
    t%=k;
    if(t==0)
        t+=k;
    if(t<duan)
    {
        ll bottom=duan-1-t;
        ll ceng=1+(duan-t)/k;
        ll top=bottom-(ceng-1)*k;
        tmp+=ceng*(bottom+top)/2;
    }
//    cout<<"tmp3:"<<tmp<<endl;


    return tmp;
}


int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
ll mt;
cin>>mt;
for(ii=1;ii<=mt;ii++)
{
#endif // use_t

    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i].x>>s[i].y>>s[i].k>>s[i].t;
    }
    for(int i=1;i<=n;i++)
    {
        x[i]=s[i].x;
        y[i]=s[i].y;
    }
    sort(1+x,x+1+n);
    sort(1+y,y+1+n);
    x[0]=0;
    y[0]=0;
    x[n+1]=m+1;
    y[n+1]=m+1;
ll  ans=0;
    ll xmi,xma,ymi,yma,tx,ty,tk,tt,cz,cy,cha;
    cz=cy=0;
    for(int mii=0;mii<=n;mii++)
    {
        for(int mjj=0;mjj<=n;mjj++)
        {
            cz=cy=0;
            xmi=x[mii];
            xma=x[mii+1]-1;
            ymi=y[mjj];
            yma=y[mjj+1]-1;
            if(xmi>xma || ymi>yma)
            {
                continue;
            }

//            cout<<xmi<< ","<< ymi<<" "<<xma<<","<<yma<<endl;

            for(int i=1;i<=n;i++)
            {
                tx=s[i].x;
                ty=s[i].y;
                tk=s[i].k;
                tt=s[i].t;
                double xm=(xmi+xma)/2.0;
                double ym=(ymi+yma)/2.0;
                ll zuoxie=1;
                if(xm>=tx && ym>=ty)
                {
                    zuoxie=0;
                }
                else if(xm<=tx && xm<=ty)
                {
                    zuoxie=0;
                }
                if(zuoxie)
                {
                    cha=xmi+ymi-tx-ty;
                    zx[cz].t=gett(cha,tt,tk);
                    zx[cz++].k=tk;
                }
                else
                {
                    cha=xma+ymi-tx-ty;
                    yx[cy].t=gett(cha,tt,tk);
                    yx[cy++].k=tk;
                }
            }

            ll lcm=1;
ll fit;
            if(cz)
            {
                fit=-1;
                for(int i=0;i<cz;i++)
                    lcm=lcm*zx[i].k/__gcd(lcm,zx[i].k);
//                cout<<"×ó lcm "<<lcm<<endl;
                for(int j=0;j<lcm;j++)
                {
                    ll fa=1;
                    for(int x=0;x<cz;x++)
                    {
                        if(j%zx[x].k!=zx[x].t)
                        {
                            fa=0;break;
                        }
                    }
                    if(fa)
                    {
                        fit=j;
                        break;
                    }
                }
                if(fit<0)
                    continue;
            }

            ll zt=fit,zk=lcm;
//            zuoxie[0].t=fit;
//            zuoxie[0].k=lcm;
            if(cy)
            {
                lcm=1;

                fit=-1;
                for(int i=0;i<cy;i++)
                    lcm=lcm*yx[i].k/__gcd(lcm,yx[i].k);
                    //                 cout<<cy<<"ÓÒ lcm "<<lcm<<endl;
                for(int j=0;j<lcm;j++)
                {
                    ll fa=1;
                    for(int x=0;x<cy;x++)
                    {
                        if(j%yx[x].k !=yx[x].t)
                        {
//                            cout<<"err:"<<" "<<yx[x].k<<" "<<yx[x].t<<endl;
                            fa=0;break;
                        }
                    }
//                    cout<<j<<":"<<fa<<" "<<endl;
                    if(fa)
                    {
                        fit=j;
                        break;
                    }
                }
                if(fit<0)
                    continue;
            }


            ll yt=fit,yk=lcm;

//            if(cz)
//            cout<<"ÓÐÐ§×óÐ±±ß/ :"<< zt<<" "<<zk<<endl;
//            if(cy)
//            cout<<"ÓÐÐ§ÓÒÐ±±ß\\ :"<< yt<<" "<<yk<<endl;
//            youxie[0].t=fit;
//            youxie[0].k=lcm;
            ll duan=min(1+xma-xmi, 1+yma-ymi);
            ll chang=max(1+xma-xmi, 1+yma-ymi);
            if(cz==0)
            {

//                ll chang=
                ans+=getju(duan,chang,yk,yt);
            }
            else if(cy == 0)
            {

                ans+=getju(duan,chang,zk,zt);
            }
            else
            {
                ans+=2; //两斜线共存
            }

//    printf("ans: %lld\n",ans);


        }

    }
    printf("%lld\n",ans);



#ifdef use_t
}
#endif // use_t
    return 0;
}

