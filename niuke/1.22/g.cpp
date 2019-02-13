#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int np[100005];
int s[100005];
int main ()
{
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&np[i]);
        s[np[i]]=i;
    }
    int l=s[x],r=s[y];
    //cout<<"   "<<l<<" "<<r<<endl;

    if(l>r)
    {
        int tmp=l;
        l=r;
        r=tmp;
    }

    int minn=x,maxx=y;
    for(int i=l;i<=r;i++)
    {
        if(np[i]<minn)
            minn=np[i];
        if(np[i]>maxx)
            maxx=np[i];
    }

    int pre_l=0,pre_r;
    while(maxx-minn+1 != r-l+1)
    {
        if(maxx-minn+1<r-l+1)
        {
            //cout<<maxx<<" "<<minn<<"   "<<l<<" "<<r<<endl;
            if(s[maxx]<l)
            {
                pre_l=l;
                l=s[maxx];
                for(int i=l;i<pre_l;i++)
                {
                    maxx=max(np[i],maxx);
                    minn=min(np[i],minn);
                }
            }
            if(s[minn]<l)
            {
                pre_l=l;
                l=s[minn];
                for(int i=l;i<pre_l;i++)
                {
                    maxx=max(np[i],maxx);
                    minn=min(np[i],minn);
                }
            }
            if(s[maxx]>r)
            {
                pre_r=r;
                r=s[maxx];
                for(int i=pre_r+1;i<=r;i++)
                {
                    maxx=max(np[i],maxx);
                    minn=min(np[i],minn);
                }
            }
            if(s[minn]>r)
            {
                pre_r=r;
                r=s[minn];
                for(int i=pre_r+1;i<=r;i++)
                {
                    maxx=max(np[i],maxx);
                    minn=min(np[i],minn);
                }
            }
        }
        else
        {
            //cout<<"1"<<endl;
            while(pre_l != l || pre_r!=r)
            {
                pre_l=l;
                pre_r=r;
                for(int i=minn;i<=maxx;i++)
                {
                    l=min(l,s[i]);
                    r=max(r,s[i]);
                }
                for(int i=l;i<=pre_l-1;i++)
                {
                    maxx=max(np[i],maxx);
                    minn=min(np[i],minn);
                }
                for(int i=pre_r+1;i<=r;i++)
                {

                    maxx=max(np[i],maxx);
                    minn=min(np[i],minn);
                }
            }

        }
    }
    cout<<l<<" "<<r;
    return 0;
}
