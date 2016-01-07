/*
ID:selfcon2
LANG:C++
PROG:stall4
*/
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
ifstream fin("stall4.in");
ofstream fout("stall4.out");
queue<int>q;
const int INF=1<<25;
static int cap[500][500],flow[500][500],a[500],p[500];
static int m,n,t1,t2,t3,f,s,t;
int main()
{
	fin>>n>>m;s=0;t=n+m+1;
	for(int i=1;i<=n;i++)
	{
		fin>>t1;
		for(int j=1;j<=t1;j++)
		{
			fin>>t2;
			cap[i][t2+n]=1;
		}
	}
	for(int i=1;i<=n;i++)cap[s][i]=1;
	for(int j=n+1;j<=n+m;j++)cap[j][t]=1;
	memset(flow,0,sizeof(flow));
	f=0;
	while(true)
	{
		memset(a,0,sizeof(a));
		a[s]=INF;
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int v=s;v<=t;v++)
			if(a[v]==0&&cap[u][v]>flow[u][v])
			{
				p[v]=u;q.push(v);
				a[v]=min(a[u],cap[u][v]-flow[u][v]);
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
	fout<<f<<endl;
	return 0;
}