#include<bits/stdc++.h>
using namespace std;
struct col
{
    int ai,bi;
    friend bool operator <(col a,col b)
    {
        return a.bi>b.bi;
    }
}c[100005];
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&c[i].ai);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&c[i].bi);
    }
    sort(c,c+m);
//    for(int i=0;i<m;i++)
//    {
//        cout<<c[i].ai<<" "<<c[i].bi<<endl;
//    }
    int th=0;
    int ans=0;
    while(n>0 && th<m)
    {
      //  cout<<ans<<" "<<th<<endl;
        if(n>=c[th].ai)
        {
            n-=c[th].ai;

            ans+=c[th].ai*c[th].bi;
            th++;
        }
        else
        {
            ans+=c[th].bi*n;
            n=0;
        }
    }
    cout<<ans;
    return 0;
}
