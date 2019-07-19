//https://codeforces.com/gymRegistration/101653/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define used_t 1
const ll q=1e9+7;
const ll maxn= 100000;
const ll INF=1e16;
const double eps=1e-8;
const double PI=acos(-1);

ll ksm(ll a,ll b,ll qq=q)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%q;
        a=a*a%q;
        b/=2;
    }
    return ans;
}

struct BigInteger{
    int A[85];
    enum{MOD = 10000};
    BigInteger(){memset(A, 0, sizeof(A)); A[0]=1;}
    void set(int x){memset(A, 0, sizeof(A)); A[0]=1; A[1]=x;}
    void print(){
        printf("%d", A[A[0]]);
        for (int i=A[0]-1; i>0; i--){
            if (A[i]==0){printf("0000"); continue;}
            for (int k=10; k*A[i]<MOD; k*=10) printf("0");
            printf("%d", A[i]);
        }
        printf("\n");
    }
    int& operator [] (int p) {return A[p];}
    const int& operator [] (int p) const {return A[p];}
    BigInteger operator + (const BigInteger& B){
        BigInteger C;
        C[0]=max(A[0], B[0]);
        for (int i=1; i<=C[0]; i++)
            C[i]+=A[i]+B[i], C[i+1]+=C[i]/MOD, C[i]%=MOD;
        if (C[C[0]+1] > 0) C[0]++;
        return C;
    }
    BigInteger operator * (const BigInteger& B){
        BigInteger C;
        C[0]=A[0]+B[0];
        for (int i=1; i<=A[0]; i++)
            for (int j=1; j<=B[0]; j++){
                C[i+j-1]+=A[i]*B[j], C[i+j]+=C[i+j-1]/MOD, C[i+j-1]%=MOD;
            }
        if (C[C[0]] == 0) C[0]--;
        return C;
    }
};

char str[100];
BigInteger dpxiao[100][10];
//BigInteger dpdeng[100][10];
ll dpdeng[100][10];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
#endif // yyhao


#ifdef used_t
ll t;
cin>>t;
for(ll ii=1;ii<=t;ii++)
{
    scanf("%s",str);
#endif // used_t
    ll len=strlen(str);
    int fa=1;
    for(int i=0;str[i+1];i++)
    {
        if(str[i]>str[i+1])
        {
            fa=0;
        }
    }
    if(fa==0)
    {
        printf("-1\n");
    continue;
    }
    BigInteger a,b,tmp;
    BigInteger cnt;
    BigInteger shi;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<10;j++)
            dpxiao[i][j].set(0),dpdeng[i][j]=0;
    }
    shi.set(10);


    a.set(0);
    cnt.set(0);
    b.set(1);
    //cnt.set(str[0]-'0');
    for(int i=0;i<str[0]-'0';i++)
    {
        dpxiao[0][i].set(1);
       //  cout<<0<<" "<<i<<":";
       //     dpxiao[0][i].print();
    }

    for(int i=0;str[i];i++)
        dpdeng[i][str[i]-'0']=1;

    //cnt.print();

    for(int i=1;str[i];i++)
    {
        ll ma=str[i]-'0';
        for(int now=0;now<=9;now++)
        {
            if(now>ma)
            {
                for(int bef = 0;bef <= now ;bef++)
                {
                    //dpxiao[i][sj]=dpxiao[i][sj]+dp[i-1][si];
                    dpxiao[i][now]=dpxiao[i][now]+dpxiao[i-1][bef];
                }

            }
            else
            {
                for(int bef = 0;bef <= now ;bef++)
                {
                    //dpxiao[i][sj]=dpxiao[i][sj]+dp[i-1][si];
                    dpxiao[i][now]=dpxiao[i][now]+dpxiao[i-1][bef];
                }
                for(int bef =0;bef<=now;bef++)
                {
                    if(dpdeng[i-1][bef] && (now<ma) )
                    {
                        dpxiao[i][now]=dpxiao[i][now]+b;
                      //  cout<<i<<" "<<now<<" "<<"jiao ";
                       // dpxiao[i][now].print();
                    }
                }

                dpdeng[i][ma]=1;
            }
//            cout<<i<<" "<<now<<":";
//            dpxiao[i][now].print();
        }
    }

    cnt.set(0);
    //cout<<len-1<<endl;
    for(int i=0;i<=9;i++)
    {
        cnt=cnt+dpxiao[len-1][i];
    }
    cnt=cnt;
    cnt.print();


#ifdef used_t
}
#endif // used_t
}

