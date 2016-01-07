/*
ID:selfcon2
LANG:C++
PROG:holstein
*/
#include <fstream>
#include <string>
using namespace std;
ifstream fin("holstein.in");
ofstream fout("holstein.out");
static int situation[30],v[30],g[30][30],V,G,ans[1000],way[1000];
int cmp()
{
	int flag=1,i;
	if(way[0]>ans[0])flag=0;
	else if(way[0]==ans[0])
		for(i=1;i<=way[0];i++)if(way[i]>ans[i]){flag=0;break;}
	if(flag)for(i=0;i<=way[0];i++)ans[i]=way[i];
}
int check()
{
	int flag=1,i;
	for(i=0;i<V;i++)if(situation[i]<v[i]){flag=0;break;}
	return flag;	
}
void dfs(int dep)
{
	int i;
	if(check())
	{
		cmp();
		return;
	}
	if(dep==G)return;
	dfs(dep+1);
	way[0]++;way[way[0]]=dep+1;
	for(i=0;i<V;i++)situation[i]+=g[dep][i];
	dfs(dep+1);
	for(i=0;i<V;i++)situation[i]-=g[dep][i];
	way[0]--;
}
int main()
{
	int i,j;
	fin>>V;ans[0]=100000;
	for(i=0;i<V;i++)fin>>v[i];
	fin>>G;
	for(i=0;i<G;i++)for(j=0;j<V;j++)fin>>g[i][j];
	dfs(0);
	fout<<ans[0];
	for(i=1;i<=ans[0];i++)fout<<" "<<ans[i];
	fout<<endl;
	return 0;
}
