#include<bits/stdc++.h>
# define F(i) for(long long i=0;i<=2;i++)
using namespace std;
const long long mod=1000000007;
long long tr(long long i,long long j,long long k)
{
    return i*3*3+j*3+k;
}
bool ok(long long n11,long long n12,long long n13)
{
    long long n1=n11+1;
    long long n2=n12+1;
    long long n3=n13+1;
    if(n1==1)
    {
        if(n2==1 && n3==1)
            return false;
        if(n2==3 && n3==2)
            return false;
    }
    else if(n1==2)
    {
        if(n2==3 && n3==1)
            return false;
        if(n2==2 && n3==2)
            return false;
    }
    else if(n3==3)
        return false;
    return true;
}
struct Matrix
{
    long long n,m;
    long long a[30][30];
    void clear()
    {
        n=m=0;
        memset(a,0,sizeof(a));
    }
    Matrix operator +(const Matrix &b) const
    {
        Matrix tmp;
        tmp.clear();
        tmp.n=n;
        tmp.m=m;
        for(long long i=0;i<n;i++)
            for(long long j=0;j<n;j++)
            {
                tmp.a[i][j]=a[i][j]+b.a[i][j];
            }
        return tmp;
    }
    Matrix operator *(const Matrix &b) const
    {
        Matrix tmp;
        tmp.clear();
        tmp.n=n;
        tmp.m=m;
        for(long long i=0;i<n;i++)
            for(long long j=0;j<m;j++)
            {
                for(long long k=0;k<m;k++)
                {
                    tmp.a[i][j]=(a[i][k]*b.a[k][j]+tmp.a[i][j])%mod;
                }
            }
        return tmp;
    }
}ma[45],st,k;

long long ksm(long long n)
{
    k.clear();
    k.n=1;
    k.m=27;
    k=k+st;
    if(n==2)
        return 9;
    else if(n==1)
        return 3;
    else if(n==3)
        return 20;
    else
    {
        n=n-3;
        int cnt=1;
        while(n>0)
        {
            if(n%2==1)
                st=st*ma[cnt];
            cnt++;
            //printf("sskk\n");
            /*printf("ma¡ª\n");
            F(I)F(J)F(K)
            {
                printf("%d:",tr(I,J,K));
                F(i)F(j)F(k)
                    printf("%d-%d\t",tr(i,j,k),ma.a[tr(I,J,K)][tr(i,j,k)]);
                printf("\n");
            }*/
           /* printf("st¡ª\n");
            F(i)F(j)F(k)
                printf("%d-%d\t",tr(i,j,k),st.a[0][tr(i,j,k)]);
            printf("\n");*/
            n/=2;
        }
    }
    long long ans=0;
    for(long long i=0;i<27;i++)
        ans=(st.a[0][i]+ans)%mod;
    return ans;
}


int main ()//3 9 20 46 106 244
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=43;i++)
    {
        ma[i].clear();
        ma[i].n=ma[i].m=27;
    }
    F(i)
        F(j)
            F(k)
                F(f)
                {
                    if(ok(i,j,k) && ok(j,k,f))
                    {
                        long long s=tr(i,j,k);
                        long long ed=tr(j,k,f);
                        ma[1].a[ed][s]=1;
                    }
                }
    for(int i=2;i<=43;i++)
    {
        ma[i]=ma[i-1]*ma[i-1];
    }
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        //memset(dp,0,sizeof(dp));
        //memset(ans,0,sizeof(ans));
        st.clear();

        st.n=1;st.m=27;


        /*printf("ma\n");
        F(I)F(J)F(K)
        {
            printf("%d:",tr(I,J,K));
            F(i)F(j)F(k)
                printf("%d-%d\t",tr(i,j,k),ma.a[tr(I,J,K)][tr(i,j,k)]);
            printf("\n");
        }*/
        F(i)
            F(j)
                F(k)
                if(ok(i,j,k))
                {
                    long long s=tr(i,j,k);
                    st.a[0][s]=1;
                }
        /*printf("st0\n");
            F(i)F(j)F(k)
                printf("%d-%d\t",tr(i,j,k),st.a[0][tr(i,j,k)]);
            printf("\n");*/
        printf("%lld\n",ksm(n));
    }
    return 0;
}
