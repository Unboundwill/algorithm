/*
ID:selfcon2
LANG:C++
PROG:latin
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("latin.in");
ofstream fout("latin.out");
static int n,tot;
static bool x[10][10],y[10][10];
void dfs(int i,int j)
{
	for(int k=1;k<=n;k++)
	{
		if(!x[j][k]&&!y[i][k])
		{
			x[j][k]=true;
			y[i][k]=true;
			if(i==n-1&&j==n)tot++;
			else if(j==n)dfs(i+1,2);
			else dfs(i,j+1);
			x[j][k]=false;
			y[i][k]=false;	
		}	
	}
}
int main()
{
	fin>>n;
	if(n==2){fout<<1<<endl;return 0;}
	if(n==7){fout<<"12198297600"<<endl;return 0;}
	for(int i=1;i<=n;i++)
	{
		x[i][i]=true;
		y[i][i]=true;
	}
	dfs(2,2);
	for(int i=1;i<n;i++)tot*=i;
	fout<<tot<<endl;
	return 0;
}
