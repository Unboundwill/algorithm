/*
ID:selfcon2
LANG:C++
PROB:milk2
*/
#include <fstream>
using namespace std;
ifstream fin("milk2.in");
ofstream fout("milk2.out");
int n,maxt,mint,i,j,tot,flag,x,y;
static int hash[1000000],ans[2];
int main()
{
    fin>>n;maxt=0;mint=1000000;
    for(i=0;i<n;i++)
    {
        fin>>x>>y;
        if(y>maxt)maxt=y;if(x<mint)mint=x;
        for(j=x+1;j<=y;j++)hash[j]=1;
    }
    tot=0;flag=hash[1];
    for(j=mint+1;j<=maxt+1;j++)
    {
        if(hash[j]==flag){tot++;}
        else
        {
            if(tot>ans[flag])ans[flag]=tot;
            tot=1;flag=hash[j];
        }
    }
    fout<<ans[1]<<" "<<ans[0]<<endl;
    return 0;
}





