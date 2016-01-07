/*
ID:selfcon2
LANG:C++
PROG:theme
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("theme.in");
ofstream fout("theme.out");
static int a[5005],f[5005];
static int maxlength,n;
int main()
{
	fin>>n;
	for(int i=1;i<=n;i++)fin>>a[i];
	//---------------------------
	maxlength=0;
	for(int i=n;i>=1;i--)
		for(int j=1;j<=i-1;j++)
		{
			if (a[i+1]-a[i]==a[j+1]-a[j])
				f[j]=min(f[j+1]+1,i-j);
			else 
				f[j]=1;
			if(f[j]>maxlength)maxlength=f[j];
		}	
	if(maxlength<5)fout<<0<<endl;
	else fout<<maxlength<<endl;
	return 0;
}

