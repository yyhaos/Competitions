#include<bits/stdc++.h>
using namespace std;
#define xia 0
#define shang 1
#define zuo 2
#define you 3
char s[505][505];

    int n,m;
struct state
{
    int i,j,ta;
    state(int ii=0,int jj=0,int tt=0)
    {
        i=ii;
        j=jj;
        ta=tt;
    }
};
int dfs(int i)
{
    state now=(-1,i,xia);
    now.i=-1;
    now.j=i;
    now.ta=xia;

    while(1)
    {
        //cout<<now.i<<" "<<now.j<<" "<<now.ta<<endl;
        int ni=now.i,nj=now.j;
        switch(now.ta)
        {
        case xia:
            ni++;
            break;
        case zuo:
            nj--;
            break;
        case shang:
            ni--;
            break;
        case you:
            nj++;
            break;
        }
        if(nj==-1 || nj==m || ni==-1)
        {
            return -1;
        }
        if(ni==n)
        {
            return nj+1;
        }
        now.i=ni;
        now.j=nj;
        switch(s[ni][nj])
        {
        case '.':
            break;
        case '\\':
            switch (now.ta)
            {
                case shang:
                    now.ta=zuo;break;
                case xia:
                    now.ta=you;break;
                case zuo:
                    now.ta=shang;break;
                case you:
                    now.ta=xia;break;
            }
            break;
        case '/':
            switch (now.ta)
            {
                case shang:
                    now.ta=you;break;
                case xia:
                    now.ta=zuo;break;
                case zuo:
                    now.ta=xia;break;
                case you:
                    now.ta=shang;break;
            }
            break;
        }
    }
}
int main ()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    for(int i=0;i<m;i++)
    {
        printf("%d\n",dfs(i));
    }
    return 0;
}
