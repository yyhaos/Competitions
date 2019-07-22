
#include<bits/stdc++.h>
using namespace std;
int N=100005;
long long tt=0;
int n;
void merge(int a[],int low,int high, int mid)
{
/*

    for(int i = 0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("-%d-%d-%d-%d\n",low,high,mid,tt);
*/
    //subarray1=a[low,mid] , subarray2=a[mid+1,high] , both sorted
    int N=high-low+1;
    int b[N];
    int left=low ,right=mid+1, th=0;
    while(left<=mid && right<=high)
    {
        if(a[left]>a[right])
            tt+=mid+1-left;
        b[th++]=a[left]<=a[right] ? a[left++] : a[right++];
        //if(a[left])
    }
    while(left<=mid)
    {
        b[th++]=a[left++];
        //tt++;
    }
    while(right<=high)
        b[th++]=a[right++];
    for(th=0;th<N;th++)
        a[low+th]=b[th];
}

void mergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,high,mid);
    }
}

int main ()
{
    int ss[100005];
    long long a,b;
    while(~scanf("%d%lld%lld",&n,&a,&b))
    {
        tt=0;
        int ra;
        long long mi=min(a,b);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ss[i]);
        }
        mergeSort(ss,0,n-1);
        printf("%lld\n",tt*mi);
    }

    return 0;
}
