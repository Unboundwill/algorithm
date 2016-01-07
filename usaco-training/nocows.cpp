/*
ID:selfcon2
LANG:C++
PROG:nocows
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("nocows.in");
ofstream fout("nocows.out");
static int n,k,h,m,i,f[205][105],b[205][105];
int main()
{
	fin>>n>>k;
	memset(f,0,sizeof(f));memset(b,0,sizeof(b));
	//f[i][j]表示由i个节点构成高度为j的子树的方案数，b[i][j]表示由i个节点构成高度不超过j的子树的方案数
	f[1][1]=1;f[3][2]=1;
	b[1][1]=1;
	b[1][2]=1;b[3][2]=1;
	for(h=3;h<=k;h++)
		for(m=1;m<=n;m++)
		{
			for(i=1;i<=m-2;i++)
			{
				f[m][h]+=f[i][h-1]*b[m-i-1][h-2]*2;
				f[m][h]+=f[i][h-1]*f[m-i-1][h-1];
				if(f[m][h]>9901)f[m][h]=9901+f[m][h]%9901;
			}
			b[m][h-1]=b[m][h-2]+f[m][h-1];
			if(b[m][h-1]>9901)b[m][h-1]=9901+b[m][h-1]%9901;
		}	
	fout<<f[n][k]%9901<<endl;	
	return 0;
}
