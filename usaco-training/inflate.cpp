/*
ID:selfcon2
LANG:C++
PROG:inflate
*/
#include <fstream>
using namespace std;
ifstream fin("inflate.in");
ofstream fout("inflate.out");
static int f[10001],w[10001],v[10001],ans=0,i,k,n,m;
int main()
{
	fin>>m>>n;
	for(i=0;i<n;i++)fin>>w[i]>>v[i];
	for(i=0;i<n;i++)
			for(k=v[i];k<=m;k++)
				f[k]=max(f[k],f[k-v[i]]+w[i]);
				//if(f[k]<f[k-v[i]]+w[i])f[k]=f[k-v[i]]+w[i];
	for(i=1;i<=m;i++)if(f[i]>ans)ans=f[i];
	fout<<ans<<endl;
	return 0;
}


