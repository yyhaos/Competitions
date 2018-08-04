#include<bits/stdc++.h>
using namespace std;
struct number
{
    int n,m;
    bool operator < (const number &b)const
    {
        if(m!=b.m)
            return m>b.m;
        else
            return n<b.n;
    }
}p[100005];
bool cmp(number a,number b)
{
    if(a.m!=b.m)
        return a.m>b.m;
    else
        return a.n<b.n;
}
//priority_queue<number> q;
//queue<number> tem2;
map <int ,int> used;
map <int ,int> th;

int maxn[100005];
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        used.clear();
        th.clear();
        //while(!q.empty())
       // {
       //     q.pop();
       // }
       // while(!tem2.empty())
        //    tem2.pop();
        memset(maxn,0,sizeof(maxn));
        memset(p,0,sizeof(p));
        int k=0;
        int n,m,tem;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tem);
            if(used[tem]>0)
            {
                p[th[tem]].m++;

            }
            else
            {
                th[tem]=k++;
                p[th[tem]].n=tem;
                p[th[tem]].m=1;
            }
            used[tem]++;
        }
        for(int i=0;i<n;i++)
            maxn[p[i].m]=max(maxn[p[i].m],p[i].n);
        sort(p,p+n,cmp);

        p[n].m=0;
        int ans=-1;
        int tem_m=p[0].m;
        //printf("k=%d m=%d tem_m=%d\n",k,m,tem_m);
        int start=0;
        int sum=0;
        while(m>=1)
        {
            int i;
            for(i=start+1;i<n;i++)
            {
                if(p[i].m!=tem_m)
                    break;
            }
            //printf("i=%d\t",t);
            int next_m=p[i].m;
            int cha=tem_m-next_m;
            //printf("m=%d sum=%d i=%d cha=%d\n",m,sum,i,cha);
            if(m<sum+i-1)
                break;
            sum+=cha*i;
            //m-=cha*i;
            ans=max(ans,maxn[tem_m]);
            //printf("m=%d\n",m);
            start=i;
            if(start>=n)
                break;
            tem_m=next_m;
        }
        if(m==0)
        {
            start=0;
            int i;
            for(i=start+1;i<n;i++)
            {
                if(p[i].m!=tem_m)
                    break;
            }
            if(i>=2)
                ans=-1;
            else
                ans=maxn[p[0].m];
        }
        printf("%d\n",ans);
    }
    return 0;
}
