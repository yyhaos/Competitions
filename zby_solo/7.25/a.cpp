#include<bits/stdc++.h>
using namespace std;
#define ll long long
char sco[10];
int main ()
{
    ll n;
    while(cin>>n)
    {
        double ans=0,fen=0;
        double tt;
        double now=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%s",&tt,sco);
            if(sco[0]=='P' || sco[0]=='N')
                continue;
//                cout<<sco<<endl;
now=0;
        if(sco[0]<'D')
            now=(double)(-sco[0]+'F'-1);
         else if(sco[0]=='D')now=(1.3);
//         cout<<now<<" "<<tt<<endl;
            if(now<0)
                now=0;
            if(sco[1]=='+')
                now+=0.3;
            else
                if(sco[1]=='-')
                now-=0.3;
            fen+=tt;
            ans+=now*tt;
//            if(fen=0)
//            cout<<now<<" "<<tt<<endl;
//            printf("%.2f %f\n",ans/fen,fen);
        }
        if(fen<0.1)
            fen=1;
        printf("%.2f\n",ans/fen);
    }

    return 0;
}
