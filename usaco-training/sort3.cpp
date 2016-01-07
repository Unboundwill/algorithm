/*
ID:selfcon2
LANG:C++
PROG:sort3
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("sort3.in");
ofstream fout("sort3.out");
int main()
{
	int a[2000],num[10],b[10][10],n,i,ans=0;
	memset(b,0,sizeof(b));memset(num,0,sizeof(num));
	fin>>n;
	for(i=0;i<n;i++){fin>>a[i];num[a[i]]++;}
	for(i=0;i<num[1];i++)b[1][a[i]]++;
	for(i=num[1];i<num[1]+num[2];i++)b[2][a[i]]++;
	for(i=num[1]+num[2];i<n;i++)b[3][a[i]]++;
	ans+=min(b[1][2],b[2][1]);b[1][2]-=min(b[1][2],b[2][1]);b[2][1]-=min(b[1][2],b[2][1]);
	ans+=min(b[1][3],b[3][1]);b[1][3]-=min(b[1][3],b[3][1]);b[3][1]-=min(b[1][3],b[3][1]);
	ans+=min(b[3][2],b[2][3]);b[3][2]-=min(b[3][2],b[2][3]);b[2][3]-=min(b[3][2],b[2][3]);
	ans+=(b[1][2]+b[1][3])*2;
	fout<<ans<<endl;
	return 0;
}
