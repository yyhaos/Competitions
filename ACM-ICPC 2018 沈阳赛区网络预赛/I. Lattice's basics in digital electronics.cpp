#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
char fi[maxn*4];
char s[maxn];
char tra[maxn*4];
int has[100000];

void trans()
{
    int c=0;
    int len_str = strlen(s);
    for(int i=0;i<len_str;i++)
    {
        int th=s[i]-'0';
        if(th>=10 || th<0)
        {
            th=s[i]-'a';
            if(th>=10 || th<0)
                th=s[i]-'A';
            th+=10;
        }
        for(int j=1;j<=4;j++)
        {
            if(th%2==1)
                tra[i*4+4-j]='1';
            else tra[i*4+4-j]='0';
            th/=2;
        }
    }
    //tra[len_str*4] = '\0';
}

char get_fi()
{
    int th=0;
    int len=strlen(tra);
    for(int i=0;i+8<len;i+=9)
    {
        int flag=0;
        for(int k=0;k<=7;k++)
        {
            flag^=(tra[i+k]-'0');

        }
        if(flag^(tra[i+8]-'0')==1)
        {
            for(int k=0;k<=7;k++)
            {
                fi[th++]=tra[i+k];
            }
        }
    }
    //fi[th] = '\0';
}

int get_num(string b){
    int res = 1;
    for (int i=0;i<b.length();i++){
        if (b[i]-'0'==0){
            res<<=1;
        }else{
            res = res<<1|1;
        }
    }
    return res;
}

void get_ans(int m){
    string ans = "";
    int cnt = 0;
    string buf = "";
    int len = strlen(fi);
    for (int i=0;i<len;i++){
        buf += fi[i];
        int mem = get_num(buf);
        if (has[mem]!=-1){
            char c = has[mem];
            ans += c;
            buf = "";
            cnt++;
            if (cnt>=m){
                break;
            }
        }
    }
    printf("%s\n",ans.c_str());
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(has,-1,sizeof(has));
        int m,n;
        scanf("%d%d",&m,&n);
        for (int i=1;i<=n;i++){
            char spp[13];
            int v;
            scanf("%d%s",&v,spp);
            string spp2 = spp;
            has[get_num(spp2)] = v;
        }
        scanf("%s",s);
        trans();
        //printf("%s\n",tra);
        get_fi();
        //printf("%s\n",fi);
        get_ans(m);
    }
    return 0;
}
