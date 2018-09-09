#include<bits/stdc++.h>
using namespace std;

map<long long,int> mp;
int cnt=0;
queue <int > g[100005];
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        for(int i=0;i<=100000;i++)
        {
            while(!g[i].empty())
                g[i].pop();
        }
        cnt=0;

        int n;
        scanf("%d",&n);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            int tn;
            scanf("%d",&tn);
            for(int j=1;j<=tn;j++)
            {
                int tx,ty;
                scanf("%d%d",&tx,&ty);
               long long k=tx*1000000000+ty;
                if(mp[k]==0)
                {

                    mp[k]=++cnt;
                  //  printf("%lld-%d\n",k,cnt);
                }
                g[mp[k]].push(i);
            }
        }
        int ans=0;
        for(int i=1;i<=cnt;i++)
        {
            //printf("i=%d\n",i);
            int tem=0,pre=-1;
            int lian=0;
            while(!g[i].empty())
            {
                int top=g[i].front();
               // printf("%d %d\n",top,pre);
                g[i].pop();
                if(pre==-1)
                {
                    pre=top;
                    lian=1;
                }
                else
                {
                    if(pre+1==top)
                    {
                        lian++;
                        pre=top;
                    }
                    else if(pre==top)
                    {
                        continue;
                    }
                    else
                    {
                        ans=max(ans,lian);
                        lian=1;
                        pre=top;
                    }
                }
            }
            ans=max(ans,lian);
        }
        if(ans==1)
            ans=0;
        printf("%d\n",ans);
    }
    return 0;
}
