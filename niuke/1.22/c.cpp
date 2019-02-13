#include<bits/stdc++.h>
using namespace std;
//int a[3005][3005];
int p[3005];
int dis[3005];
int used[3005];
queue <int > qs;
int main ()
{
    memset(used,0,sizeof(used));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);


    memset(dis,0,sizeof(dis));
    dis[1]=p[1];
    qs.push(1);
    while(!qs.empty())
    {
        int top=qs.front();
        qs.pop();
       // cout<<top<<endl;
        if(used[top]==1)
            continue;
        used[top]=1;
        for(int i=1;i<=n;i++)
        {
            if(p[top]>p[i])
            {
                if(dis[i]==0)
                    dis[i]=dis[top]^p[i];
                else
                    dis[i]=max(dis[i],dis[top]^p[i]);
                qs.push(i);
            }
        }
    }
    if(dis[n]>0)
    cout<<dis[n];
    else cout<<-1;
    return 0;
}
