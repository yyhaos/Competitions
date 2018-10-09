#include<bits/stdc++.h>
using namespace std;
long long p1[200005],p2[200005];
bool cmp(long long a,long long b)
{
    return a<b;
}
int main ()
{
    //freopen("test.txt","r",stdin);
    long long t;
    long long cnt=0;
    scanf("%lld",&t);
    for(long long ii=1;ii<=t;ii++)
    {
        cnt=0;
        memset(p1,0,sizeof(p1));
        memset(p2,0,sizeof(p2));
        long long p,n;
        scanf("%lld%lld",&p,&n);

                long long t1,t2;
            for(long long i=0;i<p;i++)
            {
                scanf("%lld %lld",&t1,&t2);
                p1[cnt]=t1;
                p2[cnt++]=t2;
            }
        sort(p1,cnt+p1,cmp);
        sort(p2,cnt+p2,cmp);
        long long l=0,r=1000000004;
        long long le=-1,len=(r+l)/2,ri=le+len;
        long long tk=100;
        while(r-l>=5 )
        {
            tk--;
           // cout<<len<<endl;
            long long th1=0;
            long long th2=0;
            long long tm=0;
            long long ans=0;
            le=0;
            ri=le+len;
            for(th1=0;p1[th1]<ri && th1<cnt;th1++)
                tm++;
            ans=tm;

            while(th1!=cnt && th2!=cnt)
            {

                if(th1==cnt)
                {
                    break;
                }
                else if(p1[th1]-ri<=p2[th2]-le)
                {

                    tm++;
                    ans=max(ans,tm);
                    long long tr=ri;
                    le+=p1[th1]-tr;
                    ri+=p1[th1]-tr;
                    th1++;
                }
                else
                {
                    tm--;
                    ans=max(ans,tm);
                    long long tl=le;
                    le+=p2[th2]-tl;
                    ri+=p2[th2]-tl;
                    th2++;
                }
               // printf("%lld %lld  %lld-%lld ",th1,th2,le,ri);
                //printf("%lld \n",tm);
            }
            //printf("%lld-%lld ans = %lld\n",l,r,ans);
            if(ans>=n)
            {
                r=len;
                len=(r+l)/2;
            }
            else
            {
                l=len;
                len=(r+l)/2;
            }
        }
        for(len=l;len<=r;len++)
        {
            long long th1=0;
            long long th2=0;
            long long tm=0;
            long long ans=0;
            le=0;
            ri=le+len;
            for(th1=0;p1[th1]<ri && th1<cnt;th1++)
                tm++;
            ans=tm;
            while(th1!=cnt && th2!=cnt)
            {

                if(th1==cnt)
                {
                    break;
                }
                else if(p1[th1]-ri<=p2[th2]-le)
                {

                    tm++;
                    ans=max(ans,tm);
                    long long tr=ri;
                    le+=p1[th1]-tr;
                    ri+=p1[th1]-tr;
                    th1++;
                }
                else
                {
                    tm--;
                    ans=max(ans,tm);
                    long long tl=le;
                    le+=p2[th2]-tl;
                    ri+=p2[th2]-tl;
                    th2++;
                }
               // printf("%lld %lld  %lld-%lld ",th1,th2,le,ri);
               // printf("%lld \n",tm);
            }
            if(ans>=n)
            {
                break;
            }
        }
        printf("Case %lld: %lld\n",ii,len);
    }
    return 0;

}
