#include<bits/stdc++.h>
#define ll long long
using namespace std;
//#define ll long long
ll mine[10][10];
ll tx[10]={1,1,1,0,-1,-1,-1,0};
ll ty[10]={1,0,-1,-1,-1,0,1,1};
long long th;
ll r,c,m;
int judge1(int i,int j)
{
    int x,y;
    for(int th=0;th<8;th++)
    {
        x=i+tx[th];
        y=j+ty[th];
        if(x>=0 && x<r &&y>=0 && y<c)
        {
            if(mine[x][y]==0)
            {
                return 1;
            }
        }
    }
    return 0;
}
ll judge0(int i,int j)
{
    int x,y;
    ll cnt=0;
    for(int th=0;th<8;th++)
    {
        x=i+tx[th];
        y=j+ty[th];
        if(x>=0 && x<r &&y>=0 && y<c)
        {
            if(mine[x][y]==1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main ()
{
    memset(mine,0,sizeof(mine));
    ll t;
    scanf("%lld",&t);

    while(t--)
    {
        ll ans=0;
        scanf("%lld%lld%lld",&r,&c,&m);
        for(ll th=(1LL<<(r*c))-1LL;th>=0;th--)
        {
            //cout<<th<<endl;
            ll cnt=0,mi=0;
            ll tt=th;
            memset(mine,0,sizeof(mine));
            while(tt>0)
            {
                if(tt&1)
                {
                    mi++;
                    mine[cnt/c][cnt%c]=1;
                }
                cnt++;
                tt=tt/2;
            }
/*
            for(ll i=0;i<r;i++)
            {
                for(ll j=0;j<c;j++)
                    printf("%lld",mine[i][j]);
                printf("\n");
            }
            printf("\n");
*/
            int flag=1;
            for(ll i=0;i<r;i++)
            {
                for(ll j=0;j<c;j++)
                {
                    if(mine[i][j]==1)
                    {
                        flag=judge1(i,j);
                    }
                    else
                    {
                        if(judge0(i,j)>m)
                        {
                            flag=0;
                        }
                        else
                        {
                            flag=1;
                        }
                    }
                    if(flag==0)
                        break;
                }
                if(flag==0)
                        break;
            }
            /*
            if(flag==1 && mi==18)
            {
                for(ll i=0;i<r;i++)
                {
                    for(ll j=0;j<c;j++)
                        printf("%lld",mine[i][j]);
                    printf("\n");
                }
                printf("\n");
            }
            */
            if(flag==1)
            {
                ans=max(mi,ans);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
