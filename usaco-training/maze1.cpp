/*
ID:selfcon2
LANG:C++
PROG:maze1
*/
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
ifstream fin("maze1.in");
ofstream fout("maze1.out");
struct node{int x,y;};
static node aim[2],t,tem;
queue<node>q;
static int i,j,w,h,flag,maxs,a[201][100],vis[201][100],dis[201][100];
static char ts[100],s[201][100];
int main()
{
	fin>>w>>h;fin.getline(ts,100);
	for(i=0;i<=2*h;i++)fin.getline(s[i],100);
	for(i=0;i<=2*h;i++)
		for(j=0;j<=2*w;j++)
		{
			dis[i][j]=1<<10;
			if(s[i][j]!=' ')a[i][j]=1;else a[i][j]=0;
			//fout<<a[i][j]<<" ";if(j==2*w)fout<<endl;
		}
	//读入
	flag=0;
	for(i=1;i<=2*h;i++)
	{	
		if(a[i][0]==0){a[i][0]=1;aim[flag].x=i;aim[flag].y=1;flag++;}
		if(a[i][2*w]==0){a[i][2*w]=1;aim[flag].x=i;aim[flag].y=2*w-1;flag++;}
	}
	for(i=1;i<=2*w;i++)
	{
		if(a[0][i]==0){a[0][i]=1;aim[flag].x=1;aim[flag].y=i;flag++;}
		if(a[2*h][i]==0){a[2*h][i]=1;aim[flag].x=2*h-1;aim[flag].y=i;flag++;}
	}
	//找到两个出口
	dis[aim[0].x][aim[0].y]=1;memset(vis,0,sizeof(vis));
	vis[aim[0].x][aim[0].y]=1;
	q.push(aim[0]);
	while(!q.empty())
	{
		tem=q.front();q.pop();
		if((a[tem.x-1][tem.y]==0)&&(!vis[tem.x-2][tem.y]))
		{ 
			t.x=tem.x-2;t.y=tem.y;dis[t.x][t.y]=dis[tem.x][tem.y]+1;
			q.push(t);vis[t.x][t.y]=1;
		}
		if((a[tem.x+1][tem.y]==0)&&(!vis[tem.x+2][tem.y]))
		{
			t.x=tem.x+2;t.y=tem.y;dis[t.x][t.y]=dis[tem.x][tem.y]+1;
			q.push(t);vis[t.x][t.y]=1;		
		}
		if((a[tem.x][tem.y-1]==0)&&(!vis[tem.x][tem.y-2]))
		{
			t.x=tem.x;t.y=tem.y-2;dis[t.x][t.y]=dis[tem.x][tem.y]+1;
			q.push(t);vis[t.x][t.y]=1;		
		}
		if((a[tem.x][tem.y+1]==0)&&(!vis[tem.x][tem.y+2]))
		{
			t.x=tem.x;t.y=tem.y+2;dis[t.x][t.y]=dis[tem.x][tem.y]+1;
			q.push(t);vis[t.x][t.y]=1;		
		}
	}
	dis[aim[1].x][aim[1].y]=1;memset(vis,0,sizeof(vis));
	vis[aim[1].x][aim[1].y]=1;
	q.push(aim[1]);
	while(!q.empty())
	{
		tem=q.front();q.pop();
		if((a[tem.x-1][tem.y]==0)&&(!vis[tem.x-2][tem.y]))
		{
			t.x=tem.x-2;t.y=tem.y;
			if(dis[tem.x][tem.y]+1<dis[t.x][t.y])
			{
				dis[t.x][t.y]=dis[tem.x][tem.y]+1;
				q.push(t);vis[t.x][t.y]=1;
			}
		}
		if((a[tem.x+1][tem.y]==0)&&(!vis[tem.x+2][tem.y]))
		{
			t.x=tem.x+2;t.y=tem.y;
			if(dis[tem.x][tem.y]+1<dis[t.x][t.y])
			{
				dis[t.x][t.y]=dis[tem.x][tem.y]+1;
				q.push(t);vis[t.x][t.y]=1;
			}
		}
		if((a[tem.x][tem.y-1]==0)&&(!vis[tem.x][tem.y-2]))
		{
			t.x=tem.x;t.y=tem.y-2;
			if(dis[tem.x][tem.y]+1<dis[t.x][t.y])
			{
				dis[t.x][t.y]=dis[tem.x][tem.y]+1;
				q.push(t);vis[t.x][t.y]=1;
			}		
		}
		if((a[tem.x][tem.y+1]==0)&&(!vis[tem.x][tem.y+2]))
		{
			t.x=tem.x;t.y=tem.y+2;
			if(dis[tem.x][tem.y]+1<dis[t.x][t.y])
			{
				dis[t.x][t.y]=dis[tem.x][tem.y]+1;
				q.push(t);vis[t.x][t.y]=1;
			}		
		}
	}
	maxs=0;
	for(i=1;i<=2*h;i++)
		for(j=1;j<=2*w;j++)
			if((dis[i][j]>maxs)&&dis[i][j]!=(1<<10))maxs=dis[i][j];		
	fout<<maxs<<endl;
	return 0;
}







