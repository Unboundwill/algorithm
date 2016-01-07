/*
ID:selfcon2
LANG:C++
PROG:fc
*/
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
ifstream fin("fc.in");
ofstream fout("fc.out");
struct node{double x,y;};
node p0,p[10000],a[10000],b[10000];
static int n,pn,pb;
static double ans=0;
double cross(node o,node a,node b)
{
	return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);	
}	
int cmp(const void * x,const void * y)
{
	node a=*(node *)x,b=*(node *)y;
	return cross(p0,a,b)<0;
}
double dis(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));	
}	
int main()
{
	//-----------------------------------init
	fin>>n;p0.x=1000000000;p0.y=1000000000;
	for(int i=0;i<n;i++)
	{
		fin>>p[i].x>>p[i].y;
		if(p[i].x<p0.x){p0=p[i];pn=i;}
		else if(p[i].x==p0.x&&p[i].y<p0.y){p0=p[i];pn=i;}
	}
	//-----------------------------------极角排序
	int j=-1;
	for(int i=0;i<n;i++)
		if(i!=pn){j++;a[j]=p[i];}
	qsort(a,n-1,sizeof(a[0]),cmp);	
	//------------------------------------Graham Scan
	b[0]=p0;b[1]=a[0];pb=2;
	for(int i=1;i<n-1;i++)
	{
		b[pb]=a[i];
		while(cross(b[pb-2],b[pb-1],b[pb])<=0)
		{
			pb--;b[pb]=a[i];
		}
		pb++;
	}	
	//--------------------------------------Calculate
	for(int i=1;i<pb;i++)
		ans+=dis(b[i-1],b[i]);
	ans+=dis(b[0],b[pb-1]);
	fout.setf(ios::fixed);
	fout.precision(2);
	fout<<ans<<endl;
	return 0;
}

