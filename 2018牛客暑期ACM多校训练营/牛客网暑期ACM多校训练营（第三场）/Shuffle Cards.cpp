#include<bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
int main ()
{
    rope<int > c;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        c.push_back(i);
    }
    while(m--)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        s--;
        c=c.substr(s,e)+c.substr(0,s)+c.substr(s+e,n-s-e);
    }
    for(int i=0;i<n;i++)
        printf("%d ",c[i]);
    return 0;
}

