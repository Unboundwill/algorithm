/*
ID:selfcon2
LANG:C++
PROG:concom
*/
#include <fstream>
using namespace std;
ifstream fin("concom.in");
ofstream fout("concom.out");
static int n,control[101][101],have[101][101],a,b,p,flag,i,j,k,l,minn=1000,maxn=0;
int main()
{
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>a>>b>>p;
		have[a][b]=p;
		if(a<minn)minn=a;if(a>maxn)maxn=a;
		if(b<minn)minn=b;if(b>maxn)maxn=b;
	}
	for(i=minn;i<=maxn;i++)control[i][i]=1;
	flag=1;
	while(flag)
	{
		flag=0;
		for(i=minn;i<=maxn;i++)
			for(j=minn;j<=maxn;j++)
				if(!control[i][j])
				{
					int t=0;
					for(k=minn;k<=maxn;k++)
					{
						t+=control[i][k]*have[k][j];
						if(t>50){flag=1;control[i][j]=1;break;}
					}
					if(control[i][j])
						for(k=minn;k<=maxn;k++)if(control[l][i])control[l][j]=1;
				}
	}
	for(i=minn;i<=maxn;i++)
		for(j=minn;j<=maxn;j++)
			if((i!=j)&&control[i][j])fout<<i<<" "<<j<<endl;
	return 0;
}
