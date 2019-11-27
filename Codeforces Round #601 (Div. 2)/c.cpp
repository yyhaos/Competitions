
#include<bits/stdc++.h>
using namespace std;
int q[100005][3];
#define ll long long
map<ll,int> mp;
map<ll,int> mp2;
int ru[100005];
int in[100005];
int main ()
{
    int n;
    cin>>n;
    memset(ru,0,sizeof(ru));
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&q[i][j]);
            ru[q[i][j]]++;
            in[q[i][j]]=i;
        }
        sort(q[i],q[i]+3);
        if(mp[ q[i][1]*n+q[i][2]]==0)
        {
            if(i==0)
                mp[ q[i][1]*n+q[i][2]]=3*n;
            else
                mp[ q[i][1]*n+q[i][2]]=i;
        }
        else
        {
            if(i==0)
                mp2[ q[i][1]*n+q[i][2]]=3*n;
            else
                mp2[ q[i][1]*n+q[i][2]]=i;
        }

//        else
        if(mp[ q[i][0]*n+q[i][2]]==0)
            mp[ q[i][0]*n+q[i][2]]=i+n;
        else mp2[ q[i][0]*n+q[i][2]]=i+n;

        if(mp[ q[i][0]*n+q[i][1]]==0)
            mp[ q[i][0]*n+q[i][1]]=i+2*n;
        else
            mp2[ q[i][0]*n+q[i][1]]=i+2*n;
    }
    int st;

//    printf("1\n");

    for(int i=1;i<=n;i++)
    {
        if(ru[i]==1)
        {
            st=i;
        }
    }
    int pos=in[st];
    printf("pos:%d\n",pos);

    ru[st]--;
    int f1=0,f2=0;
    for(int i=0;i<3;i++)
    {
        if( ru[q[pos][i]] )
        {
            printf("i:%d %d\n",i,q[pos][i]);
            if(f1==0)
            {
                f1=q[pos][i];
                ru[q[pos][i]]--;
            }
            else
            {
                f2=q[pos][i];
                ru[q[pos][i]]--;
            }
        }
    }
    int cnt=n;
    cnt--;
    printf("%d",st);
    while(cnt)
    {
//printf(" \nst:%d ff:%d %d\n",st,f1,f2);

        int nxt;


        if(f1>f2)swap(f1,f2);
        nxt= mp[ f1*n+f2 ];
//        if(nxt==0)
//        {
//            nxt=mp[f2*n+f1];
//            swap(f1,f2);
//        }

        printf(" %d",f1);
        int pos=nxt%n;
        int th=(nxt/n)%3;
//         printf(" \n11 nxt:%d pos:%d th:%d dd:%d\n",nxt,pos,th,q[pos][th] );

        if(nxt==0||q[pos][th]==st )
        {
            if(f1>f2)swap(f1,f2);
            nxt= mp2[ f1*n+f2 ];
//            if(nxt==0)
//            {
//                nxt=mp2[f2*n+f1];
//                swap(f1,f2);
//            }

//            printf(" %d",f1);
            int pos=nxt%n;
            int th=(nxt/n)%3;
//             printf(" \n22 nxt:%d pos:%d th:%d dd:%d\n",nxt,pos,th,q[pos][th] );


        }


        if(nxt==0||q[pos][th]==st )
        {
            swap(st,f1);
            if(f1>f2)swap(f1,f2);
            nxt= mp[ f1*n+f2 ];
    //        if(nxt==0)
    //        {
    //            nxt=mp[f2*n+f1];
    //            swap(f1,f2);
    //        }

//            printf(" %d",f1);
            int pos=nxt%n;
            int th=(nxt/n)%3;
//             printf(" \n1111 nxt:%d pos:%d th:%d dd:%d\n",nxt,pos,th,q[pos][th] );

            if(nxt==0||q[pos][th]==st )
            {
                if(f1>f2)swap(f1,f2);
                nxt= mp2[ f1*n+f2 ];
    //            if(nxt==0)
    //            {
    //                nxt=mp2[f2*n+f1];
    //                swap(f1,f2);
    //            }

//                printf(" %d",f1);
                int pos=nxt%n;
                int th=(nxt/n)%3;
//                 printf(" \n2222 nxt:%d pos:%d th:%d dd:%d\n",nxt,pos,th,q[pos][th] );


            }
        }

        st=f1;
        f1=q[pos][th];



//        f2=f2;
        cnt--;
    }




    return 0;
}
