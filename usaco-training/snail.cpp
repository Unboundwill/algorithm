/*
ID:selfcon2
LANG:C++
PROG:snail
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("snail.in");
ofstream fout("snail.out");
struct node{int x,y;};
const node way[4]={{-1,0},{0,-1},{1,0},{0,1}};
static int a[125][125],n,b,ans;
static bool vis[125][125][4];
void dfs(int x,int y,int p,int step)
{
	//fout<<x<<" "<<y<<" "<<step<<endl;
	int xx=x,yy=y;
	while(a[y+way[p].y][x+way[p].x]==0)
	{
		step++;
		y+=way[p].y;
		x+=way[p].x;
		a[y][x]=1;
	}	
	if(step>ans)ans=step;
	if(a[y+way[p].y][x+way[p].x]!=1)
	for(int i=0;i<4;i++)
		if(a[y+way[i].y][x+way[i].x]==0)
			dfs(x,y,i,step);
	while(x!=xx||y!=yy)
	{
		a[y][x]=0;
		y-=way[p].y;
		x-=way[p].x;
	}	
}
int main()
{
	fin>>n>>b;
	for(int i=0;i<b;i++)
	{
		char ch;int t;
		fin>>ch>>t;
		a[t][ch-'A'+1]=-1;
	}	
	for(int i=0;i<=n;i++)
	{
		a[0][i]=-1;a[n+1][i]=-1;
		a[i][0]=-1;a[i][n+1]=-1;
	}
	a[1][1]=1;
	dfs(1,1,2,1);
	dfs(1,1,3,1);
	fout<<ans<<endl;
	return 0;
}

