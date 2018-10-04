#include<bits/stdc++.h>
using namespace std;
struct point
{
    long long x,y,t;
}a[1000055];
bool cmp1(point a, point b)
{
    return a.x<b.x;
}
bool cmp2(point a, point b)
{
    return a.y<b.y;
}

int main ()
{
    long long n;
    scanf("%I64d",&n);
    char str[10];
    long long ans=0;
    long long cnt1=0,cnt2=0,o2=0,o1=0;
    for(long long i=1;i<=n;i++)
    {
        scanf("%I64d%I64d%s",&a[i].x,&a[i].y,str);
        if(str[0]=='b')
            a[i].t=1,cnt1++;
        else
            a[i].t=2,cnt2++;
    }
    o1=cnt1;
    o2=cnt2;
    sort(a+1,a+1+n,cmp1);
    ans=max(o1,o2);
    cnt1=0;
    long long left=1;
    //printf("cnt2=%I64d\n",cnt2);
    for(long long i=1;i<=n;)
    {
        //printf("i=%I64d\n",i);
        left=a[i].x;
        if(a[i].t==1)
            cnt1++;
        else
            cnt2--;
        long long j;
        for(j=i+1;j<=n;j++)
        {
            if(a[j].x==left)
            {
                if(a[j].t==1)
                    cnt1++;
                else
                    cnt2--;
            }
            else
                break;
        }
        ans=max(cnt1+cnt2,ans);
        i=j;
    }


    cnt1=o1;
    cnt2=0;

    for(long long i=1;i<=n;)
    {
        //printf("i=%I64d\n",i);
        left=a[i].x;
        if(a[i].t==2)
            cnt2++;
        else
            cnt1--;
        long long j;
        for(j=i+1;j<=n;j++)
        {
            if(a[j].x==left)
            {
                if(a[j].t==2)
                    cnt2++;
                else
                    cnt1--;
            }
            else
                break;
        }
        ans=max(cnt1+cnt2,ans);
        i=j;
    }



    //printf("cnt1=%I64d cnt2=%I64d\n",cnt1,cnt2);
    cnt2=o2;
    cnt1=0;
    sort(a+1,a+1+n,cmp2);
    left=1;
    for(long long i=1;i<=n;)
    {
        //printf("i=%I64d\n",i);
        left=a[i].y;
        if(a[i].t==1)
            cnt1++;
        else
            cnt2--;
        long long j;
        for(j=i+1;j<=n;j++)
        {
            if(a[j].y==left)
            {
                if(a[j].t==1)
                    cnt1++;
                else
                    cnt2--;
            }
            else
                break;
        }
        ans=max(cnt1+cnt2,ans);
        i=j;
    }

    cnt1=o1;
    cnt2=0;

    for(long long i=1;i<=n;)
    {
        //printf("i=%I64d\n",i);
        left=a[i].y;
        if(a[i].t==2)
            cnt2++;
        else
            cnt1--;
        long long j;
        for(j=i+1;j<=n;j++)
        {
            if(a[j].y==left)
            {
                if(a[j].t==2)
                    cnt2++;
                else
                    cnt1--;
            }
            else
                break;
        }
        ans=max(cnt1+cnt2,ans);
        i=j;
    }

            ans=max(cnt1+cnt2,ans);
    printf("%I64d\n",ans);
    return 0;
}
