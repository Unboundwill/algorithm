/*
ID:selfcon2
LANG:C++
PROG:job
*/
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream fin("job.in");
ofstream fout("job.out");
static int n,m1,m2,a[40],b[40],ta[40],tb[40],la[10005],lb[10005];
int main()
{
	fin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)fin>>a[i];
	for(int i=0;i<m2;i++)fin>>b[i];
	
	for(int i=0;i<n;i++)
	{
		int minn,mint=1<<20;
		for(int j=0;j<m1;j++)
			if(a[j]+ta[j]<mint){mint=a[j]+ta[j];minn=j;}
		la[i]=mint;ta[minn]=mint;
		mint=1<<20;
		for(int j=0;j<m2;j++)
			if(b[j]+tb[j]<mint){mint=b[j]+tb[j];minn=j;}
		lb[i]=mint;tb[minn]=mint;
	}
	fout<<la[n-1]<<" ";
	int mint=0;
	for(int i=0;i<n;i++)
		if(la[i]+lb[n-i-1]>mint)mint=la[i]+lb[n-i-1];
	fout<<mint<<endl;
}





