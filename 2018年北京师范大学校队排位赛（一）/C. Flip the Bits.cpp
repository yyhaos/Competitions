#include<bits/stdc++.h>
using namespace std;
int b[10000];
int N[10000];
long long ni;
int th=1LL;

int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(b,0,sizeof(b));
        memset(N,0,sizeof(N));
        long long n;
        cin>>n;
        ni=n;

        th=1;
        while(n>0)
        {
            b[th++]=n%2LL;
            n/=2LL;
        }
        int th2=1;
        long long i;
        long long nt=ni-1LL;
        int ans=0;
        while(nt>0)
        {
            N[th2++]=nt%2LL;
            nt/=2LL;
        }
        //printf("th=%d th2=%d",th,th2);
        for(i=th-1;i>=1;i--)
        {
            if(b[i]!=N[i])
                ans++;
        }
        //return ans;
        printf("%d\n",ans);
    }

    return 0;
}
