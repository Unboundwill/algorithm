/*
ID:selfcon2
LANG:C++
PROG:starry
*/
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;
ifstream fin("starry.in");
ofstream fout("starry.out");
struct node{int x,y;};
const node way[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
static int x1,x2,y1,y2,w,h,dictn,flag,flag2;
static char a[105][105];
struct node2
{
	int w,h;
	char map[105][105];
};
node2 dict[26],b;
void floodfill(int y,int x,int c)
{
	a[y][x]=c;
	x1=min(x1,x);x2=max(x2,x);
	y1=max(y1,y);y2=min(y2,y);
	for(int i=0;i<8;i++)
	{
		int ty=y+way[i].y,tx=x+way[i].x;
		if(ty>=0&&ty<h&&tx>=0&&tx<w&&a[ty][tx]!=c&&a[ty][tx]!='0')
			floodfill(ty,tx,c);
	}	
}
int main()
{
	//-----------------------------------------init
	fin>>w>>h;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)fin>>a[i][j];
	//-----------------------------------------calc
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if(a[i][j]=='1')
			{
				x1=w;x2=0;y1=0;y2=h;
				floodfill(i,j,'2');
				memset(b.map,'0',sizeof(b.map));
				for(int ii=y2;ii<=y1;ii++)
					for(int jj=x1;jj<=x2;jj++)
						if(a[ii][jj]=='2')b.map[ii-y2][jj-x1]=a[ii][jj];
				b.w=x2-x1+1;b.h=y1-y2+1;
				
				flag2=0;
				for(int k=0;k<dictn;k++)
				{
					
					for(int l=0;l<4;l++)
					{	
						//右旋90°
						node2 tem=b;
						b.w=tem.h;b.h=tem.w;
						for (int ii=0;ii<tem.h;ii++)
							for (int jj=0;jj<tem.w;jj++)
								b.map[jj][b.w-ii-1]=tem.map[ii][jj];
						//原图对比
						flag=1;
						if(b.w!=dict[k].w||b.h!=dict[k].h)flag=0;
						if(flag)
							for(int ii=0;ii<b.h;ii++)
								for(int jj=0;jj<b.w;jj++)
									if(b.map[ii][jj]!=dict[k].map[ii][jj]){flag=0;break;}
						if(flag){floodfill(i,j,(char)('a'+k));flag2=1;break;}
						//上下对称
						flag=1;
						if(b.w!=dict[k].w||b.h!=dict[k].h)flag=0;
						if(flag)
							for(int ii=0;ii<b.h;ii++)
								for(int jj=0;jj<b.w;jj++)
									if(b.map[ii][jj]!=dict[k].map[b.h-ii-1][jj]){flag=0;break;}
						if(flag){floodfill(i,j,(char)('a'+k));flag2=1;break;}	
					}	
					if(flag2)break;
				}	
				if(!flag2)
				{
					floodfill(i,j,(char)(dictn+'a'));
					dict[dictn]=b;
					dictn++;
				}
			}
	//---------------------------------------print
	for(int i=0;i<h;i++)
	{	
		for(int j=0;j<w;j++)fout<<a[i][j];
		fout<<endl;
	}	
	return 0;
}
