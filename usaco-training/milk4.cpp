/*
ID:selfcon2
LANG:C++
PROG:milk4
*/
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream fin("milk4.in");
ofstream fout("milk4.out");
static int q,p,v[100],f[20005],INF=1<<30;
static bool vis[20005][100];
int cmp(const void * x,const void * y)
{
	return *(int *)x-*(int *)y;
}
int main()
{
	fin>>q>>p;
	for(int i=0;i<p;i++)fin>>v[i];
	qsort(v,p,sizeof(v[0]),cmp);
	for(int i=1;i<=q;i++)
	{	
		f[i]=INF;
		for(int j=0;j<p;j++)
			for(int l=1;l*v[j]<=i;l++)
		{	
			if(vis[i-v[j]*l][j])
			{
				if(f[i]>f[i-v[j]*l])
				{
					f[i]=f[i-v[j]*l];
					memcpy(vis[i],vis[i-v[j]*l],sizeof(vis[i-v[j]*l]));
				}
				else if(f[i]==f[i-v[j]*l])
				{
					for(int k=0;k<p;k++)
						if(vis[i-v[j]*l][k]&&!vis[i][k])
						{
							memcpy(vis[i],vis[i-v[j]*l],sizeof(vis[i-v[j]*l]));
							break;
						}
						else if(vis[i][k]&&!vis[i-v[j]*l][k])break;
				}	
			}
			else
			{
				if(f[i]>f[i-v[j]*l]+1)
				{
					f[i]=f[i-v[j]*l]+1;
					memcpy(vis[i],vis[i-v[j]*l],sizeof(vis[i-v[j]*l]));
					vis[i][j]=true;
				}
				else if(f[i]==f[i-v[j]*l]+1)
				{
					vis[i-v[j]*l][j]=true;
					for(int k=0;k<p;k++)
						if(vis[i-v[j]*l][k]&&!vis[i][k])
						{
							memcpy(vis[i],vis[i-v[j]*l],sizeof(vis[i-v[j]*l]));
							break;
						}
						else if(vis[i][k]&&!vis[i-v[j]*l][k])break;
					vis[i-v[j]*l][j]=false;
				}
			}	
		}
	}
	fout<<f[q];
	for(int i=0;i<p;i++)
		if(vis[q][i])fout<<" "<<v[i];
	fout<<endl;
	return 0;
}
