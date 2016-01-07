/*
ID:selfcon2
LANG:C++
PROG:schlnet
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("schlnet.in");
ofstream fout("schlnet.out");
static bool a[200][200],into[200],out[200],vis[200];
static int n,newp[200],inton,outn,tot;
int main()
{
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		fin>>t;
		while(t)
		{
			a[i][t]=true;
			fin>>t;
		}
	}	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=true;
			newp[tot]=i;tot++;
			for(int j=1;j<=n;j++)if(a[i][j]&&a[j][i])vis[j]=true;
		}
	for(int i=0;i<tot;i++)
	{
		for(int j=0;j<tot;j++)
		if(i!=j)
		{
			if(a[newp[i]][newp[j]])out[i]=true;
			if(a[newp[j]][newp[i]])into[i]=true;
		}
		if(!out[i])outn++;
		if(!into[i])inton++;
	}	
	if(tot==1)fout<<1<<"\n"<<0<<endl;
	else
	{
		fout<<inton<<endl;
		fout<<max(inton,outn)<<endl;
	}
	return 0;
}
