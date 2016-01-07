/*
ID:selfcon2
LANG:C++
PROG:comehome
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("comehome.in");
ofstream fout("comehome.out");
static int a[100][100],n,i,j,n1,n2,t,v[100],d[100];
char t1,t2;
int main()
{
	fin>>n;
	for(i=0;i<=51;i++)
		for(j=0;j<=51;j++)a[i][j]=1<<20;
	for(i=0;i<n;i++)
	{
		fin>>t1>>t2>>t;
		if(((int)t1<=(int)('z'))&&((int)t1>=(int)('a')))n1=(int)t1-(int)('a')+1;
		else if(((int)t1<=(int)('Y'))&&((int)t1>=(int)('A')))n1=(int)t1-(int)('A')+1+26;
		else n1=0;
		if(((int)t2<=(int)('z'))&&((int)t2>=(int)('a')))n2=(int)t2-(int)('a')+1;
		else if(((int)t2<=(int)('Y'))&&((int)t2>=(int)('A')))n2=(int)t2-(int)('A')+1+26;
		else n2=0;
		if(a[n1][n2]>t){a[n1][n2]=t;a[n2][n1]=t;}
	}
	memset(v,0,sizeof(v));
	d[0]=0;
	for(i=1;i<=51;i++)d[i]=1<<20;
	for(i=0;i<=51;i++)
	{
		int mins=1<<30,x;
		for(int y=0;y<=51;y++)if(!v[y]&&d[y]<mins){mins=d[y];x=y;}
		v[x]=1;
		for(int y=0;y<=51;y++)
			if(d[y]>d[x]+a[x][y])d[y]=d[x]+a[x][y];
	}
	//for(i=0;i<=51;i++)fout<<d[i]<<endl;
	int ans=1<<30,m;
	for(i=27;i<=51;i++)
		if(d[i]<ans){m=i;ans=d[i];}
	if(m<=26)fout<<(char)(m+'a'-1)<<" ";
	else fout<<(char)(m-26+'A'-1)<<" ";
	fout<<ans<<endl;
	return 0;
}
