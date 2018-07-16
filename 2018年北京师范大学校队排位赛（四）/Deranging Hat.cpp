#include<bits/stdc++.h>
using namespace std;
struct cc
{
    char c;
    int th;
}cs[1005];
bool cmp(cc a,cc b)
{
    if(a.c==b.c)
        return a.th<b.th;
    else
        return a.c<b.c;
}
int main ()
{
    bool cmp(cc a,cc b);
    memset(cs,0,sizeof(cs));
//    memset(str,sizeof(str));
    //int pos[1005];
    char str[1005];
    cin>>str;
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        cs[i].c=str[i];
        cs[i].th=i;
    }
    sort(cs,cs+len,cmp);
    int old[1005];
    memset(old,0,sizeof(old));
    for(int i=0;i<len;i++)
    {
        old[cs[i].th]=i;
    }
    int flag=0;
    for(int i=len-1;i>=0;i--)
    {
        if(cs[old[i]].th!=old[i])
        {
            if(flag==1)
                printf("\n");
            flag=1;
            if(cs[old[i]].c>cs[i].c)
                printf("%d %d",1+old[i],1+cs[old[i]].th);
            else
                printf("%d %d",1+cs[old[i]].th,1+old[i]);
            int mid ;
            mid=cs[i].th;
            char mid_c=cs[i].c;
            int n_old=old[i];


            old[cs[i].th]=old[i];

            cs[i].th=cs[n_old].th;
            cs[i].c=cs[n_old].c;
            cs[n_old].th=mid;
            cs[n_old].c=mid_c;
        }
    }
    return 0;
}
