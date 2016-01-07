/*
ID:selfcon2
LANG:C++
PROG:camelot
*/
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
ifstream fin("camelot.in");
ofstream fout("camelot.out");
const int move[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
const int move2[8][2]={{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
struct node{int x,y;};
const int INF=1<<20;
node knight[1000],king,tem,t,king2;
queue<node>q;
static int m,n,dis[35][35][35][35],tot,sum[35][35],ans;
static bool vis[35][35];
int main()
{
	//先写一下思路吧
	//首先init读入数据，并初始化
	//其次BFS求出骑士最短路
	//再者枚举起点汇合点计算
	//init
	fin>>n>>m;
	char ch;
	fin>>ch;king.y=ch-'A'+1;fin>>king.x;
	while(fin>>ch)
	{
		knight[tot].y=ch-'A'+1;fin>>knight[tot].x;
		tot++;		
	}
	if(tot==0)
	{
		fout<<0<<endl;return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int ii=1;ii<=n;ii++)
				for(int jj=1;jj<=m;jj++)
					dis[i][j][ii][jj]=INF;
	//BFS
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			memset(vis,false,sizeof(vis));
			tem.x=i;tem.y=j;vis[i][j]=true;dis[i][j][i][j]=0;q.push(tem);
			while(!q.empty())
			{
				tem=q.front();q.pop();
				for(int k=0;k<8;k++)
				{
					t.x=tem.x+move[k][0];t.y=tem.y+move[k][1];
					if(t.x<=n&&t.x>=1&&t.y<=m&&t.y>=1&&!vis[t.x][t.y])
					{
						dis[i][j][t.x][t.y]=dis[i][j][tem.x][tem.y]+1;
						vis[t.x][t.y]=true;q.push(t);
					}
				}
			}
			for(int l=0;l<tot;l++)
				sum[i][j]+=dis[i][j][knight[l].x][knight[l].y];
		}
	//calculate	
	ans=1<<30;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(sum[i][j]+max(abs(king.x-i),abs(king.y-j))<ans)ans=sum[i][j]+max(abs(king.x-i),abs(king.y-j));
			for(int l=0;l<tot;l++)
			{
				int temp=sum[i][j]+dis[i][j][king.x][king.y]+dis[knight[l].x][knight[l].y][king.x][king.y]-dis[knight[l].x][knight[l].y][i][j];
				if(temp<ans)ans=temp;
			}
			for(int k=0;k<8;k++)
			{
				king2.x=king.x+move2[k][0];king2.y=king.y+move2[k][1];
				if(king2.x<=n&&king2.x>=1&&king2.y<=m&&king2.y>=1)
					for(int l=0;l<tot;l++)
					{
						int temp=sum[i][j]+dis[i][j][king2.x][king2.y]+dis[knight[l].x][knight[l].y][king2.x][king2.y]-dis[knight[l].x][knight[l].y][i][j]+1;
						if(temp<ans)ans=temp;
					}
			}
		}
	fout<<ans<<endl;		
	return 0;
}





