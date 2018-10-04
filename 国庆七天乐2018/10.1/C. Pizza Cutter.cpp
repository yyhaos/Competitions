#include<bits/stdc++.h>
using namespace std;
struct kk
{
    long long l,r;
};
kk a[100005];
kk b[100005];
vector <long long > A;
long long merge_count(vector<long long > &a)
{
    long long n=a.size();
    if(n<=1)
        return 0;
    long long cnt=0;
    vector<long long > b(a.begin(),a.begin()+n/2);
    vector<long long > c(a.begin()+n/2,a.end());
    cnt+=merge_count(b);
    cnt+=merge_count(c);
    long long ai=0,bi=0,ci=0;
    while(ai<n)
    {
        if(bi<b.size() && (ci==c.size()|| b[bi]<=c[ci]))
        {
            a[ai++]=b[bi++];
        }
        else
        {
            cnt+=n/2-bi;
            a[ai++]=c[ci++];
        }
    }
    return cnt;
}
bool cmp(kk a,kk b)
{
    return a.l<b.l;
}
int main ()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    long long h,v;
    scanf("%lld%lld",&h,&v);
    for(long long i=0;i<h;i++)
    {
        scanf("%lld%lld",&a[i].l,&a[i].r);
    }
    for(long long i=0;i<v;i++)
    {
        scanf("%lld%lld",&b[i].l,&b[i].r);
    }
    sort(a,a+h,cmp);
    sort(b,b+v,cmp);
    long long ans=(v+1)*(1+h);
    A.clear();
    for(long long i=0;i<h;i++)
    {
        A.push_back(a[i].r);
    }
    ans+=merge_count(A);
    A.clear();
    for(long long i=0;i<v;i++)
    {

        A.push_back(b[i].r);
    }
    ans+=merge_count(A);
    printf("%lld",ans);
    return 0;
}
