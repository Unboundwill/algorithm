/*
ID:selfcon2
LANG:C++
PROB:milk3
*/
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("milk3.in");
ofstream fout("milk3.out");
struct node{int x[3];};
queue<node> q;
static int cap[3],f[30][30][30];
void exchange(int i,int j,int k)
{
    node t,tem;
    tem=q.front();
    if((tem.x[i]!=0)&&(tem.x[j]<cap[j]))
    {
        if(tem.x[i]<=cap[j]-tem.x[j])
        {
            t.x[i]=0;t.x[j]=tem.x[j]+tem.x[i];t.x[k]=tem.x[k];
            if(!f[t.x[0]][t.x[1]][t.x[2]]){f[t.x[0]][t.x[1]][t.x[2]]=1;q.push(t);}
        }
        else
        {
            t.x[i]=tem.x[i]+tem.x[j]-cap[j];t.x[j]=cap[j];t.x[k]=tem.x[k];
            if(!f[t.x[0]][t.x[1]][t.x[2]]){f[t.x[0]][t.x[1]][t.x[2]]=1;q.push(t);}
        }
    }
}
int main()
{
    static int i,j,flag,ans[30];
    node tem;
    fin>>cap[0]>>cap[1]>>cap[2];
    tem.x[0]=0;tem.x[1]=0;tem.x[2]=cap[2];f[0][0][cap[2]]=1;
    q.push(tem);
    while(!q.empty())
    {
        exchange(1,2,0);
        exchange(1,0,2);
        exchange(2,0,1);
        exchange(2,1,0);
        exchange(0,1,2);
        exchange(0,2,1);
        q.pop();
    }
    for(i=0;i<=cap[1];i++)
        for(j=0;j<=cap[2];j++)ans[j]+=f[0][i][j];
    flag=0;
    for(i=0;i<=cap[2];i++)
        if(ans[i])
        {
            if(flag)fout<<" ";else flag=1;
            fout<<i;
        }
    fout<<endl;
    return 0;
}
