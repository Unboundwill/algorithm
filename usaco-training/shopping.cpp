/*
ID:selfcon2
LANG:C++
PROG:shopping
*/
#include <fstream>
using namespace std;
const int INF=1<<30;
ifstream fin("shopping.in");
ofstream fout("shopping.out");
struct node{int num[6],price;};
node low[1000];
static int s,f[6][6][6][6][6],mark[1000],b,many[10],p[10];
int main()
{
	fin>>s;int flag=0;
	for(int i=0;i<s;i++)
	{
		int x;
		fin>>x;
		for(int j=0;j<x;j++)
		{
			int y;
			fin>>y;
			if(!mark[y]){flag++;mark[y]=flag;}
			fin>>low[i].num[mark[y]];
		}
		fin>>low[i].price;
	}
	fin>>b;
	for(int i=0;i<b;i++)
	{
		int x;
		fin>>x;if(!mark[x]){flag++;mark[x]=flag;}
		fin>>many[mark[x]]>>p[mark[x]];
	}
	for(int i=0;i<=many[1];i++)
		for(int j=0;j<=many[2];j++)
			for(int k=0;k<=many[3];k++)
				for(int l=0;l<=many[4];l++)
					for(int m=0;m<=many[5];m++)
					{
						f[i][j][k][l][m]=i*p[1]+j*p[2]+k*p[3]+l*p[4]+m*p[5];
						if(i>=1)if(f[i][j][k][l][m]>f[i-1][j][k][l][m]+p[1])f[i][j][k][l][m]=f[i-1][j][k][l][m]+p[1];
						if(j>=1)if(f[i][j][k][l][m]>f[i][j-1][k][l][m]+p[2])f[i][j][k][l][m]=f[i][j-1][k][l][m]+p[2];
						if(k>=1)if(f[i][j][k][l][m]>f[i][j][k-1][l][m]+p[3])f[i][j][k][l][m]=f[i][j][k-1][l][m]+p[3];
						if(l>=1)if(f[i][j][k][l][m]>f[i][j][k][l-1][m]+p[4])f[i][j][k][l][m]=f[i][j][k][l-1][m]+p[4];
						if(m>=1)if(f[i][j][k][l][m]>f[i][j][k][l][m-1]+p[5])f[i][j][k][l][m]=f[i][j][k][l][m-1]+p[5];
						for(int n=0;n<s;n++)
							if(i>=low[n].num[1]&&j>=low[n].num[2]&&k>=low[n].num[3]&&l>=low[n].num[4]&&m>=low[n].num[5])
								if(f[i][j][k][l][m]>f[i-low[n].num[1]][j-low[n].num[2]][k-low[n].num[3]][l-low[n].num[4]][m-low[n].num[5]]+low[n].price)
									f[i][j][k][l][m]=f[i-low[n].num[1]][j-low[n].num[2]][k-low[n].num[3]][l-low[n].num[4]][m-low[n].num[5]]+low[n].price;
						//fout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<" "<<f[i][j][k][l][m]<<endl;		
					}
	fout<<f[many[1]][many[2]][many[3]][many[4]][many[5]]<<endl;
	return 0;
}





