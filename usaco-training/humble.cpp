/*
ID:selfcon2
LANG:C++
PROG:humble
*/
#include <fstream>
using namespace std;
ifstream fin("humble.in");
ofstream fout("humble.out");
static int k,n,p[105],pindex[105],hum[100005],tot;
int main()
{
	fin>>k>>n;
	for(int i=0;i<k;i++)fin>>p[i];
	hum[0]=1;tot=0;
	while(tot<n)
	{
		tot++;
		for(int i=0;i<k;i++)
		{
			while(hum[pindex[i]]*p[i]<=hum[tot-1])pindex[i]++;
			if(hum[tot]==0||hum[pindex[i]]*p[i]<hum[tot])hum[tot]=hum[pindex[i]]*p[i];
		}
	}
	fout<<hum[tot]<<endl;
	return 0;
}





