/*
ID:selfcon2
LANG:C++
PROB:numtri
*/
#include <fstream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    int n,i,j,tem,maxn=0;
    static int a[1005][1005],b[1005][1005];
    memset(a,0,sizeof(a));memset(b,0,sizeof(b));
    fin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)fin>>a[i][j];
    b[1][1]=a[1][1];
    for(i=2;i<=n;i++)
        for(j=1;j<=i;j++)b[i][j]=max(b[i-1][j-1],b[i-1][j])+a[i][j];
    for(i=1;i<=n;i++)if(b[n][i]>maxn)maxn=b[n][i];
    fout<<maxn<<endl;
    return 0;
}
