#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int N;
    int a[505];
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
    }
    int h;
    scanf("%d",&h);
    int ans=999999;
    int s;
    for(int i=1;i<=N;i++)
    {
        if(ans>h%a[i])
        {
            ans=h%a[i];
            s=a[i];
        }
    }
    printf("%d",s);
    return 0;
}
