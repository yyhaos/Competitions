#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
    int th;
}p[3005];
bool cmp(point a1,point a2)
{
    if(a1.y!=a2.y)
        return a1.y<a2.y;
    else
        return a1.x<a2.x;
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<3*n;i++)
        {
            scanf("%d",&p[i].x);
            scanf("%d",&p[i].y);
            p[i].th=i+1;
        }
        sort(p,p+3*n,cmp);
        for(int i=0;i<3*n;i+=3)
        {
            printf("%d %d %d\n",p[i].th,p[i+1].th,p[i+2].th);
        }
    }
    return 0;
}
