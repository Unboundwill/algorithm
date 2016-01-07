/*
ID:selfcon2
LANG:C++
PROG:wissqu
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("wissqu.in");
ofstream fout("wissqu.out");
struct node{char a;int b,c;};
//struct node2{int x,y;};
node ans[20],tans[20];
//const node2 way[8]={{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{-1,1},{1,1},{1,-1}};
static int num[6]={0,3,3,3,4,3},map[10][10];
static int tot;
static bool vis[10][10];
void dfs(int step,int x)
{
	if(step==16)
	{
		if(!tot)memcpy(ans,tans,sizeof(tans));
		tot++;
	}	
	else
	{
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
			{
				//int flag=1;
				//if(vis[i][j])continue;
				//for(int k=0;k<8;k++)
				//	if(map[i+way[k].x][j+way[k].y]==x){flag=0;break;}	
				if (!vis[i][j] && map[i-1][j-1]!=x && map[i-1][j]!=x && map[i-1][j+1]!=x
					&& map[i][j-1]!=x && map[i][j]!=x && map[i][j+1]!=x 
					&& map[i+1][j-1]!=x && map[i+1][j]!=x && map[i+1][j+1]!=x)
				//if(flag)
				{
					int t=map[i][j];
					map[i][j]=x;num[x]--;
					vis[i][j]=true;
					if(!tot)
					{
						tans[step].a=(char)(x+'A'-1);
						tans[step].b=i;tans[step].c=j;
					}
					if(step==15)dfs(16,0);
					else 
						for(int k=1;k<=5;k++)
							if(num[k])dfs(step+1,k);
					map[i][j]=t;num[x]++;
					vis[i][j]=false;
				}	
			}
	}
}
int main()
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			char ch;
			fin>>ch;
			map[i][j]=(int)ch-'A'+1;
		}	
	dfs(0,4);
	for(int i=0;i<16;i++)fout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c<<endl;
	fout<<tot<<endl;
	return 0;
}

