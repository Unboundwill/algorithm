/*
ID:selfcon2
LANG:C++
PROG:race3
*/

#include <fstream>
#include <queue>
#include <cstring>
using namespace std;
ifstream fin("race3.in");
ofstream fout("race3.out");
queue<int>q;
static int n,ans[55],tou[55],ans2[55];
static bool a[55][55],vis[55];
int main()
{
	/*
	大体思路：
	首先读入，
	然后枚举每一个点，判断是否是必经之点：
	从起点floodfill，看是否可达终点
	接着枚举每一个点，判断是否将图分成了良好的两部分：
	把这个点去掉
	从起点，floodfill，记录可达的点
	再从终点，反向floodfill，记录可达的点
	判断是否有交集
	从分割点，反向floodfill，看刚才记录的起点可达的点是否均为可达
				正向floodfill，看终点可达的点是否可达
	*/
	
	//init
	n=0;int t;
	while(fin>>t)
	{
		if(t==-1)break;
		if(t==-2){n++;continue;}
		a[n][t]=true;
	}
	n--;
	//judge must pass point
	ans[0]=0;
	for(int i=1;i<n;i++)
	{
		memset(vis,false,sizeof(vis));
		vis[i]=true;vis[0]=true;
		q.push(0);
		while(!q.empty())
		{
			int tem=q.front();q.pop();
			for(int j=1;j<=n;j++)
				if(!vis[j]&&a[tem][j])
				{
					vis[j]=true;
					q.push(j);
				}
		}
		if(vis[n]==false){ans[0]++;ans[ans[0]]=i;}
	}
	fout<<ans[0];
	for(int i=1;i<=ans[0];i++)fout<<" "<<ans[i];
	fout<<endl;
	//judge middle point
	ans2[0]=0;
	for(int k=1;k<=ans[0];k++)
	{
		int i=ans[k];
		
		memset(vis,false,sizeof(vis));
		vis[i]=true;vis[0]=true;
		q.push(0);
		while(!q.empty())
		{
			int tem=q.front();q.pop();
			for(int j=1;j<=n;j++)
				if(!vis[j]&&a[tem][j])
				{
					vis[j]=true;
					q.push(j);
				}
		}
		tou[0]=1;
		tou[1]=0;
		for(int j=1;j<n;j++)
			if(vis[j]&&j!=i){tou[0]++;tou[tou[0]]=j;}
		//for(int j=1;j<=tou[0];j++)fout<<" "<<tou[j];
		//fout<<endl;
			
		int flag=1;
		
		memset(vis,false,sizeof(vis));
		vis[i]=true;
		q.push(i);
		while(!q.empty())
		{
			int tem=q.front();q.pop();
			for(int j=0;j<=n;j++)
				if(!vis[j]&&a[tem][j])
				{
					vis[j]=true;
					q.push(j);
				}
		}
		//for(int j=0;j<=n;j++)if(vis[j])fout<<j<<" ";
		//fout<<endl;
		for(int j=1;j<=tou[0];j++)if(vis[tou[j]]){flag=0;break;}
		
		if(flag==1){ans2[0]++;ans2[ans2[0]]=i;}
	}
	
	fout<<ans2[0];
	for(int i=1;i<=ans2[0];i++)fout<<" "<<ans2[i];
	fout<<endl;	
	return 0;
}
