#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int maze[1005][1005];
#define zh 1
#define ko 0

struct poi
{
    int x,y;
    poi(int xx=0,int yy=0)
    {
        x=xx;
        y=yy;
    }
};
poi x1[1000];
poi x2[1000];
poi x3[1000];
poi x4[1000];
int sx,sy,ex,ey;
int si(int x,int y)
{
    return 2*x+2*y-4;
}
void show()
{
    printf("%d %d\n%d %d\n",sx,sy,ex,ey);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(maze[i][j]==1)
            {
                printf("x");
            }
            else
                printf(".");
        }
        printf("\n");
    }
}
void draw(poi a,poi b)
{
   //cout<<a.x<<"-"<<a.y<<" -> "<<b.x<<"-"<<b.y<<endl;
    if(a.x<b.x && a.y==b.y)
    for(int i=a.x;i<=b.x;i++)
        maze[i][a.y]=1;
    if(a.x>b.x && a.y==b.y)
    for(int i=b.x;i<=a.x;i++)
        maze[i][a.y]=1;

    if(a.y<b.y && a.x==b.x)
    for(int i=a.y;i<=b.y;i++)
        maze[a.x][i]=1;
    if(a.y>b.y && a.x==b.x)
    for(int i=b.y;i<=a.y;i++)
        maze[a.x][i]=1;
}
int main ()
{
   // cout<<poi(1,2).x<<" "<<poi(1,2).y<<endl;
    scanf("%d%d%d",&n,&m,&k);
    memset(maze,0,sizeof(maze));
    sx=1,sy=1;
    if(k<n)
    {
        ex=1,ey=k+1;
        show();
        return 0;
    }
    else if(k<m)
    {
        ex=k+1,ey=1;
        show();
        return 0;
    }
    int maxn=0;
    int c1,c2,c3,c4;
    c1=c2=c3=c4=0;
    if((n>=4 && m>=4)||n%2==0 && m%2==0 && n>=4 && m>=4)
    {
        for(int i=2;i<=min(n/2,m/2);i+=2)
        {
            x1[c1++]=poi(i,i);
        }
        for(int i=2;i<=n/2;i+=2)
        {
            if(m-i+1>m/2)
            x2[c2++]=poi(i,m-i+1);
        }
        for(int i=4;i<=m/2;i+=2)
        {
            if(n-i+3>n/2)
            x3[c3++]=poi(n-i+3,i);
        }
        for(int i=m-1;i>m/2;i-=2)
        {
            if(n-(m-i) >n/2)
            x4[c4++]=poi(n-(m-i),i);
        }
        sx=n;
        sy=1;
        draw(poi(n,2),x1[0]);
        for(int i=0;i<max(c1,max(c2,max(c3,c4)));i++)
        {//show();
            if(i<c1 && i<c2)
                draw(x1[i],x2[i]);
           // show();
            if(i<c2 && i<c4)
                draw(x2[i],x4[i]);
            //show();
            if(i<c3 && i<c4)
                draw(x3[i],x4[i]);
           // show();
            if(i<c3 && i+1<c1)
                draw(x3[i],x1[i+1]);
        }
        int cnt=0;
        int x=n,y=m;
        while(k>si(x,y))
        {
            cnt++;
            k-=si(x,y);
            x-=4;
            y-=4;
        }
        int sx,sy;
        sx=n-2*cnt;
        sy=cnt*2+1;
        if(k<x)
        {
            ex=sx-k;
            ey=sy;
        }
        else if(k<x+y-1)
        {
            ex=sx-x+1;
            ey=sy+k-(x)+1;
        }
        else if(k<2*x+y-2)
        {
            ex=sx+k-(x+y-1)-x+2;
            ey=sy+y-1;
        }
        else if(k<=x*2+y*2-6)
        {
            ex=sx;
            ey=sy-(k-(2*x+y))+y-4;
        }
        else if(k==x*2+y*2-5)
        {
            ex=sx-1;
            ey=sy+2;
        }
        else
        {
            ex=sx-2;
            ey=sy+2;
        }
        show();
        return 0;
    }
    if(n%2==1 )
    {
        for(int i=2;i<=n;i+=4)
        {
            for(int j=1;j<m;j++)
            {
                maze[i][j]=1;
            }
        }
        for(int i=4;i<=n;i+=4)
        {
            for(int j=2;j<=m;j++)
            {
                maze[i][j]=1;
            }
        }
        int nn=k/(2*m+2);
        k-=nn*(2*m+2);
        nn=nn*4+1;

        if(k<=m-1)
        {
            ex=nn;
            ey=k+1;
        }
        else if(k==m)
        {
            ex=nn+1;
            ey=m;
        }
        else if(k<=2*m)
        {
            ex=nn+2;
            ey=2*m-k+1;
        }
        else if(k==2*m+1)
        {
            ex=nn+3;
            ey=1;
        }
    }
    else
    {
        for(int j=2;j<=m;j+=4)
        {
            for(int i=1;i<n;i++)
                maze[i][j]=1;
        }
        for(int j=4;j<=m;j+=4)
        {
            for(int i=2;i<=n;i++)
            {
                maze[i][j]=1;
            }
        }
        int mm=k/(2*n+2);
         k-=mm*(2*n+2);
        mm=mm*4+1;

        if(k<=n-1)
        {
            ex=k+1,ey=mm;
        }
        else if(k==n)
        {
            ex=n,ey=mm+1;
        }
        else if(k<=2*n)
        {
            ex=2*n-k+1;
            ey=mm+2;
        }
        else if(k==2*n+1)
        {
            ex=1;
            ey=mm=3;
        }
    }
    show();
    return 0;
}
