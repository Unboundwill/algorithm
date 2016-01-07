/*
ID:selfcon2
LANG:C++
PROG:milk6
*/
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
ifstream fin("milk6.in");
ofstream fout("milk6.out");
const int INF=1<<25;
static int u[1005],v[1005],cap[1005],g[50][50],ans[1005];
static int flow[50][50],a[50],p[50];
static int n,m,depth,Max_Flow;
static bool maybe[50];
queue<int>q;
int max_flow()
{
	memset(flow,0,sizeof(flow));
	int f=0,s=1,t=n;
	while(true)
	{
		memset(a,0,sizeof(a));
		a[s]=INF;
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int v=1;v<=n;v++)
				if(a[v]==0&&g[u][v]>flow[u][v])
				{
					p[v]=u;q.push(v);
					a[v]=min(a[u],g[u][v]-flow[u][v]);
				}	
		}
		if(a[t]==0)break;
		for(int u=t;u!=s;u=p[u])
		{
			flow[p[u]][u]+=a[t];
			flow[u][p[u]]-=a[t];
		}
		f+=a[t];
	}
	return f;
}
void cut()
{
	int tem=0,dep=0;
	for(int i=1;i<=m;i++)
	{
		g[u[i]][v[i]]-=cap[i];
		if(Max_Flow-max_flow()==cap[i]){maybe[i]=true;tem+=cap[i];}
		g[u[i]][v[i]]+=cap[i];
	}
	if(tem==Max_Flow)
	{
		for(int i=1;i<=m;i++)if(maybe[i])dep++;
		fout<<dep<<endl;
		for(int i=1;i<=m;i++)if(maybe[i])fout<<i<<endl;
		exit(0);
	}	
}
void search(int k,int pos,int c)
{
	if(k==depth)
	{
		if(c==Max_Flow)
		{
			fout<<k<<endl;
			for(int i=1;i<=k;i++)fout<<ans[i]<<endl;
			exit(0);
		}
		return;
	}
	for(int i=pos+1;i<=m;i++)
		if(maybe[i])
		{
			ans[k+1]=i;
			search(k+1,i,c+cap[i]);
		}
}
int main()
{
	fin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		fin>>u[i]>>v[i]>>cap[i];
		g[u[i]][v[i]]+=cap[i];		
	}
	//---------------------------------------
	Max_Flow=max_flow();
	fout<<Max_Flow<<" ";
	//---------------------------------------
	cut();	
	//for(int i=1;i<=m;i++)if(maybe[i])fout<<i<<endl;
	//---------------------------------------	
	for(depth=1;depth<=m;depth++)search(0,0,0);
	//---------------------------------------
	fout<<0<<endl;
	return 0;
}
