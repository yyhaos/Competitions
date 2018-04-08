#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://www.bnuoj.com/v3/contest_show.php?cid=9358#problem/I
const int maxn=1000005;
int main ()
{
    long long t, ans, n, k, i, cnt, big, maxnn;
    char tem;
    //int que[maxn];
    scanf("%lld",&t);
    while(t--)
    {
        cnt=big=0;
        scanf("%lld %lld\n",&n,&k);
     //   for(i=0;i<maxn;i++)
    //    {
    //        que[i]=0;
    //    }
        for(i=0;i<n;i++)
        {
            scanf("%c",&tem);
            if(tem=='D')
            {
                big++;
            }
            else
            {
                cnt+=big;
            }
        }
        if(cnt>k)
            ans=cnt-k;
        else
            ans=k-cnt;
        maxnn=big*(n-big);
        if(k>maxnn)
            printf("-1");
        else
            printf("%lld",ans);
        if(t!=0)
            printf("\n");
    }
    return 0;
}
