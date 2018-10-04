#include<bits/stdc++.h>
using namespace std;
char y[1000000+5];
char x[1000000+5];
int nxt[1000000+4];

void kmp_pre(int m)
{
    nxt[0] = -1;
    int j = 0;
    int k = -1;
    while (j < m - 1) {
       if (k == -1 || x[j] == x[k]) {
           nxt[++j] = ++k;
       } else {
           k = nxt[k];
       }
    }
}
/*
void kmp_pre(int m)
{
    int tar=x[0];
    int first=1;
    nxt[0]=-1;
    int f1=0;
    for(int i=1;i<m;i++)
    {
        if(x[i]==tar)
        {
            first=0;
            f1=i;
        }
        if(first==0)
        {
            nxt[i]=f1;
        }
        else
            nxt[i]=i+1;
    }
}*/
int KMP_Count(int m,int n)
{
    int i,j;
    int ans=0;
    kmp_pre(m);
/*
    for(int i=0;i<m;i++)
    {
        printf("%d ",nxt[i]);
    }
    printf("\n");
*/

    i=j=0;
    while(i<n)
    {
       // printf("%d %d\n",i,j);
        while(-1!=j && y[i]!=x[j])
        {
            if(y[i]<x[j])
            {
                return -1;
            }
            j=nxt[j];
        }
        i++;
        j++;
        if(j>=m)
        {
            ans++;
            j=nxt[j];
        }
    }
    return ans;
}
int main ()
{
    int cnt=10000;
    int cnt2=200;
   // freopen("test.txt","r",stdin);
    int n;
    scanf("%d",&n);
    char tmp;
    scanf("%s",x);
    for(int i=0;i<n;i++)
    {

        if(x[i]<x[0])
        {
            printf("NO");
            return 0;
        }
        y[i]=x[i];
        y[i+n]=x[i];
    }

    string str1=y;
    string str2=x;
   //cout<<str1<<str2;
    for(int i=0;i<n;i++)
    {
        if(y[i]>x[0])
            continue;
        else if(y[i]<x[0])
        {
            printf("NO");
            return 0;
        }
        else
        {
            //cout<<"1 "<<str1.substr(i,n)<<endl;
            //cout<<"2 "<<str2<<endl;
            if(cnt==0)
            {
                break;
            }
            cnt--;
            if(str1.substr(i,n)>=str2)
            {
                continue;
            }
            else
            {
                printf("NO");
                return 0;
            }
            //i=i+j-2;
        }
    }

    for(int i=n;i>=0;i--)
    {
        if(y[i]>x[0])
            continue;
        else if(y[i]<x[0])
        {
            printf("NO");
            return 0;
        }
        else
        {
            //cout<<"1 "<<str1.substr(i,n)<<endl;
            //cout<<"2 "<<str2<<endl;
            if(cnt2==0)
            {
                break;
            }
            cnt2--;
            if(str1.substr(i,n)>=str2)
            {
                continue;
            }
            else
            {
                printf("NO");
                return 0;
            }
            //i=i+j-2;
        }
    }


    /*
    if(KMP_Count(n,2*n)==-1)
    {
        printf("NO");
    }
    else*/
        printf("YES");
    return 0;
}
