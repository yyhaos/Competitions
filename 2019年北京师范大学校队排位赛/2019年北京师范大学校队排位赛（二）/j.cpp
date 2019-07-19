#include<bits/stdc++.h>
using namespace std;

int main()
{

    #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhaos

    int a[100]={0,1,2,3,4,5};

    char s[100];
    int b[6][6];
 int ff=0;   memset(b,-1,sizeof(b));

    int t1,t2,t3,t4;
    for(int i=1;i<=5;++i){
        cin>>s;

        t1=s[0]-'A'+1;
        t2=s[2]-'A'+1;
//cout<<t1<<' '<<t2<<endl;
        if(s[1]=='<'){

            if(  b[t1][t2]==1||b[t2][t1]==0  )
                //goto labpr;
                ff=1;

            b[t1][t2]=0;b[t2][t1]=1;
        }

        else if(s[1]=='>'){

            if(b[t1][t2]==0||b[t2][t1]==1)
                //goto labpr;
                ff=1;

            b[t1][t2]=1;b[t2][t1]=0;

        }

    }

//
//for(int i=1;i<=5;++i){
//    for(int j=1;j<=5;++j)
//    cout<<b[i][j]<<' ';cout<<endl;
//}
//


    int fl=0;
    if(ff==0)while(next_permutation(a+1,a+6)){


//for(int i=1;i<=5;++i)cout<<a[i]<<' ';cout<<endl;
        int err=0;
        for(int i=1;i<=5;++i){
            for(int j=1;j<=5;++j){

                if(b[i][j]==1 && a[i]<a[j])err=1;
                if(b[i][j]==0 && a[i]>a[j])err=1;

//                if(err)break;
            }
//            if(err)break;
        }

        if(!err){
            for(int i=1;i<=5;++i){
                char uuu;
                uuu=a[i]+'A'-1;
                cout<<uuu;
            }
//            cout<<endl;
            goto lab;
        }


    }



labpr : cout<<"impossible";


lab: ;

    return 0;
}
