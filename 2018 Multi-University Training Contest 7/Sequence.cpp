#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1000005;
const int ma=15;
const LL q=1e9+7;

struct Matrix
{
    int n,m;
    LL a[ma][ma];
    void clear()
    {
        n=m=0;
        memset(a,0,sizeof(a));
    }
    Matrix operator+(const Matrix &b)const
    {
        Matrix tmp;
        tmp.n=n;
        tmp.m=m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                tmp.a[i][j]=(a[i][j]+b.a[i][j])%q;
            }
        }
        return tmp;
    }
    Matrix operator-(const Matrix &b)const
    {
        Matrix tmp;
        tmp.n=n;
        tmp.m=m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                tmp.a[i][j]=(a[i][j]-b.a[i][j])%q;
            }
        }
        return tmp;
    }
    Matrix operator*(const Matrix &b)const
    {
        Matrix tmp;
        tmp.clear();
        tmp.n=n;
        tmp.m=b.m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<b.m;j++)
            {
                for(int k=0;k<m;k++)
                    tmp.a[i][j]=(tmp.a[i][j]+a[i][k]*b.a[k][j])%q;
            }
        }
        return tmp;
    }

};
Matrix ksm(Matrix A,Matrix b,LL i)
{
    Matrix temp=A;
    //temp.clear();
   // printf("temp= %lld %lld %lld\n",temp.a[0][0],temp.a[0][1],temp.a[0][2]);
   /* for(int k=0;k<=2;k++)
    {
        for(int j=0;j<=2;j++)
        {
            printf("%d ",b.a[k][j]);
        }
        printf("\n");
    }*/
    while(i>0)
    {
        if(i&1)
        {
            temp=temp*b;
        }
        b=b*b;
    /*    for(int k=0;k<=2;k++)
        {
            for(int j=0;j<=2;j++)
            {
                printf("%d ",b.a[k][j]);
            }
            printf("\n");
        }*/
        i/=2;
   //     printf("temp= %lld %lld %lld\n",temp.a[0][0],temp.a[0][1],temp.a[0][2]);

    }
    return temp;
}
LL k[maxn];
LL k_len[maxn];
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL A,B,C,D,P,n;
        scanf("%lld%lld%lld%lld%lld%lld",&A,&B,&C,&D,&P,&n);
        if(n==1)
        {
            printf("%d\n",A);
        }
        else if(n==2)
            printf("%d\n",B);
        if(n<=2)
            continue;
        Matrix t;
        t.clear();
        t.n=3;
        t.m=3;
        t.a[0][0]=D;
        t.a[0][1]=1;
        t.a[1][0]=C;
        t.a[2][0]=1;
        t.a[2][2]=1;


        int th=1;
      //  printf("start\n");
        memset(k,0,sizeof(k));
        memset(k_len,0,sizeof(k_len));
        //LL tn=n;
        LL l,r=n;
        for(LL i=0;i<=P;i++)
        {
           // printf("i=%d\n",i);
            if(i==0)
            {
                if(r>P)
                {
                    k[th]=0;
                    k_len[th]=n-P;
                    th++;
                    r=P;
                }
            }
            else
            {
                k[th]=i;
                l=P/(i+1);
              //  printf("-%lld %lld\n",l,r);
                if(l==0)
                    l=1;
                else
                    while(P/l!=i && l<=r)
                    {
               //         printf("-- %lld %lld %lld\n",l,r,i);
                        l++;
                    }
                if(l>r && r>=1 && l<=10000LL)
                    break;
                if(l>r)
                    continue;
                k_len[th++]=r-l+1;

                if(k_len[th-1]<=1)
                    break;
                if(l<=10000LL)
                    break;
                r=l-1;
                if(r<=0)
                    break;
            }
        }
        l--;
     //   printf("$%lld\n",l);
        while(l>0)
        {
            if(P/l==k[th-1])
                k_len[th-1]++;
            else
            {
                k[th]=P/l;
                k_len[th++]=1;
            }
            l--;
        }
     //   for(int i=1;i<th;i++)
     //   {
     //       printf("%lld %lld \n",k[i],k_len[i]);
     //   }
        Matrix G2;
        G2.n=1;
        G2.m=3;
        G2.a[0][0]=B;
        G2.a[0][1]=A;
        LL ned=2;
      //   printf("GG\n");
         int flag=1;
         LL tn=n;
        for(int i=th-1;i>=1;i--)
        {
            if(ned>0)
            {
                if(k_len[i]>ned)
                {
                    k_len[i]-=ned;
                    ned=0;

                }
                else
                {
                    ned-=k_len[i];
                    continue;
                }
            }
            tn--;

            if(flag==1)
            //printf("i==%d %lld\n",th-i,k[i]);
            flag=0;
            LL tk=k[i];
            LL n=k_len[i];
            G2.a[0][2]=tk;
          //  printf("G2= %lld %lld %lld\n",G2.a[0][0],G2.a[0][1],G2.a[0][2]);
            G2=ksm(G2,t,n);
             if(tn==0)
                break;
        }
        printf("%lld\n",G2.a[0][0]);

    }

    return 0;
}
