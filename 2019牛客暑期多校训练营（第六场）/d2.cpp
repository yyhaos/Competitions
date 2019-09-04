#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e3+5;
int a[maxn];
int vis[maxn];
int check(int n,int m,int k)
{

    for(int i=0;i<n;i++) vis[i]=0;
    int cnt=0;
    for(int i=0;i<k;i++){
        int tmp = m;
        for(int j=n-1;j>=0;j--){
            if(!vis[j]&&tmp>=a[j]){
                cnt++;
                tmp-=a[j];
                vis[j]=1;
            }
        }
//        if(tmp!=0)
//            return 0;
    }

    if(cnt==n) return 1;
    else return 0;
}
int n,m,k;
int test(int m)
{
    return check(n,m,k);
}

int main(void)
{
//    freopen("in.txt","r",stdin);
    int t;scanf("%d",&t);
    int cases=0;
    while(t--){
        cases++;
        scanf("%d%d",&n,&k);
         int sum=0;
        for(int i=0;i<n;i++) scanf("%d",a+i);
        sort(a,a+n);

//        int sum=0;

    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    int fa=0;
    printf("Case #%d: ",cases);
//    cout<<n<<" "<<k<<endl;
        for(int i=max(a[n-1],sum/k);i<=sum;i++)
        {
            if(check(n,i,k))
            {
                printf("%d ",i);
                break;
            }
//            else
//            {
//                if(fa==1)
//                {
//
//                }
//            }
        }
        printf("\n");
    }

}
