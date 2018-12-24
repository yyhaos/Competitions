//2018-2019 ACM-ICPC, Asia Jiaozuo Regional Contest
//B. Ultraman vs. Aodzilla and Bodzilla

//题意就是给AB两个怪物 有各自的血量和攻击力，然后你去杀两个怪物 ，你第i次攻击的攻击力是i，你一次只能攻击一个怪物
//怪物只要活着就会攻击你，每一次怪物先攻击
//求一种攻击序列 来保证你受到的伤害和最小 且在保证受到伤害和最小的情况下 求出字典序最小的攻击序列。
//输出收到的最小伤害 和攻击序列 用AB字符串来表示 第i个字符表示第i次攻击的目标

/*
样例
CASE
HP_A HP_B AD_A AD_B

Input
2
5 15 5 25
5 15 25 5

Output
155 BBBBBA
105 AAABBB

*/

//贪心的思想 ：一定是先斩杀一个怪物 再去杀另一个怪物。planA和planC就是这种思想
//但是 在斩杀第一个怪物的时候， 可能有伤害的浪费。比如在砍第一个怪物最后一刀时，第一个怪物只有1点血量，但是你的攻击力已经有1000了，就浪费了999点伤害。
//策略： 需要把杀第一个怪物的多余伤害匀给第二个怪物，去削减它的血量。planB 和 planC
//难点在于：    1.多余伤害匀给第二个怪物后 既可能减少杀死它的次数、也可能减少不了。
//              2.由于字典序最小的约束，一些结果相同 但是攻击顺序不同的策略需要比较
//              3.两个怪物都可能作为第一个杀死的对象，但是二者由于字典序最小的约束，策略有很大差异。
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll da(ll start,ll day)  //计算从start次到start+day-1次闭区间 共day次中 的伤害和
{
    return (2*start+day-1)*day/2LL;
}
ll fi(ll tar,ll start)  //计算从start次开始 连续k次中，要打到tar伤害时最少需要的次数k_min 二分法
{
    ll mid,l=0,r=100000000;
    while(r>l)
    {
        mid=(r+l)/2;
        ll D=da(start,mid);
        if(D==tar)
        {
            if(mid>0)
                return mid;
            else
                return 0;
        }
        else if(D>tar)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    ll ans;
    for(ans=l-3 ; ans<= r+3;ans++)
    {
        if(ans<0)
            continue;
        if( da(start,ans)>=tar)
            return ans;
    }
    if(ans>r+3)
        cout<<"error ans>r+3\n"<<endl;
    return -1;
}
ll planA(string &ans,const ll& pa,const ll& pb,const ll& aa,const ll& ab)
{
    /*
        先搞A 直到A死亡再转B
    */
    ll damagehe=0;
    ll adie=fi(pa,1); //A死的至少天数 这个策略下要保证 a在这一天时死亡
   // ll ayu = da(1,adie)-pa;//杀A多出来的伤害
        ans = "";
        for(int i=1;i<=adie;i++)
        {
            ans+="A";
        }
        damagehe+=adie*(aa+ab);
        ll bdie=fi(pb,adie+1);
        for(int i=1;i<=bdie;i++)
        {
            ans+="B";
        }
        damagehe+=bdie*ab;
     //   ans+="\0";
        return damagehe;

}
ll planB(string &ans,const ll& pa,const ll& pb,const ll& aa,const ll& ab)
{
    /*
    先搞A 把多余的伤害转移给B
    */
    ll damagehe=0;
    ll adie=fi(pa,1); //A死的至少天数 这个策略下要保证 a在这一天时死亡
    ll ayu = da(1,adie)-pa;//杀A多出来的伤害
    ll trans=min(pb,ayu);   //匀给B的伤害
    if(trans==pb)   //A中余出来的伤害大于b的血量-->不如先搞B 再在B前插入A 见planD 可以直接return maxn
    {
        return 99999999999999999999LL;
    }
    else    //A中余出来的伤害比B的血量小 策略是 直接把trans这一天拿去打B就好了，因为其他方法均会在trans前一天有B就会字典序大 或者打出超出trans的伤害
    {
        ans="";
        for(int i=1;i<=trans-1;i++)
        {
            ans+="A";
        }
        ans+="B";
        for(int i=trans+1;i<=adie;i++)
        {
            ans+="A";
        }
        damagehe+=adie*(ab+aa);
        ll bdie=fi(pb-trans,adie+1);
        for(int i=1;i<=bdie;i++)
        {
            ans+="B";
        }
        damagehe+=bdie*ab;
     //   ans+="\0";
        return damagehe;
    }
}

ll planC(string &ans,const ll& pa,const ll& pb,const ll& aa,const ll& ab)
{
    /*
    先搞B 直到B死 再搞A
    */
    ll bdie=fi(pb,1);//b最多死亡的天数 这个策略下要保证 b在这一天时死亡
    ll adie=fi(pa,bdie+1);
    ans="";
    for(int i=1;i<=bdie;i++)
    {
        ans+="B";
    }
    for(int i=1;i<=adie;i++)
    {
        ans+="A";
    }
    ll Da=0;
    Da+=bdie*(aa+ab);
    Da+=adie*aa;
  //  ans+="\0";
    return Da;
}

ll planD(string &ans,const ll& pa,const ll& pb,const ll& aa,const ll& ab)
{
    /*
    先搞B 把B溢出的伤害给A
    */
    ll bdie=fi(pb,1);   //b最多死亡的天数 这个策略下要保证 b在这一天时死亡
    //ll adie=fi(pa,bdie+1);
    ans="";
    ll byu=da(1,bdie)-pb;
    if(byu==0)
        return 999999999999900000LL;//就是planC
    else
    {
        ll trans=min(byu,pa);
        if(trans==pa)  //A被B余出来的伤害打死   //不如planA
        {
            return 9999999999999999999999LL;
        }
        else//A活着 策略：1. 尽量取前k个作为A 2. 保证B的情况下 尽量减少a的死亡时间 但是 a的死亡时间最多提前一天。（pa>byu>bdie）
        {
            ll adie1=fi(pa,bdie+1);//不减少 A 的死亡天数
            ll adie2=fi(pa-byu,bdie+1);//减少后 A 的死亡天数  // adie1 >= adie2 >= adie1-1 否则byu>bdie
            ll takedamage=da(bdie+1,adie2);//死亡天数小的时候 承受的伤害
            ll least=pa-takedamage;//保证死亡天数小的时候，最少需要匀出来的伤害 核心 （least<=0 就说明A的死亡时间减少不了 即adie1==adie2）

            ll geia=fi(byu+1,1)-1;//把最多前geia天算出来  再多就超出了byu，超出后b就给不了伤害了 核心
            ll dagei=da(1,geia);//把前geia天的伤害算出来

            if(dagei>=least) //前geia天可以完成任务->减少a的死亡时间 或者 a的死亡时间不需要减少（least<0）
            {
                for(int i=1;i<=geia;i++)
                {
                    ans+="A";
                }
                for(int i=geia+1;i<=bdie;i++)
                {
                    ans+="B";
                }
                ll Da=0;
                Da+=bdie*(aa+ab);
                for(int i=1;i<=adie2;i++)
                {
                    ans+="A";
                }
               // ans+="\0";
                Da+=adie2*aa;
                return Da;
            }
            else    //完不成任务 就是说least>0且需要更多伤害，策略是把geia这一天后延至正好的那一天。比赛时没想到这个策略 凉了 ，一上大巴车就想到了 气人
            {
                ll cha=least-dagei;
                for(int i=1;i<geia;i++)
                {
                    ans+="A";
                }
                for(int i=geia;i<geia+cha;i++)
                {
                    ans+="B";
                }
                ans+="A";   //把geia天 后延 至正好的那一天 //不会超过bdie 否则要么least<=0不会进入 要么trans>pa也不会进入这种情况
                for(int i=geia+cha+1;i<=bdie;i++)
                {
                    ans+="B";
                }
                for(int i=1;i<=adie2;i++)
                {
                    ans+="A";
                }
                //ans+="\0";
                ll Da=0;
                Da+=bdie*(aa+ab);
                Da+=adie2*aa;
                return Da;
            }
        }
    }
}


int main ()
{

    //cout<<fi(3,1);
    ll pa,pb,aa,ab;
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&pa,&pb,&aa,&ab);
        string a[7];
        ll sa[6];
        sa[1]=planA(a[1],pa,pb,aa,ab);
        sa[2]=planB(a[2],pa,pb,aa,ab);
        sa[3]=planC(a[3],pa,pb,aa,ab);
        sa[4]=planD(a[4],pa,pb,aa,ab);
        ll minn=99999999999999999LL;
//        for(int i=1;i<=4;i++)
//        {
//          //  cout<<sa[i]<<" "<<a[i]<<endl;
//            //minn=min(minn,sa[i]);
//        }
        for(int i=1;i<=4;i++)
        {
            minn=min(minn,sa[i]);
        }
        ll th=-1;
        for(int i=1;i<=4;i++)
        {
            if(sa[i]==minn)
            {
                if(th==-1)
                {
                    th=i;
                }
                else
                {
                    if(a[th]>a[i])
                        th=i;
                }
            }
        }
        printf("%lld ",sa[th]); //%s 不行
        cout<<a[th];
        printf("\n");
    }
    return 0;
}
