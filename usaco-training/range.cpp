/*
ID:selfcon2
LANG:C++
PROG:range
*/
#include <fstream>
using namespace std;
ifstream fin("range.in");
ofstream fout("range.out");
static int h[2][255][255],ans[255],n;
static char a[255][255];
int main()
{
	fin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)fin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;;k++)
			{
				if(a[i][j-k]!='1')break;
				h[1][j][k]+=h[0][j][k]+1;
				if(h[1][j][k]>=k+1)ans[k+1]++;
			}
		}
		for(int j=1;j<=n;j++)
			for(int k=0;k<=n;k++)
			{
				h[0][j][k]=h[1][j][k];h[1][j][k]=0;
			}
	}
	for(int i=2;i<=n;i++)
		if(ans[i])fout<<i<<" "<<ans[i]<<endl;
	return 0;
}

