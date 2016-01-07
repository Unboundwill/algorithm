/*
ID:selfcon2
LANG:C++
PROG:bigbrn
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("bigbrn.in");
ofstream fout("bigbrn.out");
static bool a[1005][1005];
static int n,t,f[1005][1005],ans;
int main()
{
	fin>>n>>t;
	for(int i=0;i<t;i++)
	{
		int x,y;
		fin>>x>>y;
		a[x][y]=true;
	}	
	for(int i=0;i<=n+1;i++)
	{
		a[0][i]=true;
		a[n+1][i]=true;
		a[i][0]=true;
		a[i][n+1]=true;
	}	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!a[i][j])
			{
				f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
				ans=max(f[i][j],ans);
			}	
	fout<<ans<<endl;
	return 0;
}
