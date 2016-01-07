/*
ID:selfcon2
LANG:C++
PROG:agrinet
*/
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream fin("agrinet.in");
ofstream fout("agrinet.out");
static int i,j,n,tot=0,ans=0,a[105][105],r[10005],u[10005],v[10005],w[10005],p[105];
int cmp(const void * x,const void * y)
{
	return w[*(int *)x]-w[*(int *)y];	
}
int find(int x)
{
	if(p[x]==x)return x;
	else
	{
		p[x]=find(p[x]);
		return find(p[x]);
	}
}
int main()
{
	fin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			fin>>a[i][j];
	tot=0;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				r[tot]=tot;
				u[tot]=i;v[tot]=j;w[tot]=a[i][j];
				tot++;
			}	
		}
	qsort(r,tot,sizeof(r[0]),cmp);
	for(i=0;i<n;i++)p[i]=i;
	for(i=0;i<tot;i++)
	{
		int e=r[i];
		if(find(u[e])!=find(v[e]))
		{
			ans+=w[e];p[find(u[e])]=find(v[e]);
		}
	}
	fout<<ans<<endl;
	return 0;
}

