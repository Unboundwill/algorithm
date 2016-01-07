/*
ID:selfcon2
LANG:C++
PROG:ditch
*/
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
ifstream fin("ditch.in");
ofstream fout("ditch.out");
queue<int>q;
const int INF=1<<25;
static int cap[205][205],flow[205][205],a[205],p[205];
static int m,n,t1,t2,t3,f,s,t;
int main()
{
	fin>>m>>n;
	for(int i=0;i<m;i++)
	{
		fin>>t1>>t2>>t3;
		cap[t1][t2]+=t3;		
	}
	memset(flow,0,sizeof(flow));
	f=0;s=1;t=n;
	while(true)
	{
		memset(a,0,sizeof(a));
		a[s]=INF;
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int v=1;v<=n;v++)
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

