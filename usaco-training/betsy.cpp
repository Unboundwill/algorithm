/*
ID:selfcon2
LANG:C++
PROG:betsy
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("betsy.in");
ofstream fout("betsy.out");
const int px[4]={0,1,0,-1},py[4]={1,0,-1,0};
static bool a[10][10];
static int tot,n;
inline void dfs(int x,int y,int s)
{
	//fout<<x<<" "<<y<<endl;
	if(x==n&&y==1)
	{	
		if(s==n*n)tot++;
		return;
	}
	a[x][y]=true;
	
	if(a[x+1][y]&&a[x-1][y]&&!a[x][y+1]&&!a[x][y-1]){a[x][y]=false;return;}
	if(!a[x+1][y]&&!a[x-1][y]&&a[x][y+1]&&a[x][y-1]){a[x][y]=false;return;}
	
	int mustn=0,kx,ky;
	for(int i=0;i<4;i++)
	{
		int v=0,tx=x+px[i],ty=y+py[i];
		if(a[tx][ty]||(tx==n&&ty==1))continue;
		for(int j=0;j<4;j++)
			if(!a[tx+px[j]][ty+py[j]])v++;
		if(v<2)
		{	
			mustn++;kx=tx;ky=ty;
		}	
	}	
	if(mustn>1){a[x][y]=false;return;}
	else if(mustn==1){dfs(kx,ky,s+1);}
	else
	{
	
		if(!a[x+1][y])dfs(x+1,y,s+1);
		if(!a[x][y+1])dfs(x,y+1,s+1);
		if(!a[x-1][y])dfs(x-1,y,s+1);
		if(!a[x][y-1])dfs(x,y-1,s+1);
	}
	a[x][y]=false;
}
int main()
{
	fin>>n;
	if(n==1||n==2){fout<<1<<endl;return 0;}
	for(int i=0;i<=n+1;i++)
	{
		a[0][i]=true;a[i][0]=true;
		a[n+1][i]=true;a[i][n+1]=true;		
	}	
	dfs(1,1,1);
	fout<<tot<<endl;
	return 0;
}
