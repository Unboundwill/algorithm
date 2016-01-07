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
    if(row!=upperlim)                    //�����δ����
    {
        pos=upperlim&(~(row|ld|rd));     
        //ѡ�����п��Էŵĵط�  
        //(row|ld|rd)�õ����в��ܷŵ�λ�� ȡ~�õ��ܷŵ�λ�� �ٺ�upperlimȡ&�õ�nλ
        while(pos!=0)                   //�����û�а������ܷŵĵط�����
        {
            p=pos&(-pos);                
            //Ū��Ҫ�ŵ���һλ �ܷ�Ϊ1 ���ܷ�Ϊ0
            //ȡ-pos��Ϊ(not pos)+1,ȡnot��β�����ܷŵĶ���Ϊ1
            //���һ���ܷŵ�+1����1����+1��β�����ܷŵĶ����0��
            //����ֻ�иշŵ���һλ��ԭ����ͬ��&��ֻ����һλΪ1
            pos=pos-p;                   //������δ���Ե���ȥ��
            test(row+p,(ld+p)<<1,(rd+p)>>1);//���Ű�
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
