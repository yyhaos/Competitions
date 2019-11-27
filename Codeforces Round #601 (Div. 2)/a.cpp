
#include<bits/stdc++.h>
using namespace std;
int t;
int main ()
{
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int ans=abs(a-b)/5;
        int cha=(a-b>0? a-b :b-a)%5;
        if(cha==0);
        else
            if(cha<=2)ans++;
        else ans+=2;
        printf("%d\n",ans);
    }
    return 0;
}
