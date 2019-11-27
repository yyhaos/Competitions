
//https://codeforces.com/gym/102263/problem/F
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1005];
int b[1005];
int used[1005];
int ke[1005];
int bei[1005];
int nowke[1005];
int main ()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhaos
    int n,p;
    scanf("%d%d",&n,&p);
    p--;
    for(int i=1;i<n;i++)
    {
        scanf("%d",a+i);
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d",b+i);
        b[i]--;
    }
    memset(used,0,sizeof(used));
    memset(ke,0,sizeof(ke));
    memset(bei,0,sizeof(bei));
    memset(nowke,0,sizeof(nowke));
    int th=0;
    int beisum=0;
    ke[p]=1;
    int now;
    int off;
    int ncnt=0;
    for(int i=1;i<n;i++)
    {
        a[i]=(a[i]) % (n-i+1);
    }
    int fa=0;
    for(int i=1;i<n;i++)
    {
//        printf("to go : %d\n",a[i]);
//        cout<<"i:"<<i<<"  \nused:\t";
//        for(int j=0;j<n;j++){
//            printf(" %d",used[j]);
//        }
//        printf("\nke:\t");
//        for(int j=0;j<n;j++){
//            printf(" %d",ke[j]);
//        }
//        printf("\n");

        ncnt=0;
        beisum=0;
        now=0;
        th=0;
        off=0;
//        printf("111 start!:\n");
        while(ncnt<4 || th<beisum)
        {
//            printf("now:%d off:%d th:%d beisum:%d ncnt:%d\n",now,off,th,beisum,ncnt);
            if(off==0)
                ncnt++;
            if(used[off]==1)
            {
//                now++;
                off++;
                off%=n;
                continue;
            }
            if(ke[off]==1)
            {
                bei[beisum++]=now+a[i];
            }
            if(beisum>th)
            {
                while(beisum>th && bei[th] <= now)
                {
                    th++;
                    nowke[off]=1;
                }
            }
            now++;
            off++;

            off%=n;
        }
        ncnt=0;
        beisum=0;
        now=0;
        th=0;
        off=0;
//        printf("222 start!:\n");
        while(ncnt<2 || th<beisum)
        {
//            printf("now:%d off:%d th:%d beisum:%d ncnt:%d\n",now,off,th,beisum,ncnt);
            if(off==0)
                ncnt++;
            if(used[off]==1)
            {
//                now++;
                off--;
                if(off<0)off=n-1;
                continue;
            }
            if(ke[off]==1)
            {
                bei[beisum++]=now+a[i];
            }
            if(beisum>th)
            {
                while(beisum>th && bei[th] <= now)
                {
                    th++;
                    nowke[off]=1;
                }
            }
            now++;
            off--;
            if(off<0)off=n-1;
        }

            used[b[i]]=1;
        int kecnt=0;
        for(int j=0;j<n;j++)
        {
            if(used[j]==0)
                ke[j]=nowke[j];
            else
                ke[j]=0;
            nowke[j]=0;
            if(ke[j]==1)
                kecnt++;
        }
//        if(nowke[used[b[i]]])
        if(kecnt>=n-i)
        {
////            printf("fff %d %d ke:",kecnt,n-i);
//            for(int i=0;i<n;i++){
//                printf(" %d",ke[i]);
//            }
//            printf("\nUesd:");
//            for(int i=0;i<n;i++){
//                printf(" %d",used[i]);
//            }

            fa=1;
            break;
        }
        if(kecnt==0)
        {
            fa=0;
            break;
        }
    }
    if(fa==1)
        printf("Yes\n");
    else if(fa==0)
        printf("No\n");
    else
        printf("Yes");

    return 0;
}
