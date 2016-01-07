/*
ID:selfcon2
LANG:C++
PROG:picture
*/
/*
	离散化
	
	把所有矩形离散化(就是将整个平面分成许多“竖条”或“横条”，对其操作），
	每个矩形都由四条边组成，分为纵边和横边。对纵边和横边分别扫描一次，以横边为例：

    * 每个矩形的两条横边中，称下面的为始边，上面的为终边。
    * 把每条横边以纵坐标从小到大排序，如果纵坐标相同，则应把始边排到终边之前。
    * 依次枚举每条横边
          o 如果当前边为始边，则把这条边的横向的所有点j的层数增加1，即为level[j]++。
		  如果层数由0变为了1，则这一点一定是边缘点，总周长 ans++。
          o 如果当前边为终边，则把这条边的横向的所有点j的层数减少1，即为level[j]--。
		  如果层数由1变为了0，则这一点一定是边缘点，总周长 ans++。 

	同理按此方法扫描纵边，即可得到最后结果。 
*/
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream fin("picture.in");
ofstream fout("picture.out");
int n,ans,*level;
struct Line{int p,h,t;bool begin;};
Line Lx[10001],Ly[10001];
int cmp(const void * x,const void * y)
{
	if(((Line*)x)->p!=((Line*)y)->p)return ((Line*)x)->p-((Line*)y)->p;
	else if(((Line*)x)->begin)return -1;
	else return 1;
}
void scan(Line *L)
{
	for(int i=-10000;i<=10000;i++)level[i]=0;
	for(int i=1;i<=n;i++)
		if(L[i].begin)
			for(int j=L[i].h;j<L[i].t;j++)
			{
				level[j]++;
				if(level[j]==1)ans++;
			}
		else
			for(int j=L[i].h;j<L[i].t;j++)
			{
				level[j]--;
				if(level[j]==0)ans++;
			}
}
int main()
{
	int x1,x2,y1,y2;
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		fin>>x1>>y1>>x2>>y2;
		Lx[2*i-1].p=y1;Lx[2*i-1].begin=true;Lx[2*i-1].h=x1;Lx[2*i-1].t=x2;
		Lx[2*i].p=y2;Lx[2*i].begin=false;Lx[2*i].h=x1;Lx[2*i].t=x2;
		Ly[2*i-1].p=x1;Ly[2*i-1].begin=true;Ly[2*i-1].h=y1;Ly[2*i-1].t=y2;
		Ly[2*i].p=x2;Ly[2*i].begin=false;Ly[2*i].h=y1;Ly[2*i].t=y2;
	}
	n*=2;
	qsort(Lx+1,n,sizeof(Lx[0]),cmp);qsort(Ly+1,n,sizeof(Ly[0]),cmp);
	level=(int *)malloc(sizeof(int)*20002);level+=10001;
	scan(Lx);scan(Ly);
	fout<<ans<<endl;
	return 0;
}
