/*
ID:selfcon2
LANG:C++
PROG:butter
*/
#include <fstream>
#include <queue>
#include <cstring>
using namespace std;
ifstream fin("butter.in");
ofstream fout("butter.out");
const int INF=1<<25;
queue<int>q;
static int u[5000],v[5000],w[5000],d[5000],next[5000],first[5000],cow[5000];
static bool inq[1000];
int main()
{
	static int n,p,c,i,j,ans=INF,t,tot,flag;
	fin>>n>>p>>c;
	for(i=0;i<p;i++)first[i]=-1;
	for(i=0;i<n;i++){fin>>t;cow[t-1]++;}
	for(i=0;i<c;i++)
	{
		fin>>u[2*i]>>v[2*i]>>w[2*i];u[2*i]--;v[2*i]--;
		next[2*i]=first[u[2*i]];first[u[2*i]]=2*i;
		v[2*i+1]=u[2*i];u[2*i+1]=v[2*i];w[2*i+1]=w[2*i];
		next[2*i+1]=first[u[2*i+1]];first[u[2*i+1]]=2*i+1;
	}
	for(i=0;i<p;i++)
	{
		tot=0;//fout<<i<<endl;
		for(j=0;j<p;j++)if(j==i)d[j]=0;else d[j]=INF;
		memset(inq,false,sizeof(inq));
		q.push(i);inq[i]=true;
		while(!q.empty())
		{
			int x=q.front();q.pop();
			inq[x]=false;
			for(int e=first[x];e!=-1;e=next[e])if(d[v[e]]>d[x]+w[e])
			{
				d[v[e]]=d[x]+w[e];
				if(!inq[v[e]])
				{
					inq[v[e]]=true;
					q.push(v[e]);
				}
			}
		}
		for(j=0;j<p;j++)tot+=cow[j]*d[j];
		if(tot<ans)ans=tot;
		flag++;
	}
	fout<<ans<<endl;
	return 0;
}


