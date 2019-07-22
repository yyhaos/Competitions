#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("mosalah.in","r",stdin);
#endif

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,x,y;
        scanf("%d%d%d%d",&n,&m,&x,&y);
        if(y==0)
        {
            cout<<"-1\n";
            continue;
            if(m==n)
                cout<<"
        }
        ll ans=(x+y)*n-m;
        if(ans<0)
            ans=0;

        printf("%d\n",ans);

    }
    return 0;
}
