#include<bits/stdc++.h>

#define LL long long

#define TREE_SIZE (1<<(16))
const int MAX=10000005;
using namespace std;
LL a[MAX];
//LL tem[MAX];
LL max_th=0;
LL first,last;
struct k
{
    LL n,th;
}tem[MAX];
LL qu(LL l,LL r,LL s)
{
    int cnt=35;
    //int cnt=5000;
   // printf("qu:%lld %lld %lld\n",l,r,s);
    if(s>=tem[r].n)
    {
        return r;
    }
    if(s<tem[l].n)
    {
        if(l!=1)
            return l-1;
        else
            return 0;
    }
    LL old=l;
    if(l==r)
        return l;
    LL mid=(l+r)/2LL;
    while(r-l>1 && cnt>0)
    {
        cnt--;
        mid=(l+r)/2LL;
        //printf("%lld %lld\n",l,r);
        if(s>tem[mid].n)
            l=mid;
        else
            r=mid;
    }
    if(tem[r].n==s && tem[l].n==s && cnt>0)
    {
        cnt--;
        while(l>=old+1)
        {
            if(tem[l-1].n!=tem[r].n)
                break;
            l--;
        }
    }
    return l;
}
int main ()
{
    freopen("test.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        memset(tem,0,sizeof(tem));
        memset(a,0,sizeof(a));
        LL n,m,k,p,q,r,mod;
        scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&m,&k,&p,&q,&r,&mod);

//        IntervalTree x(n);
        for(int i=1;i<=k;i++)
        {
            scanf("%lld",&a[i]);
           // x.Modify(i,a[i]);
        }

        for(LL i=k+1;i<=n;i++)
        {
            a[i]=(p*a[i-1]+q*i+r)%mod;
            //x.Modify(i,a[i]);
        }
       // printf("--%lld",(1<<20)+(n/2)*2+2);
        LL A=0,B=0;
        LL mr=0,co=0;
        first=n,last=n;

//        memset(cnt,0,sizeof(cnt));
        for(LL i=n;i>=n-m+1LL;i--)
        {
            if(i==n)
            {
                tem[i].n=a[i];
                tem[i].th=i;
            }
            else
            {
                LL pos=qu(first,last,a[i]);
                first=pos;
              //  printf("pos=%lld\n",pos);
                tem[first].n=a[i];
                tem[first].th=i;
            }
        }

        co=last-first+1LL;
        B+=co^(n-m+1LL);
        A+=tem[last].n^(n-m+1LL);
      //  printf("co=%lld last=%lld A=%lld B=%lld\n",co,tem[last].n,A,B);
        for(LL i=n-m;i>=1;i--)
        {

            if(tem[last].th==i+m)
            {
                last--;
            }
            LL pos=qu(first,last,a[i]);
            first=pos;

            //printf("pos=%lld\n",pos);
            tem[first].n=a[i];
            tem[first].th=i;
            co=last-first+1LL;
            B+=co^i;
            A+=tem[last].n^i;
            //printf("co=%lld last=%lld A=%lld B=%lld\n",co,tem[last].n,A,B);
        }

        //printf("%lld\n",co);

        printf("%lld %lld\n",A,B);
    }
    return 0;
}
