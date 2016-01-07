/*
ID:selfcon2
LANG:C++
PROG:telecow
*/
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
ifstream fin("telecow.in");
ofstream fout("telecow.out");
queue<int>q;
const int INF=1<<20;
static int c[200][200],cap[205][205],flow[205][205],a[205],p[205],ans[205];
static int n,m,c1,c2,ansn,Max_Flow;
int max_flow()
{
	int f=0,s=0,t=2*n+1;
	memset(flow,0,sizeof(flow));
	while(true)
	{
		memset(a,0,sizeof(a));
		/*Find new way*/
		q.push(s);a[s]=INF;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int v=0;v<=2*n+1;v++)
				if(a[v]==0&&cap[u][v]>flow[u][v])
				{
					p[v]=u;q.push(v);
					a[v]=min(a[u],cap[u][v]-flow[u][v]);
				}
		}	
		if(a[t]==0)break;
		/*Delete this way*/
		for(int u=t;u!=s;u=p[u])
		{
			flow[p[u]][u]+=a[t];
			flow[u][p[u]]-=a[t];
		}
		f+=a[t];
	}
	return f;
}
int main()
{
	fin>>n>>m>>c1>>c2;
	for(int i=0;i<m;i++)
	{
		int t1,t2;
		fin>>t1>>t2;
		c[t1][t2]=1;c[t2][t1]=1;		
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(c[i][j])
			{
				cap[2*i-1][2*j]=INF;
				cap[2*j-1][2*i]=INF;
			}	
	for(int i=1;i<=n;i++)
	{
		cap[2*i-1][2*i]=1;cap[2*i][2*i-1]=1;
	}
	cap[0][2*c1-1]=INF;cap[0][2*c1]=INF;
	cap[2*c2-1][2*n+1]=INF;cap[2*c2][2*n+1]=INF;
	/*这么着就把图建好了*/
	Max_Flow=max_flow();
	/*求出初始最大流*/
	for(int i=1;i<=n;i++)
		if(i!=c1&&i!=c2)
		{
			cap[2*i-1][2*i]=0;cap[2*i][2*i-1]=0;
			int temp=max_flow();
			if(Max_Flow-temp==1){ans[ansn]=i;ansn++;Max_Flow=temp;if(Max_Flow==0)break;}
			else{cap[2*i-1][2*i]=1;cap[2*i][2*i-1]=1;}
		}	
	fout<<ansn<<endl;
	for(int i=0;i<ansn;i++){if(i)fout<<" ";fout<<ans[i];}
	fout<<endl;
	return 0;		
}
	/*
	没心情写题了，尤其是遇上这么一道非常复杂的题目。
	静下心来，分析一下：
	这道题是让求最小点割集，而我们非常熟悉的是求最小边割集，两个问题可以相互转化。
	原来我们是这样求最小边割集的：
	先求出最大流，
	再将每一条边删去，再求最大流，如果变化量==该边容量，这条边的maybe为true
	然后迭代加深，求个数最少，字典序最小的边集
	
	同样，我们可以按这个方法求最小点割集
	1.先拆点建图，将每个点拆成两个，然后将这条边记为m+i，容量为1，其他边容量为INF，
		整个图由邻接矩阵存储，但是要存下每条边
	2.然后求出最大流
	3.接着，枚举每一条拆点后形成的边，求最大流，如果变化量==该边容量，这条边进入ans
	
	猛然发现，这么一分析，这道题根本就不复杂，那我们开始写吧。
	
	额，又晕了。
	再想一想怎么建图。
	“	我们可以把每个点i拆成两个点i1,i2，这两个点之间建立一条边权为1的有向弧。
		对于原图中边(i,j)，建立(i2,j1)和(j2,i1)两条边权为∞的有向弧。
		这样就把求最小点割转化成了求最小边割。	”
	哦，先按原始方法建图，然后再拆点建新图。
	拆点：第i个点拆出来的点为2*i-1，2*i，源点为0，汇点为2*n+1
			要建立新的源点和汇点，和拆出来的源点汇点连无穷大的边
	*/
