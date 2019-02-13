#include<bits/stdc++.h>
using namespace std;
double x[1005];
double y[1005];
double ar[1000005];
struct s
{
    int c,k;
}ss[100005];
bool cmp(s a,s b)
{
    return a.k<b.k;
}
double x1,x2,x3,y11,y2,y3;
int n,k;
        double a,b,c,s,p;
int cnt=0;
int cc[100005];
int kao[100005];
int main ()
{
    int n;
    int cnt=0;
    cin>>n;
    int k;
    for(int i=0;i<n;i++)
    {   scanf("%d",&cc[i]);

    }
    for(int i=0;i<n;i++)
        scanf("%d",&kao[i]);
    for(int i=0;i<n;i++)
    {
        ss[i].c=cc[i];
        ss[i].k=kao[i];
    }
//    for(int i=0;i<n;i++)
//        cout<<ss[i].c<< " "<<ss[i].k<<endl;
    sort(ss,ss+n,cmp);
//    for(int i=0;i<n;i++)
//        cout<<ss[i].c<< " "<<ss[i].k<<endl;
    int yu=0;
    int be=0;
    for(int i=0;i<n;i++)
    {
//        cout<<ss[i].c<< " "<<ss[i].k<<endl;
        int now=ss[i].k;
        yu+=now-be;
        yu-=ss[i].c;
        if(yu<0)
        {
            printf("NO");
            return 0;
        }
        be=ss[i].k+2;
    }
    printf("YES");
}

