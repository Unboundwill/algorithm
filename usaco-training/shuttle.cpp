/*
ID:selfcon2
LANG:C++
PROG:shuttle
*/
#include <fstream>
using namespace std;
ifstream fin("shuttle.in");
ofstream fout("shuttle.out");
static int n,tot,a[100000];
int main()
{
	fin>>n;tot=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			int first=n+i+2;
			for(int j=1;j<=i;j++)
			{
				a[tot]=first-2*j;
				tot++;
			}
		}	
		else
		{
			int first=n-i;
			for(int j=1;j<=i;j++)
			{
				a[tot]=first+2*j;
				tot++;
			}
		}
	}
	int t=tot;
	int i=n+1;
		if(i%2==1)
		{
			int first=n+i+2;
			for(int j=1;j<=i;j++)
			{
				a[tot]=first-2*j;
				tot++;
			}
		}	
		else
		{
			int first=n-i;
			for(int j=1;j<=i;j++)
			{
				a[tot]=first+2*j;
				tot++;
			}
		}
	int s=0;
	for(i=1;i<tot;i++)
	{
		if((i-1)&&s%20!=0)fout<<" ";fout<<a[i];
		s++;if(s%20==0)fout<<endl;
	}
	for(i=n;i>=1;i--)
	{
		int first=i*(i-1)/2;
		for(int j=first;j<=first+i-1;j++){if(s%20!=0)fout<<" ";fout<<a[j];s++;if(s%20==0)fout<<endl;}	
	}
	if(s%20!=0)fout<<endl;
	return 0;
}
