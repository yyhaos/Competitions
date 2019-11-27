#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1005];
bool cmp(ll a,ll b)
{
    return a>b;
}
int main ()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhao
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",a+i);
        }
        sort(a,a+n,cmp);
        int fa=0;
        for(int i=0;i<n;i++)
        {
            if(a[i] < i+1 )
            {
                printf("%d\n",i);
                fa=1;
            }
            if(fa)
                break;
        }
        if(fa==0)
            printf("%d\n",n);
    }
    return 0;
}
