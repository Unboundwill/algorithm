/*
ID:selfcon2
LANG:C++
PROG:castle
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("castle.in");
ofstream fout("castle.out");
int color[100][100],area[1000000],a[100][100],m,n,maxssingle=0;
void flood_fill(int i,int j,int col)
{
	color[i][j]=col;area[col]++;if(area[col]>maxssingle)maxssingle=area[col];
	if(!(a[i][j]-((a[i][j]>>1)<<1)))if(!color[i][j-1])flood_fill(i,j-1,col);
	if(!((a[i][j]>>1)-((a[i][j]>>2)<<1)))if(!color[i-1][j])flood_fill(i-1,j,col);
	if(!((a[i][j]>>2)-((a[i][j]>>3)<<1)))if(!color[i][j+1])flood_fill(i,j+1,col);
	if(!((a[i][j]>>3)-((a[i][j]>>4)<<1)))if(!color[i+1][j])flood_fill(i+1,j,col);
}
int main()
{
	int i,j,maxs=0,maxi,maxj,maxp,col=0;
	fin>>m>>n;memset(color,0,sizeof(color));memset(area,0,sizeof(area));memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			fin>>a[i][j];
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)	if(!color[i][j]){col++;flood_fill(i,j,col);}
	maxs=0;
	for(j=1;j<=m;j++)
		for(i=n;i>=1;i--)
		{
			if((color[i][j]!=color[i-1][j])&&(area[color[i][j]]+area[color[i-1][j]]>maxs))
				{maxs=area[color[i][j]]+area[color[i-1][j]];maxi=i;maxj=j;maxp=3;}
			if((color[i][j]!=color[i][j+1])&&(area[color[i][j]]+area[color[i][j+1]]>maxs))
				{maxs=area[color[i][j]]+area[color[i][j+1]];maxi=i;maxj=j;maxp=4;}
		}
	fout<<col<<"\n"<<maxssingle<<"\n"<<maxs<<"\n"<<maxi<<" "<<maxj<<" ";
	if(maxp==3)fout<<"N";else fout<<"E";
	fout<<endl;
	return 0;
}


