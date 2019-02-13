
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c;
ll biao[3][105][3];
char ans[1297152];
char tmp[1297152];
void merge(char a[],int low,int high, int mid)
{


    /*
    for(int i = 0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    printf("-%d-%d-%d\n",low,high,mid);
    */
    //subarray1=a[low,mid] , subarray2=a[mid+1,high] , both sorted
    int N=high-low+1;
    char b[N];
    int left=low ,right=mid+1, th=0;

    bool xian=0;
    for(int i=0;i<mid-left+1;i++)
    {
        if(a[left+i]==a[right+i])
            continue;
        else if(a[left+i]>a[right+i])
        {
            xian=0;
            break;
        }
        else
        {
            xian=true;
            break;
        }
    }
    if(!xian)
    {
        int cnt=0;
        for(int i=right;i<=high;i++)
            b[cnt++]=a[i];
        for(int i=left;i<=mid;i++)
        {
            b[cnt++]=a[i];
        }
        for(int i=0;i<cnt;i++)
        {
            a[left+i]=b[i];
        }
    }
}

void mergeSort(char a[],int low,int high)
{
    if(high>low)
    {
       // cout<<"mer"<<low<<" "<<high<<endl;
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,high,mid);
       // cout<<ans<<endl;
    }
}

void gou(int th,int a, int b,int c)
{
   // cout<<a<<b<<c<<endl;
    if(a==1)
    {
        ans[0]='R';
    }
    else if(b==1)
    {
        ans[0]='P';
    }
    else ans[0]='S';
   // cout<<"initial:"<<ans<<endl;
    int cnt=1;
    //cout<<th;
    int tt=th;
    while(th--)
    {

        for(int i=0;i<cnt;i++)
        {
            if(ans[i]=='R')
            {
                tmp[i*2]='R';
                tmp[i*2+1]='S';
            }
            else if(ans[i]=='P')
            {
                tmp[i*2]='P';
                tmp[i*2+1]='R';
            }
            else if(ans[i]=='S')
            {
                tmp[i*2]='P';
                tmp[i*2+1]='S';
            }
        }
        cnt*=2LL;
        for(int i=0;i<cnt;i++)
        {
            ans[i]=tmp[i];
        }

       // cout<<ans<<endl;
    }
    //for(int i=1)
    mergeSort(ans,0,cnt-1);

}
int main ()
{
    //cout<<(1LL<<21);
    ll ta,tb,tc,sum,th;
    a=1;b=0;c=0;
    for(int i=0;i<=20;i++)
    {
        biao[0][i][0]=a;
        biao[0][i][1]=b;
        biao[0][i][2]=c;
        ta=a;tb=b;tc=c;
        a=ta+tb;
        b=tc+tb;
        c=ta+tc;
//        cout<<i<<" "<<a<<" "<<b<<" "<<c<<" "<<endl;

//        sum=a+b+c;
//        th=floor(0.5+log(sum)/log(2));
//        cout<<th<<endl;
    }
     a=0;b=1;c=0;
    for(int i=0;i<=20;i++)
    {
        biao[1][i][0]=a;
        biao[1][i][1]=b;
        biao[1][i][2]=c;
        ta=a;tb=b;tc=c;
        a=ta+tb;
        b=tc+tb;
        c=ta+tc;
//        cout<<i<<" "<<a<<" "<<b<<" "<<c<<" "<<endl;

//        sum=a+b+c;
//        th=floor(0.5+log(sum)/log(2));
//        cout<<th<<endl;
    }

     a=0;b=0;c=1;
    for(int i=0;i<=20;i++)
    {
        biao[2][i][0]=a;
        biao[2][i][1]=b;
        biao[2][i][2]=c;
     //   cout<<i<<" "<<a<<" "<<b<<" "<<c<<" "<<endl;
        ta=a;tb=b;tc=c;
        a=ta+tb;
        b=tc+tb;
        c=ta+tc;


        //sum=a+b+c;
        //th=floor(-0.5+log(sum)/log(2));
      //  cout<<th<<endl;
    }
    cin>>a>>b>>c;
    sum=a+b+c;
    th=floor(0.5+log(sum)/log(2));
  //  cout<<"th:"<<th<<endl;
    ll aa[3]={a,b,c};
    for(int j = 0; j<=2;j++)
    {
        int flag=1;
        for(int i=0;i<3;i++)
        {
            if(aa[i]!=biao[j][th][i])
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
            continue;
      //  cout<<"leixin:"<<j<<endl;
//        for(int i=0;i<3;i++)
//        {
//            cout<<biao[j][th][i]<<" ";
//        }
//        cout<<endl <<j<<" "<<th<<" "<<endl;
        gou(th,biao[j][0][0],biao[j][0][1],biao[j][0][2]);
        cout<<ans;
        return 0;
    }
    cout<<"IMPOSSIBLE";
        return 0;
    return 0;
}
