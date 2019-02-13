#include<bits/stdc++.h>
using namespace std;
char s[1000005];
stack <char > q;
int main ()
{
    //q.clear();
    int ans=0;
    char top;
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        if(q.empty())
        {
            q.push(s[i]);
            continue;
        }
        else
        {
            if(q.top()==s[i])
            {
                q.pop();
                ans+=10;
            }
            else
            {
                q.push(s[i]);
            }
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        cnt++;
        q.pop();
    }
    cout<<ans+cnt/2*5;
    return 0;
}
