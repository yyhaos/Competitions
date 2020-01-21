#include<bits/stdc++.h>
using namespace std;
long long  f[555];
const long long  ma=300022;
#define  INF 0x7fffffff
struct edge
{
    long long  u,v,w,th;
    edge(){}
    bool operator < (edge a)
    {
        if(w==a.w)
        {
            return th<a.th;
        }
        return w<a.w;
    }
}e[ma];
long long  ans[ma];
long long  n,m;

    long long  a[ma],b[ma],c[ma],d[ma];
long long  fi(long long  x)
{
    if(f[x]==x)return x;
    return f[x]=fi(f[x]);
}
void un(long long  x,long long  y)
{
    f[fi(x)]=y;
    fi(x);
}
signed  main ()
{

    long long  cnt=0;
    cin>>n>>m;
    for(long long  i=0;i<m;i++)
    {
        scanf("%lld%lld%lld%lld",i+a,i+b,i+c,i+d);
        if(d[i]==0)
        {
            e[cnt].u=a[i];
            e[cnt].v=b[i];
//                e[cnt].th=i+1;
            e[cnt++].w=c[i];
        }
    }
    if(cnt>=2)
    sort(e,e+cnt);
    long long  maxn=-1;
long long  cc=0;
    for(long long  now=1;now<=n;now++)
    {
long long  tt=0;
        for(long long  i=1;i<=n;i++)f[i]=i;
        for(long long  i=0;i<m;i++)
        {
            if(d[i])
            {
                if(a[i]==now || b[i]==now)
                    continue;
                    tt++;
                un(a[i],b[i]);
            }
            else
            {

            }
        }
//        cout<<INF;
long long  tans=0;
//        sort(e,e+cnt);
        for(long long  i=0;i<cnt;i++)
        {
            if(e[i].u==now || e[i].v==now)
                continue;
            if(fi(e[i].u) != fi(e[i].v))
            {
                tt++;
                un(e[i].v,e[i].u);
                tans+=e[i].w;
            }
        }
//        printf("tt:%d\n",tt);
        if(tt!=n-2)
        {
            tans=INF;
        }
        if(tans>maxn)
        {
            maxn=tans;
            cc=0;
            ans[cc++]=now;
        }
        else if(tans==maxn)
        {
            ans[cc++]=now;
        }
//        printf("%lld%lld%lld%d\n",now,tans,maxn,cc);
    }
    if(maxn==-1 || cc==0)
    {
        printf("0");
    }
    else
    {

        printf("%lld",ans[0]);
        for(long long  i=1;i<cc;i++)
        {
            printf(" %lld",ans[i]);
        }
    }

    return 0;
}
