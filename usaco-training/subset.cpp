/*
ID:selfcon2
LANG:C++
PROG:subset
*/
#include <fstream>
using namespace std;
ifstream fin("subset.in");
ofstream fout("subset.out");
static int n,i,j,m;static long long f[100000];
int main()
{
	fin>>n;if(n*(n+1)%4!=0){fout<<0<<endl;return 0;}
	m=n*(n+1)/4;f[0]=1;
	for(i=1;i<=n;i++)
		for(j=m;j>=i;j--)
		{
			f[j]+=f[j-i];			
		}
	fout<<f[m]/2<<endl;
	return 0;	
}


