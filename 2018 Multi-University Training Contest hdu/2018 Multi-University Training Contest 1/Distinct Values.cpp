#include<bits/stdc++.h>
using namespace std;
struct aa
{
    int l,r;
    bool operator < (const aa &b)const{
        return l>b.l;
    }
}a[1000005];
//int a[10000006];
bool cmp(aa a,aa b)
{
    if(a.l!=b.l)
        return a.l<b.l;
    else
        return a.r>b.r;
}
int ans[1000005];

int main ()
{
    int t;
    scanf("%d",&t);
    int teml,temr;
    while(t--)
    {
        priority_queue <aa> can;
        //memset(used,0,sizeof(used));
        int n,m;
        int mar=1,mal=1;
        //teml=99999999999;
        //temr=-99999999999;
        int teml,temr;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {

            scanf("%d %d",&a[i].l,&a[i].r);
        }
        sort(a,a+m,cmp);
        for(int i=0;i<m;i++)
        {
        //    printf("i=%d\n",i);
            if(i==0)
            {
                for(int j=1;j<=a[i].l-1;j++)
                {
                    ans[j]=1;
                }
                mal=1;
                mar=a[i].l-1;
            }
            if(a[i].l>mar)
            {
                //printf("%d %d %d\n",i,a[i].l,mar);
                for(int j=mar+1;j<=a[i].l-1;j++)
                {
                    ans[j]=1;
                }
                //can.clear();
                        while(!can.empty())
                            can.pop();
                        aa tem;
                        tem.l=1;
                        tem.r=100000;
                        can.push(tem);
                        for(int j=mar+1;j<a[i].l;j++)
                            ans[j]=1;

                    //tt(a[i].l,a[i].r);
                        mar=a[i].r;
                        mal=a[i].l;
                        for(int j=a[i].l;j<=a[i].r;j++)
                        {
                            aa tem=can.top();
                            can.pop();
                            ans[j]=tem.l;
                            if(tem.l+1<=tem.r)
                            {
                                tem.l++;
                                can.push(tem);
                            }
                            //can.pop();
                        }
            }
                //mal=a[i].l;
            else if(mar<a[i].r)
            {
                for(int j=a[i].l-1;j>=mal;j--)
                {
                    aa tem;
                    tem.l=ans[j];
                    tem.r=ans[j];
                    can.push(tem);
                }
                for(int j=mar+1;j<=a[i].r;j++)
                {
                    aa tem=can.top();
                    can.pop();
                    ans[j]=tem.l;
                    if(tem.l+1<=tem.r)
                    {
                        tem.l++;
                        can.push(tem);
                    }
                }
                mal=a[i].l;
                mar=a[i].r;
            }
            //mar=max(mar,a[i].r);
        }
        if(mar<n)
        {
            for(int i=mar+1;i<=n;i++)
            {
                ans[i]=1;
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(i!=1)
                printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
