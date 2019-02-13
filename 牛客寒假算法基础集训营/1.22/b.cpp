#include<bits/stdc++.h>
using namespace std;
int a[10];
int f(int pre,int s0,int s2,int s4)
{
    if(pre==0)
    {
        if(s4>0)
            return 16+f(4,s0,s2,s4-1);
        if(s2>0)
            return 4+f(2,s0,s2-1,s4);
        return 0;
    }
    if(pre==2)
    {
        if(s0>0)
            return 4+f(0,s0-1,s2,s4);
        if(s4>0)
            return 4+f(4,s0,s2,s4-1);
        return 0;
    }
    if(pre==4)
    {
        if(s0>0)
            return 16+f(0,s0-1,s2,s4);
        if(s2>0)
            return 4+f(2,s0,s2-1,s4);
        return 0;
    }
    return 0;
}
int main ()
{
    memset(a,0,sizeof(a));
    int n;
    int k;
    cin>>n;
    while(n--)
    {
        scanf("%d",&k);
        a[k]++;
    }
    int ans=0;
    cout<<f(0,a[0],a[2],a[4]);
//    if(a[0]>a[4])
//    {
//        ans+=16*(a[4])*2-16;
//        a[0]-=a[4]-1;
//        if(a[0]>0)
//        {
//            ans+=16;
//            a[0]--;
//        }
//        else if(a[2]>0)
//        {
//            ans+=4;
//            cout<<ans;
//            return 0;
//        }
//        else
//        if(a[2]<a[0])
//        {
//            ans+=4*2*a[2];
//            cout<<ans;
//            return 0;
//        }
//        else
//        {
//            ans+=8*a[0];
//            cout<<ans;
//            return 0;
//        }
//
//    }
//    else if(a[4]>a[0])
//    {
//        ans+=16*2*(a[0]+1)-16;
//        a[4]-=a[0]+1;
//        if(a[2]<=a[4])
//        {
//            ans+=4*2*a[2];
//            a[4]-=a[2];
//            cout<<ans;
//            return 0;
//        }
//        else
//        {
//            ans+=4*2*a[4]+4;
//            cout<<ans;
//            return 0;
//        }
//    }
//    else
//    {
//        ans+=16*2*a[4];
//        if(a[2]>0)
//            ans+=4;
//        cout<<ans;
//        return 0;
//    }

    return 0;
}
