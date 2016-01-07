/*
ID:selfcon2
LANG:C++
PROG:money
*/
#include <fstream>
using  namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
static int V,n,i,j,v[25];
static long long f[50000];
int main()
{
	fin>>V>>n;
	for(i=0;i<V;i++)fin>>v[i];
	f[0]=1;
	for(i=0;i<V;i++)
		for(j=0;j<n;j++)f[j+v[i]]+=f[j];
	fout<<f[n]<<endl;
	return 0;	
}


