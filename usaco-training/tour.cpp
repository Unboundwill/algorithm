/*
ID:selfcon2
LANG:C++
PROG:tour
*/
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
ifstream fin("tour.in");
ofstream fout("tour.out");
static bool a[200][200];
static int n,m,ans=1,f[200][200];
static string name[200];
int find(string s)
{
	for(int i=0;i<n;i++)if(s==name[i])return i;	
}
int main()
{
	fin>>n>>m;
	for(int i=0;i<n;i++)fin>>name[i];
	for(int i=0;i<m;i++)
	{
		string s1,s2;
		fin>>s1>>s2;
		a[find(s1)][find(s2)]=1;
		a[find(s2)][find(s1)]=1;
	}	
	f[0][0]=1;
	for(int j=1;j<=n-2;j++)
		if(a[0][j])f[0][j]=2;
	for(int i=0;i<n-2;i++)
	{	
		for(int j=i+1;j<=n-2;j++)
			if(f[i][j])
				for(int k=j+1;k<=n-2;k++)
				{
					if(a[i][k])
						f[j][k]=max(f[j][k],f[i][j]+1);
					if(a[j][k])
						f[i][k]=max(f[i][k],f[i][j]+1);
				}	
	}	
	for(int i=0;i<=n-2;i++)
		for(int j=i;j<=n-2;j++)
			if(a[i][n-1]&&a[j][n-1])
				ans=max(ans,f[i][j]+1);
	fout<<ans<<endl;
	return 0;
}
