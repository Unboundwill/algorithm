/*
ID:selfcon2
LANG:C++
PROG:fence
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("fence.in");
ofstream fout("fence.out");
static int a[501][501],d[501],F,ans[2000],tot;
void euler_tour(int x)
{
	for(int i=1;i<=500;i++)
		if(a[x][i])
		{
			a[x][i]--;a[i][x]--;
			euler_tour(i);
		}
	ans[tot]=x;
	tot++;
}
int main()
{
	fin>>F;
	for(int i=0;i<F;i++)
	{
		int t1,t2;
		fin>>t1>>t2;
		a[t1][t2]++;a[t2][t1]++;d[t1]++;d[t2]++;	
	}
	int start=0;
	for(int i=1;i<=500;i++){if(d[i])start=i;break;}
	for(int i=1;i<=500;i++)
		if(d[i]%2==1){start=i;break;}
	euler_tour(start);
	for(int i=tot-1;i>=0;i--)fout<<ans[i]<<endl;
	return 0;
}


