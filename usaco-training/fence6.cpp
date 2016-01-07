/*
ID:selfcon2
LANG:C++
PROG:fence6
*/
#include <fstream>
using namespace std;
ifstream fin("fence6.in");
ofstream fout("fence6.out");
const int INF=1<<25;
static int n,a[200][200],b[200][200],l[200],le[200][200],rig[200][200];
static int s,ans;
int main()
{
	//init	
	fin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)a[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		fin>>s;fin>>l[s];
		fin>>le[s][0]>>rig[s][0];
		for(int j=1;j<=le[s][0];j++)fin>>le[s][j];
		for(int j=1;j<=rig[s][0];j++)fin>>rig[s][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=le[i][0];j++)a[i][le[i][j]]=l[i]+l[le[i][j]];
		for(int j=1;j<=rig[i][0];j++)a[i][rig[i][j]]=l[i]+l[rig[i][j]];
	}	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)b[i][j]=a[i][j];
	//work
	ans=1<<30;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=le[k][0];i++)
		{
			int ii=le[k][i];
			if(ii<k)
			{
				for(int j=1;j<=rig[k][0];j++)
				{
					int jj=rig[k][j];
					if(jj<k)
						ans=min(ans,a[ii][jj]+b[k][ii]+b[k][jj]);
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	}
	fout<<ans/2<<endl;
	return 0;
}
