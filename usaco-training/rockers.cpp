/*
ID:selfcon2
LANG:C++
PROG:rockers
*/
#include <fstream>
using namespace std;
ifstream fin("rockers.in");
ofstream fout("rockers.out");
int main()
{
	static int i,j,k,n,t,m,flag,sum,v[100],vis[100],f[25][25][25],maxv,maxn,l,r;
	fin>>n>>t>>m;
	for(i=1;i<=n;i++)fin>>v[i];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			sum=0;flag=j-i+1;
			for(k=i;k<=j;k++){sum+=v[k];vis[k]=0;}
			while(sum>t)
			{
				maxv=0;maxn=0;
				for(k=i;k<=j;k++)if(!vis[k]&&v[k]>maxv){maxv=v[k];maxn=k;}
				vis[maxn]=1;sum-=maxv;
				flag--;
			}
			f[1][i][j]=flag;
		}
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)fout<<f[1][i][j]<<" ";
		fout<<endl;
		
	}*/
	for(i=2;i<=m;i++)
		for(l=1;l<=n;l++)
			for(r=l;r<=n;r++)
			{
				f[i][l][r]=f[1][l][r];
				for(k=l+1;k<=r;k++)
					f[i][l][r]=max(f[i][l][r],f[i-1][l][k-1]+f[1][k][r]);
			}
	/*for(i=1;i<=m;i++)
	{
		fout<<endl;
		for(j=1;j<=n;j++)
		{	for(k=1;k<=n;k++)fout<<f[i][j][k]<<" ";fout<<endl;}
	}*/
	fout<<f[m][1][n]<<endl;
	return 0;
}



