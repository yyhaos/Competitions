#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+5;
list<int> L;
char s[maxn];
int main(void)
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    L.clear();
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++)
        L.push_back(s[i]-'A');
    L.push_back(-3);L.push_back(-3);L.push_back(-1);L.push_back(-10);
    L.push_front(-1);L.push_front(-2);L.push_front(-3);L.push_front(-30);
    //list<int>::bidirectional_iterator_tag p;
    int now=-4,last=-4;
    int cnt=1;
    int ans=0;
    for(auto p=L.begin();p!=L.end();){
        now=*p;
//        printf("%d\n",*p);
        if(now==last){
            cnt++;
            if(cnt==3){
                p=L.erase(p);
                p--;
                p=L.erase(p);
                p--;
                p=L.erase(p);
                p--;
                p--;p--;
                ans++;
                cnt=1;
                last=now=*p;
                cout<<L<<endl;
            }
            else p++;
        }
        else{
            cnt=1;
            p++;
        }
        last=now;
    }
    printf("%d\n",ans);
}
