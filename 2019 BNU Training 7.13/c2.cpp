#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n;
char s[MAXN];
int main(void)
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("portals.in",stdin);
#endif
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        getchar();
        scanf("%s",s);
        printf("%s ",s);
        int sp,ep;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='s'){sp=i;}
            else if(s[i]=='e'){ep=i;}
        }
        char sl='*',sr='*',el='*',er='*';
        for(int i=sp-1;i>=0;i--)
        {
            if(s[i]!='.'){sl=s[i];break;}
        }
        for(int i=sp+1;i<n;i++)
        {
            if(s[i]!='.'){sr=s[i];break;}
        }
        for(int i=ep-1;i>=0;i--)
        {
            if(s[i]!='.'){el=s[i];break;}
        }
        for(int i=ep+1;i<n;i++)
        {
            if(s[i]!='.'){er=s[i];break;}
        }
        int ans=2;
//        printf("sl=%c sr=%c el=%c er=%c\n",sl,sr,el,er);
        if(abs(sp-ep)==1)ans=-1;//-1
        else if(el=='#'&&er=='#')ans=0;//0
        else if(el=='#'&&er=='*'||er=='#'&&el=='*')ans=min(ans,0);
        else if(sr=='#'&&sl=='#')ans=0;
        else if(sl=='*'&&sr=='#'||sl=='#'&&sr=='*')ans=min(ans,0);
        else if(sr=='e'||sl=='e')//1
        {
            if(sr=='e')
                if(sl!='o'||er!='o')ans=min(ans,1);
            if(sl=='e')
                if(sr!='o'||el!='o')ans=min(ans,1);
        }
//        printf("sl=%c sr=%c el=%c er=%c\n",sl,sr,el,er);
        else if(sl=='o'||sr=='o')
        {
            if(ep>0&&s[ep-1]=='o')ans=-1;
            if(ep<n-1&&s[ep+1]=='o')ans=-1;
            if(el=='o'&&er!='o'&&er!='s')ans=min(ans,1);//1
            if(el!='o'&&er=='o'&&el!='s')ans=min(ans,1);//1
        }
        printf("%d\n",ans);

    }

}
