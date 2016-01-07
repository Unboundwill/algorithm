/*
ID:selfcon2
LANG:C++
PROG:rect1
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("rect1.in");
ofstream fout("rect1.out");
struct node{int x1,y1,x2,y2,color;};
node rect[1005];
static int a,b,n,size[2505];
void put(node t,int x)
{
	int i=x;
	while(i<=n&&(t.x1>=rect[i].x2||t.y1>=rect[i].y2||t.x2<=rect[i].x1||t.y2<=rect[i].y1))
		i++;
	if(i==n+1)
	{
		size[t.color]+=(t.x2-t.x1)*(t.y2-t.y1);
		return;		
	}
	if(t.x1<rect[i].x1)
	{
		node tem=t;
		tem.x2=rect[i].x1;
		put(tem,i+1);		
		t.x1=rect[i].x1;
	}
	if(t.x2>rect[i].x2)
	{
		node tem=t;
		tem.x1=rect[i].x2;
		put(tem,i+1);
		t.x2=rect[i].x2;
	}
	if(t.y1<rect[i].y1)
	{
		node tem=t;
		tem.y2=rect[i].y1;
		put(tem,i+1);
		t.y1=rect[i].y1;
	}
	if(t.y2>rect[i].y2)
	{
		node tem=t;
		tem.y1=rect[i].y2;
		put(tem,i+1);
		t.y2=rect[i].y2;
	}
}
int main()
{
	//init
	memset(size,0,sizeof(size));
	fin>>a>>b>>n;
	rect[0].x1=0;rect[0].y1=0;rect[0].x2=a;rect[0].y2=b;rect[0].color=1;
	for(int i=1;i<=n;i++)fin>>rect[i].x1>>rect[i].y1>>rect[i].x2>>rect[i].y2>>rect[i].color;
	//倒序矩形切割
	for(int i=n;i>=0;i--)
		put(rect[i],i+1);
	//print
	for(int i=1;i<=2500;i++)
		if(size[i]!=0)fout<<i<<" "<<size[i]<<endl;
	return 0;
}



