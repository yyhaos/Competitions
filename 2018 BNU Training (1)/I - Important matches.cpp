
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    freopen("important.in","r",stdin);
    int T,k = 1;
    cin>>T;
    while(T--)
    {
        int N,M,Q;
        scanf("%d%d%d",&N,&M,&Q);
        int a[N+1][M+1];
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=M;j++)
                scanf("%d",&a[i][j]);
        printf("Case %d:\n",k++);
        while(Q--)
        {
            int A,B,C,D;
            int sum[N*M+1];
            int len = 0;
            scanf("%d%d%d%d",&A,&B,&C,&D);
            for(int i = A;i<=C;i++)
                for(int j = B;j<=D;j++)
                    sum[++len] = a[i][j];
            sort(sum+1,sum+len+1);
            printf("%d\n",sum[len/2+1]);
        }
    }
    return 0;
}
