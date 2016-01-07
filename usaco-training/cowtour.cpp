/*
ID:selfcon2
LANG:C++
PROG:cowtour
*/
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
struct node{double x,y;};
const double INF=1e20;
node p[155];
static int a[155][155],i,j,k,n;
static double ans=INF,w[155][155],far[155],infarm[155];
double dis(int i,int j)
{
	return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y));
}
int main()
{
	fin>>n;
	for(i=0;i<n;i++)fin>>p[i].x>>p[i].y;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			char ch;
			fin>>ch;
			if(ch=='1')a[i][j]=1;else a[i][j]=0;
			if(a[i][j])w[i][j]=dis(i,j);else w[i][j]=INF;
			if(i==j){w[i][j]=0;a[i][j]=1;}
		}
	//input 初始化
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(w[i][k]+w[k][j]<w[i][j])w[i][j]=w[i][k]+w[k][j];
				a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
			}
	//求出每对顶点间的最短路，且是否连通
	for(i=0;i<n;i++)
	{
		far[i]=0;
		for(j=0;j<n;j++)
			if(j!=i&&a[i][j]&&w[i][j]>far[i])far[i]=w[i][j];
	}
	//求出每个顶点相连的最远的顶点距离
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(far[i]>infarm[j])infarm[j]=far[i];
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(!a[i][j])
				if(max(far[i]+far[j]+dis(i,j),max(infarm[i],infarm[j]))<ans)
					ans=max(far[i]+far[j]+dis(i,j),max(infarm[i],infarm[j]));
		}
		//枚举不连通的两个点更新结果
	fout.setf(ios::fixed);
	fout<<ans<<setw(6)<<endl;
	return 0;
}

