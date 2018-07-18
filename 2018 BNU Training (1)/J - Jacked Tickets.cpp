
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    freopen("jacking.in","r",stdin);
    int T,k = 1;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int p[N+1] = {0};
        for(int i = 1;i<=N;i++)
            scanf("%d",&p[i]);
        int q;
        printf("Case %d:\n",k++);
        cin>>q;
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(y > x)
            {
                printf("impossible\n");
                continue;
            }
            int a = x/y;
            int b = x%y;
            printf("%d\n",(y-b)*p[a]+b*p[a+1]);
        }
    }
    return 0;
}
