/*
ID:selfcon2
LANG:C++
PROB:checker
*/
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
ifstream fin("checker.in");
ofstream fout("checker.out");
static int a[20],hash[20],n,upperlim,ans;
void dfs(int x)
{
    int i,j,could;
    if(ans>=4)return;
    if(x==n+1)
    {
        ans++;
        if(ans<=3){for(i=1;i<=n;i++){if(i-1)fout<<" ";fout<<a[i];}fout<<endl;}
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(!hash[i])
        {
            could=1;
            for(j=1;j<x;j++)if(x-j==abs(i-a[j])){could=0;break;}
            if(could){a[x]=i;hash[i]=1;dfs(x+1);hash[i]=0;}
        }
    }
}
void test(int row,int ld,int rd)
{
    int pos,p;
    if(row!=upperlim)                    //如果尚未放完
    {
        pos=upperlim&(~(row|ld|rd));     
        //选出所有可以放的地方  
        //(row|ld|rd)得到所有不能放的位置 取~得到能放的位置 再和upperlim取&得到n位
        while(pos!=0)                   //如果还没有把所有能放的地方试完
        {
            p=pos&(-pos);                
            //弄出要放的那一位 能放为1 不能放为0
            //取-pos即为(not pos)+1,取not后尾部不能放的都成为1
            //最后一个能放的+1后变成1，而+1后尾部不能放的都变成0了
            //这样只有刚放的那一位与原来相同，&后只有这一位为1
            pos=pos-p;                   //把它从未尝试的中去除
            test(row+p,(ld+p)<<1,(rd+p)>>1);//接着摆
        }
    }
    else ans++;
}
int main()
{
    fin>>n;ans=0;
    dfs(1);
    ans=0;upperlim=(1<<n)-1;
    test(0,0,0);
    fout<<ans<<endl;
    return 0;
}
