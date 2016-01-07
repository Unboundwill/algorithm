/*
ID:selfcon2
LANG:C++
PROG:fence9
*/
#include <fstream>
using namespace std;
ifstream fin("fence9.in");
ofstream fout("fence9.out");
int main()
{
	int n,m,p,ans,i;
	fin>>n>>m>>p;
	ans=p*m+2-(p+1)-1;
	if(n==0)ans-=m-1;
	else for(i=1;i<n;i++)if(m*i%n==0)ans--;
	if(n==p)ans-=m-1;
	else for(i=1;i<abs(p-n);i++)if(m*i%abs(p-n)==0)ans--;
	ans/=2;
	fout<<ans<<endl;
	return 0;
}

