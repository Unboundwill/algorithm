/*
ID:selfcon2
LANG:C++
PROG:stamps
*/
#include <fstream>
using namespace std;
ifstream fin("stamps.in");
ofstream fout("stamps.out");
const int INF=1<<30;
static int K,N,i,v[205],tot,f[2000005];
int main()
{
	fin>>K>>N;
	for(i=0;i<N;i++)fin>>v[i];
	tot=1;
	while(1)
	{
		f[tot]=INF;
		for(i=0;i<N;i++)
			if(tot>=v[i])
				if(f[tot]>f[tot-v[i]]+1)f[tot]=f[tot-v[i]]+1;
		if(f[tot]<=K)tot++;else{fout<<tot-1<<endl;break;}
	}
	return 0;
}
	
	
