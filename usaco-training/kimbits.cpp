/*
ID:selfcon2
LANG:C++
PROG:kimbits
*/
#include <fstream>
using namespace std;
ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
static unsigned int n,l,num,f[50][50];
void calc(unsigned int x)
{
	unsigned int len=n-1,m=l;
	while(len>=0)
	{
		if(x>f[len][m])
		{
			fout<<1;x-=f[len][m];
			if(len==0)break;
			len--;m--;
		}
		else
		{
			fout<<0;
			if(len==0)break;
			len--;			
		}
	}
	fout<<endl;
}
int main()
{
	fin>>n>>l>>num;
	for(int i=0;i<=n+5;i++)f[0][i]=1;
	f[1][0]=1;for(int i=1;i<=n+5;i++)f[1][i]=2;
	for(int i=2;i<=n;i++)
	{
		f[i][0]=1;
		for(int j=1;j<=i+2;j++)f[i][j]=f[i-1][j]+f[i-1][j-1];
		for(int j=i+3;j<=n+5;j++)f[i][j]=f[i][j-1];
	}
	calc(num);
	return 0;
}




