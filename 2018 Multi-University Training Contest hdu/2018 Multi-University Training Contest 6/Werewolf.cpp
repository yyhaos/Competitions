#include<bits/stdc++.h>
using namespace std;
struct peo
{
    int p,t;
}ps[1000005];
struct tt
{
    int bei,sh;
}ts[1000005];
bool cmp(tt a,tt b)
{
    if(a.bei!=b.bei)
        return a.bei<b.bei;
    else
        return a.sh<b.sh;
}
int th;
int cha[1000005];

int used[1000005];
//        int th=0;

void dfs(int i)
{
    if(cha[i]==1)
        return ;
    cha[i]=1;
    tt td;
    td.bei=i;
    td.sh=0;
    for (int j=lower_bound(ts,ts+th,td,cmp)-ts;j<th;j++)
    {
        if(ts[j].bei!=i)
            break;
        dfs(ts[j].sh);
    }
    return ;
}
int ru[100005];
int  f(int i)
{
    if(ps[i].t==0 && !used[i])
    {
        used[i]=1;
        return i;
    }

    int fa=ps[i].p;
    if(used[fa]==1)
        return ps[i].p=fa;
    return ps[i].p=f(fa);

}
int main ()
{
    int t;
    scanf("%d",&t);
    char str[10];
    int ans=0;
    while(t--)
    {
        ans=0;

        int n;
        scanf("%d",&n);
        memset(ts,0,sizeof(ts));
        memset(ru,0,sizeof(ru));
        memset(used,0,sizeof(used));
        memset(cha,0,sizeof(cha));
        memset(ps,0,sizeof(ps));
        int flag=1;
        th=0;
        for(int i=1;i<=n;i++)
        {
            int tem;
            scanf("%d %s",&tem,str);
            ps[i].p=tem;
            if(str[0]=='v')
            {
                ps[i].t=1;
                ru[tem]++;
                ts[th].bei=tem;
                ts[th++].sh=i;
            }
            else
            {
                flag=0;
                ps[i].t=0;
            }
        }
        sort(ts,ts+th,cmp);
        if(flag==1)
        {
            printf("0 0\n");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            memset(used,0,sizeof(used));
            if(ps[i].t==1 && ru[i]==0)
            {
                f(i);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(ps[i].t==1)
                continue;
            else
            {
                if(ps[i].p==i)
                {

                    dfs(i);
                    continue;
                }
                int tar=ps[i].p;
                if(ps[tar].p==i)
                {
                    dfs(tar);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(cha[i]==1)
                ans++;
        }
        printf("0 %d\n",ans);
    }
    return 0;
}
